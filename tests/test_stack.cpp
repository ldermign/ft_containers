/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:49:17 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/08 21:29:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <iostream>

template< class T >
void printStackVector( std::string name, LIBRARY::stack< T, LIBRARY::vector< T > > const &src ) {

	LIBRARY::stack< T, LIBRARY::vector< T > >	tmp(src);

	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2

	p1 BLUE << "stack " << name << RESET << " = ";
	while (!tmp.empty()) {
		p1 tmp.top() << " ";
		tmp.pop();
	}
	p3
	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2
	p1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" p2
	p3
		
}

template< class T >
void printStack( std::string name, LIBRARY::stack< T > const &src ) {

	LIBRARY::stack< T >			tmp(src);

	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2

	p1 BLUE << "stack " << name << RESET << " = ";
	while (!tmp.empty()) {
		p1 tmp.top() << " ";
		tmp.pop();
	}
	p3
	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2
	p1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" p2
	p3
		
}

void constructor_stack( void ) {

	p1 RED << "~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~ " << RESET p2
	p3

	int i4[] = {1, 2, 4, 8, 16, 32, 64, 128, 256}; // 9
	char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'}; // 8

	p1 "constructor = " p2
	LIBRARY::stack< int >	stackInt1;
	printStack("stackInt1", stackInt1);
	for (size_t i = 0 ; i < 9 ; i++)
		stackInt1.push(i4[i]);

	p1 "constructor copy = " p2
	LIBRARY::stack< int >	stackInt2(stackInt1);
	printStack("stackInt2", stackInt2);

	p1 "constructor template vector" p2
	LIBRARY::vector< char >	vectorChar1;
	for (int i = 0 ; i < 8 ; i++)
		vectorChar1.push_back(c3[i]);
	LIBRARY::stack< char, LIBRARY::vector< char > >	stackInt3(vectorChar1);
	printStackVector("stackInt3", stackInt3);

	p1 "constructor operator = " p2
	LIBRARY::stack< int >	stackInt4;
	p1 "before = " p2
	printStack("stackInt4", stackInt4);
	stackInt4 = stackInt1;
	p1 "after = " p2
	printStack("stackInt4", stackInt4);

	p3
}

void top( void ) {

	p1 RED << "~~~~~~~~~~ TOP ~~~~~~~~~~ " << RESET p2
	p3

	int i2[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4}; // 9

	LIBRARY::stack< int >		stackInt1;
	for (size_t i = 0 ; i < 9 ; i++)
		stackInt1.push(i2[i]);
	const LIBRARY::stack< int >	stackInt2(stackInt1);
	p1 "top = " << stackInt1.top() p2
	p1 "const top = " << stackInt2.top() p2

	p3
}

void push_and_pop( void ) {

	p1 RED << "~~~~~~~~~~ PUSH AND POP ~~~~~~~~~~ " << RESET p2
	p3

	std::string s5[] = {"On ", "va ", "ecrire ", "une ", "longue ", "phrase ", "comme ", "ca ", "c'est ", "ok !"}; // 10

	LIBRARY::stack< std::string >		stackString1;
	for (size_t i = 0 ; i < 9 ; i++) {
		p1 "push " << i p2
		stackString1.push(s5[i]);
		p1 "top = " << stackString1.top() p2
	}
	for (size_t i = 0 ; i < 9 ; i++) {
		p1 "pop " << i p2
		stackString1.pop();
		if (i != 8)
			p1 "top = " << stackString1.top() p2
	}
	p3
}

void operator_relationnal_stack( void ) {

	p1 RED << "~~~~~~~~~~ OPERATOR RELATIONNAL ~~~~~~~~~~ " << RESET p2
	p3

	char c2[] = {'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 's'}; // 10
	char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'}; // 8

	LIBRARY::stack< char >	stackChar1;
	LIBRARY::stack< char >	stackChar2;
	for (int i = 0 ; i < 10 ; i++)
		stackChar1.push(c2[i]);
	for (int i = 0 ; i < 8 ; i++)
		stackChar1.push(c3[i]);
	printStack("stackChar1", stackChar1);
	printStack("stackChar2", stackChar2);

	p1 YELLOW << "~~~~~ == ~~~~~ " << RESET p2
	p1 (stackChar1 == stackChar1) p2
	p1 (stackChar1 == stackChar2) p2

	p1 YELLOW << "~~~~~ != ~~~~~ " << RESET p2
	p1 (stackChar1 != stackChar1) p2
	p1 (stackChar1 != stackChar2) p2

	p1 YELLOW << "~~~~~ < ~~~~~ " << RESET p2
	p1 (stackChar1 < stackChar1) p2
	p1 (stackChar1 < stackChar2) p2

	p1 YELLOW << "~~~~~ > ~~~~~ " << RESET p2
	p1 (stackChar1 > stackChar1) p2
	p1 (stackChar1 > stackChar2) p2

	p1 YELLOW << "~~~~~ <= ~~~~~ " << RESET p2
	p1 (stackChar1 <= stackChar1) p2
	p1 (stackChar1 <= stackChar2) p2

	p1 YELLOW << "~~~~~ >= ~~~~~ " << RESET p2
	p1 (stackChar1 >= stackChar1) p2
	p1 (stackChar1 >= stackChar2) p2
	p3

	p3
}

void	test_stack( void ) {

	p3

	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~ STACK CONTAINER ~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET p2

	constructor_stack();
	top();
	push_and_pop();
	operator_relationnal_stack();

}

