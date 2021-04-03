/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/03/23 16:21:29 by pitriche         ###   ########.fr       */
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

		Vec3d<t_camera_real>	*pix;

	protected:
	private:
		bool	_is_init;

		Camera(const Camera &);
		Camera	&operator=(const Camera &);
};

#endif
