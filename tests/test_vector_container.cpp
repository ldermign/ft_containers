/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/12 17:33:03 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list>
#include <vector>
#include "vector.hpp"
#include <iostream>

#define T_SIZE_TYPE typename LIBRARY::vector<T>::value_type

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

	LIBRARY::vector< int > vct(10);
	LIBRARY::vector< int > vct2;
	LIBRARY::vector< int > vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	// printSize(vct);

	vct2.insert(vct2.end(), 42);

	vct2.insert(vct2.begin(), 2, 21);

	
	printSize(vct2);

	p1 "avant = " p2
	for (size_t i = 0 ; i < vct2.size() ; i++)
		p1 vct2[i] << " " p2
	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);
	p1 "apres" p2
	// for (size_t i = 0 ; i < vct2.size() ; i++)
	// 	p1 vct2[i] << " " p2

	// vct2.insert(vct2.end(), 2, 84);
	// printSize(vct2);

	// vct2.resize(4);
	// printSize(vct2);

	// vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	// vct.clear();
	// printSize(vct2);

	// printSize(vct);

	// for (int i = 0; i < 5; ++i)
	// 	vct3.insert(vct3.end(), i);
	// vct3.insert(vct3.begin() + 1, 2, 111);
	// printSize(vct3);





	p3

	}
	
}