/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:01:15 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/22 12:01:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

explicit	stack::stack( const C &a = C() ) : c(a) { // Inherit the constructor

}

bool	empty( void ) const {

	return c.empty();
}

size_type	stack::size( void ) const {

	return c.size();
}

value_type	&top( void ) const {

	return c.back();
}

const	value_type &top( void ) const {

	return c.back();
}

void	push( const value_type &n ) {

	c.push_back(n);
}

void	pop( void ) {
	
	c.pop_back();
}

/*
**	CANONICAL FORM
*/

stack::stack( void ) {
	
}

stack	&stack::operator=( const stack &rhs ) {
	
}

stack::stack( const stack &src ) {
	
}

stack::~stack( void ) {
	
}