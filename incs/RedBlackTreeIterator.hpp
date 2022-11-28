/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:36 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/28 14:05:34 by ldermign         ###   ########.fr       */
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

	ft::Node< T >			*_current;
	ft::Node< T >			*_root;
	ft::Node< T >			*_last;

public:

/**
	@param { start point iterator } c
	@param { root red black tree } r
	@param { end red black tree } l
*/
	RedBlackTreeIterator( Node *c, Node *r, Node *l )
		: _current(c), _root(r), _last(l) {
			// p1 "current = " << _current << " - _last = " << _last p2
	}

	RedBlackTreeIterator( void )
		: _current(), _root(), _last() {}

	virtual
	~RedBlackTreeIterator( void ) {}

// check for the const
	operator	RedBlackTreeIterator< T, Node >() const {
		return (RedBlackTreeIterator< T, Node >(this->_current, this->_root, this->_last));
	};

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
/*
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
*/
		
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

		// p1 "4" p2
		if (this->_current == this->_last) {
			// p1 "avant max" p2
			this->_current = maximum(_root);
			// p1 "segfault ?" p2
		}
		else
			Decrement();
		return *this;


			// if (_current == _last)
			// {
			// 	_current = maximum(_root);
			// 	return *this;
			// }
			// _current = Decrement(_current);

			// return *this;
	}

	Node
	*maximum( Node *tmp ) const {

	// p1 "1" p2
		if (tmp == nullptr_t || tmp == this->_last)
			return this->_last;
		// p1 "2" p2
		while (tmp->right != this->_last)
			tmp = tmp->right;
		// p1 "3" p2
		return tmp;
	}

	RedBlackTreeIterator
	operator--( int ) {

		// p1 "la ????????" p2
		RedBlackTreeIterator tmp = *this;
		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
			Decrement();
		// operator--();
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


//////////////////////////////////////////
		// if (_current->right != _last)
		// {
		// 	ft::Node<T> *temp = _current->right;
		// 	while (temp->left != _last)
		// 		temp = temp->left;
		// }
		// else
		// {
		// 	ft::Node<T> *tmp = _current->parent;
		// 		while (tmp != this->_last && tmp->right == _current) {
		// 			_current = tmp;
		// 			tmp = tmp->parent;
		// 		}
		// 	if (_current->left != tmp)
		// 		_current = tmp;
		// 	else
		// 		_current = this->_last;
		// }
		// p1 "seg ?" p2


/*
		if (this->_current != this->_last
		&& this->_current->right != this->_last) {
			Node *temp = this->_current->right;
			// this->_current = temp;
			while (temp->left != this->_last)
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
*/
/*
		if (x->right != _last)
				return minimum(x->right);

			Node	*tmp = x->parent;
			while (tmp != _last && x == tmp->right)
			{
				x = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		*/
	}


	void Decrement( void ) {

		// p1 "[" << _current->data << "] [" p2
		// << _current->parent->data << "] [" p2
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
			ft::Node<T> *parent = _current->parent;
			while (parent->left == _current)
			{
				_current = parent;
				parent = parent->parent;
			}
			_current = parent;
		}

		// p1 "+1" p2
		// if (this->_current->parent->parent == this->_current
		// 	&& this->_current->color == N_RED)
		// 	this->_current = this->_current->left;
		// 	// this->_current = this->_current->right;

		// if (this->_current->left != this->_last) {
		// 	this->_current = this->_current->left;
		//     while (this->_current->right != this->_last)
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

			// {
			// 	if (x->left != this->_last) {
			// 		return maximum(x->left);
			// 	}

			// 	Node *y = x->parent;
			// 	while (y != this->_last && x == y->left) {
			// 		x = y;
			// 		y = y->parent;
			// 	}

			// 	return y;
			// }
		
	}

/*

			else {
				Node* parent = _pnode->parent;
				while (parent != _last && _pnode == parent->left) {
					_pnode = parent;
					parent = parent->parent;
				}
				_pnode = parent;
			}

*/

};


template< class T, class Node >
struct ConstRedBlackTreeIterator : public ft::iterator< ft::bidirectional_iterator_tag, T > {

public:

	typedef T						value_type;
	typedef ConstRedBlackTreeIterator	Self;

	typedef typename ft::iterator< ft::bidirectional_iterator_tag, const T >::pointer		pointer;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, const T >::reference	reference;
	

private:

	ft::Node< T >			*_current;
	ft::Node< T >			*_root;
	ft::Node< T >			*_last;

public:

/**
	@param { start point iterator } c
	@param { root red black tree } r
	@param { end red black tree } l
*/
	ConstRedBlackTreeIterator( Node *c, Node *r, Node *l )
		: _current(c), _root(r), _last(l) {
			// p1 "current = " << _current << " - _last = " << _last p2
		}

	ConstRedBlackTreeIterator( void )
		: _current(), _root(), _last() {}

