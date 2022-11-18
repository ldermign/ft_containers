/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:43:57 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/18 15:43:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include "ft_containers.hpp"

// https://www.scaler.com/topics/cpp/pair-in-cpp/
// + code source
// https://clickhouse.com/codebrowser/ClickHouse/contrib/libcxx/include/__utility/pair.h.html#std::pair

START

template< class T1, class T2 >
struct pair {

	typedef T1	first_element;
	typedef T2	second_element;

/* CONSTRUCTEUR */
	pair( void ) : first_element(), second_element() {}

/* CONSTRUCTEUR */
	template< class T, class U >
	pair( const pair< T, U > &src ) : first_element(src.first_element), second_element(second_element) {} 

/* CONSTRUCTEUR PAR COPIE */
	pair
	&operator=( pair const &rhs ) {

		if (&rhs == this)
			return *this;

        this->first_element = src.first_element;
        this->second_element = src.second_element;

        return *this;
	}

/* DESTRUCTCEUR */
	virtual
	~pair( void ) {}

};

STOP

#endif
