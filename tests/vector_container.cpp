/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_container.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/15 17:07:51 by ldermign         ###   ########.fr       */
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
		test.push_back("Salut, "); // first time : this->size() + 1 = 0 et this->capacity() = 0
		test.push_back("c'est "); // this->size() + 1 = 1 et this->capacity() = 1
		test.push_back("un container"); // this->size() + 1 = 2 et this->capacity() = 2
		test.push_back("rempli de "); // this->size() + 1 = 4 et this->capacity() = 4
		test.push_back("std::string !\n");
		LIBRARY::vector< std::string >::iterator		it = test.begin();
		// LIBRARY::vector< std::string >::const_iterator	itcbegin = test.cbegin();

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << it[i] << " " << RESET;
		p3
		p1 "~~~~~ BEGIN & END ~~~~~" p2
		p1 "begin -> " << *(test.begin()) p2
		p1 "end -> " << *(test.end() - 1) p2
		// p1 "rbegin -> " << *(test.rbegin()) p2 // checker comment tester const
		// p1 "rend -> " << *(test.rend()) p2

		p3
		// p1 "~~~~~ UTILS ~~~~~" p2
		// p1 "size -> " << test.size() p2
		// p1 "size_max -> " << test.max_size() p2
		// p1 "capacity -> " << test.capacity() p2
		
		// p1 "empty -> " << test.empty() p2 // not working
		// tests resize
		// test reserve



		p3

	}
}