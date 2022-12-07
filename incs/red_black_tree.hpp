 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:34 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/17 12:23:06 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "ft_containers.hpp"
#include "RedBlackTreeIterator.hpp"

START

// https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html

template< 	class T,
			class Compare,
			class Node = ft::Node< T >,
			class Allocator = std::allocator< Node > > // CHECKEEERRR
class RedBlackTree {

public:

// le node a 3 pointeurs : le parents (pour remonter l'arbre), gauche et droite pour naviguer
// couleur + pair entre 2 element de la map
/*
	rbt = constructeur par copie, par default et sur plage d'ite
	par defaut, on va creer un node (new) -> ca sera toutes les extremitees,
	des noeuds qui ne contiennent rien et va delimitee l'arbre binaire, 
	il va pointer vers end (last pour moi).
	C'est le last qu'on retourne pour end().
	Des qu'on incremente les iterateurs, on va aller sur cet elements 
	(pour voir si on arrive a la fin)
	On est censee l'alouer des le debut, avec le constructeur par default
*/

/* ~~~~~ ARGUMENTS TEMPLATE ~~~~~ */
	typedef T						value_type;
	typedef Compare					value_compare;
	typedef typename ft::Node< T >	node_type;
	typedef Allocator				allocator_type;

/* ~~~~~ REFERENCES / POINTERS ~~~~~ */
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

/* ~~~~~ ~~~~~ */
	typedef typename Allocator::difference_type	difference_type;
	typedef size_t								size_type;


typedef ft::RedBlackTreeIterator< value_type, node_type >		iterator;

private:

	allocator_type	alloc;
	value_compare	comp;
	Node			*_ptrNode;
	Node			*_last;
	size_type		_size;

public:

/* ~~~~~ CONSTRUCTOR ~~~~~ */

	RedBlackTree( const value_compare &c = Compare() ) : comp(c) {

		this->_last = alloc.allocate(1);
		alloc.construct(_last, Node());
		this->_last->color = N_BLACK;
		this->_last->left = _last;
		this->_last->right = _last;
		this->_last->parent = _last;
		this->_ptrNode = this->_last;
		this->_size = 0;

	}

	~RedBlackTree( void ) {

		this->clear();
		if (this->getLast() != NULL) {
			alloc.destroy(this->getLast());
			alloc.deallocate(this->getLast(), 1);
		}
	}

/* ~~~~~ ACCESSORS ~~~~~ */

	value_compare	getComp( void ) const { return (this->comp); }
	Node			*getPtrNode( void ) const { return (this->_ptrNode); }
	Node			*getLast( void ) const { return (this->_last); }
	size_type		getSize( void ) const { return (this->_size); }
	pointer			getMinimum( void ) const { return (this->minimum(this->_ptrNode)); }
	pointer			getMaximum( void ) const { return (this->maximum(this->_ptrNode)); }
	pointer			searchConst( const value_type &key_to_find ) const { return (search(this->getPtrNode(), key_to_find)); }

/* ~~~~~ ~~~~~ */

	pointer
	search( pointer start_point, const value_type &key_to_find ) const {

		if (start_point == this->_last)
			return (start_point);
		else if (comp(key_to_find, start_point->data))
			return (search(start_point->left, key_to_find));
		else if (comp(start_point->data, key_to_find))
			return (search(start_point->right, key_to_find));
		else
			return (start_point);
	}

	void
	swap( RedBlackTree &rhs ) {

		pointer	tmpPtrNode;
		pointer	tmpLast;
		size_t	tmpSize;

		tmpPtrNode = rhs._ptrNode;
		tmpLast = rhs._last;
		tmpSize = rhs._size;

		rhs._ptrNode = this->_ptrNode;
		rhs._last = this->_last;
		rhs._size = this->_size;

		this->_ptrNode = tmpPtrNode;
		this->_last = tmpLast;
		this->_size = tmpSize;
	}

