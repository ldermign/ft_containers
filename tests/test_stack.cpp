/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:49:17 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/04 17:03:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <iostream>




void	test_stack( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ STACK CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2

	LIBRARY::stack<float>								other_stack;
	LIBRARY::vector<std::string>							lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	LIBRARY::stack<std::string, LIBRARY::vector<std::string> >	my_stack(lst);

	p1 std::boolalpha << other_stack.empty() p2;
	other_stack.push(8.5); // 8.5;
	// other_stack.push(42.4242); // 8.5; 42.4242;
	// p1 other_stack.size() p2; // 2
	// other_stack.pop(); // 8.5;
	// p1 other_stack.size() p2; // 1
	// other_stack.push(78541.987); // 8.5; 78541.987;
	// p1 other_stack.size() p2; // 2
	// p1 other_stack.top() p2; //78541.987
	// p1 std::boolalpha << other_stack.empty() p2;

	// const std::string const_top = my_stack.top();

	// p1 "const top: " << const_top p2;

	// while (!my_stack.empty())
	// {
	// 	p1 my_stack.top() p2;
	// 	my_stack.pop();
	// }




}

