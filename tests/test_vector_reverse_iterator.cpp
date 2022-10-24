/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_reverse_iterator.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:21:03 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/24 11:16:30 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	test_vector_reverse_iterator( void ) {

	p3
	
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR REVERSE ITERATOR ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	{
		LIBRARY::vector< int >	test;
		// test.push_back("C'est ");
		// test.push_back("en ");
		// test.push_back("desordre.");
		test.push_back(1);
		test.push_back(6);
		test.push_back(4);
		LIBRARY::vector< int >::reverse_iterator		first = test.rbegin();
		LIBRARY::vector< int >::reverse_iterator		second = test.rbegin(); // + 1;
		LIBRARY::vector< int >::reverse_iterator		last = test.rend();

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << first[i] << " " << RESET;
		p3
		
		p1 "operator *first - *second - *last -> " << *first << " - " << *second << " - " << *last p2
		p1 "operator first[0] - first[2] -> " << first[0] << " - " << first[2] p2
		p1 "pre incrementation -> before [" << *first << "] - during [" << *++first << "] - after [" << *first << "]" p2
		first = test.rbegin();
		p1 "post incrementation -> before [" << *first << "] - during [" << *first++ << "] - after [" << *first << "]" p2
		first = test.rbegin();
		p1 "pre decrementation second -> before [" << *second << "] - during [" << *--second << "] - after [" << *second << "]" p2
		second = test.rbegin(); // + 1;
		p1 "post decrementation second -> before [" << *second << "] - during [" << *second-- << "] - after [" << *second << "]" p2
		second = test.rbegin(); // + 1;
		second += 1;
		p1 "operator first += 2 -> " << *(first += 2) p2
		p1 "operator last -= 2 -> " << *(last -= 2) p2
		p1 "operator last + 1 -> " << *last << " - " << *(last += 1) p2;
		p1 "operator first - 1 -> " << *first << " - " << *(first -= 1) p2
		p1 "operator first == second -> " << (first == second) p2
		p1 "operator first != second -> " << (first != second) p2
		p1 "operator first + second -> " << *first + *second p2
		p1 "operator first - second -> " << first - second p2
		p1 "operator first < second -> " << (first < second) p2
		p1 "operator first > second -> " << (first > second) p2
		p1 "operator first <= second -> " << (first <= second) p2
		p1 "operator first >= second -> " << (first >= second) p2

		p3

	}
}