/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/26 10:52:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#if 1 //CREATE A REAL STL EXAMPLE
	// #include <map>
	// #include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
	// #include <stack.hpp>
	#include <vector.hpp>
#endif

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
		// using namespace ft;
		std::cout << "\n\n\t~~~~~ My Vector ~~~~~" << std::endl;
		// stack< int > mystack;
	}
	
	return 0;
}
