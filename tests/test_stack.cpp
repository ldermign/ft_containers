/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:49:17 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/08 15:24:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <iostream>

#include "test_utils.hpp"

void constructor( void ) {

	p1 RED << "~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::stack< int >	stackInt1;
	LIBRARY::stack< int >	stackInt2;

	printStack("stackInt1", stackInt1);

}

void getteurs( void ) {

	p1 RED << "~~~~~~~~~~ GETTERS ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::vector< int >	vctInt1;
	LIBRARY::vector< int >	vctInt2;
	for (int i = 0 ; i < 9 ; i++)
		vctInt2.push_back(i1[i]);

	p1 GREEN << "Getters vector empty -> " << RESET p2
	p1 "\tSize = " << vctInt1.size() p2
	p1 "\tCapacity = " << vctInt1.capacity() p2
	p1 "\tEmpty = " << vctInt1.empty() p2


	p1 GREEN << "Getters vector full -> " << RESET p2
	p1 "\tSize = " << vctInt2.size() p2
	p1 "\tCapacity = " << vctInt2.capacity() p2
	p1 "\tEmpty = " << vctInt2.empty() p2

	p3
}

void operator_relationnal( void ) {

	p1 RED << "~~~~~~~~~~ OPERATOR RELATIONNAL ~~~~~~~~~~ " << RESET p2
	p3
	
	LIBRARY::vector< char >	vctChar1(c2, c2 + 10);
	LIBRARY::vector< char >	vctChar2(c3, c3 + 8);
	printVector("vctChar1", vctChar1);
	printVector("vctChar2", vctChar2);

	p1 YELLOW << "~~~~~ == ~~~~~ " << RESET p2
	p1 (vctChar1 == vctChar1) p2
	p1 (vctChar1 == vctChar2) p2

	p1 YELLOW << "~~~~~ != ~~~~~ " << RESET p2
	p1 (vctChar1 != vctChar1) p2
	p1 (vctChar1 != vctChar2) p2

	p1 YELLOW << "~~~~~ < ~~~~~ " << RESET p2
	p1 (vctChar1 < vctChar1) p2
	p1 (vctChar1 < vctChar2) p2

	p1 YELLOW << "~~~~~ > ~~~~~ " << RESET p2
	p1 (vctChar1 > vctChar1) p2
	p1 (vctChar1 > vctChar2) p2

	p1 YELLOW << "~~~~~ <= ~~~~~ " << RESET p2
	p1 (vctChar1 <= vctChar1) p2
	p1 (vctChar1 <= vctChar2) p2

	p1 YELLOW << "~~~~~ >= ~~~~~ " << RESET p2
	p1 (vctChar1 >= vctChar1) p2
	p1 (vctChar1 >= vctChar2) p2
	p3
}

void	test_stack( void ) {

	p3

	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~ STACK CONTAINER ~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET p2

	constructor();
	// getteurs();
	// operator_relationnal();




}

