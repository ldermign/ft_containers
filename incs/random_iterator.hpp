/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/06 14:38:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

#include "ft_containers.hpp"
#include "distance.hpp"
#include "iterator.hpp"

/* source: https://clickhouse.com/codebrowser/ClickHouse/contrib/libcxx/include/__iterator/wrap_iter.h.html#258*/

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

	random_iterator( void )
		: m_iterator(0) {}

	explicit random_iterator( pointer x )
		: m_iterator(x) {}

// constructeur par copie avec template
	template< class U >
	random_iterator( const random_iterator< U > &u )
		: m_iterator(u.base()) {}

	pointer
	base( void ) const {

		return (this->m_iterator);
	}

	operator	random_iterator< const value_type >() const {
		return (random_iterator< const value_type >(this->m_iterator));
	};

	random_iterator( const random_iterator &x )
		: m_iterator(x.base()) {}

//	DESTRUCTOR

	~random_iterator( void ) {}

	bool
	operator==( const random_iterator &other ) const {

		return (m_iterator == other.m_iterator);
	}

	bool
	operator!=( const random_iterator &other ) const {

		return (m_iterator != other.m_iterator);
	}

	reference
	operator*( void ) const {

		return (*m_iterator);
	}
	
	pointer
	operator->( void ) const {

		return (m_iterator);
	}
	
	random_iterator
	&operator++( void ) {

		++m_iterator;
		return (*this);
	}
	
	random_iterator
	operator++( int ) {

		random_iterator	tmp(*this);
		++(*this);
		return (tmp);
	}
	
	random_iterator
	&operator--( void ) {

		--m_iterator;
		return (*this);
	}
	
	random_iterator
	operator--( int ) {

		random_iterator tmp(*this);
		--(*this);
		return (tmp);
	}

	random_iterator
	&operator+=( const difference_type other ) {

		m_iterator += other;
		return (*this);
	}
	
	random_iterator
	&operator-=( const difference_type other ) {

		m_iterator -= other;
		return (*this);
	}




	/* ~~~~~ + ~~~~~ */

	random_iterator
	operator+( const difference_type other ) const {

		return (random_iterator(m_iterator + other));
	}
	
	random_iterator
	operator+( const random_iterator &other ) const {

		return (random_iterator(*this + other.m_iterator));
	}





/* ~~~~~ - ~~~~~ */

	random_iterator
	operator-( const difference_type other ) const {

		return (random_iterator(m_iterator - other));
	}

	difference_type
	operator-( const random_iterator &other ) const {

		// p1 "distace" p2
		return (base() - other.base());
	}






	reference
	operator[]( std::size_t index ) const {

		return (this->m_iterator[index]);
	}
	
	bool
	operator<( const random_iterator &other ) const {

		return (m_iterator < other.m_iterator);
	}
	
	bool
	operator>( const random_iterator &other ) const {

		return (m_iterator > other.m_iterator);
	}
	
	bool
	operator<=( const random_iterator &other ) const {

		return (m_iterator <= other.m_iterator);
	}
	
	bool
	operator>=( const random_iterator &other ) const {

		return (m_iterator >= other.m_iterator);
	}

	friend random_iterator
	operator+( const difference_type &n, const random_iterator &x) {

		return (random_iterator(x.base() + n));
	}



};

template< class Iterator1, class Iterator2 >
bool
operator==(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator!=(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() != rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() < rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator<=(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() <= rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool
operator>=(	const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {
	return (lhs.base() >= rhs.base());
}

template< class Iterator > 
random_iterator< Iterator > operator+( typename random_iterator< Iterator >::differente_type &n, const ft::random_iterator< Iterator > lhs ) {
	lhs += n;
	return (lhs);
}

template< class Iterator1, class Iterator2 > 
typename random_iterator< Iterator1 >::difference_type operator-( const ft::random_iterator< Iterator1 > &lhs, const ft::random_iterator< Iterator2 > &rhs ) {

	return (lhs.base() - rhs.base());
}

STOP

#endif