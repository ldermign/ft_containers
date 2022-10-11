/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:09:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/11 15:54:54 by ldermign         ###   ########.fr       */
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
		test.push_back(123);
		test.push_back(-99);
		test.push_back(1007);
		LIBRARY::vector< int >::iterator		first = test.begin();
		LIBRARY::vector< int >::iterator		second = test.begin() + 1;
		// LIBRARY::vector< int >::iterator		third = test.begin() + 2;
		LIBRARY::vector< int >::iterator		last = test.begin() + 3;

		for (size_t i = 0 ; i < test.size() ; i++)
			PSTART RED << first[i] << " " << RESET;
		std::cout << std::endl;
		PSTART "operator first == first -> " << (first == first) PSTOP
		PSTART "operator first != first -> " << (first != first) PSTOP
		PSTART "operator *first -> " << *(first) PSTOP
		PSTART "pre incrementation -> before [" << *first << "] - during [" << *++first << "] - after [" << *first << "]" PSTOP
		first = test.begin();
		PSTART "post incrementation -> before [" << *first << "] - during [" << *first++ << "] - after [" << *first << "]" PSTOP
		first = test.begin();
		PSTART "pre decrementation -> before [" << *first << "] - during [" << *--first << "] - after [" << *first << "]" PSTOP
		first = test.begin();
		PSTART "post decrementation -> before [" << *first << "] - during [" << *first-- << "] - after [" << *first << "]" PSTOP
		first = test.begin();
		PSTART "operator second += 2 -> " << *(second += 2) PSTOP
		PSTART "operator last -= 2 -> " << *(last -= 2) PSTOP
		
		PSTART "second - first -> " << (second - first) PSTOP
		PSTART "first - second -> " << (first - second) PSTOP

		std::cout << std::endl;

	}
}