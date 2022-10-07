/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/07 14:40:30 by ldermign         ###   ########.fr       */
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

	// using	iterator	ft::iterator;
	// using	value_T = T;
	typedef		T reference; // ft::iterator::Reference
	typedef		T* pointer;
	// using	iterator_category = std::random_access_iterator_tag;
	typedef		std::ptrdiff_t difference_T;

	random_iterator( T *iter = NULL ) : m_iterator(iter) {} // {};

	bool					operator==( const random_iterator &other ) const {
		return m_iterator == other.m_iterator;
	}
	
	bool					operator!=( const random_iterator &other ) const {
		return m_iterator != other.m_iterator;
	}
	
	reference				operator*() const {
		return *m_iterator;
	}
	
	pointer					operator->() const {
		return m_iterator;
	}
	
	random_iterator			&operator++() {
		++m_iterator;
		return *this;
	}
	
	random_iterator			operator++( int ) {
		random_iterator tmp(*this);
		++(*this);
		return tmp;
	}
	
	random_iterator			&operator--() {
		--m_iterator;
		return *this;
	}
	
	random_iterator			operator--( int ) {
		random_iterator tmp(*this);
		--(*this);
		return tmp;
	}
	
	random_iterator			&operator+=( const difference_T other ) {
		m_iterator += other;
		return *this;
	}
	
	random_iterator			&operator-=( const difference_T other ) {
		m_iterator -= other;
		return *this;
	}
	
	random_iterator			operator+( const difference_T other ) const {
		return random_iterator(m_iterator + other);
	}
	
	random_iterator			operator-( const difference_T other ) const {
		return random_iterator(m_iterator - other);
	}
	
	random_iterator			operator+( const random_iterator &other ) const {
		return random_iterator(*this + other.m_iterator);
	}
	
	difference_T			operator-( const random_iterator &other ) const {
		return std::distance(other.m_iterator, m_iterator);
	}
	
	reference				operator[]( std::size_t index ) const {
		return m_iterator[index];
	}
	
	bool					operator<( const random_iterator &other ) const {
		return m_iterator < other.m_iterator;
	}
	
	bool					operator>( const random_iterator &other ) const {
		return m_iterator > other.m_iterator;
	}
	
	bool					operator<=( const random_iterator &other ) const {
		return m_iterator <= other.m_iterator;
	}
	
	bool					operator>=( const random_iterator &other ) const {
		return m_iterator >= other.m_iterator;
	}


};

STOP

#endif