/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:03:42 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 10:49:19 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include "All.hpp"

Display::Display(void) : window(0), surface(0), pixels(0), _is_init(false) { }
Display::Display(const Display &) { }
Display::~Display(void) { }

void	Display::init(std::string window_name, unsigned size_x, unsigned size_y)
{
	if (this->_is_init)
		Utils::error_quit("Can't init display twice");
	this->res_x = size_x;
	this->res_y = size_y;
	this->total_pixel = this->res_x * this->res_y;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);
	if (!(this->window = SDL_CreateWindow(window_name.c_str(), 100, 100,
				static_cast<int>(this->res_x), static_cast<int>(this->res_y),
				0)))
		exit(0);
	if (!(this->surface = SDL_GetWindowSurface(this->window)))
		exit(0);
	this->pixels = static_cast<unsigned *>(this->surface->pixels);
	this->_is_init = true;
}

bool	Display::is_init(void) const { return (this->_is_init); }

void	Display::update(void)
{
	if (SDL_UpdateWindowSurface(this->window))
		exit(0);
}

void	Display::operator=(const Display &) { }
