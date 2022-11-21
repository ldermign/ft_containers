/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/21 21:37:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "ft_containers.hpp"
#include "red_black_tree.hpp"
#include "RedBlackTreeIterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "less.hpp"

START

/*
	Cest un container qui est de type clef-valeur.
	C'est pourquoi on ne l'utilise qu'avec pair.
	
*/

template<
	class Key,
	class T,
	class Compare = ft::less< Key >,
	class Allocator = std::allocator< ft::pair< const Key, T > > >
class map {

public:

	typedef Key							key_type;
	typedef T							mapped_type;
	typedef ft::pair< const Key, T >	value_type;
	typedef ft::node< value_type >		node_type;
	typedef std::size_t					size_type;
	typedef std::ptrdiff_t				difference_type;
	
	typedef Compare				key_compare;
	typedef Allocator			allocator_type;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;

	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

/* ~~~~~ RedBlackTree ~~~~~ */
/*
	On cree un typedef du RedBlackTree
	value_type = ft::pair< const Key, T >
	key_compare = Compare
	Les clefs (value_type) sont triees en utilisant la fonction Compare.
*/
	typedef ft::RedBlackTree< value_type, key_compare >	tree;

/* ~~~~~ ITERATOR ~~~~~ */

	typedef ft::RedBlackTreeIterator< value_type, node_type >		iterator;
	typedef ft::RedBlackTreeIterator< const value_type, node_type >	const_iterator;
	typedef ft::reverse_iterator< iterator >						reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >					const_reverse_iterator;

public:

/* ~~~~~ ~~~~~ */
	class value_compare : public binary_function< value_type, value_type, bool > {

		friend class map;

		protected:

			Compare comp;
			value_compare( key_compare c ) : comp(c) {}

		public:

			bool operator()( const value_type &x, const value_type &y ) const {
				return comp(x.first, y.first);
			}
	};

private:

	tree			_t;
	node< T >		*_ptrRBT;
	node< T >		*_endNode;
	value_compare	new_compare;
	allocator_type	new_alloc;

public:

// 23.3.1.1 construct/copy/destroy:
// Complexity: Constant.
	explicit map( const Compare &comp = Compare(), const Allocator &t = Allocator() )
		: _t(), new_compare(value_compare(comp)), new_alloc(t) {}
	
	template< class InputIterator >
	map( InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &t = Allocator() );

	map( const map< Key, T, Compare, Allocator > &x )
		: _t(), new_compare(), new_alloc(x) {}

	virtual
	~map( void ) {}

	map< Key, T, Compare, Allocator > &operator=( const map< Key, T, Compare, Allocator> &rhs ) {

		if (&rhs == this)
			return *this;
		
		this->_t = rhs._t;
		this->new_alloc = rhs.new_alloc;
		this->new_compare = rhs.new_compare;
	}

/* ~~~~~ ITERATORS ~~~~~ */
	iterator
	begin( void ) {

		// node *tmp = _ptrRBT;
		// while (tmp->_left != nil)
		// 	tmp = tmp->_left;
		return iterator(tmp, _endNode, _ptrRBT);

	}

	// const_iterator
	// begin( void ) const {

	// 	return const_iterator(this->_t[0]);
	// }

	// iterator
	// end( void ) {

	// 	// return ;
	// }

// 	const_iterator
// 	end( void ) const;

// 	reverse_iterator
// 	rbegin( void );

// 	const_reverse_iterator
// 	rbegin( void ) const;

// 	reverse_iterator
// 	rend( void );

// 	const_reverse_iterator
// 	rend( void ) const;

// capacity:
	bool
	empty( void ) const {

		return (this->_t._size() == 0);
	}

	size_type
	size( void ) const {

		return this->_t.size();
	}

// 	size_type
// 	max_size( void ) const {
// // voir ca plus tard -> taille de la RAM divise par le nombre de nodes ?? 
// 		return 1;
// 	}


// //  element access:
// 	T &operator[]( const key_type &x );

// modifiers:
	// ft::pair< iterator, bool >
	// insert( const value_type &x ) {

	// 	this->_t.insert(x);

	// 	return 
	// }

	// iterator
	// insert( iterator position, const value_type &x ) {

	// 	this->_t.insert()
	// }

// 	template< class InputIterator >
// 	void
// 	insert( InputIterator first, InputIterator last );

	// void
	// erase( iterator position ) {
		
	// }

// 	size_type
// 	erase( const key_type &x );

// 	void
// 	erase( iterator first, iterator last );

// 	void
// 	swap( map< Key, T, Compare, Allocator > &x );

// 	void
// 	clear( void );

// // observers:
// 	key_compare
// 	key_comp( void ) const;

// 	value_compare
// 	value_comp( void ) const;


// 		// 23.3.1.3 map operations:
// 		iterator
// 		find( const key_type &x );

// 		const_iterator
// 		find( const key_type & x) const;

// 		size_type
// 		count( const key_type & x) const;

// 		iterator
// 		lower_bound( const key_type &x );

// 		const_iterator
// 		lower_bound( const key_type &x ) const;

// 		iterator
// 		upper_bound( const key_type &x );

// 		const_iterator
// 		upper_bound( const key_type &x ) const;

// 		ft::pair< iterator, iterator >
// 		equal_range( const key_type &x );
		
// 		ft::pair< const_iterator, const_iterator >
// 		equal_range( const key_type &x ) const;
	
	};

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator==( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y);

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator!=( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y) {

		return !(x == y);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator<( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y);

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator>( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y);
	// {
// 
		// // return (x > y);
	// }

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator>=( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y);

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator<=( const ft::map< Key, T, Compare, Allocator > &x, const ft::map< Key, T, Compare, Allocator > &y);

// specialized algorithms:
	template< class Key, class T, class Compare, class Allocator >
	void
	swap( ft::map< Key, T, Compare, Allocator > &x, ft::map< Key, T, Compare, Allocator > &y );


STOP

#endif