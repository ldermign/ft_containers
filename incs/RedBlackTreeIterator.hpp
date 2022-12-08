/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/08 23:42:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITERATOR
# define RED_BLACK_TREE_ITERATOR

#include "ft_containers.hpp"
#include "nullptr.hpp"
#include "iterator.hpp"
#include "Node.hpp"

// template
// https://cdmana.com/2021/12/202112300642463009.html

START

template< class T, class Node >
struct RedBlackTreeIterator : public ft::iterator< std::bidirectional_iterator_tag, T > {

public:

	typedef T						value_type;
	typedef RedBlackTreeIterator	Self;


	typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::pointer	pointer;
	typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::reference	reference;
	

private:

	Node			*_current;
	Node			*_root;
	Node			*_last;

public:

	RedBlackTreeIterator( Node *c, Node *r, Node *l )
		: _current(c), _root(r), _last(l) {}

	RedBlackTreeIterator( void )
		: _current(), _root(), _last() {}

	operator RedBlackTreeIterator< const T, Node > ( void ) {
		return (RedBlackTreeIterator< const T, Node >(_current, _root, _last));
	}

	~RedBlackTreeIterator( void ) {}

/* ~~~~~ ACCESSORS ~~~~~ */

	Node	*getCurrent( void ) const { return (this->_current); }

	reference
	operator*( void ) const {

		return (this->_current->data);
	}
	
	pointer
	operator->( void ) const {

		return (&(this->_current->data));
	}

	RedBlackTreeIterator
	&operator++( void ) {
		
		Increment();
		return (*this);
	}

	RedBlackTreeIterator
	operator++( int ) {

		RedBlackTreeIterator tmp = *this;
		// Increment();
		operator++();
		return (tmp);
	}

	Node
	*minimum( Node *tmp ) const {

		if (tmp == nullptr_v || tmp == this->_last)
			return (this->_last);
		while (tmp->left != this->_last)
			tmp = tmp->left;
		return (tmp);
	}

	RedBlackTreeIterator
	&operator--( void ) {

		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
			Decrement();
		return (*this);
	}

	Node
	*maximum( Node *tmp ) const {

		if (tmp == nullptr_v || tmp == this->_last)
			return (this->_last);
		while (tmp->right != this->_last)
			tmp = tmp->right;
		return (tmp);
	}

	RedBlackTreeIterator
	operator--( int ) {

		RedBlackTreeIterator tmp = *this;
		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
			Decrement();
		return (tmp);
	}

	friend bool
	operator==( const RedBlackTreeIterator &lhs, const RedBlackTreeIterator &rhs ) {

		return (lhs._current == rhs._current);
	}

	friend bool
	operator!=( const RedBlackTreeIterator &lhs, const RedBlackTreeIterator &rhs ) {

		return (!(lhs == rhs));
	}

	RedBlackTreeIterator &
	operator= (const RedBlackTreeIterator & ref) {
		if (this == &ref)
			return (*this);

		this->_current = ref._current;
		this->_root = ref._root;
		this->_last = ref._last;

		return (*this); 
	}

private:

	void Increment( void ) {

		if (_current->right != _last)
		{
			Node *temp = _current->right;
			while (temp->left != _last)
				temp = temp->left;
			_current = temp;

		}
		else
		{
			Node *tmp = _current->parent;
			if (tmp->right ==_current)
			{
				while (_current != this->_last
					&& tmp->right != this->_last
					&& _current == tmp->right) {
					_current = tmp;
					tmp = tmp->parent;
				}
			}
			if (_current->right != tmp || tmp == this->_last)
				_current = tmp;
		}
	}


	void Decrement( void ) {

        if (_current->parent->parent == _current
			&& _current->color == 1)
			_current = _current->left;
		else if (_current->left != _last) {
			_current = _current->left;
			while (_current->right != _last)
				_current = _current->right;
		}
		else
		{
			Node *parent = _current->parent;
			while (parent->left == _current)
			{
				_current = parent;
				parent = parent->parent;
			}
			_current = parent;
		}
	}

};

STOP

#endif