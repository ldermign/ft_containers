/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/22 13:44:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "ft_containers.hpp"

namespace ft {

class vector {
	
public:

	template< typename T, typename Alloc = allocator< T > >
	

//	CANONICAL FORM

	vector( void );
	vector	&operator=( const vector &rhs );
	// {
	// 	if (this == &rhs) 
	// 		return *this;
	// 	this->_host = rhs._host;
	// 	return *this;
	// }
	vector( const vector &src );
	// {
		// *this = src;
	// }
	virtual	~vector( void );

private:

	
	
};

};

#endif