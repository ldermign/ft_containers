/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 15:11:49 by ldermign         ###   ########.fr       */
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
#include "lexicographical_compare.hpp"
#include "equal.hpp"
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


// que pour la cmpilation std ??
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
	typedef ft::RedBlackTreeIterator< const value_type, node_type >	const_iterator;
	typedef ft::reverse_iterator< iterator >						reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >					const_reverse_iterator;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ CLASS VALUE_COMPARE ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	class value_compare : public binary_function< value_type, value_type, bool > {

		friend class map;

		protected:

			Compare	comp;
			value_compare( key_compare c ) : comp(c) {}

		public:

			bool operator()( const value_type &x, const value_type &y ) const {
				return (comp(x.first, y.first));
			}
	};

	typedef ft::RedBlackTree< value_type, value_compare >	tree;





/* ~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ MEMBERS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~ */

private:

	value_compare	new_compare;
	allocator_type	new_alloc;
	tree			_t;





public:

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ CONSTRUCTOR - DESTRUCTOR ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// Complexity: Constant.
	explicit map( const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), new_alloc(alloc), _t(new_compare) {}

	template< class InputIterator >
	map( InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), new_alloc(alloc), _t(new_compare) {

		this->insert(first, last);
	}

	map( const map< Key, T, Compare, Allocator > &src )
		: new_compare(Compare()), new_alloc(Allocator()), _t(new_compare) {

		this->insert(src.begin(), src.end());
	}

// copy
	map< Key, T, Compare, Allocator >
	&operator=( const map< Key, T, Compare, Allocator > &rhs ) {

		if (&rhs == this)
			return (*this);

		this->clear();
		// this->new_compare = rhs.new_compare;
		// this->new_alloc = rhs.new_alloc;
		this->insert(rhs.begin(), rhs.end());

		return (*this);
	}

	~map( void ) {}


	allocator_type	get_allocator( void ) { return (this->new_alloc); }




/* ~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ ITERATORS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~ */

	iterator
	begin( void ) {

		return (iterator(this->_t.getMinimum(), this->_t.getPtrNode(), this->_t.getLast()));
	}

	const_iterator
	begin( void ) const {

		return (const_iterator(this->_t.getMinimum(), this->_t.getPtrNode(), this->_t.getLast()));
	}

	iterator
	end( void ) {

		return (iterator(this->_t.getLast(), this->_t.getPtrNode(), this->_t.getLast()));
	}

	const_iterator
	end( void ) const {

		return (const_iterator(this->_t.getLast(), this->_t.getPtrNode(), this->_t.getLast()));
	}

	reverse_iterator
	rbegin( void ) {

		return (reverse_iterator(this->end()));
	}

	const_reverse_iterator
	rbegin( void ) const {

		return (const_reverse_iterator(this->end()));
	}

	reverse_iterator
	rend( void ) {

		return (reverse_iterator(this->begin()));
	}

	const_reverse_iterator
	rend( void ) const {

		return (const_reverse_iterator(this->begin()));
	}





/* ~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ CAPACITY ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~ */

	bool
	empty( void ) const {

		return (this->size() == 0);
	}

	size_type
	size( void ) const {

		return (this->_t.getSize());
	}

	size_type
	max_size( void ) const {

		return (static_cast< unsigned long >(std::numeric_limits< difference_type >::max() / (sizeof(ft::Node< value_type >))));
	}





/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ ELEMENT ACCESS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	T
	&operator[]( const key_type &to_print ) {

		iterator	it;
		value_type	pair(to_print, T());

		if (find(to_print) == end())
			insert(pair);
		it = find(to_print);

		return (it->second);
	}





/* ~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ INSERT ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~ */

	ft::pair< iterator, bool >
	insert( const value_type &to_add ) {

		const bool	insert_tree = this->_t.insert(to_add);

		return (ft::make_pair(this->find(to_add.first), insert_tree));
	}

	iterator
	insert( iterator position, const value_type &to_add ) {

		(void)position; //changer ca
		this->_t.insert(to_add);

		return (this->find(to_add.first));
	}

	template< class InputIterator >
	void
	insert( InputIterator first, InputIterator last ) {

		for (; first != last ; first++)
			this->insert(*first);

	}





/* ~~~~~~~~~~~~~~~~~ */
/* ~~~~~ ERASE ~~~~~ */
/* ~~~~~~~~~~~~~~~~~ */

	size_type
	erase( const key_type &value_to_del ) {

		return (this->_t.deleteNode(ft::make_pair(value_to_del, mapped_type())));
	}

	void
	erase( iterator position ) {

		this->erase(position->first);
	}

	void
	erase( iterator first, iterator last ) {

		while (first != last)
			_t.deleteNode(*first++);

	}





