/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/22 14:42:00 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
# define RED_BLACK_TREE_ITERATOR

#include "iterator.hpp"
#include "ft_containers.hpp"
#include "Node.hpp"

// template
// https://cdmana.com/2021/12/202112300642463009.html

START

template< class T, class Node >
struct RedBlackTreeIterator : public ft::iterator< ft::bidirectional_iterator_tag, T > {

public:

	typedef RedBlackTreeIterator	Self;
	// typedef ft::Node< T >			Node;

private:

	Node			*_current;
	Node			*_root;
	Node			*_last;

public:

	RedBlackTreeIterator( Node *n = NULL ) : _current(n), _root(), _last() {}

	virtual
	~RedBlackTreeIterator( void ) {}

	T
	&operator*( void ) {

		return this->_pNode->data;
	}
	
	T
	*operator->( void ) {

		return &(this->_pNode->data);
	}

	Self
	&operator++( void ) {

		Increment();
		return *this;
	}

	Self
	&operator++( int ) {

		Self tmp = this;
		Increment();
		return tmp;
	}

	Self
	&operator--( void ) {

		Decrement();
		return *this;
	}

	Self
	&operator--( int ) {

		Self tmp = this;
		Decrement();
		return tmp;
	}

	bool
	operator==( const Self &s ) {

		return this->_pNode == s._pNode;
	}

	bool
	operator!=( const Self &s ) {

		return this->_pNode != s._pNode;
	}

private:

	void Increment( void ) {

		if (this->_pNode->right) {
			Node *temp = this->_pNode->right;
			while (temp->left)
				temp = temp->left;
			this->_pNode = temp;

		}
		else
		{
			Node *tmp = this->_pNode->parent;
			if (tmp->right == this->_pNode) {
				while (this->_pNode == tmp->right) {
					this->_pNode = tmp;
					tmp = tmp->parent;
				}
			}
			if (this->_pNode->right != tmp)
				this->_pNode = tmp;
		}
	}

	void Decrement( void ) {

		if (this->_pNode->parent->parent == this->_pNode && this->_pNode->color == N_RED)
			this->_pNode = this->_pNode->left;

		else if (this->_pNode->left) {
			    while (this->_pNode->right)
				    this->_pNode = this->_pNode->right;
		}
		else {
			Node *parent = this->_pNode->parent;
			while (parent->left == this->_pNode) {
				this->_pNode = parent;
				parent = parent->parent;
			}
			this->_pNode = parent;
		}
	}

};

STOP

#endif