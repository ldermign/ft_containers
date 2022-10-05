/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/05 14:31:02 by ldermign         ###   ########.fr       */
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

	T				*_ptrVector;
	
	Allocator		_alloc;
	unsigned int	_size; // ou type size_t
// nombre d'element dans le vector
	unsigned int	_capacity; // ou type size_t
// capcite dans la stack possible

// max_size
// nombre d'element maximum du vector

public:
// types:

	typedef vector< T, Allocator >  self;

	typedef T value_type;
	typedef value_type & reference;
	typedef const value_type & const_reference;
	typedef ft::random_iterator< T > iterator;
	typedef ft::random_iterator< const T > const_iterator;
	// typedef size_t size_type; // -> juste pour dire que size_t correspond a size_type
	// du code en plus pour rien ?
	// typedef implementation defined difference_type;

	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::reverse_iterator< iterator > reverse_iterator;
	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

	explicit vector( const Allocator &x = Allocator() )
		: _ptrVector(NULL), _alloc(x), _size(0), _capacity(0) {}
	
	explicit vector( size_t n, const T &value = T(), const Allocator &x = Allocator() )
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
		this->clear();
		this->_alloc.deallocate(this->_ptrVector, this->_capacity);
	}

	self &operator=( const self &x );
	template < class InputIterator >
	void assign( InputIterator first, InputIterator last );
	void assign( size_t n, const T &u );
	
	allocator_type get_allocator() const;

// iterators:

	iterator begin( void ) {
		return iterator(_ptrVector);
	}
	
	const_iterator cbegin( void ) const {
		return const_iterator(_ptrVector);
	}
	
	iterator end( void ) {
		return iterator(&_ptrVector[_size]);
	}

	const_iterator cend( void ) const {
		return const_iterator(&_ptrVector[_size]);
	}

	reverse_iterator rbegin( void ) {
		return iterator(&_ptrVector[_size]);
	}
	
	const_reverse_iterator crbegin( void ) const {
		return const_iterator(&_ptrVector[_size]);
	}

	reverse_iterator rend( void ) {
		return iterator(_ptrVector);
	}

	const_reverse_iterator crend( void ) const {
		return const_iterator(_ptrVector);
	}
	
	size_t size( void ) const {
		return this->_size;
	}
	
	size_t max_size( void ) const {
		return _alloc.max_size();
// retourne le nombre d'element maximum que le container peut contenir
// avec les limitations du system / de la lib
	}
	
// ok ???
	// void resize( size_t new_nbr_elmt, T c = T() ) {

	// 	if (new_nbr_elmt > this->size())
	// 		this->insert(this->end(), new_nbr_elmt - this->size(), c);
	// 	else if (new_nbr_elmt < this->size())
	// 		this->erase(this->begin() + new_nbr_elmt, this->end());
	// 	else
	// 		;
	// }
	
	size_t capacity( void ) const {
		return this->_capacity;
	}
	
	bool empty( void ) const {
		return (this->_size() == 0);
	}
	
	void reserve( size_t new_cap ) {
		
		if (new_cap > this->max_size())
			return ;
			// throw std::length_error(); -> DOIT THROW ERROR
		else if (new_cap < this->capacity())
			return ;
		else {
			T *new_vector;
			new_vector = _alloc.allocate(new_cap);
			for (size_t i = 0 ; i < this->size() ; i++) {
				this->_alloc.construct(&new_vector[i], _ptrVector[i]);
				this->_alloc.destroy(&this->_ptrVector[i]);
			}
			this->_alloc.deallocate(this->_ptrVector, this->capacity());
			this->_capacity = new_cap;
			this->_ptrVector = new_vector;			
		}
	}
	
// element access: reference

	// reference operator[]( size_t n );
	// const_reference operator[]( size_t n ) const;
	// const_reference at( size_t n ) const;
	// reference at( size_t n );
	// reference front( void );
	// const_reference front( void ) const;
	// reference back( void );
	// const_reference back( void ) const;
	
// operations
	
	void push_back( const T &x ) {

		this->insert(this->end(), x);
	}

// push_back(const _Tp& __x)
// 	{
// 		bool __realloc = _M_requires_reallocation(this->size() + 1);
// 		_Base::push_back(__x);
// 		if (__realloc)
// 			this->_M_invalidate_all();
// 		_M_update_guaranteed_capacity();
// 	}

	// void pop_back( void );


// insere l'element a la position precisee
	iterator insert( iterator position, const T &x ) {
		(void)x;

		size_t at = position - this->begin();
		std::cout << at << std::endl;
		T	next = this->_ptrVector[at];

		if (this->capacity() == 0)
			reserve(1);
		else if (this->size() + 1 > this->capacity())
			reserve(this->capacity() * 2);
		
		// destroy juste avant ?
		this->_alloc.destroy(&_ptrVector[at]);
		_alloc.construct(&this->_ptrVector[at], x);
		at++;
		for (; at != this->size() ; at++) {
			next = this->_ptrVector[at];
			this->_alloc.destroy(&_ptrVector[at]);
			this->_alloc.construct(&this->_ptrVector[at], next);
		}
		// size_t		i = 0;
		// iterator	itPos = this->begin();
		// // std::cout << "size = " << this->size() << std::endl;
		// this->reserve(this->size() + 1);

		// size_t end = position - this->begin();
		// commencer par la fin

		this->_size++;
		return (position);
		// attention ! differe en fonction des cas
	}

// insere n element avant position 
	// void insert( iterator position, size_t n, const T &x );
	
	// template < class InputIterator >
	// void insert( iterator position,	InputIterator first, InputIterator last);
	
	// iterator erase( iterator position );
	
	// iterator erase( iterator first, iterator last );

	// void swap( self & );
	
	void clear( void ) {
		for (size_t i = 0 ; i != this->size() ; i++)
			this->_alloc.destroy(&_ptrVector[i]);
		// this->_alloc.deallocate(this->_ptrVector, this->_capacity);
		// utiliser aue si on a deja utiliser allocate
		this->_size = 0;
	}

	friend
	bool	operator==( const self &x, const vector< T, Allocator> &y );
	
	friend
	bool	operator<( const self &x, const self &y );
	
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