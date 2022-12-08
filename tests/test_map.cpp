/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/09 00:11:37 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <stdlib.h>
#include <map>
#include <list>
#include <iostream>
#include <iomanip>

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{(void)nl;
	o << "key: " << iterator->first << " | value: " << iterator->second;
	// if (nl)
	// 	o << std::endl;
	return ("");
}


using namespace LIBRARY;
template <class Key, class T>
void	printMap(std::string name, LIBRARY::map<Key, T>& lst)
{
	p1 BLUE << "map " << name << RESET << " = ";
	p3
	for (typename LIBRARY::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 it->first << " => " << it->second p2
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}


template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "equal -> " << (lhs == rhs) << " | different -> " << (lhs != rhs) << std::endl;
	std::cout << "inferior -> " << (lhs < rhs) << " | inferior and equal -> " << (lhs <= rhs) << std::endl;
	std::cout << "greater -> " << (lhs > rhs) << " | greater and equal -> " << (lhs >= rhs) << std::endl;
}

struct classCompare {

	bool operator() ( const char &lhs, const char &rhs ) const {
		return lhs < rhs;
	}
};

void map_constructor( void ) {

	p1 RED << "~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~ " << RESET p2
	p3

	std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2

	p1 "constructor basic = " p2
	LIBRARY::map< int, std::string >	map1;
	printMap("map1", map1);
	map1[42] = "test";
	map1[3] = "ok";
	map1[9] = "parfait";
	map1[57] = "non";
	map1[111] = "liena";
	map1[-123] = "dermigny";
	printMap("map1", map1);

	p1 "constructor by copy = " p2
	LIBRARY::map< int, std::string >	map2(map1);
	printMap("map2", map2);

	p1 "constructor by range of iterator = " p2
	LIBRARY::map< int, std::string >	map3(map1.begin(), map1.end());
	printMap("map3", map3);

	p1 "constructor with compare = " p2
	LIBRARY::map< int, std::string, classCompare >	map4;
	printMap("map3", map3);

	p3

}


