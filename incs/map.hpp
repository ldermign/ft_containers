/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/28 16:01:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "ft_containers.hpp"
#include "red_black_tree.hpp"
#include "RedBlackTreeIterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "pair.hpp"
#include "less.hpp"
#include <limits>

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

	typedef Key										key_type;
	typedef T										mapped_type;
	typedef ft::pair< const key_type, mapped_type >	value_type;
	typedef ft::Node< value_type >					node_type;
	typedef std::size_t								size_type;
	typedef std::ptrdiff_t							difference_type;
	
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

/* ~~~~~ ITERATOR ~~~~~ */

	typedef ft::RedBlackTreeIterator< value_type, node_type >		iterator;
	// typedef ft::RedBlackTreeIterator< const value_type, node_type >	const_iterator;
	typedef ft::ConstRedBlackTreeIterator< value_type, node_type >	const_iterator;
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
	
	typedef ft::RedBlackTree< value_type, value_compare >	tree;

private:

	value_compare	new_compare;
	tree			_t;
	// node< T >		*_ptrRBT;
	// node< T >		*_endNode;
	allocator_type	new_alloc;

public:

	void printTree( void ) {

		this->_t.printTree();
		// if (this->_t.getPtrNode())
		// 	this->_t.printHelper(this->_t.getPtrNode(), "", true);
	}


// 23.3.1.1 construct/copy/destroy:
// Complexity: Constant.
	explicit map( const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), _t(new_compare), new_alloc(alloc) {
			// p1 "le premier const " p2
		}

/* CONSTRUCTOR WITH RANGE OF ITERATORS */
	template< class InputIterator >
	map( InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), _t(new_compare), new_alloc(alloc) {

			// p1 "le second" p2

		this->insert(first, last);
		// p1 " seg ? test" p2
	}

	// map( const map< Key, T, Compare, Allocator > &alloc )
	// 	: new_compare(value_compare(comp)), _t(new_compare), new_alloc(alloc) {}

	virtual
	~map( void ) {
		// p1 "la" p2
	}

	map( const map< Key, T, Compare, Allocator > &src )
		: new_compare(Compare()), _t(new_compare), new_alloc(Allocator()) {

		// p1 "un autre constructeur ??" p2
		this->insert(src.begin(), src.end());
	}

/* CONSTRUCTORS BY COPY */
	map< Key, T, Compare, Allocator > &operator=( const map< Key, T, Compare, Allocator > &rhs ) {

		// p1 "le constructeur par copie ??? mais quoi ????" p2

		if (&rhs == this)
			return *this;
		
		this->_t = rhs._t;
		this->new_alloc = rhs.new_alloc;
		this->new_compare = rhs.new_compare;

		return *this;
	}





/* ~~~~~ ITERATORS ~~~~~ */
	iterator
	begin( void ) {

		return iterator(this->_t.getMinimum(), this->_t.getPtrNode(), this->_t.getLast());
	}

	const_iterator
	begin( void ) const {

		return const_iterator(this->_t.getMinimum(), this->_t.getPtrNode(), this->_t.getLast());
	}

	iterator
	end( void ) {

		return iterator(this->_t.getLast(), this->_t.getPtrNode(), this->_t.getLast());
	}

	const_iterator
	end( void ) const {

		return const_iterator(this->_t.getLast(), this->_t.getPtrNode(), this->_t.getLast());
	}

	reverse_iterator
	rbegin( void ) {

		return reverse_iterator(this->end());
	}

	const_reverse_iterator
	rbegin( void ) const {

		return const_reverse_iterator(this->end());
	}

	reverse_iterator
	rend( void ) {

		return reverse_iterator(this->begin());
	}

	const_reverse_iterator
	rend( void ) const {

		return const_reverse_iterator(this->begin());
	}





/* ~~~~~ CAPACITY ~~~~~ */

	// bool
	// empty( void ) const {

	// 	return (this->_t._size() == 0);
	// }

	size_type
	size( void ) const {

		return this->_t.getSize();
	}

	size_type
	max_size( void ) const {

		return (static_cast< unsigned long >(std::numeric_limits< difference_type >::max() / sizeof(ft::Node< int >)));
	}





