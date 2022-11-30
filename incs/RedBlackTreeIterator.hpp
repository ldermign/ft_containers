/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/30 15:58:20 by ldermign         ###   ########.fr       */
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

	RedBlackTreeIterator( void )
		: _current(), _root(), _last() {}

	operator RedBlackTreeIterator< const T, Node > (void) {
		return (RedBlackTreeIterator< const T, Node >(_current, _root, _last));
	}

	// template <class U, class N>
	// RedBlackTreeIterator (const RedBlackTreeIterator<U, N> ref ) :
	// 	_current(ref._current), _root(ref._root), _last(ref._last) {}

	~RedBlackTreeIterator( void ) {}

/* ~~~~~ ACCESSORS ~~~~~ */

	ft::Node< T >	*getCurrent( void ) const { return this->_current; }


	reference
	operator*( void ) const {

		return (this->_current->data);
	}
	
	pointer
	operator->( void ) const {

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

		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
			Decrement();
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
		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
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
			if (_current->right != tmp)
				_current = tmp;
		}
	}


	void Decrement( void ) {

        if (_current->parent->parent == _current
			&& _current->color == 1)
			_current = _current->left;
		else if (_current->left != _last)
		{
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


// template< class T, class Node >
// struct ConstRedBlackTreeIterator : public ft::iterator< ft::bidirectional_iterator_tag, T > {

// public:

// 	typedef T						value_type;
// 	typedef ConstRedBlackTreeIterator	Self;

// 	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::pointer		pointer;
// 	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::reference	reference;
	

// private:

// 	ft::Node< T >			*_current;
// 	ft::Node< T >			*_root;
// 	ft::Node< T >			*_last;

// public:

// /**
// 	@param { start point iterator } c
// 	@param { root red black tree } r
// 	@param { end red black tree } l
// */
// 	ConstRedBlackTreeIterator( Node *c, Node *r, Node *l )
// 		: _current(c), _root(r), _last(l) {}

// 	ConstRedBlackTreeIterator( void )
// 		: _current(), _root(), _last() {}

// 	~ConstRedBlackTreeIterator( void ) {}

// /* ~~~~~ ACCESSORS ~~~~~ */

// 	ft::Node< T >	*getCurrent( void ) const { return this->_current; }


// 	reference
// 	operator*( void ) {

// 		return this->_current->data;
// 	}
	
// 	pointer
// 	operator->( void ) const {

// 		return &(this->_current->data);
// 	}

// 	ConstRedBlackTreeIterator
// 	&operator++( void ) {
		
// 		Increment();
// 		return *this;
// 	}

// 	ConstRedBlackTreeIterator
// 	operator++( int ) {

// 		ConstRedBlackTreeIterator tmp = *this;
// 		// Increment();
// 		operator++();
// 		return tmp;
// 	}

// 	Node
// 	*minimum( Node *tmp ) const {

// 		if (tmp == nullptr_t || tmp == this->_last)
// 			return this->_last;
// 		while (tmp->left != this->_last)
// 			tmp = tmp->left;
// 		return tmp;
// 	}

// 	ConstRedBlackTreeIterator
// 	&operator--( void ) {

// 		if (this->_current == this->_last)
// 			this->_current = maximum(_root);
// 		else
// 			Decrement();
// 		return *this;
// 	}

// 	Node
// 	*maximum( Node *tmp ) const {

// 		if (tmp == nullptr_t || tmp == this->_last)
// 			return this->_last;
// 		while (tmp->right != this->_last)
// 			tmp = tmp->right;
// 		return tmp;
// 	}

// 	ConstRedBlackTreeIterator
// 	operator--( int ) {

// 		ConstRedBlackTreeIterator tmp = *this;
// 		if (this->_current == this->_last)
// 			this->_current = maximum(_root);
// 		else
// 			Decrement();
// 		return tmp;
// 	}

// 	bool
// 	operator==( const ConstRedBlackTreeIterator &s ) {

// 		return this->_current == s._current;
// 	}

// 	bool
// 	operator!=( const ConstRedBlackTreeIterator &s ) {

// 		return this->_current != s._current;
// 	}

// private:

// 	void Increment( void ) {

// 		if (_current->right != _last)
// 		{
// 			Node *temp = _current->right;
// 			while (temp->left != _last)
// 				temp = temp->left;
// 			_current = temp;

// 		}
// 		else
// 		{
// 			Node *tmp = _current->parent;
// 			if (tmp->right ==_current)
// 			{
// 				while (_current != this->_last 
// 					&& tmp->right != this->_last
// 					&& _current == tmp->right) {
// 					_current = tmp;
// 					tmp = tmp->parent;
// 				}
// 			}
// 			if (_current->right != tmp)
// 				_current = tmp;
// 		}
// 	}


// 	void Decrement( void ) {

//         if (_current->parent->parent == _current
// 			&& _current->color == 1)
// 			_current = _current->left;
// 		else if (_current->left != _last)
// 		{
// 			_current = _current->left;
// 			while (_current->right != _last)
// 				_current = _current->right;
// 		}
// 		else
// 		{
// 			ft::Node<T> *parent = _current->parent;
// 			while (parent->left == _current)
// 			{
// 				_current = parent;
// 				parent = parent->parent;
// 			}
// 			_current = parent;
// 		}
// 	}
// };

STOP

#endif