/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:43:57 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/21 15:16:37 by ldermign         ###   ########.fr       */
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


START

template< class T1, class T2 >
struct pair {

	typedef T1	first_element;
	typedef T2	second_element;

	first_element	first_elmt;
	second_element	second_elmt;

/* CONSTRUCTEUR */
	pair( void ) : first_elmt(), second_elmt() {}

/* CONSTRUCTEUR */
	template< class T, class U >
	pair( const pair< T, U > &src ) : first_elmt(src.first_elmt), second_elmt(src.second_elmt) {} 

/* CONSTRUCTEUR PAR COPIE */
	pair
	&operator=( pair const &y ) {

		if (&y == this)
			return *this;

        this->first_elmt = y.first_elmt;
        this->second_elmt = y.second_elmt;

        return *this;
	}

/* DESTRUCTCEUR */
	virtual
	~pair( void ) {}

/* MAKE PAIR */
	pair< T1, T2 > make_pair( T1 x, T2 y ) {

		return (pair< T1, T2 > (x,y) );
	}

};

template< class T1, class T2 >
bool
operator==( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
    return x.first_elmt == y.first_elmt && x.second_elmt == y.second_elmt;
}

template< class T1, class T2 >
bool
operator!=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return !(x == y);
}

template<class T1, class T2>
bool
operator<( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return x.first_elmt < y.first_elmt || (!(y.first_elmt < x.first_elmt) && x.second_elmt < y.second_elmt);
}

template<class T1, class T2>
bool
operator<=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return !(y < x);
}

template<class T1, class T2>
bool
operator>( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return y < x;
}

template<class T1, class T2>
bool
operator>=( const pair< T1, T2 > &x, const pair< T1, T2 > &y ) {
	return !(x < y);
}

STOP

#endif
