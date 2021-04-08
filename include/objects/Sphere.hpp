/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 18:48:18 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_HPP
# define SPHERE_HPP

# include <iostream>
# include "Object.hpp"

class Sphere : public Object
{
	public :
		Sphere(unsigned id);
		Sphere(const Sphere &src);
		virtual ~Sphere(void);

		float	size;

		bool	hit(const Vec3d<float> &dir, std::vector<Hit> &hits);
		bool	hit(const Vec3d<float> &origin, const Vec3d<float> &dir,
			std::vector<Hit> &hits);
		virtual	Vec3d<float>	normal(const Vec3d<float> &hit_pos) const;

		Sphere	&operator=(const Sphere &rhs);

	protected:
	private:
		Sphere(void);
};

std::ostream	&operator<<(std::ostream &lhs, const Sphere &rhs);

#endif
