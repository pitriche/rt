/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/09 11:26:19 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene(void) : ambiant(0.0) { }
Scene::Scene(const Scene &src) { *this = src; }
Scene::~Scene(void) { }

/*
** Free space for hardcoding animations, because it isn't a bonus to place
** them in the file
*/
void	Scene::apply_animation(void)
{
	// default animations
	// static bool left = true;
	// if (left)
	// {
	// 	this->spot[0]->absolute_pos.x += 0.5f;
	// 	// all.scene.obj[3]->pos.x += 0.007f;
	// 	// all.scene.obj[4]->pos.x += 0.007f;
	// 	if (this->spot[0]->absolute_pos.x > 20)
	// 		left = false;
	// }
	// else
	// {
	// 	this->spot[0]->absolute_pos.x -= 0.5f;
	// 	// all.scene.obj[3]->pos.x -= 0.007f;
	// 	// all.scene.obj[4]->pos.x -= 0.007f;
	// 	if (this->spot[0]->absolute_pos.x < -20)
	// 		left = true;
	// }

	// test_light animations
	// this->spot[0]->absolute_pos.rotate_y(0.08f);
	// this->obj[1]->absolute_pos.rotate_x(0.14f);
	// this->obj[2]->absolute_pos.rotate_y(0.06f);
	// this->obj[2]->absolute_pos.rotate_x(-0.06f);
	// this->obj[3]->absolute_pos.rotate_y(0.05f);

	// test spheres
	// this->obj[1]->absolute_pos.z += 0.0001;
}

void	Scene::apply_camera(const Vec3d<float> &camera_pos,
	const Vec3d<float> &camera_dir)
{
	for (unsigned obj_id = 0; obj_id < this->obj.size(); ++obj_id)
		this->obj[obj_id]->apply_camera(camera_pos, camera_dir);
	
	for (unsigned obj_spot = 0; obj_spot < this->spot.size(); ++obj_spot)
		this->spot[obj_spot]->apply_camera(camera_pos, camera_dir);
	
	for (unsigned obj_para = 0; obj_para < this->para.size(); ++obj_para)
		this->para[obj_para]->apply_camera(camera_dir);
}

Scene	&Scene::operator=(const Scene &)
{ return (*this); }
