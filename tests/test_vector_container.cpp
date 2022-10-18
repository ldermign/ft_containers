/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/18 15:01:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	test_vector_container( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	{
		// LIBRARY::vector< std::string >	test;
		// test.push_back("Salut, "); // first time : this->size() + 1 = 0 et this->capacity() = 0
		// test.push_back("c'est "); // this->size() + 1 = 1 et this->capacity() = 1
		// test.push_back("un container "); // this->size() + 1 = 2 et this->capacity() = 2
		// test.push_back("rempli de "); // this->size() + 1 = 4 et this->capacity() = 4
		// test.push_back("std::string !");
		// LIBRARY::vector< std::string >::iterator		it = test.begin();
		// // LIBRARY::vector< std::string >::const_iterator	itcbegin = test.cbegin();

		// for (size_t i = 0 ; i < test.size() ; i++)
		// 	p1 BLUE << "[" << it[i] << "]" << RESET;
		// p3 p3
		
		// p1 "~~~~~ BEGIN & END ~~~~~" p2
		// p1 "begin -> " << *(test.begin()) p2
		// p1 "end -> " << *(test.end() - 1) p2
		// p1 "rbegin -> " << *(test.rbegin()) p2 // checker comment tester const
		// p1 "rend -> " << *(test.rend()) p2

		LIBRARY::vector< int > vct(7);
		LIBRARY::vector< int > vct_two(4);
		LIBRARY::vector< int > vct_three;
		LIBRARY::vector< int > vct_four;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;
		for (size_t i = 0 ; i < vct.size() ; i++)
			p1 BLUE << "[" << vct[i] << "]" << RESET;
		p3
		for (unsigned long int i = 0; i < vct_two.size(); ++i)
			vct_two[i] = (vct_two.size() - i) * 5;
		for (size_t i = 0 ; i < vct_two.size() ; i++)
			p1 BLUE << "[" << vct_two[i] << "]" << RESET;
		p3 p3

		p1 vct.size() << " - " p2 // ok
		p1 vct_two.size() p2 // ok

		// vct_three.assign(vct.begin(), vct.end());
		vct.assign(vct_two.begin(), vct_two.end());
		// vct_two.assign(2, 42);
		// vct_four.assign(4, 21);

		p1 "after assign = " p2
		for (size_t i = 0 ; i < vct.size() ; i++)
			p1 BLUE << "[" << vct[i] << "]" << RESET;
		p3

		std::cout << "\t### After assign(): ###" << std::endl;

		p1 vct.size() << " - " p2
		// p1 vct_two.size() << " - " p2
		// p1 vct_three.size() << " - " p2
		// p1 vct_four.size() p2


		// vct_four.assign(6, 84);
		// p1 vct_four.size() p2
		
		// std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

		// vct.assign(5, 53);
		// vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

		// p1 vct.size() << " - " p2
		// p1 vct_two.size() p2


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