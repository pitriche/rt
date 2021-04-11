/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hit.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/11 16:49:06 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hit.hpp"

Hit::Hit(void) : enter(false), obj(0), dist(0.0f) { }
Hit::Hit(bool enter_, Object *obj_, float dist_) : enter(enter_), obj(obj_),
dist(dist_) { }
Hit::Hit(const Hit &src) { *this = src; }
Hit::~Hit(void) { }

Vec3d<float>	Hit::pos(const Vec3d<float> &origin, const Vec3d<float> &dir)
	const
{ return (origin + (dir * this->dist)); }

Hit	&Hit::operator=(const Hit &rhs)
{
	this->enter = rhs.enter;
	this->obj = rhs.obj;
	this->dist = rhs.dist;
	return (*this);
}
