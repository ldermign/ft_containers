/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 15:42:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "ft_containers.hpp"
#include <iostream>
#include <map>
#include <utility>
#include <list>
#include <stack>
#include <set>
#include "stack.hpp"
#include "map.hpp"
// #include "set.hpp"

# define CCOUT(color, x) std::cout << color << x << CRESET << std::endl;
# define COUT(x) std::cout << x << std::endl;
# define EXCEPTION(x, y) public: class x : public std::exception { const char * what (void) const throw { return y; } }
# define P_TAB(x) print_tab(x);
# define P_TABC(color, x) print_tab_color(x, color);
# define ENABLE_IF(x) typename ft::enable_if<!ft::is_integral<x>::value, x >::type
# define LOG( message ) logError( __LINE__, message );
// # define BLACK 0
// # define RED 1


//Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

//Regular underline text
# define UBLK "\e[4;30m"
# define URED "\e[4;31m"
# define UGRN "\e[4;32m"
# define UYEL "\e[4;33m"
# define UBLU "\e[4;34m"
# define UMAG "\e[4;35m"
# define UCYN "\e[4;36m"
# define UWHT "\e[4;37m"

//Regular background
# define BLKB "\e[40m"
# define REDB "\e[41m"
# define GRNB "\e[42m"
# define YELB "\e[43m"
# define BLUB "\e[44m"
# define MAGB "\e[45m"
# define CYNB "\e[46m"
# define WHTB "\e[47m"

//High intensty background 
# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//High intensty text
# define HBLK "\e[0;90m"
# define HRED "\e[0;91m"
# define HGRN "\e[0;92m"
# define HYEL "\e[0;93m"
# define HBLU "\e[0;94m"
# define HMAG "\e[0;95m"
# define HCYN "\e[0;96m"
# define HWHT "\e[0;97m"

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//Reset
// # define reset "\e[0m"
# define CRESET "\e[0m"
# define COLOR_RESET "\e[0m"

using namespace LIBRARY;



int leak_i = 0;

class LeakClass
{
	public:

		LeakClass()
		{
			ptr = new int;
		}

		LeakClass(const LeakClass& other)
		: ptr(NULL)
		{
			(void)other;
			if (leak_i++ == 10)
				throw std::runtime_error("error leak custom");
			if (ptr)
				delete ptr;
			ptr = new int;
		}

		LeakClass operator=(const LeakClass& rhs)
		{
			(void)rhs;
			if (ptr)
				delete ptr;
			ptr = new int;
			return (*this);
		}

		~LeakClass()
		{
			delete ptr;
		}

		int *ptr;
};


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	CCOUT(YELHB, "                                         GMARY'S TESTS                                         ");
	COUT("\n\n\n")
	CCOUT(UMAG, "NO ARGS = ALL\n0 - VECTOR\n1 - STACK\n2 - MAP\n3 - SET\n4 - PAIR\n");
	std::string arg;
	std::string special_arg;
	// sleep(1);
	if (ac == 3)
	{
		arg = av[1];
		special_arg = av[2];
	}
	else if (ac == 2)
		arg = av[1];
	else
		arg = "all";

	//! NORMAL TESTS FOR VECTOR
