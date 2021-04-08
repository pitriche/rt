/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 19:10:32 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object(void) : id(0) { }
Object::Object(unsigned id_) : id(id_), absolute_pos(0.0f, 0.0f, 0.0f),
	absolute_dir(0.0f, 0.0f, 0.0f), pos(0.0f, 0.0f, 0.0f),
	dir(0.0f, 0.0f, 0.0f), color(255, 255, 255),
	is_full(false), transparency(0.0f), reflectivity(0.0f) { }
Object::Object(const Object &src) : id(src.id) { *this = src; }
Object::~Object(void) { }

bool			Object::hit(const Vec3d<float> &, std::vector<Hit> &)
{ throw std::logic_error("Calling Object base hit method"); }

bool			Object::hit(const Vec3d<float> &, const Vec3d<float> &,
	std::vector<Hit> &)
{ throw std::logic_error("Calling Object base hit method"); }

Vec3d<float>	Object::normal(const Vec3d<float> &) const
{ throw std::logic_error("Calling Object base normal method"); }

Object	&Object::operator=(const Object &rhs)
{
	this->absolute_pos = rhs.absolute_pos;
	this->absolute_dir = rhs.absolute_dir;
	this->color = rhs.color;
	this->is_full = rhs.is_full;
	this->transparency = rhs.transparency;
	this->transparency = rhs.reflectivity;
	return (*this);
}

void	Object::apply_camera(const Vec3d<float> &camera_pos,
	const Vec3d<float> &camera_dir)
{
	this->pos = this->absolute_pos - camera_pos;
	this->pos.rotate_y(-camera_dir.y);
	this->pos.rotate_x(-camera_dir.x);
	this->pos.rotate_z(-camera_dir.z);
}

/*
** Id comparison
*/
bool	Object::operator==(const Object &rhs) { return (this->id == rhs.id); }

/*
** Id comparison
*/
bool	Object::operator!=(const Object &rhs) { return (this->id != rhs.id); }
