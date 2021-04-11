/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThreadContext.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:57:00 by pitriche          #+#    #+#             */
/*   Updated: 2021/04/11 12:20:48 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADCONTEXT_HPP
# define THREADCONTEXT_HPP

# include <iostream>
# include <pthread.h>

/*
** Context for threads
*/
struct ThreadContext
{
	public :
		ThreadContext(void);
		virtual ~ThreadContext(void);

		pthread_t	thread;
		unsigned	start;
		unsigned	end;

	protected:
	private:
		ThreadContext(const ThreadContext &src);
		void	operator=(const ThreadContext &rhs);
};

#endif
