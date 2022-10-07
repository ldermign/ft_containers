/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/07 13:14:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include "ft_containers.hpp"
#include <iostream>

int	main( void ) {

	vector_iterator();


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
