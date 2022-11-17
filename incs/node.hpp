/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:27:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/17 10:59:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <iostream>
#include "ft_containers.hpp"

START

template< class T >
struct node {

public:

	typedef T value_type;
	typedef size_t size_type;

	T		data;
 	size_t	color;
 	node	*parent; // (except root node)
 	node	*left;
 	node	*right;

/* ~~~~~ CANONICAL FORM ~~~~~ */

	node( void )
	: data(0), color(N_BLACK), parent(NULL), left(NULL), right(NULL) {}

	node( const T &src )
	: data(src.data), color(src.color), parent(src.parent), left(src.left), right(src.right) {}

	node
	&operator=( const T &rhs ) {

		if (&rhs == this)
			return *this;

		rhs.data = this->data;
		rhs.color = this->color;
		rhs.parent = this->parent;
		rhs.left = this->left;
		rhs.right = this->right;

		return *this;
	}

	virtual
	~node( void ) {}

};

STOP

#endif