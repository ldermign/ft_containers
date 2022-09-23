/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:44:18 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/23 15:04:28 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft {

/*
**	CANONICAL FORM
*/

vector::vector( void ) {
	
}

vector	&vector::operator=( const vector &rhs ) {
	if (this == &rhs) 
		return *this;
// 	this->_host = rhs._host;
	return *this;
}

vector::vector( const vector &src ) {
	*this = src;
}

vector::~vector( void ) {
	
}

};