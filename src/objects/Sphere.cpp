/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/03 19:17:12 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(void) : Object(0) { }
Sphere::Sphere(unsigned id) : Object(id), size(0) { }
Sphere::Sphere(const Sphere &src) : Object(src.id) { *this = src; }
Sphere::~Sphere(void) { }

bool	Sphere::hit(const Vec3d<float> &dir, Hit &hit) const
{
	float a;
	float b;
	float c;
	float det;
	float dist;
	float tmp_sqrt;

	a = dir * dir;
	b = 2 * (dir * (this->pos * -1.0f));
	c = (this->pos * this->pos) - (this->size * this->size);
	det = b * b - 4 * a * c;
	if (det <= 0)
		return (false);
	tmp_sqrt = static_cast<float>(std::sqrt(det));
	if (-b > tmp_sqrt)
		dist = (-b - tmp_sqrt) / (2 * a);
	else
		dist = (-b + tmp_sqrt) / (2 * a);
	if (dist > 0)
	{
		hit.dist = dist;
		return (true);
	}
	return (false);
}

bool	Sphere::hit(const Vec3d<float> &ray_origin, const Vec3d<float> &ray_dir, Hit
	&hit) const
{
	float a;
	float b;
	float c;
	float det;
	float dist;
	float tmp_sqrt;


	a = ray_dir * ray_dir;
	b = 2 * (ray_dir.x * (ray_origin.x - this->pos.x) +
		ray_dir.y * (ray_origin.y - this->pos.y) +
		ray_dir.z * (ray_origin.z - this->pos.z));
	c = (this->pos * this->pos) +
		ray_origin * ray_origin -
		2 * (this->pos * ray_origin) -
		(this->size * this->size);
	det = b * b - 4 * a * c;
	if (det <= 0)
		return (false);
	tmp_sqrt = static_cast<float>(std::sqrt(det));
	if (-b > tmp_sqrt + 8E-5)
		dist = (-b - tmp_sqrt) / (2 * a);
	else
		dist = (-b + tmp_sqrt) / (2 * a);
	if (dist > 8E-5)
	{
		hit.dist = dist;
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

Sphere	&Sphere::operator=(const Sphere &rhs)
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
