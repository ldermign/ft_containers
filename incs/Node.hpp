/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:27:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/23 14:13:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <iostream>
#include "ft_containers.hpp"

START

template< class T >
struct Node {

public:

	typedef T		value_type;
	typedef size_t	size_type;

	T		data;
 	size_t	color;
 	Node	*parent; // (except root node)
 	Node	*left;
 	Node	*right;

/* ~~~~~ CANONICAL FORM ~~~~~ */

	Node( void )
		: data(), color(N_BLACK), parent(NULL), left(NULL), right(NULL) {}

	Node( T *new_data )
		: data(new_data), color(N_BLACK), parent(NULL), left(NULL), right(NULL) {}

	Node( value_type v, Node *p, Node* l, Node *r, size_t c )
		: data(v), color(c), parent(p), left(l), right(r) {}

	Node( const T &src )
		: data(src.data), color(src.color), parent(src.parent), left(src.left), right(src.right) {}

	Node
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
	~Node( void ) {}

};

STOP

#endif