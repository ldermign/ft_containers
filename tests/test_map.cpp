/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:56:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/17 15:19:10 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <map>
#include "map.hpp"
#include <iostream>
#include "red_black_tree.hpp"

void	test_map( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ MAP CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2

	ft::node< std::string >	noeud1;
	ft::node< std::string >	noeud2(noeud1);
	
	// ft::RedBlackTree< std::string > test(noeud1);
	ft::RedBlackTree< int > test;
	test.insert(42);
	test.insert(0);
	test.insert(-111);

	// ft::RedBlackTree	tree();
    // for (int x = 0 ; x < 52 ; x++)
    //     tree.insert(x);
    // tree.print();

}