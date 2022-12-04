/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/04 15:28:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <stdlib.h>
#include <map>
#include <list>
#include <iostream>



template <class Key, class T>
void	print(LIBRARY::map<Key, T>& lst)
{
	for (typename LIBRARY::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 *it << ' ';
	p1 '\n';
}




void	test_map( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ MAP CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2




	LIBRARY::pair<int, std::string>			my_pair(8, "salut");
	LIBRARY::map<int, std::string>			test;
	LIBRARY::map<int, std::string>::iterator	it;

	test.insert(my_pair);
	test.insert(LIBRARY::pair<int, std::string>(-4, "bar"));
	test.insert(LIBRARY::pair<int, std::string>(2, "machin"));
	test.insert(LIBRARY::pair<int, std::string>(3, "foo"));
	test.insert(LIBRARY::pair<int, std::string>(746, "Marcel"));
	test.insert(LIBRARY::pair<int, std::string>(1, "truc"));
	it = test.begin();
	p1 '\n';

	while (it != test.end())
	{
		// p1 "start of while\n";
		p1 it->first << ", " << it->second << '\n';
		it++;
// 		p1 "iterator incremented\n";

// #ifndef STD
// 		p1 it.getPointer() << '\n';
// 		p1 test.end().getPointer() << '\n';
// #endif

	}
	p1 "End of display loop\n";




}