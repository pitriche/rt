/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 22:02:32 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(void) : Object(0) { }
Sphere::Sphere(unsigned id) : Object(id), size(0) { }
Sphere::Sphere(const Sphere &src) : Object(src.id) { *this = src; }
Sphere::~Sphere(void) { }

static bool	_add_hits(float a, float b, float det, std::vector<Hit> &hits)
{
	(void)a;
	(void)b;
	(void)det;
	(void)hits;
	return true; // transfert code here
}

bool		Sphere::hit(const Vec3d<float> &ray_dir, std::vector<Hit> &hits)
{
	_add_hits(0, 0, 0, hits); // tej ça
	float a;
	float b;
	float c;
	float det;
	float dist_min;
	float dist_max;
	float tmp_sqrt;

	a = ray_dir * ray_dir;
	b = 2 * (ray_dir * (this->pos * -1.0f));
	c = (this->pos * this->pos) - (this->size * this->size);
	det = b * b - 4 * a * c;
	if (det <= 0)
		return (false);


	tmp_sqrt = std::sqrtf(det);
	dist_min = (-b - tmp_sqrt) / (2 * a);
	dist_max = (-b + tmp_sqrt) / (2 * a);
	if (dist_min > 0.0f)
	{
		hits.push_back(Hit());
		hits.back().dist = dist_min;
		hits.back().obj = this;
		hits.back().enter = true;
	}
	if (dist_max > 0.0f)
	{
		hits.push_back(Hit());
		hits.back().dist = dist_max;
		hits.back().obj = this;
		hits.back().enter = false;
		return (true);
	}
	return (false);
}

bool		Sphere::hit(const Vec3d<float> &ray_origin, const Vec3d<float> &ray_dir,
	std::vector<Hit> &hits)
{
	float a;
	float b;
	float c;
	float det;
	float dist_min;
	float dist_max;
	float tmp_sqrt;

	a = ray_dir * ray_dir;
	// optimize if origin is null
	if (ray_origin == Vec3d<float>(0,0,0))
	{
		b = 2 * (ray_dir * (this->pos * -1.0f));
		c = (this->pos * this->pos) - (this->size * this->size);
	}
	else
	{
		b = 2 * (ray_dir * (ray_origin - this->pos));
		c = (this->pos * this->pos) + (ray_origin * ray_origin) -
		2 * (this->pos * ray_origin) - (this->size * this->size);
	}
	det = b * b - 4 * a * c;
	if (det <= 0)
		return (false);

	tmp_sqrt = std::sqrtf(det);
	dist_min = (-b - tmp_sqrt) / (2 * a);
	dist_max = (-b + tmp_sqrt) / (2 * a);
	if (dist_min > 0.0f)
	{
		hits.push_back(Hit());
		hits.back().dist = dist_min;
		hits.back().obj = this;
		hits.back().enter = true;
	}
	if (dist_max > 0.0f)
	{
		hits.push_back(Hit());
		hits.back().dist = dist_max;
		hits.back().obj = this;
		hits.back().enter = false;
		return (true);
	}
	return (false);
}

Vec3d<float>	Sphere::normal(const Vec3d<float> &hit_pos) const
{
	Vec3d<float>	vec_normal;
	
	vec_normal = hit_pos - this->pos;
	vec_normal.normalize();
	return(vec_normal);
}

Sphere			&Sphere::operator=(const Sphere &rhs)
{
	this->Object::operator=(rhs);
	this->size = rhs.size;
	return (*this);
}

std::ostream	&operator<<(std::ostream &lhs, const Sphere &rhs)
{
	return (lhs << "Sphere - pos:" << rhs.pos << ", size:" << rhs.size <<
		", color:" << rhs.color);
}
