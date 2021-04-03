/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 17:46:41 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void) : rgb(0) { }
Color::Color(unsigned rgb_) : rgb(rgb_) { }
Color::Color(unsigned char r_, unsigned char g_, unsigned char b_) : rgb(0)
{
	this->r(r_);
	this->g(g_);
	this->b(b_);
}

Color::Color(const Color &src) { *this = src; }
Color::~Color(void) { }

unsigned	Color::r(void) const { return ((this->rgb >> 16) & 0xff); }
unsigned	Color::g(void) const { return ((this->rgb >> 8) & 0xff); }
unsigned	Color::b(void) const { return (this->rgb & 0xff); }

void		Color::r(unsigned char r)
{ this->rgb = (this->rgb & 0xff00ffff) + (static_cast<unsigned>(r) << 16); }
void		Color::g(unsigned char g)
{ this->rgb = (this->rgb & 0xffff00ff) + (static_cast<unsigned>(g) << 8); }
void		Color::b(unsigned char b)
{ this->rgb = (this->rgb & 0xffffff00) + static_cast<unsigned>(b); }

/*
** multiply rgb values by coef, all white if negative coef is given
*/
unsigned	Color::rgb_dim(float coef)
{
	unsigned	r;
	unsigned	g;
	unsigned	b;

	r = static_cast<unsigned>(this->r() * coef);
	g = static_cast<unsigned>(this->g() * coef);
	b = static_cast<unsigned>(this->b() * coef);
	if (r & 0xffffff00)
		r = 0xff;
	if (g & 0xffffff00)
		g = 0xff;
	if (b & 0xffffff00)
		b = 0xff;
	return ((r << 16) | (g << 8) | b);
}


Color	&Color::operator=(const Color &rhs)
{
	this->rgb = rhs.rgb;
	return (*this);
}

std::ostream	&operator<<(std::ostream &lhs, const Color &rhs)
{
	return (lhs << "[RGB " << rhs.r() << "," << rhs.g() << "," << rhs.b() <<
		"]");
}