/* ~~~~~ ELEMENT ACCESS ~~~~~ */

	T
	&operator[]( const key_type &to_print ) {
	
		// iterator	tmp = ;
		// this->_t.search(this->_t.getPtrNode(), to_print);
		// if (tmp == this->_t.getLast())
		// 	ft::make_pair(this->insert(to_print), T());
		// return to_print;// tamere
	
		// insert(ft::make_pair(to_print, mapped_type()));
		// return find(to_print)->second;

		iterator	it;
		value_type	pair(to_print, T());

		if (find(to_print) == end())
			insert(pair);
		it = find(to_print);
		return (it->second);

		// return (*((insert(make_pair(to_print, T()))).first)).second; // --> non...
	}




/* ~~~~~ INSERT ~~~~~ */

	ft::pair< iterator, bool >
	insert( const value_type &to_add ) {

		// p1 "Bloque pour la valeur = " << to_add p2
		const bool	wesh = this->_t.insert(to_add);
		// p1 "la" p2
		return ft::make_pair(this->find(to_add.first), wesh);

		// const bool	r = _rbt.insert(v);
		// 	return ft::make_pair(find(v.first), r);

	}

	// iterator
	// insert( iterator position, const value_type &x ) {

	// 	iterator	tmp = this->begin();
	// 	while (tmp != position && tmp != this->end())
	// 		tmp++;
		
		
	// }

	template< class InputIterator >
	void
	insert( InputIterator first, InputIterator last ) {
	// call 1 insert

		// p1 "first = " << *first p2
		for (; first != last ; first++) {
					// p1 "first = " << *first p2

			// p1 "test" p2
			this->insert(*first);
		}

	}





/* ~~~~~ ERASE ~~~~~ */

	size_type
	erase( const key_type &value_to_del ) {

		if (find(value_to_del) == end())
			return 0;
		
		this->_t.deleteNode(find(value_to_del));
		return 1;
	}

	void
	erase( iterator position ) {

		this->eras(position->first);
	}

	void
	erase( iterator first, iterator last ) {

		for (; first != last ; first++)
			erase(first->second);
		// ou le first ???
	}





/* ~~~~~ SWAP ~~~~~ */

// 	void
// 	swap( map< Key, T, Compare, Allocator > &x ) {

// }





/* ~~~~~ CLEAR ~~~~~ */

	void
	clear( void ) {

		// this->erase(this->begin(), this->end());
		// this->new_alloc.deallocate(); // ??
		// this->_size = 0;
		this->_t.clear();
	}





/* ~~~~~ OBSERVERS ~~~~~ */
// 	key_compare
// 	key_comp( void ) const;

// 	value_compare
// 	value_comp( void ) const;





/* ~~~~~ OPERATIONS ~~~~~ */
	iterator
	find( const key_type &to_find ) {

		// const bool	r = this->_t.insert(x);
		// return ft::make_pair(this->find(x), r);
		return (iterator(this->_t.searchConst(ft::make_pair(to_find, mapped_type())), this->_t.getPtrNode(), this->_t.getLast()));
		// return iterator(this->_t, this->_t.getLast(), this->_t.searchTree(ft::make_pair(x, mapped_type())));
	}

	const_iterator
	find( const value_type &to_find ) const {

		return (const_iterator(this->_t.searchConst(ft::make_pair(to_find, mapped_type())), this->_t.getPtrNode(), this->_t.getLast()));
		// return (const_iterator(this->_t.search(to_find), this->_t.getPtrNode(), this->_t.getLast()));
	}

	// size_type
	// count( const key_type &x ) const;

	// iterator
	// lower_bound( const key_type &x );

	// const_iterator
	// lower_bound( const key_type &x ) const;

	// iterator
	// upper_bound( const key_type &x );

	// const_iterator
	// upper_bound( const key_type &x ) const;

	// ft::pair< iterator, iterator >
	// equal_range( const key_type &x );
		
	// 	ft::pair< const_iterator, const_iterator >
	// this->insert(ft::make_pair(to_add, T()));
	// 	return (this->find(to_add)->second);
	// 	equal_range( const key_type &x ) const;
	

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