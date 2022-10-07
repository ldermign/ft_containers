/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:09:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/07 14:50:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	vector_iterator( void ) {

	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~ VECTOR ITERATOR ~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	{

		ft::vector< int >	real(4, 42);
		ft::vector< int >::iterator		first = real.begin();
		ft::vector< int >::iterator		second = real.begin() + 2;

		PSTART "operator == -> " << first == first PSTOP
		PSTART "second - first -> " << second - first PSTOP
		PSTART "first - second -> " << first - second PSTOP


	}
}