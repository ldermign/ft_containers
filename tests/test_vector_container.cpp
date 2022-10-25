/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/25 15:07:22 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	checkErase(LIBRARY::vector< std::string > const &vct,
					LIBRARY::vector< std::string >::const_iterator const &it)
{

	// p1 "avant" p2
	
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	p1 "2 SIZE vct = " << vct.size() p2
}


void	test_vector_container( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	{

	LIBRARY::vector< std::string > vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	p1 "1 SIZE vct = " << vct.size() p2

	// p1 "not ok for now" p2

	// p1 "before = ";
	// for (size_t i = 0 ; i < vct.size() ; i++)
	// 	p1 vct[i] << " " p2

	checkErase(vct, vct.erase(vct.begin() + 2));

	// p1 "after = ";
	// for (size_t i = 0 ; i < vct.size() ; i++)
	// 	p1 vct[i] << " " p2

	// p1 "first erase is ok" p2

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back("Hello");
	vct.push_back("Hi there");
	p1 "3 SIZE vct = " << vct.size() p2
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	p1 "4 SIZE vct = " << vct.size() p2
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

	p3

	}
	
}