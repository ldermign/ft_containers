/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/27 12:21:56 by ldermign         ###   ########.fr       */
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

	typedef random_iterator< T >  self;

	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::value_type			value_type;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::iterator_category	iterator_category;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::difference_type		difference_type;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::reference			reference;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::pointer				pointer;

	// typedef		std::ptrdiff_t difference_type;
	// typedef		T value_type;
	// typedef		T reference; // ft::iterator::Reference
	// typedef		T* pointer;
	// typedef		random_access_iterator_tag iterator_category;
	

	random_iterator( void ) : m_iterator(0) {}

	explicit random_iterator( pointer x ) : m_iterator(x) {}

	template< class U > random_iterator( const random_iterator< U > &u ); // Effects: Initializes m_iterator with u.m_iterator.
	pointer			base( void ) const {
		return this->m_iterator;
	}
	
	operator	random_iterator< const value_type >() const {
		return (random_iterator< const value_type >(this->m_iterator));
	};
	// erreur de cast entre iterator et const_iterator

	random_iterator( const random_iterator &x ) : m_iterator(x.base()) {}

//	DESTRUCTOR

	virtual ~random_iterator( void ) {}

	random_iterator	&operator=( const random_iterator &rhs ) {
		
		if (this == &rhs)
			return *this;
		
		this->m_iterator = rhs.m_iterator;

		return *this;
		
	}

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