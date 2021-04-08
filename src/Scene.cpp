/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 22:53:49 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene(void) : ambiant(0.0) { }
Scene::Scene(const Scene &src) { *this = src; }
Scene::~Scene(void) { }

void	Scene::apply_animation(void)
{
	// to Scene::animation()
	// static bool left = true;
	// if (left)
	// {
	// 	all.scene.spot[0]->pos.x += 0.5f;
	// 	// all.scene.obj[3]->pos.x += 0.007f;
	// 	// all.scene.obj[4]->pos.x += 0.007f;
	// 	if (all.scene.spot[0]->pos.x > 20)
	// 		left = false;
	// }
	// else
	// {
	// 	all.scene.spot[0]->pos.x -= 0.5f;
	// 	// all.scene.obj[3]->pos.x -= 0.007f;
	// 	// all.scene.obj[4]->pos.x -= 0.007f;
	// 	if (all.scene.spot[0]->pos.x < -20)
	// 		left = true;
	// }
	// // all.scene.obj[5]->pos.z += 0.3f;
	this->spot[0]->absolute_pos.rotate_y(0.08);
	this->obj[1]->absolute_pos.rotate_x(0.14);
	this->obj[2]->absolute_pos.rotate_y(-0.06);
	this->obj[2]->absolute_pos.rotate_x(-0.06);
	this->obj[3]->absolute_pos.rotate_y(0.05);
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
