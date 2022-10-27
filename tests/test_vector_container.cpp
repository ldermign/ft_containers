/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/27 15:32:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

#define T_SIZE_TYPE typename LIBRARY::vector<T>::value_type

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
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
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

	LIBRARY::vector< int > vct(5);
	LIBRARY::vector< int > vct2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 7;
	printSize(vct);

	vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
	printSize(vct2);
	// vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
	// printSize(vct2);
	// vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
	// printSize(vct2);

	// std::cout << "insert return:" << std::endl;

	// std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
	// std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;
	// std::cout << "----------------------------------------" << std::endl;

	// printSize(vct2);



	p3

	}
	
}