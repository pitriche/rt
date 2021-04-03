/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:29:13 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/03 18:56:25 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "All.hpp"

#include <pthread.h>

#include "Parser.hpp"
#include "Sphere.hpp"

All	all;

void	init(void)
{
	if (!all.disp.is_init())
		Utils::error_quit("Need a Window: in .mica file");
	all.cam.init(1280, 720, 90);
	all.time.set_average_sample(5);
	//all.time.set_fps(60);
	all.set_threads(4);
}

void	*threadFun(void *arg)
{
	ThreadContext	&tc = *reinterpret_cast<ThreadContext *>(arg);
	Hit				hits[MAX_HITS];
	Hit				*closest_hit;
	unsigned		nhit;
	unsigned		color;

	Vec3d<float>	null(0.0f, 0.0f, 0.0f);

	for (unsigned pix = tc.start; pix < tc.end; pix++)
	{
		nhit = 0;
		for (unsigned obj_id = 0; obj_id < all.scene.obj.size(); ++obj_id)
		{
			if (all.scene.obj[obj_id]->hit(all.cam.pix[pix], hits[nhit]))
			{
				hits[nhit].obj = all.scene.obj[obj_id];
				if (nhit == 0)
					closest_hit = hits;
				else
					if (hits[nhit].dist < closest_hit->dist)
						closest_hit = &hits[nhit];
				++nhit;
			}
		}
		if (nhit)
		{
			Vec3d<float>	hit_pos(0.0f, 0.0f, 0.0f);
			Vec3d<float>	vec_light;
			Vec3d<float>	vec_normal;
			Hit				tmp_hit;
			bool			masked;
			float			dp;

			hit_pos = closest_hit->pos(hit_pos, all.cam.pix[pix]); 
			vec_light = all.scene.spot[0]->pos - hit_pos;
			vec_light.normalize();
			vec_normal = closest_hit->obj->normal(hit_pos);
			masked = false;
			for (unsigned obj_id = 0; obj_id < all.scene.obj.size(); ++obj_id)
			{
				if (all.scene.obj[obj_id]->hit(hit_pos, vec_light, tmp_hit))
					masked = true;
			}
			dp = vec_light * vec_normal;
			if (dp < 0)
				dp *= -1.0f;
			if (masked)
				dp = 0.0f;
			color = closest_hit->obj->color.rgb_dim(dp);
			all.disp.pixels[pix] = color;
		}
	}
	return (0);
}


static void	loop(void)
{
	static bool left = true;
	if (left)
	{
		all.scene.spot[0]->pos.x += 0.5;
		// all.scene.obj[3]->pos.x += 0.007;
		// all.scene.obj[4]->pos.x += 0.007;
		if (all.scene.spot[0]->pos.x > 20)
			left = false;
	}
	else
	{
		all.scene.spot[0]->pos.x -= 0.5;
		// all.scene.obj[3]->pos.x -= 0.007;
		// all.scene.obj[4]->pos.x -= 0.007;
		if (all.scene.spot[0]->pos.x < -20)
			left = true;
	}
	


	all.event.update();
	for (unsigned i = 0; i < all.disp.total_pixel; i++)
		all.disp.pixels[i] = 0;
	
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
