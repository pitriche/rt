/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plan.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/03/26 15:46:29 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAN_HPP
# define PLAN_HPP

# include <iostream>
# include "Object.hpp"

class Plan : public Object
{
	public :
		Plan(unsigned id);
		Plan(const Plan &src);
		virtual ~Plan(void);

		bool			hit(const Vec3d<float> &dir, std::vector<Hit> &hits);
		bool			hit(const Vec3d<float> &origin, const Vec3d<float> &dir,
			std::vector<Hit> &hits);
		Vec3d<float>	normal(const Vec3d<float> &hit_pos) const;

		Plan	&operator=(const Plan &rhs);

	protected:
	private:
		Plan(void);
};

std::ostream	&operator<<(std::ostream &lhs, const Plan &rhs);

#endif
