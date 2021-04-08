/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plan.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/03/27 16:55:31 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plan.hpp"
#include <cmath>

Plan::Plan(void) : Object(0) { }
Plan::Plan(unsigned id) : Object(id), absolute_dir(0.0f, 0.0f, 0.0f) { }
Plan::Plan(const Plan &src) : Object(src.id) { *this = src; }
Plan::~Plan(void) { }

bool	Plan::hit(const Vec3d<float> &ray_dir, std::vector<Hit> &hits)
{
	float dist;
	float det;

	det = ray_dir * this->dir;
	if (det == 0.0f)
		return (false);
	dist = this->pos * this->dir;
	dist /= det;
	if (dist < 0.0f)
		return (false);
	
	hits.push_back(Hit());
	hits.back().dist = dist;
	hits.back().obj = this;
	throw std::logic_error("implement enter/exit for plans");
	return (true);
}

bool	Plan::hit(const Vec3d<float> &ray_origin, const Vec3d<float> &ray_dir,
	std::vector<Hit> &hits)
{
	float dist;
	float det;

	det = ray_dir * this->dir;
	if (det == 0.0f)
		return (false);
	dist = (this->pos - ray_origin) * this->dir;
	dist /= det;
	if (dist < 0.0f)
		return (false);

	hits.push_back(Hit());
	hits.back().dist = dist;
	hits.back().obj = this;
	throw std::logic_error("implement enter/exit for plans");
	return (true);
}

Vec3d<float>	Plan::normal(const Vec3d<float> &) const
{ return(this->dir); }

Plan	&Plan::operator=(const Plan &rhs)
{
	this->Object::operator=(rhs);
	this->dir = rhs.dir;
	return (*this);
}

std::ostream	&operator<<(std::ostream &lhs, const Plan &rhs)
{
	return (lhs << "Plan - origin:" << rhs.pos << ", color:" << rhs.color);
}
