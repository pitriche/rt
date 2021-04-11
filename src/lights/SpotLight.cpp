/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpotLight.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/11 21:12:03 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpotLight.hpp"
#include "All.hpp"

SpotLight::SpotLight(void) { }
SpotLight::SpotLight(const SpotLight &src) { *this = src; }
SpotLight::~SpotLight(void) { }

extern unsigned debug_x, debug_y; // VIRER ÇA ############################################################################################################################################################################################################################################################################################## 

/*
** check if the given hits block the light
*/
static bool	_do_block(std::vector<Hit> &hits, float light_dist)
{
	for (unsigned hit_id = 0; hit_id < hits.size(); ++hit_id)
		if (hits[hit_id].enter && hits[hit_id].dist < light_dist)
			return (true);
	return (false);
}

float		SpotLight::illuminance_at(const Vec3d<float> &hit_pos, const
	Vec3d<float> &normal) const
{
	float				illuminance;
	float				dot_product;
	Vec3d<float>		vec_light;
	float				light_dist;
	std::vector<Hit>	hits;

	vec_light = this->pos - hit_pos;
	light_dist = vec_light.length();
	vec_light.normalize();
	dot_product = vec_light * normal;
	if (dot_product < 0.0f)
		return (0);
	illuminance = (this->lflux * dot_product) / (light_dist * 12.56637f);
	hits.reserve(8);
	for (unsigned obj_id = 0; obj_id < all.scene.obj.size(); ++obj_id)
	{
		hits.clear();
		if (all.scene.obj[obj_id]->hit(hit_pos, vec_light, hits))
		{
			if (_do_block(hits, light_dist))
			{
				illuminance = 0;
				break ;
			}
		}
	}
	return (illuminance);
}

void		SpotLight::apply_camera(const Vec3d<float> &camera_pos, const
	Vec3d<float> &camera_dir)
{
	this->pos = this->absolute_pos - camera_pos;
	this->pos.rotate_y(-camera_dir.y);
	this->pos.rotate_x(-camera_dir.x);
	this->pos.rotate_z(-camera_dir.z);
}



SpotLight	&SpotLight::operator=(const SpotLight &rhs)
{
	this->pos = rhs.pos;
	this->lflux = rhs.lflux;
	return (*this);
}
