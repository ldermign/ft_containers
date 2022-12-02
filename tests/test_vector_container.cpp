/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_container.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 15:50:31 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list>
#include <vector>
#include "vector.hpp"
#include <iostream>

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


//Reset
// # define reset "\e[0m"
# define CRESET "\e[0m"
# define COLOR_RESET "\e[0m"


#define TESTED_TYPE std::string

// #define T_SIZE_TYPE typename LIBRARY::vector<T>::value_type
#define T_SIZE_TYPE size_t



/*
single element (1)
	iterator insert (iterator position, const value_type& val);

fill (2)
    void insert (iterator position, size_type n, const value_type& val);

range (3)
	template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);
*/


template <typename T>
void	printVector(LIBRARY::vector< T > const &vct, std::string str) {

	p1 str << "\n";
	for (size_t i = 0 ; i < vct.size() ; i++)
		p1 "\t-> " << vct[i] p2
}

void	is_empty(LIBRARY::vector< int > const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <typename T>
void	printSize(LIBRARY::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename LIBRARY::vector<T>::const_iterator it = vct.begin();
		typename LIBRARY::vector<T>::const_iterator ite = vct.end();
		std::cout << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	p3
	std::cout << "###############################################" << std::endl;
	p3
}


void	checkErase(LIBRARY::vector< std::string > const &vct,
					LIBRARY::vector< std::string >::const_iterator const &it)
{

	// p1 "avant" p2
	
	static int	i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	p1 "2 SIZE vct = " << vct.size() p2
}


		# define CCOUT(color, x) std::cout << color << x << CRESET << std::endl;
# define COUT(x) std::cout << x << std::endl;
# define EXCEPTION(x, y) public: class x : public std::exception { const char * what (void) const throw { return y; } }
# define P_TAB(x) print_tab(x);
# define P_TABC(color, x) print_tab_color(x, color);
# define ENABLE_IF(x) typename ft::enable_if<!ft::is_integral<x>::value, x >::type
# define LOG( message ) logError( __LINE__, message );


void	test_vector_container( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	
	{

	LIBRARY::vector<TESTED_TYPE> vct(8);
	LIBRARY::vector<TESTED_TYPE> vct2;
	LIBRARY::vector<TESTED_TYPE>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	printSize(vct, true);

	std::cout << "push_back():\n" << std::endl;

	vct.push_back("One long string");
	vct2.push_back("Another long string");

	printSize(vct);
	printSize(vct2);

	vct.pop_back();
	vct2.pop_back();

	printSize(vct);
	printSize(vct2);


	{
// if (arg == "0" || arg == "vector" || arg == "all")
	// {

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
	/*
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
	*/


	p3

	}
	
}