/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/05 16:04:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"


template <class T>
void	print(LIBRARY::vector<LIBRARY::vector<T> >& lst)
{
	for (typename LIBRARY::vector<LIBRARY::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename LIBRARY::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			p1 *it2 << ' ';
		p3
	}
}

template <class T>
void	print(LIBRARY::vector<T>& lst)
{
	for (typename LIBRARY::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 *it << ' ';
	p3
}
class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { p1 "Default constructor" p2 } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { p1 "Int constructor" p2 (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <class T>
void	print_vector(LIBRARY::vector<T> &test)
{
	typename LIBRARY::vector<T>::iterator		beg = test.begin();
	typename LIBRARY::vector<T>::iterator		end = test.end();
	p1 "size : " << test.size() << ", capacity : " << test.capacity() p2
	for (typename LIBRARY::vector<T>::iterator it = beg; it != end; it++)
	{
		p1 *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			p1 std::endl;
	}
	p1 std::endl;
}

template <class T>
void	push_pop_back_tests(void)
{
	p1 std::endl << "PUSH BACK & POP BACK TESTS" p2
	LIBRARY::vector<T> test;

	p1 "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() p2
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		p1 test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			p1 std::endl;
	}
	print_vector<T>(test);
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	print_vector<T>(test);
}

template <class T>
void	resize_tests(void)
{
	p1 std::endl << "RESIZE TESTS" p2
	LIBRARY::vector<T> test(12, 12);

	test.resize(72);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.resize(100);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.resize(4170);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.resize(171, 12);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.resize(62);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
}

template <class T>
void	insert_tests()
{
	p1 std::endl << "INSERT TESTS" p2
	LIBRARY::vector<T> test(1, 1);
	LIBRARY::vector<T> test2(5, 5);

	p1"la"p2
	test.insert(test.begin(), 200, 12);
	p1"ca timeout"p2
	print_vector<T>(test);
	test.insert(test.begin() + 12, 200, 30);
	print_vector<T>(test);
	test.insert(test.end(), 12, 50);
	print_vector<T>(test);
	test.insert(test.end() - 1, 0, 60);
	print_vector<T>(test);
	test.insert(test.end() - 1, 1, 70);
	print_vector<T>(test);
	test.insert(test.begin() + 412, test2.begin(), test2.end());
	print_vector<T>(test);
	test.insert(test.begin() + 6, test2.begin(), test2.end());
	print_vector<T>(test);
	test.insert(test.end(), test2.begin(), test2.end());
	print_vector<T>(test);
}

template <class T>
void	reserve_tests(void)
{
	p1 std::endl << "RESERVE TESTS" p2
	LIBRARY::vector<T> test(65, 7);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.reserve(12);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.reserve(66);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.reserve(128);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.reserve(1023);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	test.reserve(10252);
	p1 "s: " << test.size() << ", c: " << test.capacity() p2
	try
	{
		test.reserve(test.max_size() + 1);
	}
	catch(std::length_error &le)
	{
		p1 "length error" p2
	}
	catch(std::exception &e)
	{
		p1 "error : " << e.what() p2
	}
	print_vector<T>(test);
}

template <class T>
void	copy_swap_tests(void)
{
	p1 std::endl << "COPY && SWAP TESTS" p2
	LIBRARY::vector<T> test;
	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
	LIBRARY::vector<T> test_copy(test);
	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	print_vector<T>(test_copy);
	LIBRARY::vector<T> test_range(test.begin() + 20, test.begin() + 30);
	print_vector<T>(test_range);
	test_copy.swap(test);
	print_vector<T>(test);
	print_vector<T>(test_copy);
	test_copy.swap(test_range);
	print_vector<T>(test_range);
	print_vector<T>(test_copy);
	test.swap(test_copy);
	print_vector<T>(test);
	print_vector<T>(test_copy);
}

template <class T>
void	reverse_it_tests(void)
{
	p1 std::endl << "REVERSE IT TESTS" p2
	LIBRARY::vector<T> test;
	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
	typename LIBRARY::vector<T>::reverse_iterator		revbeg = test.rbegin();
	for (typename LIBRARY::vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
	{
		p1 *it << " ";
		if (!((revbeg - it) % 10) && it != revbeg)
			p1 std::endl;
	}
	p1 *(test.rbegin() + 2) p2
	p1 *(test.rend() - 8) p2
	p1 (test.rbegin() == revbeg) p2
	revbeg++;
	p1 *revbeg p2
	p1 (test.rbegin() == test.rend()) p2
	p1 (test.rbegin() <= test.rbegin()) p2
	p1 (test.rbegin() < test.rend()) p2
	p1 (test.rbegin() >= test.rend()) p2
	revbeg += 3;
	p1 *revbeg p2
	p1 std::endl;
}

template <class T>
void	erase_clear_tests(void)
{
	p1 std::endl << "ERASE && CLEAR TESTS" p2
	LIBRARY::vector<T> test(31, 12);
	test.erase(test.begin(), test.begin() + 5);
	print_vector<T>(test);
	test.erase(test.begin() + 12, test.begin() + 16);
	print_vector<T>(test);
	test.clear();
	print_vector<T>(test);
}

void	max_size_tests(void)
{
	p1 std::endl << "MAX SIZE TESTS" p2
	LIBRARY::vector<int> test(31, 12);
	LIBRARY::vector<std::string> test2;
	LIBRARY::vector<long long int> test3;
	LIBRARY::vector<Awesome> test4;
	LIBRARY::vector<unsigned int> test5(12, 340);
	p1 test.max_size() p2
	p1 test2.max_size() p2
	p1 test3.max_size() p2
	p1 test4.max_size() p2
	p1 test5.max_size() p2
}

void	awesome_tests(void)
{
	p1 std::endl << "AWESOME TESTS" p2
	LIBRARY::vector<Awesome> test(21, 12);
	print_vector<Awesome>(test);
	LIBRARY::vector<Awesome> test2;
	print_vector<Awesome>(test2);
	test2.push_back(12);
	test2.push_back(8);
	test2.push_back(16);
	print_vector<Awesome>(test2);
	p1 "SAME ?" << (test.begin() + 1 == test2.begin() + 1) p2
	test.assign(test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test = test2;
	print_vector<Awesome>(test);
	p1 "SAME ?" << (test.begin() + 1 == test2.begin() + 1) p2
	test.insert(test.end(), test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test.insert(test.begin(), test2.begin(), test2.end());
	test2 = test;
	print_vector<Awesome>(test);
	p1 "end awesome test" p2
}







void	test_vector( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	
	{

// push_pop_back_tests<int>();
// 	resize_tests<int>();
	insert_tests<int>();
	// reserve_tests<int>();
	// copy_swap_tests<int>();
	// reverse_it_tests<int>();
	// erase_clear_tests<int>();
	// max_size_tests();
	// awesome_tests();
	// push_pop_back_tests<Awesome>();
	// resize_tests<Awesome>();
	// insert_tests<Awesome>();
	// reserve_tests<Awesome>();
	// copy_swap_tests<Awesome>();
	// reverse_it_tests<Awesome>();
	// erase_clear_tests<Awesome>();





	p3

	}
	
}