/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/15 11:57:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list>
#include <vector>
#include "vector.hpp"
#include <iostream>

#define TESTED_TYPE std::string

// #define T_SIZE_TYPE typename LIBRARY::vector<T>::value_type
#define T_SIZE_TYPE size_t



/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/


template <typename T>
void	printVector(LIBRARY::vector< T > const &vct, std::string str) {

	p1 str << "\n";
	for (size_t i = 0 ; i < vct.size() ; i++)
		p1 "\t-> " << vct[i] p2
}

void	is_empty(LIBRARY::vector< int > const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <typename T>
void	printSize(LIBRARY::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename LIBRARY::vector<T>::const_iterator it = vct.begin();
		typename LIBRARY::vector<T>::const_iterator ite = vct.end();
		std::cout << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	p3
	std::cout << "###############################################" << std::endl;
	p3
}


void	checkErase(LIBRARY::vector< std::string > const &vct,
					LIBRARY::vector< std::string >::const_iterator const &it)
{

	// p1 "avant" p2
	
	static int	i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	p1 "2 SIZE vct = " << vct.size() p2
}


void	test_vector_container( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	
	{

	LIBRARY::vector<TESTED_TYPE> vct(8);
	LIBRARY::vector<TESTED_TYPE> vct2;
	LIBRARY::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	printSize(vct, true);

	std::cout << "push_back():\n" << std::endl;

	vct.push_back("One long string");
	vct2.push_back("Another long string");

	printSize(vct);
	printSize(vct2);

	vct.pop_back();
	vct2.pop_back();

	printSize(vct);
	printSize(vct2);




	p3

	}
	
}