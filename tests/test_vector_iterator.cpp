/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_iterator.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:09:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/17 11:35:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
// #include "reverse_iterator.hpp"
#include "vector.hpp"
#include <iostream>

void	test_vector_iterator( void ) {

	p3
	
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR ITERATOR ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	{
		LIBRARY::vector< int >	test;
		test.push_back(42);
		test.push_back(123);
		test.push_back(-99);
		test.push_back(1007);
		test.push_back(11111);
		LIBRARY::vector< int >::iterator		first = test.begin();
		LIBRARY::vector< int >::iterator		second = test.begin() + 1;
		// LIBRARY::vector< int >::iterator		third = test.begin() + 2;
		LIBRARY::vector< int >::iterator		last = test.begin() + 3;

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << first[i] << " " << RESET;
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << *(first) p2
		p1 "pre incrementation -> before [" << *first << "] - during [" << *++first << "] - after [" << *first << "]" p2
		first = test.begin();
		p1 "post incrementation -> before [" << *first << "] - during [" << *first++ << "] - after [" << *first << "]" p2
		first = test.begin();
		p1 "pre decrementation second -> before [" << *second << "] - during [" << *--second << "] - after [" << *second << "]" p2
		second = test.begin() + 1;
		p1 "post decrementation second -> before [" << *second << "] - during [" << *second-- << "] - after [" << *second << "]" p2
		second = test.begin() + 1;
		p1 "operator second += 2 -> " << *(second += 2) p2
		p1 "operator last -= 2 -> " << *(last -= 2) p2
		p1 "operator first + 1 -> " << *first << " - " << *(first + 1) p2
		p1 "operator last - 1 -> " << *last << " - " << *(last - 1) p2
		p1 "operator first + last -> " << *first + *last p2
		p1 "operator first - last -> " << *first - *last p2
		p1 "operator first[0] - first[3] -> " << first[0] << " - " << first[3] p2
		p1 "operator first < second -> " << (first < second) p2
		p1 "operator first > second -> " << (first > second) p2
		p1 "operator first <= second -> " << (first <= second) p2
		p1 "operator first >= second -> " << (first >= second) p2

		p3

	}
}