void map_iterators( void ) {

	p1 RED << "~~~~~~~~~~ ITERATORS ~~~~~~~~~~ " << RESET p2
	p3

	p1 YELLOW << "~~~~~ ACCESSORS ~~~~~ " << RESET p2

	LIBRARY::map< int, char >	map1;
	map1[7] = 'l';
	map1[6] = 'd';
	map1[5] = 'e';
	map1[4] = 'r';
	map1[3] = 'm';
	map1[2] = 'i';
	map1[1] = 'g';
	map1[0] = 'n';
	printMap("map1", map1);

	LIBRARY::map< int, char >::iterator					it1 = map1.begin();
	LIBRARY::map< int, char >::const_iterator			it2 = map1.begin();
	LIBRARY::map< int, char >::iterator					it3 = map1.end();
	LIBRARY::map< int, char >::const_iterator			it4 = map1.end();
	LIBRARY::map< int, char >::reverse_iterator			it5 = map1.rbegin();
	LIBRARY::map< int, char >::const_reverse_iterator	it6 = map1.rbegin();
	LIBRARY::map< int, char >::reverse_iterator			it7 = map1.rend();
	LIBRARY::map< int, char >::const_reverse_iterator	it8 = map1.rend();

	it3--;it4--;it7--;it8--;
	p1 "\tBegin = [" << it1->first << "][" << it1->second << "]" p2
	p1 "\tBegin const = [" << it2->first << "][" << it2->second << "]" p2
	p1 "\tEnd = [" << it3->first << "][" << it3->second << "]" p2
	p1 "\tEnd const = [" << it4->first << "][" << it4->second << "]" p2
	p1 "\tReverse begin = [" << it5->first << "][" << it5->second << "]" p2
	p1 "\tReverse begin const = [" << it6->first << "][" << it6->second << "]" p2
	p1 "\tReverse end = [" << it7->first << "][" << it7->second << "]" p2
	p1 "\tReverse end const = [" << it8->first << "][" << it8->second << "]" p2

	p3
	p1 YELLOW << "~~~~~ MODIFIERS ~~~~~ " << RESET p2
	{
		LIBRARY::map< int, char >::iterator		first = map1.begin();
		LIBRARY::map< int, char >::iterator		second = map1.begin();
		LIBRARY::map< int, char >::iterator		last = map1.begin();
		second++;
		last++;
		last++;
		last++;

		printMap("map1", map1);
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << printPair(first) p2
		p1 "pre incrementation -> before [" << printPair(first) << "] - during [" << printPair(++first) << "] - after [" << printPair(first) << "]" p2
		first = map1.begin();
		p1 "post incrementation -> before [" << printPair(first) << "] - during [" << printPair(first++) << "] - after [" << printPair(first) << "]" p2
		first = map1.begin();
		p1 "pre decrementation second -> before [" << printPair(second) << "] - during [" << printPair(--second) << "] - after [" << printPair(second) << "]" p2
		second = map1.begin();second++;
		p1 "post decrementation second -> before [" << printPair(second) << "] - during [" << printPair(second--) << "] - after [" << printPair(second) << "]" p2
		second = map1.begin();second++;
	}

	p1 YELLOW << "~~~~~ REVERSE ~~~~~ " << RESET p2
	{
		LIBRARY::reverse_iterator< LIBRARY::map< int, char >::iterator >	ret = map1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::map< int, char >::iterator >	first = map1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::map< int, char >::iterator >	second = map1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::map< int, char >::iterator >	last = map1.rbegin();
		second++;
		last++;
		last++;
		last++;

		printMap("map1", map1);
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << printPair(first) p2
		p1 "pre incrementation -> before [" << printPair(first) << "] - during [" << printPair(++first) << "] - after [" << printPair(first) << "]" p2
		first = ret;
		p1 "post incrementation -> before [" << printPair(first) << "] - during [" << printPair(first++) << "] - after [" << printPair(first) << "]" p2
		first = ret;
		p1 "pre decrementation second -> before [" << printPair(second) << "] - during [" << printPair(--second) << "] - after [" << printPair(second) << "]" p2
		second = ret;second++;
		p1 "post decrementation second -> before [" << printPair(second) << "] - during [" << printPair(second--) << "] - after [" << printPair(second) << "]" p2
		second = ret;second++;
	}

	p3
}

void map_capacity( void ) {

	p1 RED << "~~~~~~~~~~ CAPACITY ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< int, char >	map1;
	map1[0] = 's';
	map1[1] = 'a';
	map1[2] = 'l';
	map1[3] = 'u';
	map1[4] = 't';
	map1[5] = ' ';
	map1[6] = ':';
	map1[7] = ')';
	// printMap("map1", map1);

	p1 "map full" p2
	p1 "empty = " << map1.empty() p2
	p1 "size = " << map1.size() p2
	p1 "max_size = " << map1.max_size() p2

	p1 "map empty" p2
	LIBRARY::map< int, int >	map2;
	p1 "empty = " << map1.empty() p2
	p1 "size = " << map1.size() p2
	p1 "max_size = " << map1.max_size() p2

	p3
}

void map_element_access( void ) {

	p1 RED << "~~~~~~~~~~ ELEMENT_ACCESS ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< int, std::string >	map1;
	map1[6] = "c'est une ";
	map1[123] = "serie de ";
	map1[-2] = "std :: ";
	map1[0] = "string et ";
	map1[92] = "c'est tout ";
	printMap("map1", map1);
	p1 "access element -2 -> " << map1[-2] << " 92 -> " << map1[92] p2
	p1 "access element 0 -> " << map1[0] << " 6 -> " << map1[6] p2

	p3
}

