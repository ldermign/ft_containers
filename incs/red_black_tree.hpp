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
#include "less.hpp"
#include "node.hpp"
#include "RedBlackTreeIterator.hpp"

START

template< 	class T,
			class Compare,
			class node = ft::node< T >,
			class Allocator = std::allocator< node > > // CHECKEEERRR
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
	typedef typename ft::node< T >	node_type;
	typedef Allocator				allocator_type;

/* ~~~~~ REFERENCES / POINTERS ~~~~~ */
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

/* ~~~~~ ~~~~~ */
	// typedef ft::random_iterator< T >		iterator;
	// typedef ft::random_iterator< const T >	const_iterator;
	typedef typename Allocator::difference_type	difference_type;
	typedef size_t								size_type;


private:

	node_type	_ptrNode;
	node_type	_last;
	size_t		_size; // a faire

public:

/* ~~~~~ CONSTRUCTOR ~~~~~ */

	// RedBlackTree( void ) {

	// 	_last = new node;
	//     _last->color = N_BLACK;
	//     _last->left = NULL;
	//     _last->right = NULL;
	//     _ptrNode = _last;
	// }

	RedBlackTree( void ) {}
		// : _last(new node), _last->color(N_BLACK), _last->left(NULL), _last->right(NULL), _ptrNode(_last) {}

	virtual
	~RedBlackTree( void ) {}

	// void
	// initializeNULLNode( node_type here, node_type parent ) {

	// 	here->data = 0;
	// 	here->parent = parent;
	// 	here->left = NULL;
	// 	here->right = NULL;
	// 	here->color = 0;
	// }

  // Preorder
// void preOrderHelper(pointer node) {
// if (node != NULL) {
// p1 node->data << " ";
// preOrderHelper(node->left);
// preOrderHelper(node->right);
// }
// }

  // Inorder
// void inOrderHelper(pointer node) {
// if (node != NULL) {
// inOrderHelper(node->left);
// p1 node->data << " ";
// inOrderHelper(node->right);
// }
// }

  // Post order
// void postOrderHelper(pointer node) {
// if (node != NULL) {
// postOrderHelper(node->left);
// postOrderHelper(node->right);
// p1 node->data << " ";
// }
// }

// pointer searchTreeHelper(pointer node, int key) {
// if (node == NULL || key == node->data) {
// return node;
// }

// if (key < node->data) {
// return searchTreeHelper(node->left, key);
// }
// return searchTreeHelper(node->right, key);
// }

private:

  // For balancing the tree after deletion
	void
	deleteFix( pointer x ) {

		pointer s;

		while (x != _ptrNode && x->color == 0) {

			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				if (s->left->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->right->color == 0) {
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = _ptrNode;
				}
			}
			else {
				s = x->parent->left;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}
				if (s->right->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->left->color == 0) {
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}
					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = _ptrNode;
				}
			}
		}
	
		x->color = 0;
	}

	void
	rbTransplant( pointer u, pointer v ) {

		if (u->parent == NULL)
			_ptrNode = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	void
	deleteNodeHelper( pointer tmp, int key ) {

		pointer z = this->_last;
		pointer x, y;

		while (tmp != this->_last) {
			if (tmp->data == key)
				z = tmp;

			if (tmp->data <= key)
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}
		if (z == this->_last) {
			p1 "Key not found in the tree" p2;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == this->_last) {
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == NULL) {
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
		delete z;
		if (y_original_color == 0)
			deleteFix(x);
	}

	// For balancing the tree after insertion
	void
	insertFix( pointer k ) {

		pointer u;
		while (k->parent->color == 1) {

			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;
				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {
						k = k->parent;
						leftRotate(k);
					}
				k->parent->color = 0;
				k->parent->parent->color = 1;
				rightRotate(k->parent->parent);
				}
			}
			if (k == _ptrNode)
				break ;
		}

		_ptrNode->color = 0;
	}

	void
	printHelper( pointer root, std::string indent, bool last ) {
	
		if (root != this->_last) {
			p1 indent;
			if (last) {
				p1 "R----";
				indent += "   ";
			}
			else {
				p1 "L----";
				indent += "|  ";
			}
			std::string sColor = root->color ? "RED" : "BLACK";
			p1 root->data << "(" << sColor << ")" p2;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

public:

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

	pointer
	searchTree( int k ) {

		return searchTreeHelper(this->root, k);
	}

	pointer
	minimum( pointer tmp ) {

		while (tmp->left != this->_last)
			tmp = tmp->left;
		return tmp;
	}

	pointer
	maximum( pointer tmp ) {

		while (tmp->right != this->_last) {
			tmp = tmp->right;
		}
		return tmp;
	}

	pointer
	successor( pointer x ) {

		if (x->right != this->_last)
			return minimum(x->right);

		pointer y = x->parent;
		while (y != this->_last && x == y->right) {
			x = y;
			y = y->parent;
		}
		return y;
	}

	pointer
	predecessor( pointer x ) {

		if (x->left != this->_last) {
			return maximum(x->left);
		}

		pointer y = x->parent;
		while (y != this->_last && x == y->left) {
			x = y;
			y = y->parent;
		}

		return y;
	}





/* ~~~~~ ROTATE ~~~~~ */

	void
	leftRotate( pointer x ) {

		pointer y = x->right; // set y
		x->right = y->left; // turn y’s left subtree into x’s right subtree
		if (y->left != this->_last)
			y->left->parent = x;
		y->parent = x->parent; // link x’s parent to y
		if (x->parent == NULL)
			this->root = y;
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

		if (x->parent == NULL)
			this->root = y;

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
	void
	insert( int key ) {

		node_type tmp = new node;
		tmp->parent = NULL;
		tmp->data = key;
		tmp->left = this->_last;
		tmp->right = this->_last;
		tmp->color = 1;

		node_type y = NULL;
		node_type x = this->_ptrNode;

		while (x != this->_last) {
			y = x;
			if (tmp->data < x->data)
				x = x->left;
			else
				x = x->right;
		}

		tmp->parent = y;
		if (y == NULL)
			_ptrNode = tmp;
		else if (tmp->data < y->data)
			y->left = tmp;
		else
			y->right = tmp;
		if (tmp->parent == NULL) {
			tmp->color = 0;
			return;
		}
		if (tmp->parent->parent == NULL)
			return;

		insertFix(tmp);
	}



	pointer
	getRoot( void ) {

		return this->_ptrNode;
	}

	void
	deleteNode( int data ) {

		deleteNodeHelper(this->_ptrNode, data);
	}

	void
	printTree( void ) {

		if (_ptrNode)
			printHelper(this->_ptrNode, "", true);
	}



};

STOP

#endif