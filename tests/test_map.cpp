/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/09 10:23:06 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <stdlib.h>
#include <map>
#include <list>
#include <iostream>
#include <iomanip>

template< typename T >
std::string	printPair( const T &iterator, std::ostream &o = std::cout )
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	return ("");
}

template< class Key, class T >
void	printMap( std::string name, LIBRARY::map< Key, T > &tmp ) {

	p1 BLUE << "map " << name << RESET << " = ";
	p3
	p1 "empty = " << tmp.empty() p2
	p1 "size = " << tmp.size() p2
	p1 "max_size = " << tmp.max_size() p2
	for (typename LIBRARY::map< Key, T >::iterator it = tmp.begin(); it != tmp.end(); it++)
		p1 it->first << " => " << it->second p2
}

template< class T >
void	cmp( const T &lhs, const T &rhs ) {

	static int i = 0;

	p1 "############### [" << i++ << "] ###############" p2
	p1 "equal -> " << (lhs == rhs) << " | different -> " << (lhs != rhs) p2
	p1 "inferior -> " << (lhs < rhs) << " | inferior and equal -> " << (lhs <= rhs) p2
	p1 "greater -> " << (lhs > rhs) << " | greater and equal -> " << (lhs >= rhs) p2
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

void map_key_and_value_comp( void ) {

	p1 RED << "~~~~~~~~~~ KEY AND VALUE COMP ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< char, int >					map1;
	LIBRARY::map< char, int >::key_compare		map1Key = map1.key_comp();
	LIBRARY::map< char, int >::value_compare	map1Val = map1.value_comp();
	map1['a'] = 1;
	map1['c'] = 3;
	map1['l'] = 12;
	map1['z'] = 26;
	printMap("map1", map1);
	char 						low = map1.begin()->first;
	LIBRARY::pair< char, int >	high = *map1.rbegin();
	

	p1 YELLOW << "~~~~~ KEY COMP ~~~~~ " << RESET p2
	LIBRARY::map< char, int >::iterator		it = map1.begin();
	for (; it != map1.end() && map1Key(it->first, low) ; it++) {
		p1 it->first << " is greater than " << low p2
	}
	if (it != map1.end())
		p1 it->first << " is not lower than " << low p2

	p3
	p1 YELLOW << "~~~~~ VALUE COMP ~~~~~ " << RESET p2
	LIBRARY::map< char, int >::iterator		it2 = map1.begin();
	for (; it2 != map1.end() && map1Val(*it2, high) ; it2++) {
		p1 it2->first << " is greater than " << high.second p2
	}
	if (it2 != map1.end())
		p1 it2->first << " is not higher than " << high.second p2
	p3
}

void map_operations( void ) {

	p1 RED << "~~~~~~~~~~ OPERATIONS ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< std::string, int >	amis;
	amis["Elisa"] = 1;
	amis["Sirine"] = 1;
	amis["Sarra"] = 1;
	amis["Delphine"] = 1;
	amis["Lenny"] = 1;
	amis["Roxane"] = 1;
	amis["Joan"] = 0;
	amis["Matthieu"] = 0;
	amis["Mathias"] = 0;
	amis["Benji"] = 0;
	amis["Xavier"] = 0;
	LIBRARY::map< std::string, int >::iterator			it;
	LIBRARY::map< std::string, int >::iterator			itNON;
	LIBRARY::map< std::string, int >::const_iterator	itC;
	LIBRARY::map< std::string, int >::const_iterator	itCNON;
	printMap("amis", amis);

	p1 YELLOW << "~~~~~ FIND ~~~~~ " << RESET p2
	p1 "iterator = " p2
	it = amis.find("Elisa");
	itNON = amis.find("Elise");
	p1 "const_iterator = " p2
	itC = amis.find("Lenny");
	itCNON = amis.find("Lennie");

	p1 YELLOW << "~~~~~ COUNT ~~~~~ " << RESET p2
	p1 "count = " << amis.count("Joan") p2
	p1 "count = " << amis.count("Jean") p2


	LIBRARY::map< std::string, std::string >	pays;
	pays["France"] = "Paris";
	pays["Espagne"] = "Madrid";
	pays["Angleterre"] = "Londres";
	pays["Italie"] = "Rome";
	pays["Chypres"] = "Nicosie";
	pays["Malte"] = "La Valette";
	pays["Suisse"] = "Berne";
	pays["Allemagne"] = "Berlin";
	const LIBRARY::map< std::string, std::string >	pays2(pays);
	printMap("pays", pays);

	p1 YELLOW << "~~~~~ LOWER BOUND ~~~~~ " << RESET p2
	p1 "lower_bound(\"Malte\")->first = " << pays.lower_bound("Malte")->first p2
	p1 "lower_bound(\"Inde\")->first = " << pays.lower_bound("Inde")->first p2
	p1 "lower_bound(\"Espagne\")->first = " << pays.lower_bound("Espagne")->first p2
	p1 "const -> " p2
	p1 "lower_bound(\"Malte\")->first = " << pays2.lower_bound("Malte")->first p2
	p1 "lower_bound(\"Inde\")->first = " << pays2.lower_bound("Inde")->first p2
	p1 "lower_bound(\"Espagne\")->first = " << pays2.lower_bound("Espagne")->first p2
	p3

	p1 YELLOW << "~~~~~ UPPER BOUND ~~~~~ " << RESET p2
	p1 "upper_bound(\"Malte\")->first = " << pays.upper_bound("Malte")->first p2
	p1 "upper_bound(\"Inde\")->first = " << pays.upper_bound("Inde")->first p2
	p1 "upper_bound(\"Espagne\")->first = " << pays.upper_bound("Espagne")->first p2
	p1 "const -> " p2
	p1 "upper_bound(\"Malte\")->first = " << pays2.upper_bound("Malte")->first p2
	p1 "upper_bound(\"Inde\")->first = " << pays2.upper_bound("Inde")->first p2
	p1 "upper_bound(\"Espagne\")->first = " << pays2.upper_bound("Espagne")->first p2
	p3

	p1 YELLOW << "~~~~~ EQUAL RANGE ~~~~~ " << RESET p2
	LIBRARY::pair< LIBRARY::map< std::string, std::string >::iterator, LIBRARY::map< std::string, std::string >::iterator > ret;
	LIBRARY::pair< LIBRARY::map< std::string, std::string >::iterator, LIBRARY::map< std::string, std::string >::iterator > ret2;
	ret = pays.equal_range("France");
	ret2 = pays.equal_range("Pologne");
	p1 "equal range ok = " << ret.first->first p2
	p1 "equal range not ok = " << ret2.first->first p2

	p3
}

void map_allocator( void ) {

	p1 RED << "~~~~~~~~~~ ALLOCATOR ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< int, std::string >		map;
	LIBRARY::pair< const int, std::string >	*ptr_pair;
	LIBRARY::pair< const int, std::string >	pair;
	printMap("map", map);

	p1 "ptr_pair = map.get_allocator().allocate(1)" p2
	ptr_pair = map.get_allocator().allocate(1);
	p1 "pair.second = \"one\"" << std::endl;
	pair.second = "one";
	p1 "map.get_allocator().construct(ptr_pair, pair)" p2
	map.get_allocator().construct(ptr_pair, pair);
	p1 "ptr_pair->second = " << ptr_pair->second p2
	p1 "map.get_allocator().destroy(ptr_pair)" p2
	map.get_allocator().destroy(ptr_pair);
	p1 "map.get_allocator().deallocate(ptr_pair, 1)" p2
	map.get_allocator().deallocate(ptr_pair, 1);
	p3
}

void map_clean ( void ) {

	p1 RED << "~~~~~~~~~~ CLEAN ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< std::string, std::string >	pays;
	pays["France"] = "Paris";
	pays["Espagne"] = "Madrid";
	pays["Angleterre"] = "Londres";
	pays["Italie"] = "Rome";
	pays["Chypres"] = "Nicosie";
	pays["Malte"] = "La Valette";
	pays["Suisse"] = "Berne";
	pays["Allemagne"] = "Berlin";

	p1 YELLOW << "~~~~~ ERASE KEY ~~~~~ " << RESET p2
	p1 "pays before -> " p2
	printMap("pays", pays);
	pays.erase("France");
	p1 "pays after -> " p2
	printMap("pays", pays);

	p1 YELLOW << "~~~~~ ERASE ITERATOR POSITION ~~~~~ " << RESET p2
	LIBRARY::map< std::string, std::string >::iterator	second_to_del;
	second_to_del = pays.begin();
	second_to_del++;
	p1 "pays before -> " p2
	printMap("pays", pays);
	pays.erase(second_to_del);
	p1 "pays after -> " p2
	printMap("pays", pays);
	
	p1 YELLOW << "~~~~~ ERASE ITERATOR RANGE ~~~~~ " << RESET p2
	LIBRARY::map< std::string, std::string >::iterator	second;
	LIBRARY::map< std::string, std::string >::iterator	before_last;
	second = pays.begin();
	second++;
	before_last = pays.end();
	before_last--;
	before_last--;
	p1 "pays before -> " p2
	printMap("pays", pays);
	pays.erase(second, before_last);
	p1 "pays after -> " p2
	printMap("pays", pays);

	p1 YELLOW << "~~~~~ CLEAR ~~~~~ " << RESET p2
	p1 "pays before -> " p2
	printMap("pays", pays);
	pays.clear();
	p1 "pays after -> " p2
	printMap("pays", pays);
	p3

}

void map_relationnal_operator( void ) {

	p1 RED << "~~~~~~~~~~ RELATIONNAL OPERATOR ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::map< std::string, std::string >	pays;
	pays["France"] = "Paris";
	pays["Espagne"] = "Madrid";
	pays["Angleterre"] = "Londres";
	pays["Italie"] = "Rome";
	pays["Chypres"] = "Nicosie";
	pays["Malte"] = "La Valette";
	pays["Suisse"] = "Berne";
	pays["Allemagne"] = "Berlin";
	LIBRARY::map< std::string, std::string >	pays2;
	pays["Portugal"] = "Lisbonne";
	pays["Inde"] = "New Dehli";
	pays["Australie"] = "Canberra";
	pays["Etats-Unis"] = "Washington";
	pays["Canada"] = "Ottawa";
	pays["Japon"] = "Tokyo";
	pays["Bresil"] = "Brasilia";
	pays["Luxembourg"] = "Luxembourg";

	cmp(pays, pays2);
	cmp(pays, pays);
	cmp(pays2, pays2);
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
	map_key_and_value_comp();
	map_operations();
	map_allocator();
	map_clean();
	map_relationnal_operator();

	p3


}