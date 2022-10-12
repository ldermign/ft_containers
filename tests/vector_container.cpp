/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_container.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/12 13:56:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

void	vector_container( void ) {

	std::cout << std::endl;
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	{
		LIBRARY::vector< std::string >	test;
		test.push_back("Salut, ");
		test.push_back("c'est ");
		test.push_back("un container");
		test.push_back("rempli de ");
		test.push_back("std::string !\n");
		LIBRARY::vector< std::string >::iterator		it = test.begin();

		for (size_t i = 0 ; i < test.size() ; i++)
			PSTART RED << it[i] << " " << RESET;
		PSAUT
		PSTART "~~~~~ BEGIN & END ~~~~~" PSTOP
		PSTART "begin -> " << *(test.begin()) PSTOP
		// PSTART "cbegin -> " << *(test.cbegin()) PSTOP // checker comment tester const
		PSTART "end -> " << *(test.end()) PSTOP
		// PSTART "cend -> " << *(test.cend()) PSTOP // checker comment tester const
		PSTART "rbegin -> " << *(test.rbegin()) PSTOP
		// PSTART "crbegin -> " << *(test.crbegin()) PSTOP // checker comment tester const
		PSTART "rend -> " << *(test.rend()) PSTOP
		// PSTART "crend -> " << *(test.crend()) PSTOP // checker comment tester const

		PSAUT
		PSTART "~~~~~ UTILS ~~~~~" PSTOP
		


		PSAUT

	}
}