	// For balancing the tree after insertion
	void
	insertFix( pointer k ) {

		pointer u;
		while (k->parent->color == N_RED) {

			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == N_RED) {
					u->color = N_BLACK;
					k->parent->color = N_BLACK;
					k->parent->parent->color = N_RED;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = N_BLACK;
					k->parent->parent->color = N_RED;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;
				if (u->color == N_RED) {
					u->color = N_BLACK;
					k->parent->color = N_BLACK;
					k->parent->parent->color = N_RED;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = N_BLACK;
					k->parent->parent->color = N_RED;
					rightRotate(k->parent->parent);
				}
			}
			if (k == _ptrNode)
				break ;
		}

		_ptrNode->color = 0;
	}

	// void
	// printHelper( pointer root, std::string indent, bool last ) {
	
	// 	if (root != this->_last) {
	// 		p1 indent;
	// 		if (last) {
	// 			p1 "R----";
	// 			indent += "   ";
	// 		}
	// 		else {
	// 			p1 "L----";
	// 			indent += "|  ";
	// 		}
	// 		std::string sColor = root->color ? "RED" : "BLACK";
	// 		p1 root->data << "(" << sColor << ")" p2;
	// 		printHelper(root->left, indent, false);
	// 		printHelper(root->right, indent, true);
	// 	}
	// }

public:

	void
	printTree( void ) {

		if (this->_ptrNode)
			printHelper(this->_ptrNode, "", true);
	}

	void
	preorder( void ) {

		preOrderHelper(this->root);
	}

	void
	inorder( void ) {

		inOrderHelper(this->root);
	}

	void
	postorder( void ) {

		postOrderHelper(this->root);
	}

/* ~~~~~ LOWER AND UPPER BOUND ~~~~~ */

	pointer
	min( pointer s ) const {

		if (s == NULL || s == this->getLast())
			return this->getLast();
		for (; s->left != this->getLast(); s = s->left)
			;

		return (s);
	}

	pointer
	lower_bound( const value_type &v ) const {

		pointer	p = min(this->getPtrNode());

		for (; p != this->getLast(); p = successor(p)) {
			if (!comp(p->data, v))
				break ;
		}

		return (p);
	}


	pointer
	upper_bound( const value_type &v ) const {

		pointer	p = min(this->getPtrNode());

		for (; p != this->_last; p = successor(p)) {
			if (comp(v, p->data))
				break ;
		}

		return (p);
	}



/* ~~~~~ ~~~~~ */

	pointer
	minimum( pointer tmp ) const {

		if (tmp == nullptr_v || tmp == this->_last)
			return (this->_last);
		while (tmp->left != this->_last)
			tmp = tmp->left;

		return (tmp);
	}

	pointer
	maximum( pointer tmp ) const {

		if (tmp == nullptr_v || tmp == this->_last)
			return (this->_last);
		while (tmp->right != this->_last)
			tmp = tmp->right;

		return (tmp);
	}

	pointer
	successor( pointer x ) const {

		if (x->right != this->_last)
			return (minimum(x->right));

		pointer y = x->parent;
		while (y != this->_last && x == y->right) {
			x = y;
			y = y->parent;
		}

		return (y);
	}

	pointer
	predecessor( pointer x ) {

		if (x->left != this->_last) {
			return (maximum(x->left));
		}

		pointer y = x->parent;
		while (y != this->_last && x == y->left) {
			x = y;
			y = y->parent;
		}

		return (y);
	}





/* ~~~~~ ROTATE ~~~~~ */

	void
	leftRotate( pointer x ) {

		pointer y = x->right; // set y
		x->right = y->left; // turn y’s left subtree into x’s right subtree
		if (y->left != this->_last)
			y->left->parent = x;
		y->parent = x->parent; // link x’s parent to y
		if (x->parent == this->_last)
			this->_ptrNode = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x; // put x on y’s left
		x->parent = y;
	}


	void
	rightRotate( pointer x ) {

		pointer y = x->left;
		x->left = y->right;

		if (y->right != this->_last)
			y->right->parent = x;
		y->parent = x->parent;

		if (x->parent == this->_last)
			this->_ptrNode = y;

		else if (x == x->parent->right)
			x->parent->right = y;

		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}





/* ~~~~~ INSERT NODE ~~~~~ */
// insert the key to the tree in its appropriate position
	// and fix the tree