void map_modifiers( void ) {

	p1 RED << "~~~~~~~~~~ MODIFIERS ~~~~~~~~~~ " << RESET p2
	p3

	p1 YELLOW << "~~~~~ SWAP ~~~~~ " << RESET p2
	LIBRARY::map< std::string, std::string >	homme;
	LIBRARY::map< std::string, std::string >	femme;
	homme["genre"] = "masculin";
	homme["prenom"] = "Jean-Claude";
	homme["nom"] = "Van Damme";
	homme["age"] = "infini";
	homme["atout"] = "adore (vraiment beaucoup) l'eau";
	femme["genre"] = "feminin";
	femme["prenom"] = "Liena";
	femme["nom"] = "Dermigny";
	femme["age"] = "24";
	femme["atout"] = "aime bien l'eau (mais d'un facon saine)";
	p1 "before swap -> " p2
	printMap("homme", homme);
	printMap("femme", femme);
	homme.swap(femme);
	p1 "after swap -> " p2
	printMap("homme", homme);
	printMap("femme", femme);

	p1 YELLOW << "~~~~~ INSERT VALUE ~~~~~ " << RESET p2
	LIBRARY::map< int, std::string >	map1;
	LIBRARY::map< int, std::string >	map2;
	map1[17] = "Marie";
	map1[5] = "Petunia";
	map1[24] = "Liena";
	map1[22] = "Sirine";
	map1[20] = "Elisa";
	map1[24] = "Roxane";
	map1[6] = "Angelina";
	p1 "before insert -> " p2
	printMap("map1", map1);
	map1.insert(LIBRARY::make_pair< int, std::string >(99, "Tasha"));
	p1 "after insert -> " p2
	printMap("map1", map1);

	p1 YELLOW << "~~~~~ INSERT POSITION AND VALUE ~~~~~ " << RESET p2
	p1 "before insert -> " p2
	printMap("map1", map1);
	map1.insert(map1.begin(), LIBRARY::make_pair< int, std::string >(7, "Ludmilla"));
	p1 "after insert -> " p2
	printMap("map1", map1);

	p1 YELLOW << "~~~~~ INSERT RANGE ITERATOR ~~~~~ " << RESET p2
	LIBRARY::map< int, std::string >::iterator		it1 = map1.begin();
	LIBRARY::map< int, std::string >::iterator		it2 = map1.end();
	it1++;it2--;it1++;it2--;
	p1 "before insert -> " p2
	printMap("map1", map1);
	map1.insert(it1, it2);
	p1 "after insert -> " p2
	printMap("map1", map1);

	p3

}


void map_operations( void ) {

	p1 RED << "~~~~~~~~~~ OPERATIONS ~~~~~~~~~~ " << RESET p2
	p3

	// std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	// std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	// std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2

	// p1 YELLOW << "~~~~~ PUSH_BACK ~~~~~ " << RESET p2
	// LIBRARY::map< std::string >	mapString1;
	// p1 GREEN << "mapString1 before -> " << RESET p2
	// printmap("mapString1", mapString1);
	// for (size_t i = 0 ; i < 4 ; i++)
	// 	mapString1.push_back(s1[i]);
	// p1 GREEN << "mapString1 after -> " << RESET p2
	// printmap("mapString1", mapString1);
	// LIBRARY::map< std::string >	mapString2;
	// p1 GREEN << "mapString2 before -> " << RESET p2
	// printmap("mapString2", mapString2);
	// for (size_t i = 0 ; i < 4 ; i++)
	// 	mapString2.push_back(s2[i]);
	// p1 GREEN << "mapString2 after -> " << RESET p2
	// printmap("mapString2", mapString2);
	// p3

	// p1 YELLOW << "~~~~~ POP_BACK ~~~~~ " << RESET p2
	// p1 GREEN << "mapString1 before -> " << RESET p2
	// printmap("mapString1", mapString1);
	// for (size_t i = 0 ; i < 2 ; i++)
	// 	mapString1.pop_back();
	// p1 GREEN << "mapString1 after -> " << RESET p2
	// printmap("mapString1", mapString1);
	// p3

	// p1 YELLOW << "~~~~~ INSERT WITH POSITION AND VALUE ~~~~~ " << RESET p2
	// LIBRARY::map< std::string >	mapString3;
	// p1 GREEN << "mapString3 before -> " << RESET p2
	// for (size_t i = 0 ; i < 2 ; i++)
	// 	mapString1.push_back(s3[i]);
	// printmap("mapString3", mapString3);
	// mapString3.insert(mapString3.begin(), "EN PREMIER - ");
	// printmap("mapString3", mapString3);
	// mapString3.insert(mapString3.end() - 1, "EN AVANT DERNIER");
	// printmap("mapString3", mapString3);
	// p3

	// p1 YELLOW << "~~~~~ INSERT WITH POSITION, LENGTH AND VALUE ~~~~~ " << RESET p2
	// p1 GREEN << "mapString2 before -> " << RESET p2
	// printmap("mapString2", mapString2);
	// mapString2.insert(mapString2.begin() + 2, 2, " et une fois !");
	// p1 GREEN << "mapString2 after -> " << RESET p2
	// printmap("mapString2", mapString2);
	// mapString2.insert(mapString2.end(), 1, " et de deux !");
	// p1 GREEN << "mapString2 after second call -> " << RESET p2
	// printmap("mapString2", mapString2);
	// p3

	// p1 YELLOW << "~~~~~ INSERT WITH RANGE ITERATOR ~~~~~ " << RESET p2
	// LIBRARY::map< std::string >	mapString4;
	// p1 GREEN << "mapString4 before -> " << RESET p2
	// printmap("mapString4", mapString4);
	// mapString4.insert(mapString4.begin(), mapString2.begin(), mapString2.begin() + 2);
	// mapString4.insert(mapString4.begin() + 1, mapString1.begin() + 3, mapString1.end());
	// p1 GREEN << "mapString2 after 2 insert range -> " << RESET p2
	// printmap("mapString2", mapString2);
	// p3

	p3
}

