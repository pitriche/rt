/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParaLight.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 17:16:33 by pitriche         ###   ########.fr       */
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

		Vec3d<float>	inverted_dir;	// inverse of the light's direction
		float			illuminance;	// illuminance at 90 degree in lux

		ParaLight	&operator=(const ParaLight &rhs);

	protected:
	private:
};

#endif
