/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpotLight.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/07 19:52:31 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPOTLIGHT_HPP
# define SPOTLIGHT_HPP

# include "Vec3d.hpp"

class SpotLight
{
	public :
		SpotLight(void);
		SpotLight(const SpotLight &src);
		virtual ~SpotLight(void);

		Vec3d<float>	absolute_pos; // initial position
		Vec3d<float>	pos;
		float			lflux; // luminous flux in lumen

		float	illuminance_at(const Vec3d<float> &hit_pos, const
			Vec3d<float> &normal) const;

		void	apply_camera(const Vec3d<float> &camera_pos, const
			Vec3d<float> &camera_dir);

		SpotLight	&operator=(const SpotLight &rhs);

	protected:
	private:
};

#endif
