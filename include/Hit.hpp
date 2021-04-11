/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hit.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/11 16:54:47 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Hit;

#ifndef HIT_HPP
# define HIT_HPP

# include "Vec3d.hpp"
# include "Object.hpp"

# define SPHERE_EPSILON	1e-3f

class Hit
{
	public :
		Hit(void);
		Hit(bool enter_, Object *obj_, float dist_);
		Hit(const Hit &src);
		virtual ~Hit(void);

		// true if ray enters in object, false if ray exit object
		bool			enter;
		Object			*obj;
		float			dist;

		Vec3d<float>	pos(const Vec3d<float> &origin, const Vec3d<float> &dir)
		const;
		//Vec3d<float>	normal(Vec3d<float> &hit_pos);

		Hit	&operator=(const Hit &rhs);

	protected:
	private:
};

#endif