/* ~~~~~~~~~~~~~~~~ */
/* ~~~~~ SWAP ~~~~~ */
/* ~~~~~~~~~~~~~~~~ */

	void
	swap( map< Key, T, Compare, Allocator > &x ) {

		map	tmp;
		
		tmp.new_compare = x.new_compare;
		tmp.new_alloc = x.new_alloc;
		tmp._t = x._t;

		x.new_compare = this->new_compare;
		x.new_alloc = this->new_alloc;
		x._t = this->_t;

		this->new_compare = tmp.new_compare;
		this->new_alloc = tmp.new_alloc;
		this->_t = tmp._t;
}




/* ~~~~~~~~~~~~~~~~~ */
/* ~~~~~ CLEAR ~~~~~ */
/* ~~~~~~~~~~~~~~~~~ */

	void
	clear( void ) {

		this->_t.clear();
	}





/* ~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ OBSERVERS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~ */

	key_compare
	key_comp( void ) const {

		return (key_compare());
	}

	value_compare
	value_comp( void ) const {

		return (value_compare(this->key_comp()));
	}





/* ~~~~~~~~~~~~~~~~ */
/* ~~~~~ FIND ~~~~~ */
/* ~~~~~~~~~~~~~~~~ */

	iterator
	find( const key_type &to_find ) {

		return (iterator(this->_t.searchConst(ft::make_pair(to_find, mapped_type())), this->_t.getPtrNode(), this->_t.getLast()));
	}

	const_iterator
	find( const key_type &to_find ) const {

		return (const_iterator(this->_t.searchConst(ft::make_pair(to_find, mapped_type())), this->_t.getPtrNode(), this->_t.getLast()));
	}





/* ~~~~~~~~~~~~~~~~~ */
/* ~~~~~ COUNT ~~~~~ */
/* ~~~~~~~~~~~~~~~~~ */

	size_type
	count( const key_type &value ) const {

		return (this->find(value) != this->end());
	}





/* ~~~~~~~~~~~~~~~~~ */
/* ~~~~~ BOUND ~~~~~ */
/* ~~~~~~~~~~~~~~~~~ */
// https://cplusplus.com/reference/algorithm/lower_bound/?kw=lower_bound

	iterator
	lower_bound( const key_type &lower_key ) {

		iterator	tmp = this->begin();

		while (tmp != this->end()) {
			if (tmp.getCurrent()->data.first >= lower_key)
				break ;
			tmp++;
		}

		return (tmp);
	}

	const_iterator
	lower_bound( const key_type &lower_key ) const {

		const_iterator	tmp = this->begin();

		while (tmp != this->end()) {
			if (tmp.getCurrent()->data.first >= lower_key)
				break ;
			tmp++;
		}

		return (tmp);
	}

	iterator
	upper_bound( const key_type &upper_key ) {

		iterator	tmp = this->begin();

		while (tmp != this->end()) {
			if (tmp.getCurrent()->data.first > upper_key)
				break ;
			tmp++;
		}

		return (tmp);
	}

	const_iterator
	upper_bound( const key_type &upper_key ) const {

		const_iterator	tmp = this->begin();

		while (tmp != this->end()) {
			if (tmp.getCurrent()->data.first > upper_key)
				break ;
			tmp++;
		}

		return (tmp);
	}





/* ~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ EQUAL RANGE ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~ */

// Returns a range containing all elements with the given key in the container.
// The range is defined by two iterators, one pointing to the first element
// that is not less than key and another pointing to the first element greater
// than key. Alternatively, the first iterator may be obtained with lower_bound(),
// and the second with upper_bound().
// Compares the keys to key.

	ft::pair< iterator, iterator >
	equal_range( const key_type &key ) {

		iterator	first = this->lower_bound(key);
		iterator	last = this->upper_bound(key);

		return (ft::make_pair(first, last));
	}

	ft::pair< const_iterator, const_iterator >
	equal_range( const key_type &key ) const {

		const_iterator	first = this->lower_bound(key);
		const_iterator	last = this->upper_bound(key);

		return (ft::make_pair(first, last));
	}





/* ~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ OTHERS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~ */

	void
	printTree( void ) {

		this->_t.printTree();
	}

};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ RELATIONNAL OPERATORS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator==( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator!=( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator<( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator>( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		return (!(lhs < rhs) && (lhs != rhs));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator<=( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		return (!(lhs > rhs));
	}

	template< class Key, class T, class Compare, class Allocator >
	bool
	operator>=( const ft::map< Key, T, Compare, Allocator > &lhs, const ft::map< Key, T, Compare, Allocator > &rhs ) {

		return (!(lhs < rhs));
	}

	template< class Key, class T, class Compare, class Allocator >
	void
	swap( ft::map< Key, T, Compare, Allocator > &lhs, ft::map< Key, T, Compare, Allocator > &rhs ) {

		lhs.swap(rhs);
	}


STOP

#endif