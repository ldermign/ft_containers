/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/07 22:32:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

#include "test_utils.hpp"

#include <ctime>
#include <unistd.h>

template< class T >
void printVector(std::string name, LIBRARY::vector< T > const &src) {

	typename LIBRARY::vector< T >::const_iterator	it = src.begin();
	typename LIBRARY::vector< T >::const_iterator	it2 = src.end();

	p1 BLUE << "vector " << name << RESET << " = ";
	for (; it != it2 ; it++)
		p1 *it << " ";
	p3
	
	p1 "size = " << src.size() p2
	p1 "max_size = " << src.max_size() p2
	p1 "capacity = " << src.capacity() p2
	p1 "empty = " << src.empty() p2
		
}

void constructor( void ) {

	LIBRARY::vector< std::string >	vctString1;
	for (size_t i = 0 ; i < s1->length() ; i++)
		vctString1.push_back(s1[i]);
	LIBRARY::vector< std::string >	vctString2;
	for (size_t i = 0 ; i < s2->length() ; i++)
		vctString2.push_back(s2[i]);
	LIBRARY::vector< std::string >	vctString3(42);
	LIBRARY::vector< std::string >	vctString4(vctString1);
	LIBRARY::vector< std::string >	vctString5(vctString2.begin() + 1, vctString2.end() - 1);
	LIBRARY::vector< std::string >	vctString6(s3, s3 + sizeof(s3) / sizeof(std::string));
	LIBRARY::vector< Test >			vctTest1;

	printVector("vctString1", vctString1);
	printVector("vctString2", vctString2);
	printVector("vctString3", vctString3);
	printVector("vctString4", vctString4);
	printVector("vctString5", vctString5);
	printVector("vctString5", vctString6);
	printVector("vctTest1", vctTest1);

}

void operator_equal( void ) {

}

void getteurs( void ) {

}

void iterators( void ) {

}

void reserve_and_resize( void ) {

}

void add_values( void ) {

}

void modifiers( void ) {

}

void data_acces( void ) {

}

void clean ( void ) {

}

void operator_relationnal( void ) {

}




void	test_vector( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2

	srand((unsigned)time(NULL) * getpid());

	constructor();
	operator_equal();
	getteurs();
	iterators();
	reserve_and_resize();
	add_values();
	modifiers();
	data_acces();
	clean();
	operator_relationnal();
	
}