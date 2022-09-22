/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:01:03 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/22 12:02:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "ft_containers.hpp"

namespace ft {

template< class T, Class Container = deque< T > >

class stack {

public:

	typedef typename C::value_type value_type;
	typedef typename C::size_type size_type;
	typedef C container_type;

	explicit	stack( const C &a = C() );
	bool		empty( void ) const;
	size_type	size( void ) const;
	value_type	&top( void ) const;
	const		value_type &top( void ) const;
	void		push( const value_type &n );
	void		pop( void );

//	CANONICAL FORM

	stack( void );
	stack	&operator=( const stack &rhs );
	// {
	// 	if (this == &rhs) 
	// 		return *this;
	// 	this->_host = rhs._host;
	// 	return *this;
	// }
	stack( const stack &src );
	// {
		// *this = src;
	// }
	virtual	~stack( void );


protected:

	C c;

};

};

#endif