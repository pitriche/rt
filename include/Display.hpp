/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:57:00 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/01 10:48:25 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <iostream>
# include <SDL.h>

/*
** Interface to the graphic library
*/
struct Display
{
	public :
		Display(void);
		virtual ~Display(void);

		SDL_Window	*window;
		SDL_Surface	*surface;
		unsigned	*pixels;

		unsigned	res_x;
		unsigned	res_y;
		unsigned	total_pixel;

		void	init(std::string window_name, unsigned size_x, unsigned size_y);
		bool	is_init(void) const;
		void	update(void);

	protected:
	private:
		bool	_is_init;
		Display(const Display &);
		void	operator=(const Display &);
};

#endif
