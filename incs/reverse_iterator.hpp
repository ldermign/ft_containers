/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:42:12 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/14 15:01:02 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "ft_containers.hpp"
#include "iterator.hpp"
#include "random_iterator.hpp"

START

template< class Iterator >
class reverse_iterator :
	public ft::iterator<
	typename ft::iterator_traits< Iterator >::iterator_category,
	typename ft::iterator_traits< Iterator >::value_type,
	typename ft::iterator_traits< Iterator >::difference_type,
	typename ft::iterator_traits< Iterator >::pointer,
	typename ft::iterator_traits< Iterator >::reference > {
		
protected:

	Iterator current;

public:
	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits< Iterator >::difference_type difference_type;
	typedef typename ft::iterator_traits< Iterator >::reference reference;
	typedef typename ft::iterator_traits< Iterator >::pointer pointer;
	 
	reverse_iterator( void ) : current(0) {}

	explicit reverse_iterator( Iterator x ) : current(x) {}

	template< class U > reverse_iterator( const reverse_iterator< U > &u ); // Effects: Initializes current with u.current.
	Iterator			base( void ) const {
		return this->current;
	}
	// { current(u.curent) } // explicit

	reference			operator*( void ) const {
		return *current;
	}

	pointer				operator->( void ) const {
		return current;
	}
	
	reverse_iterator	&operator++( void ) {
		++current;
		return *this;
	}

	reverse_iterator	operator++( int ) {
		reverse_iterator tmp(*this);
		++(*this);
		return tmp;
	}

	reverse_iterator	&operator--( void ) {
		--current;
		return *this;
	}

	reverse_iterator	operator--(int) {
		reverse_iterator tmp(*this);
		--(*this);
		return tmp;
	}

	reverse_iterator	&operator+=( difference_type n ) {
		current += n;
		return *this;
	}

	reverse_iterator	&operator-=( difference_type n ) {
		current -= n;
		return *this;
	}

	reverse_iterator	operator+ ( difference_type n ) const {
		return reverse_iterator(current - n);
	}

	reverse_iterator	operator- ( difference_type n ) const {
		return reverse_iterator(current + n);
	}
	
	reference			operator[]( difference_type index ) const {
		return this->current[index];
	}

};

template< class Iterator >
bool operator==( const reverse_iterator<  Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x == y;
}

template< class Iterator >
bool operator<( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x < y;
}

template< class Iterator >
bool operator!=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x != y;
}

template< class Iterator >
bool operator>( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x > y;
}

template< class Iterator >
bool operator>=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x >= y;
}

template< class Iterator >
bool operator<=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x <= y;
}

template< class Iterator >
typename reverse_iterator< Iterator >::difference_type operator-( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y );

template< class Iterator >
reverse_iterator< Iterator > operator+( typename reverse_iterator< Iterator >::difference_type n, const reverse_iterator< Iterator > &x );


STOP

#endif