void map_allocator( void ) {

	p1 RED << "~~~~~~~~~~ ALLOCATOR ~~~~~~~~~~ " << RESET p2
	p3

	// std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	// std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	// std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2
	// std::string s4[] = {"Et ", "un ", "bonjour ", "a ", "tous !"}; // 5

	// p1 YELLOW << "~~~~~ [] ~~~~~ " << RESET p2
	// LIBRARY::map< std::string >	mapString1;
	// for (size_t i = 0 ; i < 5 ; i++)
	// 	mapString1.push_back(s4[i]);
	// printmap("mapString1", mapString1);
	// p1 "reference at = " p2
	// p1 "[1] = " << mapString1[1] << " [4] = " << mapString1[4] p2
	// const LIBRARY::map< std::string >	mapString1cpy(s2, s2 + 3);
	// printmap("mapString1cpy", mapString1cpy);
	// p1 "const reference [] = " p2
	// p1 "[1] = " << mapString1cpy[1] << " [4] = " << mapString1cpy[4] p2
	// p3

	// p1 YELLOW << "~~~~~ AT ~~~~~ " << RESET p2
	// p1 "reference at = " p2
	// try {
	// 	p1 mapString1.at(mapString1.size() - 1) p2
	// 	p1 mapString1.at(mapString1.size() + 1) p2
	// }
	// catch (const std::exception &e) {
	// 	p1 e.what() p2
	// }
	// p1 "const reference at = " p2
	// try {
	// 	p1 mapString1cpy.at(mapString1cpy.size() - 1) p2
	// 	p1 mapString1cpy.at(mapString1cpy.size() + 1) p2
	// }
	// catch (const std::exception &e) {
	// 	p1 e.what() p2
	// }
	// p3

	// p1 YELLOW << "~~~~~ FRONT ~~~~~ " << RESET p2
	// LIBRARY::map< std::string >			mapString2(s1, s1 + 4);
	// LIBRARY::map< std::string >			mapString3(s2, s2 + 4);
	// const LIBRARY::map< std::string >	mapString4(s3, s3 + 2);
	// const LIBRARY::map< std::string >	mapString5(s4, s4 + 5);
	// p1 "front mapString2 = " << mapString2.front() p2
	// p1 "front mapString3 = " << mapString3.front() p2
	// p1 "const front mapString2 = " << mapString2.front() p2
	// p1 "const front mapString3 = " << mapString3.front() p2

	// p3

	// p1 YELLOW << "~~~~~ BACK ~~~~~ " << RESET p2
	// p1 "back mapString2 = " << mapString2.back() p2
	// p1 "back mapString3 = " << mapString3.back() p2
	// p1 "const back mapString4 = " << mapString4.back() p2
	// p1 "const back mapString5 = " << mapString5.back() p2
	p3
}

