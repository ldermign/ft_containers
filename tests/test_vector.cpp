/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/09 11:03:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
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
	p1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" p2
	p3
		
}

void constructor( void ) {

	p1 RED << "~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~ " << RESET p2
	p3

	std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2

	LIBRARY::vector< std::string >	vctString1;
	for (size_t i = 0 ; i < 4 ; i++)
		vctString1.push_back(s1[i]);
	LIBRARY::vector< std::string >	vctString2;
	for (size_t i = 0 ; i < 4 ; i++)
		vctString2.push_back(s2[i]);
	LIBRARY::vector< std::string >	vctString3(42);
	LIBRARY::vector< std::string >	vctString4(vctString1);
	LIBRARY::vector< std::string >	vctString5(vctString2.begin() + 1, vctString2.end() - 1);
	LIBRARY::vector< std::string >	vctString6(s3, s3 + sizeof(s3) / sizeof(std::string));

	printVector("vctString1", vctString1);
	printVector("vctString2", vctString2);
	printVector("vctString3", vctString3);
	printVector("vctString4", vctString4);
	printVector("vctString5", vctString5);
	printVector("vctString5", vctString6);
	p3

}

void operator_equal( void ) {

	p1 RED << "~~~~~~~~~~ OPERATOR = ~~~~~~~~~~ " << RESET p2
	p3

	std::string s5[] = {"On ", "va ", "ecrire ", "une ", "longue ", "phrase ", "comme ", "ca ", "c'est ", "ok !"}; // 10

	LIBRARY::vector< std::string >	vctString1;
	LIBRARY::vector< std::string >	vctString2;
	for (size_t i = 0 ; i < 10 ; i++)
		vctString1.push_back(s5[i]);
	printVector("vctString1", vctString1);
	p1 "vctString2 before operator = " p2
	printVector("vctString2", vctString2);
	vctString2 = vctString1;
	p1 "vctString2 after operator = " p2
	printVector("vctString2", vctString2);
	p3

}

