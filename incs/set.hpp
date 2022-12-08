/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:54:53 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/08 12:38:17 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

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
	class T,
	class Compare = ft::less< T >,
	class Allocator = std::allocator< T > >
class set {

public:

	typedef T						key_type;
	typedef T		 				value_type;
	typedef ft::Node< value_type >	node_type;
	typedef std::size_t				size_type;
	typedef std::ptrdiff_t			difference_type;
	
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
	value_type = ft::pair< const T >
	key_compare = Compare
	Les clefs (value_type) sont triees en utilisant la fonction Compare.
*/

/* ~~~~~ ITERATOR ~~~~~ */

	typedef ft::RedBlackTreeIterator< const value_type, node_type >	iterator;
	typedef ft::RedBlackTreeIterator< const value_type, node_type >	const_iterator;
	typedef ft::reverse_iterator< const_iterator >					reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >					const_reverse_iterator;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ CLASS VALUE_COMPARE ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	class value_compare : public binary_function< value_type, value_type, bool > {

		friend class set;

		protected:

			Compare	comp;
			value_compare( key_compare c ) : comp(c) {}

		public:

			bool operator()( const value_type &x, const value_type &y ) const {
				return (comp(x, y));
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
	explicit set( const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), new_alloc(alloc), _t(new_compare) {}

	template< class InputIterator >
	set( InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator() )
		: new_compare(value_compare(comp)), new_alloc(alloc), _t(new_compare) {

		this->insert(first, last);
	}

	set( const set< T, Compare, Allocator > &src )
		: new_compare(Compare()), new_alloc(Allocator()), _t(new_compare) {

		this->insert(src.begin(), src.end());
	}

// copy
	set< T, Compare, Allocator >
	&operator=( const set< T, Compare, Allocator > &rhs ) {

		if (&rhs == this)
			return (*this);

		this->clear();
		this->insert(rhs.begin(), rhs.end());

		return (*this);
	}

	~set( void ) {}


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





/* ~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ INSERT ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~ */

	ft::pair< iterator, bool >
	insert( const value_type &to_add ) {

		const bool	insert_tree = this->_t.insert(to_add);
		return (ft::make_pair(this->find(to_add), insert_tree));
	}

	iterator
	insert( iterator position, const value_type &to_add ) {

		(void)position;
		this->_t.insert(to_add);

		return (this->find(to_add));
	}

	template< class InputIterator >
	void
	insert( InputIterator first, InputIterator last ) {

		for (; first != last ; ++first)
			this->insert(*first);

	}





/* ~~~~~~~~~~~~~~~~~ */
/* ~~~~~ ERASE ~~~~~ */
/* ~~~~~~~~~~~~~~~~~ */

	size_type
	erase( const key_type &value_to_del ) {

		return (this->_t.deleteNode(value_to_del));
	}

	void
	erase( iterator position ) {

		this->erase(*position);
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
	swap( set< T, Compare, Allocator > &x ) {

		this->_t.swap(x._t);
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

		return (iterator(this->_t.searchConst(to_find), this->_t.getPtrNode(), this->_t.getLast()));
	}

	const_iterator
	find( const key_type &to_find ) const {

		return (const_iterator(this->_t.searchConst(to_find), this->_t.getPtrNode(), this->_t.getLast()));
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

		return (iterator(_t.lower_bound(lower_key), _t.getPtrNode(), _t.getLast()));
	}

	const_iterator
	lower_bound( const key_type &lower_key ) const {

		return (const_iterator(_t.lower_bound(lower_key), _t.getPtrNode(), _t.getLast()));
	}

	iterator
	upper_bound( const key_type &upper_key ) {
	
		return (iterator(_t.upper_bound(upper_key), _t.getPtrNode(), _t.getLast()));
	}

	const_iterator
	upper_bound( const key_type &upper_key ) const {

		return (const_iterator(_t.upper_bound(upper_key), _t.getPtrNode(), _t.getLast()));
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

};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ RELATIONNAL OPERATORS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	template< class T, class Compare, class Allocator >
	bool
	operator==( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Compare, class Allocator >
	bool
	operator!=( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (!(lhs == rhs));
	}

	template< class T, class Compare, class Allocator >
	bool
	operator<( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Compare, class Allocator >
	bool
	operator>( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (!(lhs < rhs) && (lhs != rhs));
	}

	template< class T, class Compare, class Allocator >
	bool
	operator<=( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (!(lhs > rhs));
	}

	template< class T, class Compare, class Allocator >
	bool
	operator>=( const ft::set< T, Compare, Allocator > &lhs, const ft::set< T, Compare, Allocator > &rhs ) {

		return (!(lhs < rhs));
	}

	template< class T, class Compare, class Allocator >
	void
	swap( ft::set< T, Compare, Allocator > &lhs, ft::set< T, Compare, Allocator > &rhs ) {

		lhs.swap(rhs);
	}


STOP

#endif