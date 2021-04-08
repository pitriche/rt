/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:03:42 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 18:30:24 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Event.hpp"
#include "All.hpp"

Event::Event(void) { }
Event::Event(const Event &) { }
Event::~Event(void) { }

void	Event::_keychange(SDL_Keycode kc)
{
	switch (kc)
	{
		// camera position control 
		case (SDLK_w):
			all.cam.pos.z += 0.5f;
			break;
		case (SDLK_a):
			all.cam.pos.x -= 0.5f;
			break;
		case (SDLK_s):
			all.cam.pos.z -= 0.5f;
			break;
		case (SDLK_d):
			all.cam.pos.x += 0.5f;
			break;
		case (SDLK_SPACE):
			all.cam.pos.y += 0.5f;
			break;
		case (SDLK_z):
			all.cam.pos.y -= 0.5f;
			break;

		// camera rotation control
		case (SDLK_UP):
			all.cam.dir.x -= static_cast<float>(M_PI_4 / 5.0);
			break;
		case (SDLK_DOWN):
			all.cam.dir.x += static_cast<float>(M_PI_4 / 5.0);
			break;
		case (SDLK_LEFT):
			all.cam.dir.y -= static_cast<float>(M_PI_4 / 5.0);
			break;
		case (SDLK_RIGHT):
			all.cam.dir.y += static_cast<float>(M_PI_4 / 5.0);
			break;
		case (SDLK_COMMA):
			all.cam.dir.z -= static_cast<float>(M_PI_4 / 5.0);
			break;
		case (SDLK_PERIOD):
			all.cam.dir.z += static_cast<float>(M_PI_4 / 5.0);
			break;




		case (SDLK_ESCAPE):
			exit(0);
			break;
		default:
			std::cout << "other pressed" << std::endl;
			break;
	}
}

void	Event::update(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			exit(0);
		// if (event.type == SDL_KEYDOWN && !event.key.repeat)
		if (event.type == SDL_KEYDOWN)
			this->_keychange(event.key.keysym.sym);
	}
}

void	Event::operator=(const Event &) { }
