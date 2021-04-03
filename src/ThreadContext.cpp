/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThreadContext.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:03:42 by pitriche          #+#    #+#             */
/*   Updated: 2021/03/21 14:46:47 by brunomartin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ThreadContext.hpp"
#include "All.hpp"

ThreadContext::ThreadContext(void) : start(0), end(0) { }
ThreadContext::ThreadContext(const ThreadContext &) { }
ThreadContext::~ThreadContext(void) { }

void	ThreadContext::operator=(const ThreadContext &) { }
