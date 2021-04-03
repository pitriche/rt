/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hit.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 17:52:19 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Hit;

#ifndef HIT_HPP
# define HIT_HPP

# include "Vec3d.hpp"
# include "Object.hpp"

class Hit
{
	public :
		Hit(void);
		Hit(const Hit &src);
		virtual ~Hit(void);

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
