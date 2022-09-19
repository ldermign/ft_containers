/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/19 15:53:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "ft_containers.hpp"

class Vector {
	
public:

//	ITERATORS

	iterator	begin( );
	

//	CANONICAL FORM

	Vector( void );
	Vector	&operator=( const Vector &rhs );
	// {
	// 	if (this == &rhs) 
	// 		return *this;
		
	// 	this->_host = rhs._host;
	// 	this->_port = rhs._port;
	// 	this->_serverName = rhs._serverName;
	// 	this->_defaultServer = rhs._defaultServer;
	// 	this->_errorPage = rhs._errorPage;
	// 	this->_clientMaxBodySize = rhs._clientMaxBodySize;
	// 	this->_location = rhs._location;
		
	// 	return *this;
	// }
	Vector( const Vector &src );
	// {
		// *this = src;
	// }
	virtual	~Vector( void );

private:

	
	
};


#endif