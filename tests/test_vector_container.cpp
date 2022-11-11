/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/11 18:36:35 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list>
#include <vector>
#include "vector.hpp"
#include <iostream>

#define T_SIZE_TYPE typename LIBRARY::vector<T>::value_type

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

	const int start_size = 7;
	LIBRARY::vector< int > vct(start_size, 20);
	LIBRARY::vector< int > vct2;
	LIBRARY::vector< int >::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	printSize(vct, true);

	vct.resize(10, 42);
	printSize(vct, true);

	vct.resize(18, 43);

	
	// printSize(vct, true);
	// vct.resize(10);
	// printSize(vct, true);
	// vct.resize(23, 44);
	// printSize(vct, true);
	// vct.resize(5);
	// printSize(vct, true);
	// vct.reserve(5);
	// vct.reserve(3);
	// printSize(vct, true);
	// vct.resize(87);
	// vct.resize(5);
	// printSize(vct, true);

	// is_empty(vct2);
	// vct2 = vct;
	// is_empty(vct2);
	// vct.reserve(vct.capacity() + 1);
	// printSize(vct, true);
	// printSize(vct2, true);

	// vct2.resize(0);
	// is_empty(vct2);
	// printSize(vct2, true);





	p3

	}
	
}