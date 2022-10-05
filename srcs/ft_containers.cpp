/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/05 14:40:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {

	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~ ITERATOR ~~~~~~~~~~\n" PSTOP
	PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	{
		PSTART "-----> REAL vector" PSTOP
		using namespace std;

		vector< int >	real(4, 42);
		vector< int >::iterator		first = real.begin();
		vector< int >::iterator		second = real.begin() + 2;

		PSTART "second - first = " << second - first PSTOP
		PSTART "first - second = " << first - second PSTOP


	}
	{
		PSTART "-----> MY vector" PSTOP
		using namespace ft;

		vector< int >	mine(4, 42);
		vector< int >::iterator		first = mine.begin();
		vector< int >::iterator		second = mine.begin() + 2;

		PSTART "second - first = " << second - first PSTOP
		PSTART "first - second = " << first - second PSTOP
	}


	// PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	// PSTART "\t~~~~~~~~~~ VECTOR ~~~~~~~~~~\n" PSTOP
	// PSTART "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" PSTOP
	// {
	// 	using namespace std;

	// 	std::cout << "\t~~~~~ Real Vector ~~~~~" << std::endl;
		
	// 	std::vector< int > realVector;
	
	// 	std::cout << std::endl;
	// 	std::cout << "capacity [" << realVector.capacity()
	// 		<< "] - size = [" << realVector.size() << "]" << std::endl;
	// 	realVector.push_back(42);
	// 	realVector.push_back(123);
	// 	realVector.push_back(0);
	// 	realVector.push_back(1007);
	// 	realVector.insert(realVector.begin() + 2, -404);
	// 	std::cout << "insert [" << *(realVector.insert(realVector.begin() + 2, -404)) << "]" << std::endl;

	// 	for (std::vector< int >::iterator it = realVector.begin() ; it != realVector.end(); ++it) {
	// 	    std::cout << *it;
	// 		if (it + 1 != realVector.end())
	// 			std::cout << " - ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << "capacity [" << realVector.capacity()
	// 		<< "] - size = [" << realVector.size() << "]" << std::endl;

	// }
	// {
	// 	using namespace ft;

	// 	ft::vector< int > myVector;
	// 	// appel de explicit vector( size_type n, const T &value = T(), const Allocator &x = Allocator() )

	// 	std::cout << std::endl;
	// 	std::cout << "capacity [" << myVector.capacity()
	// 		<< "] - size = [" << myVector.size() << "]" << std::endl;
	// 	myVector.push_back(42);
	// 	myVector.push_back(123);
	// 	myVector.push_back(0);
	// 	myVector.push_back(1007);
	// 	myVector.insert(myVector.begin() + 2, -404);
	// 	std::cout << "insert [" << *(myVector.insert(myVector.begin() + 2, -404)) << std::endl;


	// 	std::cout << "\n\t~~~~~ My Vector ~~~~~" << std::endl;
	// 	for (ft::vector< int >::iterator it = myVector.begin() ; it != myVector.end(); ++it) {
	// 	    std::cout << *it;
	// 		if (it + 1 != myVector.end())
	// 			std::cout << " - ";
	// 	}
	// 	std::cout << std::endl;
	// 	std::cout << "capacity [" << myVector.capacity()
	// 		<< "] - size = [" << myVector.size() << "]" << std::endl;
	// }
	
	return 0;
}