void getteurs( void ) {

	p1 RED << "~~~~~~~~~~ GETTERS ~~~~~~~~~~ " << RESET p2
	p3

	int i1[] = {42, 0, -111, 666, 1337, -222, 4, -9, 9}; // 9

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

void iterators( void ) {

	p1 RED << "~~~~~~~~~~ ITERATORS ~~~~~~~~~~ " << RESET p2
	p3

	char c1[] = {'L', 'i', 'e', 'n', 'a'}; // 

	p1 YELLOW << "~~~~~ ACCESSORS ~~~~~ " << RESET p2
	LIBRARY::vector< char >	vctChar1;
	for (size_t i = 0 ; i < 2 ; i++)
		vctChar1.push_back(c1[i]);
	LIBRARY::vector< char >::iterator		it1 = vctChar1.begin();
	LIBRARY::vector< char >::const_iterator	it2 = vctChar1.begin();
	LIBRARY::vector< char >::iterator		it3 = vctChar1.end() - 1;
	LIBRARY::vector< char >::const_iterator	it4 = vctChar1.end() - 1;
	LIBRARY::vector< char >::reverse_iterator		it5 = vctChar1.rbegin();
	LIBRARY::vector< char >::const_reverse_iterator	it6 = vctChar1.rbegin();
	LIBRARY::vector< char >::reverse_iterator		it7 = vctChar1.rend();
	LIBRARY::vector< char >::const_reverse_iterator	it8 = vctChar1.rend();

	p1 "\tBegin = " << *it1 p2
	p1 "\tBegin const = " << *it2 p2
	p1 "\tEnd = " << *it3 p2
	p1 "\tEnd const = " << *it4 p2
	p1 "\tReverse begin = " << *it5 p2
	p1 "\tReverse begin const = " << *it6 p2
	p1 "\tReverse end = " << *it7 p2
	p1 "\tReverse end const = " << *it8 p2

	p3
	p1 YELLOW << "~~~~~ MODIFIERS ~~~~~ " << RESET p2
	{
		LIBRARY::vector< int >	test;
		test.push_back(42);
		test.push_back(123);
		test.push_back(-99);
		test.push_back(1007);
		test.push_back(11111);
		LIBRARY::vector< int >::iterator		first = test.begin();
		LIBRARY::vector< int >::iterator		second = test.begin() + 1;
		LIBRARY::vector< int >::iterator		last = test.begin() + 3;

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << first[i] << " " << RESET;
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << *(first) p2
		p1 "pre incrementation -> before [" << *first << "] - during [" << *++first << "] - after [" << *first << "]" p2
		first = test.begin();
		p1 "post incrementation -> before [" << *first << "] - during [" << *first++ << "] - after [" << *first << "]" p2
		first = test.begin();
		p1 "pre decrementation second -> before [" << *second << "] - during [" << *--second << "] - after [" << *second << "]" p2
		second = test.begin() + 1;
		p1 "post decrementation second -> before [" << *second << "] - during [" << *second-- << "] - after [" << *second << "]" p2
		second = test.begin() + 1;
		p1 "operator second += 2 -> " << *(second += 2) p2
		p1 "operator last -= 2 -> " << *(last -= 2) p2
		p1 "operator first + 1 -> " << *first << " - " << *(first + 1) p2
		p1 "operator last - 1 -> " << *last << " - " << *(last - 1) p2
		p1 "operator first + last -> " << *first + *last p2
		p1 "operator first - last -> " << *first - *last p2
		p1 "operator first[0] - first[3] -> " << first[0] << " - " << first[3] p2
		p1 "operator first < second -> " << (first < second) p2
		p1 "operator first > second -> " << (first > second) p2
		p1 "operator first <= second -> " << (first <= second) p2
		p1 "operator first >= second -> " << (first >= second) p2
	}
	p3
	p1 YELLOW << "~~~~~ REVERSE ~~~~~ " << RESET p2
	{
		LIBRARY::vector< int >	test;
		test.push_back(1);
		test.push_back(6);
		test.push_back(4);
		LIBRARY::vector< int >::reverse_iterator		first = test.rbegin();
		LIBRARY::vector< int >::reverse_iterator		second = test.rbegin(); // + 1;
		LIBRARY::vector< int >::reverse_iterator		last = test.rend();

		for (size_t i = 0 ; i < test.size() ; i++)
			p1 RED << first[i] << " " << RESET;
		p3
		
		p1 "operator *first - *second - *last -> " << *first << " - " << *second << " - " << *last p2
		p1 "operator first[0] - first[2] -> " << first[0] << " - " << first[2] p2
		p1 "pre incrementation -> before [" << *first << "] - during [" << *++first << "] - after [" << *first << "]" p2
		first = test.rbegin();
		p1 "post incrementation -> before [" << *first << "] - during [" << *first++ << "] - after [" << *first << "]" p2
		first = test.rbegin();
		p1 "pre decrementation second -> before [" << *second << "] - during [" << *--second << "] - after [" << *second << "]" p2
		second = test.rbegin(); // + 1;
		p1 "post decrementation second -> before [" << *second << "] - during [" << *second-- << "] - after [" << *second << "]" p2
		second = test.rbegin(); // + 1;
		second += 1;
		p1 "operator first += 2 -> " << *(first += 2) p2
		p1 "operator last -= 2 -> " << *(last -= 2) p2
		p1 "operator last + 1 -> " << *last << " - " << *(last += 1) p2;
		p1 "operator first - 1 -> " << *first << " - " << *(first -= 1) p2
		p1 "operator first == second -> " << (first == second) p2
		p1 "operator first != second -> " << (first != second) p2
		p1 "operator first + second -> " << *first + *second p2
		p1 "operator first - second -> " << first - second p2
		p1 "operator first < second -> " << (first < second) p2
		p1 "operator first > second -> " << (first > second) p2
		p1 "operator first <= second -> " << (first <= second) p2
		p1 "operator first >= second -> " << (first >= second) p2
	}

	p3
}

void reserve_and_resize( void ) {

	p1 RED << "~~~~~~~~~~ MEMORY ~~~~~~~~~~ " << RESET p2
	p3

	int i1[] = {42, 0, -111, 666, 1337, -222, 4, -9, 9}; // 9
	int i2[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4}; // 9

	p1 YELLOW << "~~~~~ RESERVE ~~~~~ " << RESET p2
	LIBRARY::vector< int >	vctInt1;
	vctInt1.reserve(9);
	for (size_t i = 0 ; i < 9 ; i++)
		vctInt1.push_back(i2[i]);
	printVector("vctInt1", vctInt1);
	vctInt1.reserve(13);
	for (size_t i = 9 ; i < 13 ; i++)
		vctInt1.push_back(i);
	printVector("vctInt1", vctInt1);
	vctInt1.reserve(2);
	printVector("vctInt1", vctInt1);
	vctInt1.reserve(vctInt1.capacity() + 42);
	printVector("vctInt1", vctInt1);
	vctInt1.reserve(vctInt1.size() * 42);
	printVector("vctInt1", vctInt1);
	vctInt1.reserve(0);
	printVector("vctInt1", vctInt1);

	p1 YELLOW << "~~~~~ RESIZE ~~~~~ " << RESET p2
	LIBRARY::vector< int >	vctInt2;
	for (int i = 0 ; i < 9 ; i++)
		vctInt2.push_back(i1[i]);
	printVector("vctInt2", vctInt2);
	vctInt2.resize(12, 42);
	printVector("vctInt2", vctInt2);
	vctInt2.resize(0, 7);
	// std::error
	try {
		printVector("vctInt2", vctInt2);
		vctInt2.resize(4578941561541561, 3);
	}
	catch (std::exception &e) {
		p1 e.what() p2
	}
	printVector("vctInt2", vctInt2);
	vctInt2.resize(0, 0);
	printVector("vctInt2", vctInt2);
	vctInt2.resize(14, 14);
	for (int i = 0 ; i < 9 ; i++)
		vctInt2.push_back(i1[i]);
	printVector("vctInt2", vctInt2);

	p3
}

void add_values( void ) {

	p1 RED << "~~~~~~~~~~ ADD VALUES ~~~~~~~~~~ " << RESET p2
	p3

	std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2

	p1 YELLOW << "~~~~~ PUSH_BACK ~~~~~ " << RESET p2
	LIBRARY::vector< std::string >	vctString1;
	p1 GREEN << "vctString1 before -> " << RESET p2
	printVector("vctString1", vctString1);
	for (size_t i = 0 ; i < 4 ; i++)
		vctString1.push_back(s1[i]);
	p1 GREEN << "vctString1 after -> " << RESET p2
	printVector("vctString1", vctString1);
	LIBRARY::vector< std::string >	vctString2;
	p1 GREEN << "vctString2 before -> " << RESET p2
	printVector("vctString2", vctString2);
	for (size_t i = 0 ; i < 4 ; i++)
		vctString2.push_back(s2[i]);
	p1 GREEN << "vctString2 after -> " << RESET p2
	printVector("vctString2", vctString2);
	p3

	p1 YELLOW << "~~~~~ POP_BACK ~~~~~ " << RESET p2
	p1 GREEN << "vctString1 before -> " << RESET p2
	printVector("vctString1", vctString1);
	for (size_t i = 0 ; i < 2 ; i++)
		vctString1.pop_back();
	p1 GREEN << "vctString1 after -> " << RESET p2
	printVector("vctString1", vctString1);
	p3

	p1 YELLOW << "~~~~~ INSERT WITH POSITION AND VALUE ~~~~~ " << RESET p2
	LIBRARY::vector< std::string >	vctString3;
	p1 GREEN << "vctString3 before -> " << RESET p2
	for (size_t i = 0 ; i < 2 ; i++)
		vctString1.push_back(s3[i]);
	printVector("vctString3", vctString3);
	vctString3.insert(vctString3.begin(), "EN PREMIER - ");
	printVector("vctString3", vctString3);
	vctString3.insert(vctString3.end() - 1, "EN AVANT DERNIER");
	printVector("vctString3", vctString3);
	p3

	p1 YELLOW << "~~~~~ INSERT WITH POSITION, LENGTH AND VALUE ~~~~~ " << RESET p2
	p1 GREEN << "vctString2 before -> " << RESET p2
	printVector("vctString2", vctString2);
	vctString2.insert(vctString2.begin() + 2, 2, " et une fois !");
	p1 GREEN << "vctString2 after -> " << RESET p2
	printVector("vctString2", vctString2);
	vctString2.insert(vctString2.end(), 1, " et de deux !");
	p1 GREEN << "vctString2 after second call -> " << RESET p2
	printVector("vctString2", vctString2);
	p3

	p1 YELLOW << "~~~~~ INSERT WITH RANGE ITERATOR ~~~~~ " << RESET p2
	LIBRARY::vector< std::string >	vctString4;
	p1 GREEN << "vctString4 before -> " << RESET p2
	printVector("vctString4", vctString4);
	vctString4.insert(vctString4.begin(), vctString2.begin(), vctString2.begin() + 2);
	vctString4.insert(vctString4.begin() + 1, vctString1.begin() + 3, vctString1.end());
	p1 GREEN << "vctString2 after 2 insert range -> " << RESET p2
	printVector("vctString2", vctString2);
	p3

	p3
}

void modifiers( void ) {

	p1 RED << "~~~~~~~~~~ MODIFIERS ~~~~~~~~~~ " << RESET p2
	p3

	int i1[] = {42, 0, -111, 666, 1337, -222, 4, -9, 9}; // 9
	int i2[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4}; // 9
	int i4[] = {1, 2, 4, 8, 16, 32, 64, 128, 256}; // 9

	p1 YELLOW << "~~~~~ SWAP ~~~~~ " << RESET p2
	LIBRARY::vector< int >	vctInt1;
	for (size_t i = 0 ; i < 9 ; i++)
		vctInt1.push_back(i2[i]);
	LIBRARY::vector< int >	vctInt2;
	for (size_t i = 0 ; i < 9 ; i++)
		vctInt2.push_back(i1[i]);
	p1 GREEN << "vctInt1 before swap -> " << RESET p2
	printVector("vctInt1", vctInt1);
	p1 GREEN << "vctInt2 before swap -> " << RESET p2
	printVector("vctInt2", vctInt2);
	vctInt1.swap(vctInt2);
	p1 GREEN << "vctInt1 after swap -> " << RESET p2
	printVector("vctInt1", vctInt1);
	p1 GREEN << "vctInt2 after swap -> " << RESET p2
	printVector("vctInt2", vctInt2);
	p3

	p1 YELLOW << "~~~~~ ASSIGN COUNT AND VALUE ~~~~~ " << RESET p2
	LIBRARY::vector< int >	vctInt3;
	for (size_t i = 0 ; i < 9 ; i++)
		vctInt3.push_back(i4[i]);
	p1 GREEN << "vctInt3 before assign -> " << RESET p2
	printVector("vctInt3", vctInt3);
	vctInt3.assign(3, 42);
	p1 GREEN << "vctInt3 after assign -> " << RESET p2
	printVector("vctInt3", vctInt3);
	p3

	p1 YELLOW << "~~~~~ ASSIGN RANGE ITERATOR ~~~~~ " << RESET p2
	p1 GREEN << "vctInt3 before assign with range -> " << RESET p2
	printVector("vctInt3", vctInt3);
	vctInt3.assign(i4 + 1, i4 + 6);
	p1 GREEN << "vctInt3 after assign with range -> " << RESET p2
	printVector("vctInt3", vctInt3);
	p3

}

void data_acces( void ) {

	p1 RED << "~~~~~~~~~~ DATA ACCESS ~~~~~~~~~~ " << RESET p2
	p3

	std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2
	std::string s4[] = {"Et ", "un ", "bonjour ", "a ", "tous !"}; // 5

	p1 YELLOW << "~~~~~ [] ~~~~~ " << RESET p2
	LIBRARY::vector< std::string >	vctString1;
	for (size_t i = 0 ; i < 5 ; i++)
		vctString1.push_back(s4[i]);
	printVector("vctString1", vctString1);
	p1 "reference at = " p2
	p1 "[1] = " << vctString1[1] << " [4] = " << vctString1[4] p2
	const LIBRARY::vector< std::string >	vctString1cpy(s2, s2 + 3);
	printVector("vctString1cpy", vctString1cpy);
	p1 "const reference [] = " p2
	p1 "[1] = " << vctString1cpy[1] << " [4] = " << vctString1cpy[4] p2
	p3

	p1 YELLOW << "~~~~~ AT ~~~~~ " << RESET p2
	p1 "reference at = " p2
	try {
		p1 vctString1.at(vctString1.size() - 1) p2
		p1 vctString1.at(vctString1.size() + 1) p2
	}
	catch (const std::exception &e) {
		p1 e.what() p2
	}
	p1 "const reference at = " p2
	try {
		p1 vctString1cpy.at(vctString1cpy.size() - 1) p2
		p1 vctString1cpy.at(vctString1cpy.size() + 1) p2
	}
	catch (const std::exception &e) {
		p1 e.what() p2
	}
	p3

	p1 YELLOW << "~~~~~ FRONT ~~~~~ " << RESET p2
	LIBRARY::vector< std::string >			vctString2(s1, s1 + 4);
	LIBRARY::vector< std::string >			vctString3(s2, s2 + 4);
	const LIBRARY::vector< std::string >	vctString4(s3, s3 + 2);
	const LIBRARY::vector< std::string >	vctString5(s4, s4 + 5);
	p1 "front vctString2 = " << vctString2.front() p2
	p1 "front vctString3 = " << vctString3.front() p2
	p1 "const front vctString2 = " << vctString2.front() p2
	p1 "const front vctString3 = " << vctString3.front() p2

	p3

	p1 YELLOW << "~~~~~ BACK ~~~~~ " << RESET p2
	p1 "back vctString2 = " << vctString2.back() p2
	p1 "back vctString3 = " << vctString3.back() p2
	p1 "const back vctString4 = " << vctString4.back() p2
	p1 "const back vctString5 = " << vctString5.back() p2
	p3
}

void clean ( void ) {

	p1 RED << "~~~~~~~~~~ CLEAN ~~~~~~~~~~ " << RESET p2
	p3

	std::string s4[] = {"Et ", "un ", "bonjour ", "a ", "tous !"}; // 5
	std::string s5[] = {"On ", "va ", "ecrire ", "une ", "longue ", "phrase ", "comme ", "ca ", "c'est ", "ok !"}; // 10

	LIBRARY::vector< std::string >	vctString1;
	for (size_t i = 0 ; i < 10 ; i++)
		vctString1.push_back(s5[i]);

	p1 YELLOW << "~~~~~ ERASE ITERATOR POSITION ~~~~~ " << RESET p2
	p1 "before erase position = " p2
	printVector("vctString1", vctString1);
	vctString1.erase(vctString1.begin() + 6);
	p1 "after erase position = " p2
	printVector("vctString1", vctString1);
	
	p1 YELLOW << "~~~~~ ERASE ITERATOR RANGE ~~~~~ " << RESET p2
	p1 "before erase iterator range = " p2
	printVector("vctString1", vctString1);
	vctString1.erase(vctString1.begin() + 2, vctString1.end());
	p1 "after erase iterator range = " p2
	printVector("vctString1", vctString1);
	p3

	p1 YELLOW << "~~~~~ CLEAR ~~~~~ " << RESET p2
	p1 "before clear = " p2
	printVector("vctString1", vctString1);
	vctString1.clear();
	p1 "after clear = " p2
	printVector("vctString1", vctString1);
	LIBRARY::vector< std::string >	vctString2;
	for (size_t i = 0 ; i < 5 ; i++)
		vctString2.push_back(s4[i]);
	p1 "before clear = " p2
	printVector("vctString2", vctString2);
	vctString2.clear();
	p1 "after clear = " p2
	printVector("vctString2", vctString2);
	p3

}

void operator_relationnal( void ) {

	p1 RED << "~~~~~~~~~~ OPERATOR RELATIONNAL ~~~~~~~~~~ " << RESET p2
	p3

	char c2[] = {'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 's'}; // 10
	char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'}; // 8

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

void	test_vector( void ) {

	p3

	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET p2

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