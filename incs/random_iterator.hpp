/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/12 09:24:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include "ft_containers.hpp"
#include "iterator.hpp"

START

template< class T >
class random_iterator {
// on va se suicider ! salut
private:

	T		*m_iterator;

public:

	typedef		std::ptrdiff_t difference_type;
	typedef		T value_type;
	typedef		T reference; // ft::iterator::Reference
	typedef		T* pointer;
	typedef		random_access_iterator_tag iterator_category;

	random_iterator( T *iter = NULL ) : m_iterator(iter) {} // {};

	bool			operator==( const random_iterator &other ) const {
		return m_iterator == other.m_iterator;
	}
	
	bool			operator!=( const random_iterator &other ) const {
		return m_iterator != other.m_iterator;
	}

	reference		operator*( void ) const {
		return *m_iterator;
	}
	
	pointer			operator->( void ) const {
		return m_iterator;
	}
	
	random_iterator	&operator++( void ) {
		++m_iterator;
		return *this;
	}
	
	random_iterator	operator++( int ) {
		random_iterator tmp(*this);
		++(*this);
		return tmp;
	}
	
	random_iterator	&operator--( void ) {
		--m_iterator;
		return *this;
	}
	
	random_iterator	operator--( int ) {
		random_iterator tmp(*this);
		--(*this);
		return tmp;
	}

	random_iterator	&operator+=( const difference_type other ) {
		m_iterator += other;
		return *this;
	}
	
	random_iterator	&operator-=( const difference_type other ) {
		m_iterator -= other;
		return *this;
	}

	random_iterator	operator+( const difference_type other ) const {
		return random_iterator(m_iterator + other);
	}
	
	random_iterator	operator-( const difference_type other ) const {
		return random_iterator(m_iterator - other);
	}
	
	random_iterator	operator+( const random_iterator &other ) const {
		return random_iterator(*this + other.m_iterator);
	}
	
	difference_type	operator-( const random_iterator &other ) const {
		return std::distance(other.m_iterator, m_iterator);
	}

		//tests

	reference		operator[]( std::size_t index ) const {
		return this->m_iterator[index];
	}
	
	bool			operator<( const random_iterator &other ) const {
		return m_iterator < other.m_iterator;
	}
	
	bool			operator>( const random_iterator &other ) const {
		return m_iterator > other.m_iterator;
	}
	
	bool			operator<=( const random_iterator &other ) const {
		return m_iterator <= other.m_iterator;
	}
	
	bool			operator>=( const random_iterator &other ) const {
		return m_iterator >= other.m_iterator;
	}


};

STOP

#endif