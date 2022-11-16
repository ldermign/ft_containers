/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:33 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/16 11:48:17 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "ft_containers.hpp"
#include "reverse_iterator.hpp" // ?????
#include "pair.hpp"
#include "less.hpp"

START

// template<
// 	class Key,
// 	class T,
// 	class Compare = ft::less< Key >,
// 	class Allocator = std::allocator< ft::pair< const Key, T > > >
// class map : public ft::iterator< ft::bidirectional_iterator_tag, T > {

// private:



// public:
// // types:
// 	typedef Key									key_type;
// 	typedef T									mapped_type;
// 	typedef ft::pair< const Key, T >			value_type;
// 	typedef Compare								key_compare;

// 	typedef Allocator							allocator_type;
// 	typedef value_type&					reference;
// 	typedef const value_type&	const_reference;

// 	// typedef iterator; // See 23.1
// 	// typedef const_iterator; // See 23.1
// 	// typedef size_type; // See 23.1
// 	// typedef difference_type;// See 23.1

// 	typedef typename Allocator::pointer					pointer;
// 	typedef typename Allocator::const_pointer			const_pointer;

	
// 	typedef ft::reverse_iterator< iterator >		reverse_iterator;
// 	typedef ft::reverse_iterator< const_iterator >	const_reverse_iterator;
// // creer iterator bibdirectionnel et faire un typename

// 	class value_compare : public binary_function< value_type, value_type, bool > {

// 		friend class map;

// 		protected:

// 			Compare comp;
// 			value_compare( key_compare c ) : comp(c) {}

// 		public:

// 			bool operator()( const value_type &x, const value_type &y ) const {
// 				return comp(x.first, y.first);
// 			}
// 	};

// // 23.3.1.1 construct/copy/destroy:
// 	explicit map( const Compare &comp = Compare(), const Allocator &t = Allocator() );
	
// 	template< class InputIterator >
// 	map( InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &t = Allocator() );
	
// 	map( const map< Key, T, Compare, Allocator > &x );
	
// 	virtual	~map( void ) {}

// 	map< Key, T, Compare, Allocator > &operator=( const map< Key, T, Compare, Allocator> &x );

// // iterators:
// 	iterator
// 	begin( void );

// 	const_iterator
// 	begin( void ) const;

// 	iterator
// 	end( void );

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

// // capacity:
// 	bool
// 	empty( void ) const;

// 	size_type
// 	size( void ) const;

// 	size_type
// 	max_size( void ) const;


// // 23.3.1.2 element access:
// 	T &operator[]( const key_type &x );

// // modifiers:
// 	ft::pair< iterator, bool >
// 	insert( const value_type &x );

// 	iterator
// 	insert( iterator position, const value_type &x );

// 	template< class InputIterator >
// 	void
// 	insert( InputIterator first, InputIterator last );

// 	void
// 	erase( iterator position );

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
	
// 	};

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator==( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator!=( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator<( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator>( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator>=( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// 	template< class Key, class T, class Compare, class Allocator >
// 	bool
// 	operator<=( const map< Key, T, Compare, Allocator > &x, const map< Key, T, Compare, Allocator > &y);

// // specialized algorithms:
// 	template< class Key, class T, class Compare, class Allocator >
// 	void
// 	swap( map< Key, T, Compare, Allocator > &x, map< Key, T, Compare, Allocator > &y );

// }

STOP

#endif