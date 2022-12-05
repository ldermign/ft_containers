/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/05 11:07:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <stdlib.h>
#include <map>
#include <list>
#include <iostream>

#include <iomanip>


# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"


using namespace LIBRARY;
template <class Key, class T>
void	print(LIBRARY::map<Key, T>& lst)
{
	p1 "printing a map : \n";
	for (typename LIBRARY::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 it->first << " => " << it->second p2
}




void	test_map( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ MAP CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2

	p1 "/* ********************************************************************** */" << _END p2
	p1 std::endl;


	LIBRARY::map<std::string, int> mymap;
	print(mymap);



	p1 std::endl;
	p1 "mymap.max_size(): " << (mymap.max_size() > 10000) p2
	print(mymap);
	p1 std::endl;


	print(mymap);
	mymap.insert(LIBRARY::pair<std::string, int>("ft", 42));

	print(mymap);
	mymap.insert(LIBRARY::pair<std::string, int>("one", 1));


	LIBRARY::map<std::string, int>::iterator mit;
	LIBRARY::map<std::string, int>::iterator it;
	// print(mymap);
	// it = mymap.lower_bound("aaa");
	// print(mymap);
	// p1 std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second p2
	// p1 std::endl;
	// print(mymap);
	// it = mymap.lower_bound("one");
	// print(mymap);
	// p1 std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second p2
	// p1 std::endl;
	// print(mymap);
	// it = mymap.lower_bound("oae");
	// print(mymap);
	// p1 std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second p2
	// p1 std::endl;
	// print(mymap);
	// it = mymap.lower_bound("ft");
	// print(mymap);
	// p1 std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second p2
	// p1 std::endl;
	// print(mymap);
	// it = mymap.lower_bound("zzz");
	// print(mymap);
	
	// if (it == mymap.end())
	// 	p1 std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" p2
	// p1 std::endl;
	// print(mymap);
	// it = mymap.upper_bound("aaa");
	
	// print(mymap);
	// p1 std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second p2;
	// p1 std::endl;
	// print(mymap);
	// it = mymap.upper_bound("oae");
	// print(mymap);
	// p1 std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second p2;
	// p1 std::endl;
	// print(mymap);
	// it = mymap.upper_bound("one");
	
	// if (it == mymap.end())
	// 	p1 std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" p2
	// print(mymap);
	// p1 std::endl;
	// it = mymap.upper_bound("ft");
	// print(mymap);
	// p1 std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second p2;
	// p1 std::endl;
	// print(mymap);
	// it = mymap.upper_bound("zzz");
	
	// if (it == mymap.end())
	// 	p1 std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" p2
	// print(mymap);
	// p1 std::endl;

	// print(mymap);
	// mymap.erase("undefined");
	// print(mymap);
	// mymap.erase("ft");
	// print(mymap);
	// p1 _WHITE << "# double clear" << _END p2
	// mymap.clear();
	// print(mymap);
	// mymap.clear();
	// print(mymap);
	// mymap["lol"];
	// print(mymap);
	// mymap.insert(LIBRARY::pair<std::string, int>("xD", 123));
	// print(mymap);
	// mymap.insert(mymap.end(), LIBRARY::pair<std::string, int>("uch", 442));
	// print(mymap);
	// mymap.insert(mymap.begin(), LIBRARY::pair<std::string, int>("uch", 22));
	// print(mymap);
	// mymap.insert(mymap.end(), LIBRARY::pair<std::string, int>("uch", 23));
	// print(mymap);
	// mymap.insert(LIBRARY::pair<std::string, int>("uch", 23));
	// print(mymap);
	// mymap["lol"] = 8;


	// print(mymap);
	map<std::string, int> map2;

	// print(mymap);
	// print(map2);
	// print(mymap);
	// p1 "empty line\n";
	// print(map2);
	// p1 "empty line2\n";

	swap(mymap, map2);
	p1 "empty line3\n";
	print(mymap);
	p1 "empty line4\n";
	print(map2);
	p1 "empty line5\n";
	mymap = map2;
	print(mymap);
	print(map2);

	p1 std::setw(40) << "map == map2: " << (mymap == map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;

/*

	mymap.clear();
	print(mymap);
	print(map2);

	mymap["satan"] = 666;
	print(mymap);
	print(map2);
	p1 std::setw(40) << "mymap == map2: " << (mymap == map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;
	p1 std::setw(40) << "mymap <= map2: " << (mymap <= map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;
	p1 std::setw(40) << "mymap >= map2: " << (mymap >= map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;
	p1 std::setw(40) << "mymap > map2: " << (mymap > map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;
	p1 std::setw(40) << "mymap < map2: " << (mymap > map2) p2
	print(mymap);
	print(map2);
	p1 std::endl;

*/

}