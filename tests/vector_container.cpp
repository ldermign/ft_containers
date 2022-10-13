/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_container.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/13 14:09:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
// #include "reverse_iterator.hpp"
#include <iostream>

void	vector_container( void ) {

	std::cout << std::endl;
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	{
		LIBRARY::vector< std::string >	test;
		test.push_back("Salut, ");
		test.push_back("c'est ");
		test.push_back("un container");
		test.push_back("rempli de ");
		test.push_back("std::string !\n");
		LIBRARY::vector< std::string >::iterator		it = test.begin();

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << it[i] << " " << RESET;
		p3
		p1 "~~~~~ BEGIN & END ~~~~~" p2
		p1 "begin -> " << *(test.begin()) p2
		// p1 "cbegin -> " << *(test.cbegin()) p2 // checker comment tester const
		p1 "end -> " << *(test.end()) p2
		// p1 "cend -> " << *(test.cend()) p2 // checker comment tester const
		p1 "rbegin -> " << *(test.rbegin()) p2
		// p1 "crbegin -> " << *(test.crbegin()) p2 // checker comment tester const
		// p1 "rend -> " << *(test.rend()) p2
		// p1 "crend -> " << *(test.crend()) p2 // checker comment tester const

		p3
		p1 "~~~~~ UTILS ~~~~~" p2
		p1 "size -> " << test.size() p2
		p1 "size_max -> " << test.max_size() p2
		p1 "capacity -> " << test.capacity() p2
		// p1 "empty -> " << test.empty() p2 // not working
		// tests resize
		// test reserve



		p3

	}
}