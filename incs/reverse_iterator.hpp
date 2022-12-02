/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:42:12 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 14:49:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "ft_containers.hpp"
#include "iterator.hpp"
#include "distance.hpp"
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
	 
	reverse_iterator( void ) 
		: _current() {}

	explicit reverse_iterator( Iterator x )
		: _current(x) {}

	template< class U >
	reverse_iterator( const reverse_iterator< U > &u )
		: _current(u.base()) {}// Effects: Initializes _current with u._current.

	reverse_iterator( const reverse_iterator &x )
		: _current(x.base()) {}

	operator	reverse_iterator< const iterator_type >() const {
		return (reverse_iterator< const iterator_type >(this->m_iterator));
	};

	~reverse_iterator( void ) {}


	template < class U >
	reverse_iterator
	&operator=( const reverse_iterator< U > &x ) {

		this->_current = x.base();
		return (*this);
	}

	Iterator
	base( void ) const {

		return (this->_current);
	}

	reference
	operator*( void ) const {

		Iterator tmp = this->_current;
		return (*--tmp);
	}

	pointer
	operator->( void ) const {

		return (&(operator*()));
	}
	
	reverse_iterator
	&operator++( void ) {

		--this->_current;
		return (*this);
	}

	reverse_iterator
	operator++( int ) {

		reverse_iterator tmp(*this);
		--this->_current;
		return (tmp);
	}

	reverse_iterator
	&operator--( void ) {

		++this->_current;
		return (*this);
	}

	reverse_iterator
	operator--(int) {

		reverse_iterator tmp(*this);
		++this->_current;
		return (tmp);
	}

	reverse_iterator
	&operator+=( difference_type n ) {

		this->_current -= n;
		return (*this);
	}

	reverse_iterator
	&operator-=( difference_type n ) {
		this->_current += n;
		return (*this);
	}

	reverse_iterator
	operator+( difference_type n ) const {

		return (reverse_iterator(this->_current - n));
	}

	reverse_iterator
	operator-( difference_type n ) const {

		return (reverse_iterator(this->_current + n));
	}
	
	reference
	operator[]( difference_type index ) const {

		return (this->_current[- index - 1]);
	}

};

template< class Iterator1, class Iterator2 >
bool
operator==( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator!=( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>=( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() <= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<=( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (lhs.base() >= rhs.base());
}

template< class Iterator1, class Iterator2 >
typename reverse_iterator< Iterator1 >::difference_type
operator-( const reverse_iterator< Iterator1 > &lhs, const reverse_iterator< Iterator2 > &rhs ) {

	return (rhs.base() - lhs.base());
}

template< class Iterator >
reverse_iterator< Iterator >
operator+( typename reverse_iterator< Iterator >::difference_type n, const reverse_iterator< Iterator > &lhs ) {

	return (reverse_iterator< Iterator >(lhs.base() - n));
}


STOP

#endif