/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:44:18 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/26 11:32:02 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "vector.hpp"

START

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

STOP