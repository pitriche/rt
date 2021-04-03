/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scene.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 18:13:34 by pitriche         ###   ########.fr       */
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
		double					ambiant;	// Ambiant light in lux

		Scene	&operator=(const Scene &rhs);

	protected:
	private:
};

#endif