	virtual
	~ConstRedBlackTreeIterator( void ) {}

// check for the const
	// operator	ConstRedBlackTreeIterator< T, Node >() const {
	// 	return (ConstRedBlackTreeIterator< T, Node >(this->_current, this->_root, this->_last));
	// };

	reference
	operator*( void ) {

		return this->_current->data;
	}
	
	pointer
	operator->( void ) const {

		return &(this->_current->data);
	}

	ConstRedBlackTreeIterator
	&operator++( void ) {

/*
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
*/
		
		Increment();
		return *this;

	}

	ConstRedBlackTreeIterator
	operator++( int ) {

		ConstRedBlackTreeIterator tmp = *this;
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

	ConstRedBlackTreeIterator
	&operator--( void ) {

		// p1 "4" p2
		if (this->_current == this->_last) {
			// p1 "avant max" p2
			this->_current = maximum(_root);
			// p1 "segfault ?" p2
		}
		else
			Decrement();
		return *this;


		// if (_current == _last)
		// {
		// 	_current = maximum(_root);
		// 	return *this;
		// }
		// _current = Decrement(_current);

		// return *this;
	}

	Node
	*maximum( Node *tmp ) const {

	// p1 "1" p2
		if (tmp == nullptr_t || tmp == this->_last)
			return this->_last;
		// p1 "2" p2
		while (tmp->right != this->_last)
			tmp = tmp->right;
		// p1 "3" p2
		return tmp;
	}

	ConstRedBlackTreeIterator
	operator--( int ) {

		// p1 "la ????????" p2
		ConstRedBlackTreeIterator tmp = *this;
		if (this->_current == this->_last)
			this->_current = maximum(_root);
		else
			Decrement();
		// operator--();
		return tmp;
	}

	bool
	operator==( const ConstRedBlackTreeIterator &s ) {

		return this->_current == s._current;
	}

	bool
	operator!=( const ConstRedBlackTreeIterator &s ) {

		return this->_current != s._current;
	}

private:

	void Increment( void ) {

		if (_current->right != _last)
		{
			Node *temp = _current->right;
			while (temp->left != _last) {
				// p1 "salut je suis un while" p2
				temp = temp->left;
			}
			_current = temp;

		}
		else
		{
			Node *tmp = _current->parent;
			if (tmp->right == _current)
			{
				while (
					tmp != _last &&
					// tmp->right != _last &&
					// _current != _last &&
					_current == tmp->right) {
					// p1 "a tmp = " << tmp << " avec " << tmp->data << " - last = " << _last << " avec " << _last->data p2
					
					// p1 "toujours un while" p2
					_current = tmp;
					tmp = tmp->parent;
					// p1 "p tmp = " << tmp << " avec " << tmp->data << " - last = " << _last << " avec " << _last->data p2
				}
			}
			if (_current->right != tmp)
				_current = tmp;
		}



/*

		if (_current->right != _last)
		{
			ft::Node<T> *temp = _current->right;
			while (temp->left != _last)
				temp = temp->left;
		}
		else
		{
			ft::Node<T> *tmp = _current->parent;
				while (tmp != this->_last && tmp->right == _current) {
					_current = tmp;
					tmp = tmp->parent;
				}
			if (_current->left != tmp)
				_current = tmp;
			else
				_current = this->_last;
		}
*/

/*
		if (this->_current != this->_last
		&& this->_current->right != this->_last) {
			Node *temp = this->_current->right;
			// this->_current = temp;
			while (temp->left != this->_last)
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
*/
/*
		if (x->right != _last)
				return minimum(x->right);

			Node	*tmp = x->parent;
			while (tmp != _last && x == tmp->right)
			{
				x = tmp;
				tmp = tmp->parent;
			}
			return tmp;
			*/
	}

	void Decrement( void ) {

		// p1 "[" << _current->data << "] [" p2
		// << _current->parent->data << "] [" p2
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
			ft::Node<T> *parent = _current->parent;
			while (parent->left == _current)
			{
				_current = parent;
				parent = parent->parent;
			}
			_current = parent;
		}

		// p1 "+1" p2
		// if (this->_current->parent->parent == this->_current
		// 	&& this->_current->color == N_RED)
		// 	this->_current = this->_current->left;
		// 	// this->_current = this->_current->right;

		// if (this->_current->left != this->_last) {
		// 	this->_current = this->_current->left;
		//     while (this->_current->right != this->_last)
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

			// {
			// 	if (x->left != this->_last) {
			// 		return maximum(x->left);
			// 	}

			// 	Node *y = x->parent;
			// 	while (y != this->_last && x == y->left) {
			// 		x = y;
			// 		y = y->parent;
			// 	}

			// 	return y;
			// }
		
	}

/*

			else {
				Node* parent = _pnode->parent;
				while (parent != _last && _pnode == parent->left) {
					_pnode = parent;
					parent = parent->parent;
				}
				_pnode = parent;
			}

*/

};

STOP

#endif