/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:03:42 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/03 16:45:09 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "All.hpp"

All::All(void) : _threads(1) { }
All::All(const All &) { }
All::~All(void) { }

void	All::set_threads(unsigned nb_t)
{
	if (nb_t > 64)
		throw std::out_of_range("Max threads: 64");
	if (nb_t == 0)
		throw std::out_of_range("Requires at least one thread");
	this->_threads = nb_t;
}

unsigned	All::nb_threads(void) const { return (this->_threads); }


void	All::operator=(const All &) { }
