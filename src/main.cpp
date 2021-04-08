/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:29:13 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 22:38:20 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// parsing
#include <fstream>		// parsing

#include <pthread.h>	// posix threads
#include <cstring>		// memset

#include "All.hpp"
#include "Parser.hpp"

All	all;

void	init(void)
{
	if (!all.disp.is_init())
		Utils::error_quit("Need a Window: in .mica file");
	if (!all.cam.is_init())
		Utils::error_quit("Need a Camera: in .mica file");
	all.time.set_average_sample(5);
	//all.time.set_fps(60);
	all.set_threads(4);
}

static bool	_compare_dist(const Hit &hit1, const Hit &hit2)
{ return (hit1.dist < hit2.dist); }

void	*threadFun(void *arg)
{
	ThreadContext		&tc = *reinterpret_cast<ThreadContext *>(arg);
	std::vector<Hit>	hits;
	Hit					*closest_hit;
	unsigned			selected_hit;

	hits.reserve(MAX_EXPECTED_HITS);
	for (unsigned pix = tc.start; pix < tc.end; pix++)
	{
		hits.clear();
		for (unsigned obj_id = 0; obj_id < all.scene.obj.size(); ++obj_id)
			// all.scene.obj[obj_id]->hit(all.cam.pix[pix], hits);
			all.scene.obj[obj_id]->hit(Vec3d<float>(0,0,0), all.cam.pix[pix], hits);

		std::sort(hits.begin(), hits.end(), _compare_dist);
		selected_hit = 0;
		while (hits.size() > 0UL && hits[selected_hit].dist < 0.0f)
			++selected_hit;
			//find closest hit (vry important)
			// tolerance negative for entering hits
			// tolerance positive for exiting hits
		closest_hit = &hits[selected_hit];



		if (hits.size() != 0)
		{
			Vec3d<float>	hit_pos;
			Vec3d<float>	hit_normal;
			float			illuminance;

			illuminance = all.scene.ambiant;
			hit_pos = closest_hit->pos(Vec3d<float>(0, 0, 0), all.cam.pix[pix]); 
			hit_normal = closest_hit->obj->normal(hit_pos);
			for (unsigned id_spot = 0; id_spot < all.scene.spot.size();
				++id_spot)
				illuminance += all.scene.spot[id_spot]->illuminance_at(hit_pos,
					hit_normal);
			for (unsigned id_para = 0; id_para < all.scene.para.size();
				++id_para)
				illuminance += all.scene.para[id_para]->illuminance_at(hit_pos,
					hit_normal);

			all.disp.pixels[pix] = closest_hit->obj->color.rgb_dim(illuminance *
				all.cam.fspeed);
			/* debug lines */
			// if (pix % all.disp.res_x == 700)
			// 	all.disp.pixels[pix] = 0xff2020;
			// if (pix % all.disp.res_x == 701 && (((pix / all.disp.res_x) * 100) / 720) % 10 == 0)
			// 	all.disp.pixels[pix] = 0xff2020;
		}
	}
	return (0);
}


static void	loop(void)
{
	all.event.update();
	all.scene.apply_animation();
	all.scene.apply_camera(all.cam.pos, all.cam.dir);

	std::memset(all.disp.pixels, 0, all.disp.total_pixel * sizeof(unsigned));

	for (unsigned i = 0; i < all.nb_threads(); i++)
	{
		all.tc[i].start = i * all.disp.total_pixel / all.nb_threads();
		all.tc[i].end = (i + 1) * all.disp.total_pixel / all.nb_threads() - 1;
		pthread_create(&all.tc[i].thread, 0, threadFun, &all.tc[i]);
	}
	for (unsigned i = 0; i < all.nb_threads(); i++)
		pthread_join(all.tc[i].thread, 0);

	all.disp.update();
	all.time.update();
	std::cout << "  " << all.time.fps_average() << std::endl;
}

int			main(int ac, char **av)
{
	std::string	filename;
	std::fstream fs;

	if (ac > 1)
		filename = static_cast<std::string>(av[1]);
	else
		filename = "scenes/default.mica";

	fs.open(filename);
	if (!fs.is_open())
		Utils::error_quit("Couldn't open file");

	Parser::parse(fs, all.scene);
	fs.close();

	init();

	while (1)
		loop();
	return (0);
}
