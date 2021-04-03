/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParaLight.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:54 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/02 09:11:12 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ParaLight.hpp"

ParaLight::ParaLight(void) { }
ParaLight::ParaLight(const ParaLight &src) { *this = src; }
ParaLight::~ParaLight(void) { }

ParaLight	&ParaLight::operator=(const ParaLight &rhs)
{
	this->inverted_dir = rhs.inverted_dir;
	this->illuminance = rhs.illuminance;
	return (*this);
}
