/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/23 16:04:27 by ldermign         ###   ########.fr       */
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

private:

	Node			*_current;
	Node			*_root;
	Node			*_last;

public:

	RedBlackTreeIterator( Node *c, Node *r, Node *l )
		: _current(c), _root(r), _last(l) {}

	virtual
	~RedBlackTreeIterator( void ) {}

	T
	&operator*( void ) {

		return this->_current->data;
	}
	
	T
	*operator->( void ) {

		return &(this->_current->data);
	}

	RedBlackTreeIterator
	&operator++( void ) {

		Increment();
		return *this;
	}

	RedBlackTreeIterator
	operator++( int ) {

		RedBlackTreeIterator tmp = *this;
		Increment();
		return tmp;
	}

	RedBlackTreeIterator
	&operator--( void ) {

		Decrement();
		return *this;
	}

	RedBlackTreeIterator
	operator--( int ) {

		RedBlackTreeIterator tmp = *this;
		Decrement();
		return tmp;
	}

	bool
	operator==( const RedBlackTreeIterator &s ) {

		return this->_current == s._current;
	}

	bool
	operator!=( const RedBlackTreeIterator &s ) {

		return this->_current != s._current;
	}

private:

	void Increment( void ) {

		if (this->_current->right) {
			Node *temp = this->_current->right;
			// this->_current = temp;
			while (temp->left)
				temp = temp->left;
			this->_current = temp;

		}
		else
		{
			Node *tmp = this->_current->parent;
			if (tmp->right == this->_current) {
				while (this->_current == tmp->right) {
					this->_current = tmp;
					tmp = tmp->parent;
				}
			}
			if (this->_current->right != tmp)
				this->_current = tmp;
		}
	}

	void Decrement( void ) {

		if (this->_current->parent->parent == this->_current && this->_current->color == N_RED)
			// this->_current = this->_current->left;
			this->_current = this->_current->right;

		if (this->_current->left) {
			this->_current = this->_current->left;
		    while (this->_current->right)
			    this->_current = this->_current->right;
		}
		else {
			Node *parent = this->_current->parent;
			while (parent && parent->left == this->_current) {
				this->_current = parent;
				parent = parent->parent;
			}
			this->_current = parent;
		}

		
	}

/*

			else {
				Node* parent = _pnode->_parent;
				while (parent != nil && _pnode == parent->_left) {
					_pnode = parent;
					parent = parent->_parent;
				}
				_pnode = parent;
			}

*/

};

STOP

#endif