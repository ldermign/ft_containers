/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/26 19:20:50 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <map>
#include <list>
#include "map.hpp"
#include <iostream>
#include "red_black_tree.hpp"
#include "pair.hpp"


#define _pair LIBRARY::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
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

template <typename T1, typename T2>
void	printReverse(LIBRARY::map<T1, T2> &mp)
{
	typename LIBRARY::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}


#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class T>
void	is_empty(T const &mp)
{
	std::cout << "is_empty: " << mp.empty() << std::endl;
}



void	test_map( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ MAP CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2

	// ft::RedBlackTree< int, std::less< int > > elisa;
	// elisa.insert(42);
	// elisa.insert(1);
	// elisa.insert(-111);
	// elisa.insert(123);
	// elisa.insert(-2);

	// elisa.printTree();

	

	////////////////////////////////////////////
	// ft::map< int, int > elisa2;
	// elisa2.insert(ft::pair< int, int >(42, 57));
	// elisa2.insert(ft::pair< int, int >(-123, 0));
	// elisa2.insert(ft::pair< int, int >(4, 9898));
	
	// elisa2.printTree();

	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	LIBRARY::map<T1, T2> mp(lst.begin(), lst.end());
		p1 "~~~~~~~~~~~~~~~~~~~~~LA ??~~~~~~~~~~~~~~~~~~~" p2
	LIBRARY::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	(void)ite; (void)it;
	p1 "~~~~~~~~~~~~~~~~~~~~~MERDE~~~~~~~~~~~~~~~~~~~" p2
	// ft::pair< T1, T2 > wesh = *(--(--ite));
	LIBRARY::map<T1 , T2> mp_range(it, --(--ite));
		p1 "~~~~~~~~~~~~~~~~~~~~~EUHHH~~~~~~~~~~~~~~~~~~~" p2
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	p1 "avant = " p2
	for (size_t i = 0 ; i < mp.size() ; i++)
		p1 mp[i] << " ";
	p3

	

	it = mp.begin(); ite = --(--mp.end());
	LIBRARY::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	p1 "apres = " p2
	for (size_t i = 0 ; i < mp.size() ; i++)
		p1 mp[i] << " ";
	p3

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	// printSize(mp_range);
	// printSize(mp_copy);

	// mp = mp_copy;
	// mp_copy = mp_range;
	// mp_range.clear();

	// std::cout << "\t-- PART TWO --" << std::endl;
	// printSize(mp);
	// printSize(mp_range);
	// printSize(mp_copy);


}