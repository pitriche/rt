/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/05 12:26:29 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"
#include "Utils.hpp"

Camera::Camera(void) : pix(0), _is_init(false) { }
Camera::Camera(const Camera &) { }
Camera::~Camera(void)
{
	if (pix)
		delete [] pix;
}

/*
** this code is optimized for readability, and so is written for -O3 flag
*/
void	Camera::init(unsigned res_x, unsigned res_y, unsigned fov)
{
	Vec3d<t_camera_real>	*tmp;
	t_camera_real			pix_l;

	if (fov >= 180 || fov == 0)
		throw std::out_of_range("Invalid fov");
	if (this->_is_init)
		Utils::error_quit("Cannot initialize Camera twice");
		// delete [] this->pix;
	this->pix = new Vec3d<t_camera_real>[res_x * res_y];
	tmp = this->pix;
	pix_l = tanf(fov * static_cast<float>(M_PI) / 360.0f) / (float)res_x;
	for (int j = 0; j < static_cast<int>(res_y); j++)
	{
		for (int i = 0; i < static_cast<int>(res_x); i++)
		{
			tmp->x = (i - (static_cast<int>(res_x) / 2)) * pix_l;
			tmp->y = ((static_cast<int>(res_y) / 2) - j) * pix_l;
			tmp->z = 1.0f;
			tmp->normalize();
			++tmp;
		}
	}
	this->_is_init = true;
}

Camera	&Camera::operator=(const Camera &) { return (*this); }
