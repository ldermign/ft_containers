/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:43:57 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 14:30:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include "ft_containers.hpp"

// https://www.scaler.com/topics/cpp/pair-in-cpp/
// + code source
// https://clickhouse.com/codebrowser/ClickHouse/contrib/libcxx/include/__utility/pair.h.html#std::pair
// pour les operateurs relationnels
// https://cplusplus.com/reference/utility/pair/operators/
// pour les types membres
// https://en.cppreference.com/w/cpp/utility/pair


START

template< class T1, class T2 >
struct pair {

	typedef T1	first_type;
	typedef T2	second_type;

	first_type	first;
	second_type	second;

/* CONSTRUCTEUR */
	pair( void ) : first(), second() {}

	pair ( const first_type &a, const second_type &b )
		: first(a), second(b) {}

/* CONSTRUCTEUR */
	template< class T, class U >
	pair( const pair< T, U > &src )
		: first(src.first), second(src.second) {} 

/* CONSTRUCTEUR PAR COPIE */
	pair &operator=( const pair &other ) {

		if (&other == this)
			return (*this);

        this->first = other.first;
        this->second = other.second;

        return (*this);
	}

	operator
	pair< const T1, const T2 > (void) const {

		return (pair< const T1, const T2 >(first, second));
	}

/* DESTRUCTEUR */
	~pair( void ) {}

};

/* ~~~~~ MAKE PAIR ~~~~~ */
template< class T1, class T2 >
ft::pair< T1, T2 > make_pair( T1 x, T2 y ) {

	return (ft::pair< T1, T2 >(x,y));
}

template< class T1, class T2 >
bool
operator==( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
    return (x.first == y.first && x.second == y.second);
}

template< class T1, class T2 >
bool
operator!=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return (!(x == y));
}

template< class T1, class T2 >
bool
operator<( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
}

template< class T1, class T2 >
bool
operator<=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return (!(y < x));
}

template< class T1, class T2 >
bool
operator>( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return (y < x);
}

template< class T1, class T2 >
bool
operator>=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return (!(x < y));
}

// SUPPRIMEER
template< class T1, class T2 >
std::ostream &operator<<( std::ostream &o, pair< T1, T2 > const &pair ) {

	o << pair.first << " - " << pair.second;
	return (o);
}

STOP

#endif
