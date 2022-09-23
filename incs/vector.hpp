/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/23 15:04:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "ft_containers.hpp"

namespace ft {

	class vector {
		
	public:

		template< typename T > class chaipas;
		

	//	CANONICAL FORM

		vector( void );
		vector	&operator=( const vector &rhs );
		vector( const vector &src );
		virtual	~vector( void );

	private:

		
		
	};

};

#endif