//!====================================================================================================================================================
	if (arg == "0" || arg == "vector" || arg == "all")
	{

		COUT("\n\n\n")
		CCOUT(YELHB, "                                         VECTOR TESTS                                         ");
		COUT("\n\n\n")
		

		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		

		LIBRARY::vector<int> myvector;
		LIBRARY::vector<int> myvector2(5);
		LIBRARY::vector<int> myvector3(5, 42);
		LIBRARY::vector<int> myvector4(myvector3);
		LIBRARY::vector<int> myvector5(myvector3.begin(), myvector3.end());
		LIBRARY::vector<std::string> myvector6(5, "hello");

		COUT("size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		COUT("size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT("size: " << myvector4.size() << " capacity: " << myvector4.capacity());
		COUT("size: " << myvector5.size() << " capacity: " << myvector5.capacity());

		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;

		for (LIBRARY::vector<int>::iterator it = myvector4.begin(); it != myvector4.end(); it++)
			std::cout << *it << std::endl;

		for (LIBRARY::vector<int>::iterator it = myvector5.begin(); it != myvector5.end(); it++)
			std::cout << *it << std::endl;

		CCOUT(UMAG, "                                         ASSIGNATION\n");

		COUT("before assignation size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector = myvector3;
		COUT("after assignation size: " << myvector.size() << " capacity: " << myvector.capacity());

		for (LIBRARY::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;

		CCOUT(UMAG, "                                         PUSH BACK\n");
		
		myvector.push_back(89);
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.push_back(90);
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.push_back(91);

		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		myvector.push_back(92);
		myvector.push_back(93);
		myvector.push_back(-94);
		myvector.push_back(-95);
		myvector.push_back(-96);
		myvector.push_back(-97);

		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());

		myvector6.push_back("wesh");
		myvector6.push_back("hell nooo");
		myvector6.push_back("c mort frr");
		myvector6.push_back("wougada");
		
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		

		CCOUT(UMAG, "                                         ITERATORS\n");

		for (LIBRARY::vector<int>::iterator it = myvector.end(); it != myvector.begin(); --it)
			std::cout << *it << std::endl;

		for (LIBRARY::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
			std::cout << *it << std::endl;
		
		LIBRARY::vector<std::string>::iterator ito = myvector6.begin();
		ito++;
		ito++;
		ito--;
		--ito;

		CCOUT(UMAG, "                                         INSERT\n");

		myvector.insert(myvector.begin(), 42);
		myvector.insert(myvector.begin(), 42);
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		for (LIBRARY::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.insert(myvector.begin(), 2, 42);
		for (LIBRARY::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		p1 "testttt" p2
		COUT("before insert with 3 args --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.insert(myvector.begin(), myvector3.begin(), myvector3.end());
		COUT("after insert with 3 args --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		
		CCOUT(UMAG, "                                         ERASE\n");

		COUT("before erase --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.erase(myvector.begin());
		for (LIBRARY::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("after erase --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector3.erase(myvector3.begin(), myvector3.end());
		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("erase --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

		CCOUT(UMAG, "                                         SWAP\n");
		
		myvector3.push_back(42);
		myvector3.push_back(42);
		myvector3.push_back(42);
		myvector.push_back(12);
		myvector.push_back(12);
		
		myvector.swap(myvector3);
		for (LIBRARY::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("swap --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("swap --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

		CCOUT(UMAG, "                                         CLEAR\n");

		myvector6.clear();
		COUT("swap --- size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
			
		CCOUT(UMAG, "                                         AT\n");
		myvector3.at(0) = 42;
		COUT("at --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT(myvector3.at(0));
		COUT("at --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT("back: " << myvector3.back());
		COUT("front: " << myvector3.front());
		for (LIBRARY::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		
		CCOUT(UMAG, "                                         POP BACK\n");
		
		COUT("pop back --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.pop_back();
		for (LIBRARY::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("pop back --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         ASSIGN\n");
		
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.assign(5, 42);
		for (LIBRARY::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		LIBRARY::vector<int>::const_iterator it_const_int = myvector2.begin();
		LIBRARY::vector<int>::const_iterator it_const_end = myvector2.end();

		myvector2.assign(it_const_int, it_const_end);
		for (LIBRARY::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
			
		it_const_int++;
		it_const_end--;
		myvector2.assign(it_const_int, it_const_end);
		for (LIBRARY::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         RESIZE\n");

		COUT("resize --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.resize(10);
		for (LIBRARY::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("resize --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         OPERATOR []\n");

		COUT("operator [] --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2[0] = 42;
		myvector2[1] = 42;
		COUT("operator [] --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
	}
	if (special_arg == "0" )
	{
		try
		{
			LIBRARY::vector<int> myvector(10);
			myvector.push_back(42);
			myvector.at(42);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (special_arg == "10" )
	{
		try
		{
			LIBRARY::vector<int> myvector(10);
			myvector.push_back(42);
			CCOUT(BRED, "exception on reserve")
			myvector.reserve(myvector.max_size() + 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (special_arg == "11" )
	{
		try
		{
			LIBRARY::vector<int> myvector(10);
			myvector.push_back(42);
			CCOUT(BRED, "exception on resize")
			myvector.resize(myvector.max_size() + 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (special_arg == "12" )
	{

		ft::vector<LeakClass> v;
		try
		{
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());
			v.push_back(LeakClass());

		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
//!====================================================================================================================================================
	if (arg == "1" || arg == "stack" || arg == "all")
	{

		COUT("\n\n\n")
		CCOUT(YELHB, "                                         STACK TESTS                                         ");
		COUT("\n\n\n")
		

		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		LIBRARY::map<int, int> map;
		LIBRARY::stack<int, LIBRARY::map<int, int> > mystack_test(map);
		COUT("empty: " << mystack_test.empty());
		COUT("size: " << mystack_test.size());
	
		CCOUT(UMAG, "                                         TEST\n");

		LIBRARY::stack<int> mystack;
		mystack.push(42);
		mystack.push(478);
		mystack.push(389);
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		mystack.pop();
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		LIBRARY::stack<int> mystack2(mystack);
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		mystack2.pop();
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		COUT("empty: " << mystack.empty());
		
	}
//!====================================================================================================================================================
	if (arg == "2" || arg == "map" || arg == "all" )
	{
		COUT("\n\n\n")
		CCOUT(YELHB, "                                         MAP TESTS                                         ");
		COUT("\n\n\n")
		
		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		LIBRARY::map<int, int> map;
		map.insert(LIBRARY::pair<int, int>(42, 42));
		map.insert(LIBRARY::pair<int, int>(478, 478));
		map.insert(LIBRARY::pair<int, int>(389, 389));
		map.insert(LIBRARY::pair<int, int>(443, 443));
		for (LIBRARY::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		LIBRARY::map<int, int> map2(map);
		for (LIBRARY::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		LIBRARY::map<int, int> map3(map2.begin(), map2.end());
		for (LIBRARY::map<int, int>::iterator it = map3.begin(); it != map3.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		LIBRARY::map<int, int> map4(map3.begin(), map3.end(), map3.key_comp());
		for (LIBRARY::map<int, int>::iterator it = map4.begin(); it != map4.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		LIBRARY::map<int, int> map5(map4.begin(), map4.end(), map4.key_comp(), map4.get_allocator());
		for (LIBRARY::map<int, int>::iterator it = map5.begin(); it != map5.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		LIBRARY::map<int, int> map6(map5.begin(), map5.end(), map5.key_comp(), map5.get_allocator());
		for (LIBRARY::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;

		CCOUT(UMAG, "                                         CLEAR\n");

		COUT("size: " << map6.size());
		map6.clear();
		COUT("size: " << map6.size());
		COUT("empty: " << map.empty());
		for (LIBRARY::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		
		CCOUT(UMAG, "                                         OPERATOR\n");

		map6 = map;
		COUT("size: " << map6.size());
		COUT("size: " << map6.size());
		COUT("empty: " << map.empty());
		for (LIBRARY::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map6[42]);
		COUT(map6[-30]);
		COUT(map6[478]);
		map6[478] = 42;

		CCOUT(UMAG, "                                         ITERATORS\n");
		
		for (LIBRARY::map<int, int>::iterator it = map6.begin(); it != map6.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT("reverse iterator");
		for (LIBRARY::map<int, int>::reverse_iterator it = map6.rbegin(); it != map6.rend(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT("const it + decrement"); //!becareful this test can take things in memory so its normal that output is not the same
		// for (LIBRARY::map<int, int>::const_iterator it = map6.end(); it != map6.begin(); --it)
		// 	std::cout << it->first << " " << it->second << std::endl;

		LIBRARY::map<int, int>::const_iterator it_decrement = map6.end();
		--it_decrement;
		for (; it_decrement != map6.begin(); --it_decrement)
			std::cout << it_decrement->first << " " << it_decrement->second << std::endl;

		CCOUT(UMAG, "                                         COUNT\n");
		COUT(map6.count(42));
		COUT(map6.count(4782));
		COUT(map6.count(-478));
		// COUT(map6.count(10000000000)); //BUG: FUCK apres un peu logique mais comment la std traite ca ??

		CCOUT(UMAG, "                                         SIZE\n");
		COUT(map6.size());
		COUT(map6.max_size());
		COUT(map6.empty());
		COUT(map.size());
		COUT(map.max_size());
		COUT(map.empty());
		COUT(map4.size());
		COUT(map4.max_size());
		COUT(map4.empty());
		COUT(map2.size());
		COUT(map2.max_size());
		COUT(map2.empty());
		COUT(map3.size());
		COUT(map3.max_size());
		COUT(map3.empty());

		CCOUT(UMAG, "                                         FIND\n");
		//TODO: when find is not found, it return end() and not begin() like std
		COUT(map6.find(42)->first);
		// COUT(map6.find(4782)->first); //BUG: dont return same value it return the size of the map but need to segfault when the key is string wttff
		// COUT(map6.find(-478)->first);
		// COUT(map6.find(100000)->first);
		COUT(map6.find(478)->first);
		COUT(map6.find(478)->second);
		COUT(map6.find(478)->first);
		// COUT(map6.find(-470)->second);
		LIBRARY::map<std::string, int> map7;
		map7["42"] = 42;
		map7["-42"] = -42;
		map7["0"] = 0;
		COUT(map7.find("42")->first);
		COUT(map7.find("42")->second);
		COUT(map7.find("-42")->first);
		COUT(map7.find("-42")->second);
		// COUT(map7.find("jdfhjdfh")->first); //BUG : segfault on the real one but not on mine
		// COUT(map7.find("jdfhjdfh")->second);
		CCOUT(UMAG, "                                         INSERT\n");
		LIBRARY::map<int, int> map8;
		LIBRARY::map<int, int>::iterator map8_it = map8.begin();

		COUT((map8.insert(map8_it, LIBRARY::pair<int, int>(33333, 33333)))->first);
		COUT(map3.size());
		COUT(map3.max_size());
		// LIBRARY::map<int, int> map8; //!this test is also impossible to create
		// LIBRARY::map<int, int>::iterator map8_it;

		// COUT((map8.insert(map8_it, LIBRARY::pair<int, int>(33333, 33333)))->first);
		map8.insert(LIBRARY::pair<int, int>(42, 42));
		map8.insert(LIBRARY::pair<int, int>(2222, 2222));
		map8.insert(LIBRARY::pair<int, int>(-86, -86));
		COUT(map3.size());
		COUT(map3.max_size());
		for (LIBRARY::map<int, int>::iterator it = map8.begin(); it != map8.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map3.size());
		COUT(map3.max_size());
		map8.insert(map8.begin(), map8.end());
		for (LIBRARY::map<int, int>::iterator it = map8.begin(); it != map8.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		map8.insert(map8.end(), map8.end());
		for (LIBRARY::map<int, int>::iterator it = map8.begin(); it != map8.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		
		CCOUT(UMAG, "                                         ERASE\n");
		LIBRARY::map<int, int> map9(map8);
		map9.erase(map9.begin());
		for (LIBRARY::map<int, int>::iterator it = map9.begin(); it != map9.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map9.size());
		COUT(map9.max_size());
		map9.erase(42);
		for (LIBRARY::map<int, int>::iterator it = map9.begin(); it != map9.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map9.size());
		COUT(map9.max_size());
		map9.erase(map9.begin(), map9.end());
		for (LIBRARY::map<int, int>::iterator it = map9.begin(); it != map9.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map9.size());
		COUT(map9.max_size());
		
		CCOUT(UMAG, "                                         SWAP\n");
		
		map6.swap(map4);
		for (LIBRARY::map<int, int>::iterator it = map6.begin(); it != map6.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		for (LIBRARY::map<int, int>::iterator it = map4.begin(); it != map4.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map6.size());
		COUT(map6.max_size());
		COUT(map4.size());
		COUT(map4.max_size());

		CCOUT(UMAG, "                                         LOWER BOUND\n");
		
		COUT(map4.lower_bound(42)->first);
		COUT(map4.lower_bound(478)->first);
		COUT(map4.lower_bound(-47855)->first);
		COUT(map4.upper_bound(42)->first);
		// COUT(map4.upper_bound(478)->first); //!test cannot be possible because its undefined behavior
		COUT(map4.upper_bound(-47855)->first);
		
		CCOUT(UMAG, "                                         EQUAL RANGE\n");

		LIBRARY::pair<LIBRARY::map<int, int>::iterator, LIBRARY::map<int, int>::iterator> pair1 = map4.equal_range(42);
		COUT(pair1.first->first);	

	}
	//!====================================================================================================================================================
	if (arg == "3" || arg == "set" || arg == "all" )
	{
		// COUT("\n\n\n")
		// CCOUT(YELHB, "                                         SET TESTS                                         ");
		// COUT("\n\n\n")
		
		// CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		// LIBRARY::set<int> set;
		// set.insert(42);
		// set.insert(478);
		// set.insert(389);
		// set.insert(443);
		// for (LIBRARY::set<int>::iterator it = set.begin(); it != set.end(); it++)
		// 	std::cout << *it << std::endl;
		// LIBRARY::set<int> set2(set);
		// for (LIBRARY::set<int>::iterator it = set2.begin(); it != set2.end(); it++)
		// 	std::cout << *it << std::endl;
		// LIBRARY::set<int> set3(set2.begin(), set2.end());
		// for (LIBRARY::set<int>::iterator it = set3.begin(); it != set3.end(); it++)
		// 	std::cout << *it << std::endl;
		// LIBRARY::set<int> set4(set3.begin(), set3.end(), set3.key_comp());
		// for (LIBRARY::set<int>::iterator it = set4.begin(); it != set4.end(); it++)
		// 	std::cout << *it << std::endl;
		// LIBRARY::set<int> set5(set4.begin(), set4.end(), set4.key_comp(), set4.get_allocator());
		// for (LIBRARY::set<int>::iterator it = set5.begin(); it != set5.end(); it++)
		// 	std::cout << *it << std::endl;
		// LIBRARY::set<int> set6(set5.begin(), set5.end(), set5.key_comp(), set5.get_allocator());
		// for (LIBRARY::set<int>::iterator it = set6.begin(); it != set6.end(); it++)
		// 	std::cout << *it << std::endl;

		// CCOUT(UMAG, "                                         CLEAR\n");

		// COUT("size: " << set6.size());
		// set6.clear();
		// COUT("size: " << set6.size());
		// COUT("empty: " << set.empty());
		// for (LIBRARY::set<int>::iterator it = set6.begin(); it != set6.end(); it++)
		// 	std::cout << *it << std::endl;
		
		// CCOUT(UMAG, "                                         OPERATOR\n");

		// set6 = set;
		// COUT("size: " << set6.size());
		// COUT("size: " << set6.size());
		// COUT("empty: " << set.empty());
		// for (LIBRARY::set<int>::iterator it = set6.begin(); it != set6.end(); it++)
		// 	std::cout << *it << std::endl;

		// CCOUT(UMAG, "                                         ITERATORS\n");
		
		// for (LIBRARY::set<int>::iterator it = set6.begin(); it != set6.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT("reverse iterator");
		// for (LIBRARY::set<int>::reverse_iterator it = set6.rbegin(); it != set6.rend(); ++it)
		// 	std::cout << *it << std::endl;
		// // COUT("const it + decrement"); //!becareful this test can take things in memory so its normal that output is not the same
		// // // for (LIBRARY::set<int>::const_iterator it = set6.end(); it != set6.begin(); --it)
		// // // 	std::cout << *it << std::endl;

		// LIBRARY::set<int>::const_iterator it_decrement = set6.end();
		// --it_decrement;
		// for (; it_decrement != set6.begin(); --it_decrement)
		// 	std::cout << *it_decrement << std::endl;

		// CCOUT(UMAG, "                                         COUNT\n");
		// COUT(set6.count(42));
		// COUT(set6.count(4782));
		// COUT(set6.count(-478));

		// CCOUT(UMAG, "                                         SIZE\n");
		// COUT(set6.size());
		// COUT(set6.max_size());
		// COUT(set6.empty());
		// COUT(set.size());
		// COUT(set.max_size());
		// COUT(set.empty());
		// COUT(set4.size());
		// COUT(set4.max_size());
		// COUT(set4.empty());
		// COUT(set2.size());
		// COUT(set2.max_size());
		// COUT(set2.empty());
		// COUT(set3.size());
		// COUT(set3.max_size());
		// COUT(set3.empty());

		// CCOUT(UMAG, "                                         FIND\n");
		// //TODO: when find is not found, it return end() and not begin() like std
		// COUT(*set6.find(42));
		// // COUT(set6.find(4782)); //BUG: dont return same value it return the size of the set but need to segfault when the key is string wttff
		// // COUT(set6.find(-478));
		// // COUT(set6.find(100000));
		// COUT(*set6.find(478));
		// COUT(*set6.find(478));
		// COUT(*set6.find(478));
		// // COUT(set6.find(-470));
		// LIBRARY::set<std::string> set7;
		// set7.insert("42");
		// set7.insert("-42");
		// set7.insert("0");
		// COUT(*set7.find("42"));
		// COUT(*set7.find("42"));
		// COUT(*set7.find("-42"));
		// COUT(*set7.find("-42"));
		// // COUT(set7.find("jdfhjdfh")); //BUG : segfault on the real one but not on mine
		// // COUT(set7.find("jdfhjdfh"));
		// CCOUT(UMAG, "                                         INSERT\n");
		// LIBRARY::set<int> set8;
		// LIBRARY::set<int>::iterator set8_it = set8.begin();

		// COUT((*set8.insert(set8_it, 33333)));
		// COUT(set3.size());
		// COUT(set3.max_size());
		// // // LIBRARY::set<int> set8; //!this test is also impossible to create
		// // // LIBRARY::set<int>::iterator set8_it;

		// // // COUT((set8.insert(set8_it, LIBRARY::pair<int>(33333, 33333)))->first);
		// set8.insert(42);
		// set8.insert(2222);
		// set8.insert(-86);
		// COUT(set3.size());
		// COUT(set3.max_size());
		// for (LIBRARY::set<int>::iterator it = set8.begin(); it != set8.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT(set3.size());
		// COUT(set3.max_size());
		// set8.insert(set8.begin(), set8.end());
		// for (LIBRARY::set<int>::iterator it = set8.begin(); it != set8.end(); ++it)
		// 	std::cout << *it << std::endl;
		// set8.insert(set8.end(), set8.end());
		// for (LIBRARY::set<int>::iterator it = set8.begin(); it != set8.end(); ++it)
		// 	std::cout << *it << std::endl;
		
		// CCOUT(UMAG, "                                         ERASE\n");
		// LIBRARY::set<int> set9(set8);
		// set9.erase(set9.begin());
		// for (LIBRARY::set<int>::iterator it = set9.begin(); it != set9.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT(set9.size());
		// COUT(set9.max_size());
		// set9.erase(42);
		// for (LIBRARY::set<int>::iterator it = set9.begin(); it != set9.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT(set9.size());
		// COUT(set9.max_size());
		// set9.erase(set9.begin(), set9.end());
		// for (LIBRARY::set<int>::iterator it = set9.begin(); it != set9.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT(set9.size());
		// COUT(set9.max_size());
		
		// CCOUT(UMAG, "                                         SWAP\n");
		
		// set6.swap(set4);
		// for (LIBRARY::set<int>::iterator it = set6.begin(); it != set6.end(); ++it)
		// 	std::cout << *it << std::endl;
		// for (LIBRARY::set<int>::iterator it = set4.begin(); it != set4.end(); ++it)
		// 	std::cout << *it << std::endl;
		// COUT(set6.size());
		// COUT(set6.max_size());
		// COUT(set4.size());
		// COUT(set4.max_size());

		// CCOUT(UMAG, "                                         LOWER BOUND\n");
		
		// COUT(*set4.lower_bound(42));
		// COUT(*set4.lower_bound(478));
		// COUT(*set4.lower_bound(-47855));
		// COUT(*set4.upper_bound(42));
		// // COUT(set4.upper_bound(478)); //!test cannot be possible because its undefined behavior
		// COUT(*set4.upper_bound(-47855));
		
		// // CCOUT(UMAG, "                                         EQUAL RANGE\n");

		// // LIBRARY::pair<LIBRARY::set<int>::iterator, LIBRARY::set<int>::iterator> pair1 = set4.equal_range(42);
		// // COUT(pair1.first);	
	}
//!=================================================================================================================================================
	if (arg == "4" || arg == "pair" || arg == "all" )
	{
		COUT("\n\n\n")
		CCOUT(YELHB, "                                         PAIR TESTS                                         ");
		COUT("\n\n\n")
		
		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		LIBRARY::pair<int, int> pair1;
		COUT(pair1.first);
		COUT(pair1.second);
		LIBRARY::pair<int, int> pair2(42, 42);
		COUT(pair2.first);
		COUT(pair2.second);
		LIBRARY::pair<int, int> pair3(pair2);
		COUT(pair3.first);
		COUT(pair3.second);
		LIBRARY::pair<int, int> pair4(LIBRARY::pair<int, int>(42, 42));
		COUT(pair4.first);
		COUT(pair4.second);
		
	}
//!=================================================================================================================================================
	if (special_arg == "impossible")
	{
		LIBRARY::map<int, int> map;
		map.insert(LIBRARY::pair<int, int>(42, 42));
		map.insert(LIBRARY::pair<int, int>(478, 478));
		map.insert(LIBRARY::pair<int, int>(389, 389));
		map.insert(LIBRARY::pair<int, int>(443, 443));

		for (LIBRARY::map<int, int>::const_iterator it = map.end(); it != map.begin(); --it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map.find(4782)->first);

		LIBRARY::map<int, int> map8;
		LIBRARY::map<int, int>::iterator map8_it;

		COUT((map8.insert(map8_it, LIBRARY::pair<int, int>(33333, 33333)))->first);


		LIBRARY::map<std::string, int> map7;
		map7["42"] = 42;
		map7["-42"] = -42;
		map7["0"] = 0;
		COUT(map7.find("jdfhjdfh")->first);
	}
	if (special_arg == "nocompile")
	{
		// LIBRARY::set<int> set6;
		// COUT(set6[42]); //!test cannot compile
	}

}

