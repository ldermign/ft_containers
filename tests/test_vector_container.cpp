/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/25 08:57:38 by ldermign         ###   ########.fr       */
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
		
		LIBRARY::vector< int > vct(5);
		LIBRARY::vector< int >::iterator it = vct.begin(), ite = vct.end();

		std::cout << "len: " << (ite - it) << std::endl;
		for (; it != ite; ++it)
			*it = (ite - it);
		p1 "vct = ";
		for (size_t i = 0 ; i < vct.size() ; i++)
			p1 vct[i] << " ";
		p3

		it = vct.begin();
		LIBRARY::vector< int > vct_range(it, --(--ite));
		for (int i = 0; it != ite; ++it)
			*it = ++i * 5;
		p1 "vct_range = ";
		for (size_t i = 0 ; i < vct_range.size() ; i++)
			p1 vct_range[i] << " ";
		p3

		it = vct.begin();
		LIBRARY::vector< int > vct_copy(vct);
		for (int i = 0; it != ite; ++it)
			*it = ++i * 7;
		vct_copy.push_back(42);
		vct_copy.push_back(21);
		p1 "vct_copy = ";
		for (size_t i = 0 ; i < vct_copy.size() ; i++)
			p1 vct_copy[i] << " ";
		p3

		std::cout << "\t-- PART ONE --" << std::endl;
		p1 "SIZE vct = " << vct.size() p2
		p1 "SIZE vct_range = " << vct_range.size() p2 // normalement 3 -> , ici 0
		p1 "SIZE vct_copy = " << vct_copy.size() p2

		vct = vct_copy;
		vct_copy = vct_range;
		vct_range.clear();

		std::cout << "\t-- PART TWO --" << std::endl;

		p1 "SIZE vct = " << vct.size() p2 // normalement 7, ici 0
		p1 "SIZE vct_range = " << vct_range.size() p2
		p1 "SIZE vct_copy = " << vct_copy.size() p2 // normalement 3, ici 7


	p3

	}
}