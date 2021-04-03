/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpotLight.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/02 09:11:38 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpotLight.hpp"

SpotLight::SpotLight(void) { }
SpotLight::SpotLight(const SpotLight &src) { *this = src; }
SpotLight::~SpotLight(void) { }

SpotLight	&SpotLight::operator=(const SpotLight &rhs)
{
	this->pos = rhs.pos;
	this->lflux = rhs.lflux;
	return (*this);
}
