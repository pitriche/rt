/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpotLight.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/02 09:08:27 by pitriche         ###   ########.fr       */
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

		Vec3d<float>	pos;
		float			lflux; // luminous flux in lumen

		SpotLight	&operator=(const SpotLight &rhs);

	protected:
	private:
};

#endif
