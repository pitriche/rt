/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/09 15:53:14 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Object;

#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <vector>

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

		Vec3d<float>	absolute_pos; // initial position
		Vec3d<float>	absolute_dir; // initial direction, pitch yaw roll in radiant

		// xyz position, after camera translation
		Vec3d<float>	pos;
		// xyz vector, after camera rotation
		Vec3d<float>	dir_vec;
		
		Color			color;

		bool			is_full; // object has volume or not
		float			transparency; // 0 to 1 real
		float			reflectivity; // 0 to 1 real

		// ray intersection function with 0,0,0 origin
		virtual bool			hit(const Vec3d<float> &dir, std::vector<Hit>
			&hits);
		virtual bool			hit(const Vec3d<float> &origin,
			const Vec3d<float> &dir, std::vector<Hit> &hits);
		virtual	Vec3d<float>	normal(const Vec3d<float> &hit_pos) const;

		void					apply_camera(const Vec3d<float> &camera_pos,
			const Vec3d<float> &camera_dir);

		virtual Object	&operator=(const Object &rhs);
		bool			operator==(const Object &rhs);
		bool			operator!=(const Object &rhs);

	protected:
	private:
		Object(void);
};

#endif
