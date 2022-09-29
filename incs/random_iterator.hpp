/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/29 14:05:50 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include "ft_containers.hpp"
#include "iterator_traits.hpp"

START

template< class T > struct random_iterator : public bidirectional_iterator_tag;

class random_iterator {
	
private:

	T		*ptr_it;

public:

	// using	value_T = T;
	// using	reference = value_T &;
	// using	pointer = value_T *;
	// using	iterator_category = std::random_access_iterator_tag;
	// using	difference_T = std::ptrdiff_t;

	random_iterator(T *iter = nullptr) : m_iterator{ iter } {}



	bool					operator==( const iterator &other ) const noexcept { return m_iterator == other.m_iterator; }
	bool					operator!=( const iterator &other ) const noexcept { return m_iterator != other.m_iterator; }
	reference				operator*() const noexcept { return *m_iterator; }
	pointer					operator->() const noexcept { return m_iterator; }
	random_iterator&		operator++() noexcept { ++m_iterator; return *this; }
	random_iterator			operator++( int ) noexcept { iterator tmp(*this); ++(*this); return tmp; }
	random_iterator			&operator--() noexcept { --m_iterator; return *this; }
	random_iterator			operator--( int ) noexcept { iterator tmp(*this); --(*this); return tmp; }
	random_iterator			&operator+=( const difference_T other ) noexcept { m_iterator += other; return *this; }
	random_iterator			&operator-=( const difference_T other ) noexcept { m_iterator -= other; return *this; }
	random_iterator			operator+( const difference_T other ) const noexcept { return iterator(m_iterator + other); }
	random_iterator			operator-( const difference_T other ) const noexcept { return iterator(m_iterator - other); }
	random_iterator			operator+( const iterator &other ) const noexcept { return iterator(*this + other.m_iterator); }
	difference_T			operator-( const iterator &other ) const noexcept { return std::distance(m_iterator, other.m_iterator); }
	reference				operator[]( std::size_t index ) const { return m_iterator[index]; }
	bool					operator<( const iterator &other ) const noexcept { return m_iterator < other.m_iterator; }
	bool					operator>( const iterator &other ) const noexcept { return m_iterator > other.m_iterator; }
	bool					operator<=( const iterator &other ) const noexcept { return m_iterator <= other.m_iterator; }
	bool					operator>=( const iterator &other ) const noexcept { return m_iterator >= other.m_iterator; }


};

STOP

#endif