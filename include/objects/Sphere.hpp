/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/03 17:57:31 by pierre42         ###   ########.fr       */
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

		bool	hit(const Vec3d<float> &dir, Hit &hit) const;
		bool	hit(const Vec3d<float> &origin, const Vec3d<float> &dir, Hit
			&hit) const;
		virtual	Vec3d<float>	normal(const Vec3d<float> &hit_pos) const;

		Sphere	&operator=(const Sphere &rhs);

	protected:
	private:
		Sphere(void);
};

std::ostream	&operator<<(std::ostream &lhs, const Sphere &rhs);

#endif
