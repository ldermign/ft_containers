/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:13:17 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/07 22:44:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
# define TEST_UTILS_HPP

#include <stdlib.h>
#include <ostream>

std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("};
std::string s2[] = {"Une ", "serie ", "de ", "phrase..."};
std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"};

int i1[] = {42, 0, -111, 666, 1337, -222, 4, -9, 9};
int i2[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
int i3[] = {1234567890, 987654321};

char c1[] = {'L', 'i', 'e', 'n', 'a'};
char c2[] = {'C', 'o', 'n', 't', 'a', 'i', 'n', 'e', 'r', 's'};
char c3[] = {'l', 'd', 'e', 'r', 'm', 'i', 'g', 'n'};

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

struct Test {

public:

	Test( std::string *ss, int *ii, char *cc )
		: one(ss), two(ii), three(cc) {}
	~Test( void ) {}

	std::string	*getOne( void ) { return (this->one); }
	int			*getTwo( void ) { return (this->two); }
	char		*getThree( void ) { return (this->three); }


std::string	operator*( void ) {
	return this->one;
}

private:

	std::string	*one;
	int			*two;
	char		*three;

};

std::ostream &operator<<( std::ostream &o, Test &test ) {

	o << test.getOne() << " - " << test.getTwo() << " - " << test.getThree();
	return (o);
};

#endif