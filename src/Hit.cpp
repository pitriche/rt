/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hit.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 17:51:16 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hit.hpp"

Hit::Hit(void) : obj(0), dist(0.0f) { }
Hit::Hit(const Hit &src) { *this = src; }
Hit::~Hit(void) { }

Vec3d<float>	Hit::pos(const Vec3d<float> &origin, const Vec3d<float> &dir)
	const
{ return (origin + (dir * this->dist)); }

Hit	&Hit::operator=(const Hit &rhs)
{
	this->obj = rhs.obj;
	this->dist = rhs.dist;
	return (*this);
}
