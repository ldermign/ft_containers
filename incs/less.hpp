/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:43:35 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/15 11:59:10 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

#include "ft_containers.hpp"
/*
https://stackoverflow.com/questions/13867996/why-is-stdless-a-class-template
*/

START

template< class Arg1, class Arg2, class Result >
struct binary_function {

	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
};

template< class T > 
struct less : binary_function< T, T, bool > {

	bool operator()( const T &lhs, const T &rhs ) const {
		return lhs < rhs; // assumes that the implementation uses a flat address space
	}
};

STOP

#endif