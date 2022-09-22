/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/22 12:01:57 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 1 //CREATE A REAL STL EXAMPLE
	// #include <map>
	#include <stack>
	// #include <vector>
	namespace ft = std;
#else
	// #include <map.hpp>
	#include <stack.hpp>
	// #include <vector.hpp>
#endif

int	main() {

	{
		using namespace ft;
		stack< int > mystack;
	}
	{
		using namespace std;
		stack< int > realstack;
	}
	
	
	return 0;
}