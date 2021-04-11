/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParaLight.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/11 21:00:33 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParaLight.hpp"
#include "All.hpp"

/*
** check if the given hits block the light
*/
static bool	_do_block(std::vector<Hit> &hits)
{
	for (unsigned hit_id = 0; hit_id < hits.size(); ++hit_id)
		if (hits[hit_id].enter)
			return (true);
	return (false);
}

ParaLight::ParaLight(void) { }
ParaLight::ParaLight(const ParaLight &src) { *this = src; }
ParaLight::~ParaLight(void) { }

float	ParaLight::illuminance_at(const Vec3d<float> &hit_pos, const
	Vec3d<float> &normal) const
{
	float				illuminance;
	float				dot_product;
	Vec3d<float>		vec_light;
	std::vector<Hit>	hits;

	vec_light = this->inverted_dir_vec;
	dot_product = vec_light * normal;
	illuminance = this->illuminance * dot_product;
	hits.reserve(8);
	for (unsigned obj_id = 0; obj_id < all.scene.obj.size(); ++obj_id)
	{
		hits.clear();
		if (all.scene.obj[obj_id]->hit(hit_pos, vec_light, hits))
		{
			if (_do_block(hits))
			{
				illuminance = 0;
				break ;
			}
		}
	}
	return (illuminance);
}

void	ParaLight::apply_camera(const Vec3d<float> &camera_dir)
{
	this->inverted_dir_vec = Vec3d<float>(0.0f, 0.0f, -1.0f);

	this->inverted_dir_vec.rotate_x(this->absolute_dir.x);
	this->inverted_dir_vec.rotate_y(this->absolute_dir.y);
	this->inverted_dir_vec.rotate_y(-camera_dir.y);
	this->inverted_dir_vec.rotate_x(-camera_dir.x);
	this->inverted_dir_vec.rotate_z(-camera_dir.z);
}

ParaLight	&ParaLight::operator=(const ParaLight &rhs)
{
	this->absolute_dir = rhs.absolute_dir;
	this->inverted_dir_vec = rhs.inverted_dir_vec;
	this->illuminance = rhs.illuminance;
	return (*this);
}
