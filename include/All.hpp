/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:59:50 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/08 18:46:37 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HPP
# define ALL_HPP

# include "Camera.hpp"
# include "Display.hpp"
# include "Event.hpp"
# include "ThreadContext.hpp"
# include "Scene.hpp"
# include "Time.hpp"
# include "Utils.hpp"

# define MAX_THREADS		64
# define MAX_EXPECTED_HITS	64


struct All
{
	public :
		Time			time;
		Display			disp;
		Camera			cam;
		Event			event;
		Scene			scene;
		ThreadContext	tc[MAX_THREADS];

		void		set_threads(unsigned nb_t);
		unsigned	nb_threads(void) const;

		All(void);
		virtual ~All(void);

	protected:
	private:
		unsigned _threads;

		All(const All &);
		void	operator=(const All &);
};

extern All	all;

#endif
