/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:42:12 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/24 09:05:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "ft_containers.hpp"
#include "iterator.hpp"
#include "random_iterator.hpp"
#include "reverse_iterator.hpp"

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

	Iterator _current;

public:

	typedef Iterator iterator_type;
	typedef typename ft::iterator_traits< Iterator >::value_type			value_type;
	typedef typename ft::iterator_traits< Iterator >::difference_type		difference_type;
	typedef typename ft::iterator_traits< Iterator >::pointer				pointer;
	typedef typename ft::iterator_traits< Iterator >::reference				reference;
	typedef typename ft::iterator_traits< Iterator >::iterator_category		iterator_category;
	 
	reverse_iterator( void ) : _current(0) {}

	explicit reverse_iterator( Iterator x ) : _current(x) {}

	template< class U > reverse_iterator( const reverse_iterator< U > &u ); // Effects: Initializes _current with u._current.
	Iterator			base( void ) const {
		return this->_current;
	}
	// { _current(u.curent) } // explicit

	reverse_iterator( const reverse_iterator &x ) : _current(x.base()) {}

	virtual ~reverse_iterator( void ) {}

	reference			operator*( void ) const {
		Iterator tmp = this->_current;
		return *--tmp;
		// return *_current;
	}

	pointer				operator->( void ) const {
		return &(operator*());
	}
	
	reverse_iterator	&operator++( void ) {
		--this->_current;
		return *this;
	}

	reverse_iterator	operator++( int ) {
		reverse_iterator tmp(*this);
		// --(*this);
		--this->_current;
		return tmp;
	}

	reverse_iterator	&operator--( void ) {
		++this->_current;
		return *this;
	}

	reverse_iterator	operator--(int) {
		reverse_iterator tmp(*this);
		// ++(*this);
		++this->_current;
		return tmp;
	}

	reverse_iterator	&operator+=( difference_type n ) {
		this->_current -= n;
		return *this;
	}

	reverse_iterator	&operator-=( difference_type n ) {
		this->_current += n;
		return *this;
	}

	reverse_iterator	operator+( difference_type n ) const {
		return reverse_iterator(this->_current - n);
	}

	reverse_iterator	operator-( difference_type n ) const {
		return reverse_iterator(this->_current + n);
	}
	
	reference			operator[]( difference_type index ) const {
		return this->_current[- index - 1];
	}

};

template< class Iterator >
bool operator==( const reverse_iterator<  Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() == y.base();
}

template< class Iterator >
bool operator!=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() != y.base();
}

template< class Iterator >
bool operator<( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() > y.base();
}

template< class Iterator >
bool operator>( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() < y.base();
}

template< class Iterator >
bool operator>=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() <= y.base();
}

template< class Iterator >
bool operator<=( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return x.base() >= y.base();
}

template< class Iterator >
typename reverse_iterator< Iterator >::difference_type operator-( const reverse_iterator< Iterator > &x, const reverse_iterator< Iterator > &y ) {
	return y.base() - x.base();
}

template< class Iterator >
reverse_iterator< Iterator > operator+( typename reverse_iterator< Iterator >::difference_type n, const reverse_iterator< Iterator > &x ) {
	return x.base() - n;
}


STOP

#endif