void map_clean ( void ) {

	p1 RED << "~~~~~~~~~~ CLEAN ~~~~~~~~~~ " << RESET p2
	p3

	// std::string s4[] = {"Et ", "un ", "bonjour ", "a ", "tous !"}; // 5
	// std::string s5[] = {"On ", "va ", "ecrire ", "une ", "longue ", "phrase ", "comme ", "ca ", "c'est ", "ok !"}; // 10

	// LIBRARY::map< std::string >	mapString1;
	// for (size_t i = 0 ; i < 10 ; i++)
	// 	mapString1.push_back(s5[i]);

	p1 YELLOW << "~~~~~ ERASE KEY ~~~~~ " << RESET p2

	p1 YELLOW << "~~~~~ ERASE ITERATOR POSITION ~~~~~ " << RESET p2
	// p1 "before erase position = " p2
	// printmap("mapString1", mapString1);
	// mapString1.erase(mapString1.begin() + 6);
	// p1 "after erase position = " p2
	// printmap("mapString1", mapString1);
	
	p1 YELLOW << "~~~~~ ERASE ITERATOR RANGE ~~~~~ " << RESET p2
	// p1 "before erase iterator range = " p2
	// printmap("mapString1", mapString1);
	// mapString1.erase(mapString1.begin() + 2, mapString1.end());
	// p1 "after erase iterator range = " p2
	// printmap("mapString1", mapString1);
	// p3

	p1 YELLOW << "~~~~~ CLEAR ~~~~~ " << RESET p2
	// p1 "before clear = " p2
	// printmap("mapString1", mapString1);
	// mapString1.clear();
	// p1 "after clear = " p2
	// printmap("mapString1", mapString1);
	// LIBRARY::map< std::string >	mapString2;
	// for (size_t i = 0 ; i < 5 ; i++)
	// 	mapString2.push_back(s4[i]);
	// p1 "before clear = " p2
	// printmap("mapString2", mapString2);
	// mapString2.clear();
	// p1 "after clear = " p2
	// printmap("mapString2", mapString2);
	p3

}

void map_relationnal_operator( void ) {

	p1 RED << "~~~~~~~~~~ RELATIONNAL OPERATOR ~~~~~~~~~~ " << RESET p2
	p3

	// char c2[] = {'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 's'}; // 10
	// char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'}; // 8

	// LIBRARY::map< char >	mapChar1(c2, c2 + 10);
	// LIBRARY::map< char >	mapChar2(c3, c3 + 8);
	// printmap("mapChar1", mapChar1);
	// printmap("mapChar2", mapChar2);

	// p1 YELLOW << "~~~~~ == ~~~~~ " << RESET p2
	// p1 (mapChar1 == mapChar1) p2
	// p1 (mapChar1 == mapChar2) p2

	// p1 YELLOW << "~~~~~ != ~~~~~ " << RESET p2
	// p1 (mapChar1 != mapChar1) p2
	// p1 (mapChar1 != mapChar2) p2

	// p1 YELLOW << "~~~~~ < ~~~~~ " << RESET p2
	// p1 (mapChar1 < mapChar1) p2
	// p1 (mapChar1 < mapChar2) p2

	// p1 YELLOW << "~~~~~ > ~~~~~ " << RESET p2
	// p1 (mapChar1 > mapChar1) p2
	// p1 (mapChar1 > mapChar2) p2

	// p1 YELLOW << "~~~~~ <= ~~~~~ " << RESET p2
	// p1 (mapChar1 <= mapChar1) p2
	// p1 (mapChar1 <= mapChar2) p2

	// p1 YELLOW << "~~~~~ >= ~~~~~ " << RESET p2
	// p1 (mapChar1 >= mapChar1) p2
	// p1 (mapChar1 >= mapChar2) p2
	p3
}


void	test_map( void ) {

	p3
		
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~ MAP CONTAINER ~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET p2

	map_constructor();
	map_iterators();
	map_capacity();
	map_element_access();
	map_modifiers();

	map_operations();
	map_allocator();
	map_clean();
	map_relationnal_operator();

	p3


}