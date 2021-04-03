/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre42 <pierre42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/03 17:57:20 by pierre42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Object;

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "Hit.hpp"
# include "Vec3d.hpp"
# include "Color.hpp"

class Object
{
	public :
		Object(unsigned id);
		Object(const Object &src);
		virtual ~Object(void);

		const unsigned	id; // object id, allows for quick comparison

		Vec3d<float>	pos; // xyz position
		Color			color;

		bool			is_full; // object has volume or not
		float			transparency; // 0 to 1 real
		float			reflectivity; // 0 to 1 real

		// ray intersection function with 0,0,0 origin
		virtual bool			hit(const Vec3d<float> &dir, Hit &hit) const;
		virtual bool			hit(const Vec3d<float> &origin,
			const Vec3d<float> &dir, Hit &hit) const;
		virtual	Vec3d<float>	normal(const Vec3d<float> &hit_pos) const;

		virtual Object	&operator=(const Object &rhs);
		bool			operator==(const Object &rhs);
		bool			operator!=(const Object &rhs);

	protected:
	private:
		Object(void);
};

#endif
