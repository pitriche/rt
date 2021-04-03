/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 11:28:44 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP

# include <iostream>

class Color
{
	public :
		Color(void);
		Color(unsigned rgb);
		Color(unsigned char r, unsigned char g, unsigned char b);
		Color(const Color &src);
		virtual ~Color(void);

		unsigned	rgb;

		unsigned	r(void) const;
		unsigned	g(void) const;
		unsigned	b(void) const;
		void		r(unsigned char r);
		void		g(unsigned char g);
		void		b(unsigned char b);

		unsigned	rgb_dim(float coef);

		Color	&operator=(const Color &rhs);

	protected:
	private:
};

std::ostream	&operator<<(std::ostream &lhs, const Color &rhs);

#endif
