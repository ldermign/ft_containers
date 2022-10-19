/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/19 15:51:46 by ldermign         ###   ########.fr       */
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
			
		LIBRARY::vector< int > foo(3, 15);
		LIBRARY::vector< int > bar(5, 42);
		
		LIBRARY::vector< int >::const_iterator it_foo = foo.begin();
		// on creer un const_iterator de vector appelle it_foo
		// LIBRARY::vector< int >::const_iterator it_bar = bar.begin();

		// std::cout << "BEFORE SWAP" << std::endl;

		// std::cout << "foo contains:" << std::endl;
		// p1 "foo size = " << foo.size() p2
		// std::cout << "bar contains:" << std::endl;
		// p1 "bar size = " << bar.size() p2

		// foo.swap(bar);

		// std::cout << "AFTER SWAP" << std::endl;

		// std::cout << "foo contains:" << std::endl;
		// p1 "foo size = " << foo.size() p2
		// std::cout << "bar contains:" << std::endl;
		// p1 "bar size = " << bar.size() p2

		// std::cout << "Iterator validity:" << std::endl;
		// std::cout << (it_foo == bar.begin()) << std::endl;
		// std::cout << (it_bar == foo.begin()) << std::endl;




	p3

	}
}