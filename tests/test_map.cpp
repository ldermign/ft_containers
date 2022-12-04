/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/04 16:51:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <stdlib.h>
#include <map>
#include <list>
#include <iostream>


using namespace LIBRARY;

template <class Key, class T>
void	print2(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 it->first << " => " << it->second p2;
}



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



p1 "~debut~" p2
	LIBRARY::pair<int, std::string>			my_pair(8, "salut");
p1 "~creation my_pair~" p2
	LIBRARY::map<int, std::string>			test;
p1 "~creation test~" p2
	LIBRARY::map<int, std::string>::iterator	it;
p1 "~creation iterator~" p2


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
		p1 it->first << ", " << it->second p2;
		it++;
// 		p1 "iterator incremented\n";

// #ifndef STD
// 		p1 it.getPointer() p2;
// 		p1 test.end().getPointer() p2;
// #endif

	}
	/*
	p1 "End of display loop" p2
 {
	LIBRARY::map<char,int> mymap;


	if (mymap.begin() != mymap.end())
		p1 "This should not happen\n";

	  mymap['b'] = 100;
	  mymap['a'] = 200;
	  mymap['c'] = 300;

	if (mymap.begin() == mymap.end())
		p1 "This is wrong\n";
  // show content:
  for (LIBRARY::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
    p1 it->first << " => " << it->second p2;

	p1 "Hello there\n";
	for (LIBRARY::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
    p1 it->first << " => " << it->second p2;
	p1 "General Kenobi\n";

	LIBRARY::map<char, int>::const_iterator it = mymap.begin();
	LIBRARY::map<char, int>::const_iterator ti = mymap.end();
	p1 "Wupwup\n";

	it++;
	++it;
	it--;
	--it;
	p1 "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	p1 "Trump is a kiddo\n";
	LIBRARY::map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
    	p1 it->first << " => " << it->second p2;
		it++;
	}
 }
 */
////////////////////////////////////


}