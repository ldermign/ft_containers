/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:09:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/11 09:32:49 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	vector_iterator( void ) {

	std::cout << std::endl;
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~ VECTOR ITERATOR ~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	{
		LIBRARY::vector< int >	test;
		test.push_back(42);
		// test.push_back(123);s
		// test.push_back(0);
		// test.push_back(1007);
		LIBRARY::vector< int >::iterator		first = test.begin();
		LIBRARY::vector< int >::iterator		second = test.begin() + 2;

		for (int i = 0 ; i < 4 ; i++)
			PSTART RED << first[i] << " " << RESET;
		std::cout << std::endl;
		PSTART "operator first == first -> " << (first == first) PSTOP
		PSTART "operator first != first -> " << (first != first) PSTOP
		PSTART "operator *first -> " << *(first) PSTOP
		// PSTART "operator test->begin() -> " << test->begin() PSTOP
		PSTART "operator *first -> " << *(second) PSTOP
		PSTART "second - first -> " << (second - first) PSTOP
		PSTART "first - second -> " << (first - second) PSTOP

		std::cout << std::endl;

	}
}