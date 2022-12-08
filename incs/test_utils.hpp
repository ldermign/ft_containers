/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:13:17 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/08 15:23:12 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

#include <stdlib.h>
#include <ostream>

#include "stack.hpp"

std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2
std::string s4[] = {"Et ", "un ", "bonjour ", "a ", "tous !"}; // 5
std::string s5[] = {"On ", "va ", "ecrire ", "une ", "longue ", "phrase ", "comme ", "ca ", "c'est ", "ok !"}; // 10

int i1[] = {42, 0, -111, 666, 1337, -222, 4, -9, 9}; // 9
int i2[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4}; // 9
int i3[] = {1234567890, 987654321}; // 2
int i4[] = {1, 2, 4, 8, 16, 32, 64, 128, 256}; // 9

char c1[] = {'L', 'i', 'e', 'n', 'a'}; // 
char c2[] = {'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 's'}; // 10
char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'}; // 8

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

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

template< class T >
void printStack( std::string name, LIBRARY::stack< T > const &src ) {

	LIBRARY::stack< T >			tmp(src);

	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2

	p1 BLUE << "stack " << name << RESET << " = ";
	for (; tmp.empty() != 0 ;) {
		p1 tmp.top() << " ";
		tmp.pop();
	}
	p3

	p1 "size = " << tmp.size() p2
	p1 "empty = " << tmp.empty() p2

	p1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" p2
	p3
		
}

// struct Test {

// public:

// 	Test( std::string *ss, int *ii, char *cc )
// 		: one(ss), two(ii), three(cc) {}
// 	~Test( void ) {}

// 	std::string	*getOne( void ) { return (this->one); }
// 	int			*getTwo( void ) { return (this->two); }
// 	char		*getThree( void ) { return (this->three); }


// std::string	operator*( void ) {
// 	return this->one;
// }

// private:

// 	std::string	*one;
// 	int			*two;
// 	char		*three;

// };

// std::ostream &operator<<( std::ostream &o, Test &test ) {

// 	o << test.getOne() << " - " << test.getTwo() << " - " << test.getThree();
// 	return (o);
// };

#endif