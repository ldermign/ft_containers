/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/03 14:51:02 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {

	{
		using namespace std;

		std::cout << "\t~~~~~ Real Vector ~~~~~" << std::endl;
		
		std::vector< int > realVector;
		realVector.push_back(42);
		realVector.push_back(123);
		realVector.push_back(-404);
		realVector.push_back(0);
		realVector.push_back(1007);

		for (std::vector< int >::iterator it = realVector.begin() ; it != realVector.end(); ++it) {
		    std::cout << *it;
			if (it + 1 != realVector.end())
				std::cout << " - ";
		}


	}
	{
		using namespace ft;

		ft::vector< int > myVector(4, 42);
		// appel de explicit vector( size_type n, const T &value = T(), const Allocator &x = Allocator() )

		// myVector.push_back(42);
		// myVector.push_back(123);
		// myVector.push_back(-404);
		// myVector.push_back(0);
		// myVector.push_back(1007);

		std::cout << "\n\n\t~~~~~ My Vector ~~~~~" << std::endl;
		for (ft::vector< int >::iterator it = myVector.begin() ; it != myVector.end(); ++it) {
		    std::cout << *it;
			if (it + 1 != myVector.end())
				std::cout << " - ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
