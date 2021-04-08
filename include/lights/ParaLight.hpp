/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParaLight.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 16:50:29 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARALIGHT_HPP
# define PARALIGHT_HPP

# include "Vec3d.hpp"

class ParaLight
{
	public :
		ParaLight(void);
		ParaLight(const ParaLight &src);
		virtual ~ParaLight(void);

		// yaw pitch roll, inverse of the light's direction
		Vec3d<float>	absolute_dir;

		// XYZ vector, inverse of the light's direction
		Vec3d<float>	inverted_dir_vec;
		float			illuminance;	// illuminance at 90 degree in lux

		float	illuminance_at(const Vec3d<float> &hit_pos, const // implement this
			Vec3d<float> &normal) const;

		void	apply_camera(const Vec3d<float> &camera_pos); // and that

		ParaLight	&operator=(const ParaLight &rhs);

	protected:
	private:
};

#endif
