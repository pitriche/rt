/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/02 14:44:16 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void) : id(0) { }
Object::Object(unsigned id_) : id(id_), pos(0.0f, 0.0f, 0.0f), color(255, 255, 255),
	is_full(false), transparency(0.0f), reflectivity(0.0f) { }
Object::Object(const Object &src) : id(src.id) { *this = src; }
Object::~Object(void) { }

bool			Object::hit(const Vec3d<float> &, Hit &) const
{ throw std::logic_error("Not implemented"); }

bool			Object::hit(const Vec3d<float> &, const Vec3d<float> &, Hit &)
const { throw std::logic_error("Not implemented"); }

Vec3d<float>	Object::normal(const Vec3d<float> &) const
{ throw std::logic_error("Not implemented"); }

Object	&Object::operator=(const Object &rhs)
{
	this->pos = rhs.pos;
	this->color = rhs.color;
	this->is_full = rhs.is_full;
	this->transparency = rhs.transparency;
	this->transparency = rhs.reflectivity;

	return (*this);
}

/*
** Id comparison
*/
bool	Object::operator==(const Object &rhs) { return (this->id == rhs.id); }

/*
** Id comparison
*/
bool	Object::operator!=(const Object &rhs) { return (this->id != rhs.id); }