/**
	// TODO: ne plus utiliser new... faire avec allocate 
*/
	bool
	insert( const value_type key ) {
// Ordinary Binary Search Insertion

		pointer	tmp = alloc.allocate(1);
		alloc.construct(tmp, Node(key, this->_last, this->_last, this->_last, N_RED));

		pointer	y = nullptr_v;
		pointer	x = this->_ptrNode;

		while (x != this->_last && x != nullptr_v) {
			y = x;
			if (this->comp(tmp->data, x->data)) //
				x = x->left;
			else if (this->comp(x->data, tmp->data))
				x = x->right;
			else {
				alloc.destroy(tmp);
				if (tmp != NULL)
					alloc.deallocate(tmp, 1);
				return false;
			}
		}

		// y is parent of x
		tmp->parent = y;
		if (y == nullptr_v)
			this->_ptrNode = tmp;
		else if (this->comp(tmp->data, y->data)) //
			y->left = tmp;
		else
			y->right = tmp;

		this->_size++;
		// if new node is a root node, simply return
		if (tmp->parent == nullptr_v) {
			tmp->color = N_BLACK;
			tmp->parent = this->_last;
			// p1 "first element" p2;
			return true;
		}

		// if the grandparent is null, simply return
		if (tmp->parent->parent == this->_last)
			return true;

		// Fix the tree
		insertFix(tmp);
		return true;
	}





/* ~~~~~ DELETE NODE ~~~~~ */

	bool
	deleteNode( const value_type &data ) {

		return (deleteNodeHelper(this->getPtrNode(), data));
	}

// private:
// For balancing the tree after deletion
	void
	deleteFix( pointer x ) {

		pointer s;

		while (x != this->_ptrNode && x->color == N_BLACK) {

			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == N_RED) {
					s->color = N_BLACK;
					x->parent->color = N_RED;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == N_BLACK && s->right->color == N_BLACK) {
					s->color = N_RED;
					x = x->parent;
				}
				else {
					if (s->right->color == N_BLACK) {
						s->left->color = N_BLACK;
						s->color = N_RED;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = N_BLACK;
					s->right->color = N_BLACK;
					leftRotate(x->parent);
					x = _ptrNode;
				}
			}

			else {
				s = x->parent->left;
				if (s->color == N_RED) {
					s->color = N_BLACK;
					x->parent->color = N_RED;
					rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->right->color == N_BLACK) {
					s->color = N_RED;
					x = x->parent;
				}
				else {
					if (s->left->color == N_BLACK) {
						s->right->color = N_BLACK;
						s->color = N_RED;
						leftRotate(s);
						s = x->parent->left;
					}
					s->color = x->parent->color;
					x->parent->color = N_BLACK;
					s->left->color = N_BLACK;
					rightRotate(x->parent);
					x = this->getPtrNode();
				}
			}
		}
	
		x->color = N_BLACK;
	}

	void
	rbTransplant( pointer u, pointer v ) {

		if (u->parent == this->_last)
			this->_ptrNode = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	bool
	deleteNodeHelper( pointer tmp, const value_type &key ) {

		pointer z = this->_last;
		pointer x, y;

		while (tmp != this->getLast())
		{
			if (this->comp(tmp->data, key))
				tmp = tmp->right;
			else if (this->comp(key, tmp->data))
				tmp = tmp->left;
			else {
				z = tmp;
				tmp = tmp->right;
			}
		}

		if (z == this->_last) {
			// p1 "Key not found in the tree" p2;
			return false;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == this->_last) {
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == this->_last) {
			x = z->left;
			rbTransplant(z, z->left);
		}
		else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
				x->parent = y;
			else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		alloc.destroy(z);
		if (z != NULL)
			alloc.deallocate(z, 1);
		if (y_original_color == N_BLACK)
			deleteFix(x);
		this->_size--;
		return true;
	}


/* ~~~~~ CLEAR ~~~~~ */

	void
	clear_loop( Node *root ) {

		if (root == this->getLast())
			return ;

		clear_loop(root->left); 
		clear_loop(root->right); 

		alloc.destroy(root);
		if (root != NULL)
			alloc.deallocate(root, 1);

	}

	void
	clear( void ) {

		clear_loop(this->getPtrNode());
		this->_size = 0;
		this->_ptrNode = this->getLast();
	}

};

STOP

#endif
