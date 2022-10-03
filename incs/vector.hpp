/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/03 15:46:21 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
// #include <new>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "ft_containers.hpp"
#include "random_iterator.hpp"

START

template < class T, class Allocator = std::allocator< T > >
class vector {

private:

	T 				*_ptrVector;
	Allocator		_alloc;
	unsigned int	_size; // ou type size_type
	unsigned int	_capacity; // ou type size_type

public:
// types:

	typedef vector< T, Allocator >  self;

	typedef T value_type;
	typedef value_type & reference;
	typedef const value_type & const_reference;
	typedef ft::random_iterator< T > iterator;
	typedef ft::random_iterator< const T > const_iterator;
	typedef size_t size_type;
	// typedef implementation defined difference_type;

	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::reverse_iterator< iterator > reverse_iterator;
	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

	explicit vector( const Allocator &x = Allocator() )
		: _ptrVector(NULL), _alloc(x), _size(0), _capacity(0) {}
	
	explicit vector( size_type n, const T &value = T(), const Allocator &x = Allocator() )
		: _alloc(x), _size(n), _capacity(n) {

		// utiliser une fct d'allocation de alloc pour donner la bonne taille au ptr de vector
		// https://en.cppreference.com/w/cpp/memory/allocator/allocate
		// https://cplusplus.com/reference/memory/allocator/construct/
		_ptrVector = _alloc.allocate(_capacity); // ou x._capacity ??

		// construire autant d'element que de n
		// https://en.cppreference.com/w/cpp/memory/allocator/construct
		for (size_t i = 0 ; i < n ; i++)
			_alloc.construct(&_ptrVector[i], value);
			// new(_ptrVector[i]) T(value);
			// void construct(pointer p, const T& val)    { new(p) T(val); }
		}

// ne pas utiliser jusqu'a enable_if
	// template < class InputIterator >
	// vector( InputIterator first, InputIterator last, const Allocator & = Allocator() ) {
		
	// }

	vector( const self &x ) {
		// : _ptrVector(NULL), _alloc(x), _size(0), _capacity(0) {
		(void)x;
	}
	
	~vector( void ) {
		
		// detruire avec deallocate ? destroy ?
		this->_alloc.deallocate(this->_ptrVector, this->_capacity);
		this->_alloc.destroy(this->_ptrVector);
	}

	self &operator=( const self &x );
	template < class InputIterator >
	void assign( InputIterator first, InputIterator last );
	void assign( size_type n, const T &u );
	
	allocator_type get_allocator() const;

	// iterators:
	iterator begin( void ) {

		return iterator(_ptrVector);
	}
	
	const_iterator begin( void ) const {

		return const_iterator(_ptrVector);
	}
	
	iterator end( void ) {

		return iterator(_ptrVector + _size);
	}

	// const_iterator end( void ) const;
	// reverse_iterator rbegin( void );
	// const_reverse_iterator rbegin( void ) const;
	// reverse_iterator rend( void );
	// const_reverse_iterator rend( void ) const;
	// size_type size( void ) const;
	// size_type max_size( void ) const;
	
	// ok ???
	// void resize( size_type sz, T c = T() ) {
	
	// 	if (sz > size())
	// 		insert(end(), sz - size(), c);
	// 	else if (sz < size())
	// 		erase(begin() + sz, end());
	// 	else
	// 		;
	// }
	
	// size_type capacity( void ) const;
	// bool empty( void ) const;
	// void reserve( size_type n );
	
	// // element access:
	// reference operator[]( size_type n );
	// const_reference operator[]( size_type n ) const;
	// const_reference at( size_type n ) const;
	// reference at( size_type n );
	// reference front( void );
	// const_reference front( void ) const;
	// reference back( void );
	// const_reference back( void ) const;
	
	// void push_back( const T &x ) {
		
	// }

	// void pop_back( void );
	// iterator insert( iterator position, const T &x );
	// void insert( iterator position, size_type n, const T &x );
	// template < class InputIterator >
	// void insert( iterator position,	InputIterator first, InputIterator last);
	// iterator erase( iterator position );
	// iterator erase( iterator first, iterator last );
	// void swap( self & );
	// void clear( void );

	friend
	bool	operator==( const self &x, const vector< T, Allocator> &y );
	
	friend
	bool	operator< ( const self &x, const self &y );
	
	friend
	bool	operator!=( const self &x, const self &y );
	
	friend
	bool	operator>( const self &x, const vector< T, Allocator> &y );
	
	friend
	bool	operator>=( const self &x, const self &y );
	
	friend
	bool	operator<=( const self &x, const self &y );
	
	// specialized algorithms:
	friend
	void	swap( self &x, self &y);
	

//	CANONICAL FORM

	// vector( void );
	// vector	&operator=( const vector &rhs );
	// vector( const vector &src );
	// virtual	~vector( void );
	
};

STOP

#endif