/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/25 12:46:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
# define RED_BLACK_TREE_ITERATOR

#include "iterator.hpp"
#include "ft_containers.hpp"
#include "nullptr.hpp"
#include "Node.hpp"

// template
// https://cdmana.com/2021/12/202112300642463009.html

START

template< class T, class Node >
struct RedBlackTreeIterator : public ft::iterator< ft::bidirectional_iterator_tag, T > {

public:

	typedef T						value_type;
	typedef RedBlackTreeIterator	Self;

	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::pointer		pointer;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::reference	reference;
	

private:

	Node			*_current;
	Node			*_root;
	Node			*_last;

public:

/**
	@param { start point iterator } c
	@param { root red black tree } r
	@param { end red black tree } l
*/
	RedBlackTreeIterator( Node *c, Node *r, Node *l )
		: _current(c), _root(r), _last(l) {}

	virtual
	~RedBlackTreeIterator( void ) {}

// check for the const
	// operator	RedBlackTreeIterator< T, Node >() const {
	// 	return (RedBlackTreeIterator< T, Node >(this->_current, this->_root, this->_last));
	// };

	reference
	operator*( void ) {

		return this->_current->data;
	}
	
	pointer
	operator->( void ) const {

		return &(this->_current->data);
	}

	RedBlackTreeIterator
	&operator++( void ) {

		// Increment();
		if (_current == maximum(_root))
			{
				_current = _last;
				return *this;
			}
			else if (_current == _last)
			{
				_current = nullptr_t;
				return *this;
			}
			_current = Increment(_current);
			return *this;
		// return *this;
	}

	RedBlackTreeIterator
	operator++( int ) {

		RedBlackTreeIterator tmp = *this;
		// Increment();
		operator++();
		return tmp;
	}

	Node
	*minimum( Node *tmp ) const {

		if (tmp == nullptr_t || tmp == this->_last)
			return this->_last;
		while (tmp->left != this->_last)
			tmp = tmp->left;
		return tmp;
	}

	RedBlackTreeIterator
	&operator--( void ) {

		// Decrement();
		// return *this;


			if (_current == _last)
			{
				_current = maximum(_root);
				return *this;
			}
			_current = Decrement(_current);

			return *this;
	}

	Node
	*maximum( Node *tmp ) const {

		if (tmp == nullptr_t || tmp == this->_last)
			return this->_last;
		while (tmp->right != this->_last)
			tmp = tmp->right;

		return tmp;
	}

	RedBlackTreeIterator
	operator--( int ) {

		RedBlackTreeIterator tmp = *this;
		// Decrement();
		operator--();
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

	Node *Increment( Node *x ) {

		// if (this->_current != this->_last && this->_current->right) {
		// 	Node *temp = this->_current->right;
		// 	// this->_current = temp;
		// 	while (temp->left)
		// 		temp = temp->left;
		// 	this->_current = temp;

		// }
		// else
		// {
		// 	Node *tmp = this->_current->parent;
		// 	if (tmp->right == this->_current) {
		// 		while (this->_current == tmp->right) {
		// 			this->_current = tmp;
		// 			tmp = tmp->parent;
		// 		}
		// 	}
		// 	if (this->_current->right != tmp)
		// 		this->_current = tmp;
		// }

		if (x->right != _last)
				return minimum(x->right);

			Node	*tmp = x->parent;
			while (tmp != _last && x == tmp->right)
			{
				x = tmp;
				tmp = tmp->parent;
			}
			return tmp;
	}

	Node *Decrement( Node *x ) {

		// p1 "+1" p2
		// if (
		// 	// this->_current->parent != this->_root
		// 	// && this->_current->parent->parent != this->_root
		// 	this->_current->parent->parent == this->_current
		// 	&& this->_current->color == N_RED)
		// 	this->_current = this->_current->left;
		// 	// this->_current = this->_current->right;

		// if (this->_current->left) {
		// 	this->_current = this->_current->left;
		//     while (this->_current->right)
		// 	    this->_current = this->_current->right;
		// }
		// else {
		// 	Node *parent = this->_current->parent;
		// 	while (parent && parent->left == this->_current) {
		// 		this->_current = parent;
		// 		parent = parent->parent;
		// 	}
		// 	this->_current = parent;
		// }

			{
				if (x->left != this->_last) {
					return maximum(x->left);
				}

				Node *y = x->parent;
				while (y != this->_last && x == y->left) {
					x = y;
					y = y->parent;
				}

				return y;
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