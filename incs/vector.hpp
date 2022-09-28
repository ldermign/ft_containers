/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/28 15:44:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include "ft_containers.hpp"

START

template < class T, class Allocator = std::allocator< T > >
class vector : public iterator_traits {

public:
// types:
	// typedef typename Allocator::reference reference;
	// typedef typename Allocator::const_reference const_reference;
	// typedef implementation defined iterator;
	// typedef implementation defined const_iterator;
	// typedef implementation defined size_type;
	// typedef implementation defined difference_type;
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer
	typedef ft::reverse_iterator< iterator > reverse_iterator;
	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;
	explicit vector( const Allocator & = Allocator() );
	explicit vector( size_type n, const T& value = T(), const Allocator & = Allocator() );

	template < class InputIterator >
	vector( InputIterator first, InputIterator last, const Allocator & = Allocator() );

	vector( const vector< T, Allocator > &x );
	~vector();

	vector< T, Allocator > &operator=( const vector< T, Allocator > &x );
	template < class InputIterator >
	void assign( InputIterator first, InputIterator last );
	void assign( size_type n, const T &u );
	
	allocator_type get_allocator() const;
	// iterators:
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	size_type size() const;
	size_type max_size() const;
	void resize( size_type sz, T c = T() );
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);
	
	// element access:
	reference operator[]( size_type n );
	const_reference operator[]( size_type n ) const;
	const_reference at( size_type n ) const;
	reference at( size_type n );
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;
	void push_back( const T &x );
	void pop_back();
	iterator insert( iterator position, const T &x );
	void insert( iterator position, size_type n, const T &x );
	template < class InputIterator >
	void insert( iterator position,	InputIterator first, InputIterator last);
	iterator erase( iterator position );
	iterator erase( iterator first, iterator last );
	void swap( vector< T, Allocator > & );
	void clear();

	template < class T, class Allocator >
	bool operator==( const vector< T, Allocator > &x,
	const vector< T, Allocator> &y );
	template < class T, class Allocator >
	bool operator< ( const vector< T,Allocator > &x,
	const vector< T, Allocator > &y );
	template < class T, class Allocator >
	bool operator!=( const vector< T, Allocator > &x,
	const vector< T, Allocator > &y);
	template < class T, class Allocator >
	bool operator> ( const vector< T, Allocator > &x,
	const vector< T, Allocator> &y );
	template < class T, class Allocator >
	bool operator>=( const vector< T, Allocator > &x,
	const vector< T, Allocator > &y );
	template < class T, class Allocator >
	bool operator<=( const vector< T, Allocator > &x,
	const vector< T, Allocator > &y );
	// specialized algorithms:
	template< class T, class Allocator >
	void swap( vector< T, Allocator > &x, vector< T, Allocator > &y);
	

//	CANONICAL FORM

	// vector( void );
	// vector	&operator=( const vector &rhs );
	// vector( const vector &src );
	// virtual	~vector( void );

private:

	T 				*_ptr;
	Allocator		_alloc;
	unsigned int	_size;
	unsigned int	_capacity;
	
};

STOP

#endif