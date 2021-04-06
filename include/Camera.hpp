/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/05 14:25:00 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "Vec3d.hpp"
# include <cmath>

typedef	float	t_camera_real;

// REMEMBER TO FLOAT !!! 0.1f 2.0f 1.4f

struct Camera
{
	public :
		Camera(void);
		virtual ~Camera(void);

		/*
		** generates the camera from the given screen resolution and fov (deg)
		*/
		void	init(unsigned res_x, unsigned res_y, unsigned fov);

		bool	is_init(void) const;

		Vec3d<float>			pos;

		/*
		** pitch yaw roll from Z axis with Y axis as up, in radian, clockwise
		** around each axis
		*/
		Vec3d<float>			dir;

		Vec3d<t_camera_real>	*pix;

	protected:
	private:
		bool	_is_init;

		Camera(const Camera &);
		Camera	&operator=(const Camera &);
};

#endif
