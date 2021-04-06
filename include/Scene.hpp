/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/05 14:59:36 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_HPP
# define SCENE_HPP

# include <vector>
# include "Object.hpp"
# include "SpotLight.hpp"
# include "ParaLight.hpp"

class Scene
{
	public :
		Scene(void);
		Scene(const Scene &src);
		virtual ~Scene(void);

		std::vector<Object *>	obj;

		std::vector<SpotLight *>	spot; 		// Spot lights
		std::vector<ParaLight *>	para;		// Parallel lights
		float						ambiant;	// Ambiant light illuminance in lux

		Scene	&operator=(const Scene &rhs);

	protected:
	private:
};

#endif
