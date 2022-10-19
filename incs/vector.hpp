/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/19 16:00:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "ft_containers.hpp"
#include "random_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

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

	vector( const self &x ) : _alloc(x._alloc) {
		size_t    i = 0;
		// this->_allocator = x.get_allocator();
		this->_ptrVector = this->_alloc.allocate(x.capacity());
		while (i < x._size) {
			this->_alloc.construct(&(this->_ptrVector[i]), x._ptrVector[i]);
			i++;
		}
		this->_size = x.size();
		this->_capacity = x.capacity();
	}

	~vector( void ) {
		
		// detruire avec deallocate ? destroy ?
		this->clear();
		this->_alloc.deallocate(this->_ptrVector, this->_capacity);
	}

	self &operator=( const self &rhs ) {
		
		if (this != &rhs)
			return *this;
		
		if (rhs._size == 0) {
			this->_size = 0;
			this->_capacity = 0;
			// this->_alloc = NULL;
			// error de compilation pour swap
			this->_ptrVector = NULL;
			return *this;
		}
		this->_size = rhs._size;
		this->_ptrVector = this->_alloc.allocate(rhs.capacity());
		if (&rhs != this)
			for (size_t i = 0 ; i < this->_size ; i++)
				this->_alloc.construct(&(this->_ptrVector[i]), rhs._ptrVector[i]);

		return *this;
	}

	void assign( size_t count, const T &value ) {
		// Replaces the contents with count copies of valeur value
		// count 	- 	the new size of the container
		// value 	- 	the value to initialize elements of the container with


		// p1 "ca passe ici ?" p2
		
		this->clear();
		// p1 RED << count << RESET p2
		if (count > this->size())
			this->reserve(count);
		for (size_t i = 0 ; i < count ; i++)
			this->_alloc.construct(&(this->_ptrVector[i]), value);
		this->_size = count;
	}

	template < class InputIterator >
	void assign( InputIterator first, InputIterator last,
	// typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type * = NULL ) {
	typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type * = NULL ) {
		// Replaces the contents with copies of those in the range [first, last).
		// The behavior is undefined if either argument is an iterator into *this.
		// This overload has the same effect as overload (1) if InputIt is an int type.

		// p1 "normalement non... " << "first = " << *first << " - last - 1 = " << *(last - 1) p2

		size_t	length = last - first;
		this->clear();
		
		// p1 RED << "length = " << length << " with size = " << this->size() << RESET p2
		if (length > this->size()) {
			// p1 "\t\treserve ?" p2
			this->reserve(length);
		}
		// p1 RED << "apres reserve" << RESET p2
		for (size_t i = 0 ; i < length && *first != *last; i++) {
			// p1 "avant" p2
			
			this->_alloc.construct(&(this->_ptrVector[i]), *first);
			// p1 "test" p2
			first++;
		}
		this->_size = length;
	}

	allocator_type get_allocator() const;

// iterators:

	iterator begin( void ) {
		return iterator(&this->_ptrVector[0]);
	}

	iterator end( void ) {
		return iterator(&this->_ptrVector[this->_size]);
	}

	const_iterator begin( void ) const {
		// p1 "test" p2
		return const_iterator(&this->_ptrVector[0]);
	}

	const_iterator end( void ) const {
		return const_iterator(&this->_ptrVector[this->_size]);
	}

	reverse_iterator rbegin( void ) {
		return reverse_iterator(this->end());
	}
	
	reverse_iterator rend( void ) {
		return reverse_iterator(this->begin());
	}
	
	const_reverse_iterator rbegin( void ) const {
		return reverse_iterator(this->end());
	}
	
	const_reverse_iterator rend( void ) const {
		return reverse_iterator(this->begin());
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
// NOOOONNN REVOIRRRRR
	void resize( size_t new_nbr_elmt, T c = T() ) {

		if (new_nbr_elmt > this->size())
			this->insert(this->end(), new_nbr_elmt - this->size(), c);
		else if (new_nbr_elmt < this->size())
			this->erase(this->begin() + new_nbr_elmt, this->end());
		else
			;
	}
	
	size_t capacity( void ) const {
		return this->_capacity;
	}
	
	bool empty( void ) const {
		return this->_size() == 0;
	}
	
	void reserve( size_t new_cap ) {
		
		if (new_cap > this->max_size()) {
			// p1 "new_cap SUP max_size()" p2
			// throw std::length_error(); // -> DOIT THROW ERROR
			return ;
		}
		else if (new_cap <= this->capacity()) {
			// p1 "new_cap INF capacity" p2
			return ;
		}
		else if (new_cap == 1 && this->capacity() <= this->size()) {
			this->_ptrVector = this->_alloc.allocate(1);
			this->_capacity = 1;
		}
		else {
			// p1 BLUE "passe" RESET p2
			T	*new_vector;
			new_vector = this->_alloc.allocate(new_cap);
			for (size_t i = 0 ; i < this->size() ; i++) {
				this->_alloc.construct(&new_vector[i], this->_ptrVector[i]);
				this->_alloc.destroy(&this->_ptrVector[i]);
			}
			this->_alloc.deallocate(this->_ptrVector, this->capacity());
			this->_capacity = new_cap;
			this->_ptrVector = new_vector;
		}
	}
	
// element access: reference

	reference operator[]( size_t index ) {
		return this->_ptrVector[index];
	}
	
	const_reference operator[]( size_t index ) const {
		return this->_ptrVector[index];
	}

	reference at( size_t index ) {
		// pour la phrase de out_of_range
		// https://en.cppreference.com/w/cpp/container/vector/at
		// vector::_M_range_check: __n (which is 6) >= this->size() (which is 6)
		std::stringstream tmp;
		tmp << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << this->size() << ")";
		
		std::string string = tmp.str();
		if (index >= this->size())
			throw std::out_of_range(string);
		return this->_ptrVector[index];
	}

	const_reference at( size_t index ) const {

		std::stringstream tmp;
		tmp << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << this->size() << ")";

		std::string string = tmp.str();
		if (index >= this->size())
			throw std::out_of_range(string);
		return this->_ptrVector[index];
	}
	
	reference front( void ) {
		return this->_ptrVector[0];
	}
	
	const_reference front( void ) const {
		return this->_ptrVector[0];	
	}
	
	reference back( void ) {
		return this->_ptrVector[this->size() - 1];
	}
	
	const_reference back( void ) const {
		return this->_ptrVector[this->size() - 1];
	}
	
// operations
	
	void push_back( const T &x ) {

		// std::cout << "i = " << this->size() << " x = " << x << std::endl;

		if (this->capacity() == 0) {
			// p1 "first time : this->size() + 1 = " << this->size() << " et this->capacity() = " << this->capacity() p2
			this->reserve(1);
		}
		else if (this->size() + 1 > this->capacity() * 2) {
			// p1 "normalement ok" p2
			this->reserve(this->size() + 1);
		}
		else if (this->size() + 1 > this->capacity()) {
			// p1 "this->size() + 1 = " << this->size() << " et this->capacity() = " << this->capacity() p2
			this->reserve(this->capacity() * 2);
		}
		// p1 "next for i = " << size() p2
		this->insert(this->end(), 1, x);
	}

	void pop_back( void ) {
		
		this->_alloc.destroy(this->end() - 1);
	}


// insere l'element a la position precisee
	iterator insert( iterator position, const T &x ) {

		this->insert(position, 0, x);
	}

// insere n element avant position 
	void insert( iterator position, size_t n, const T &x ) {

		if (this->capacity() == 0) {
			
			this->reserve(1);
		}
		else if (this->size() + n > this->capacity() * 2) {
			// p1 "normalement ok" p2
			this->reserve(this->size() + n);
		}
		else if (this->size() + n > this->capacity()) {
			// p1 "normalement ok" p2
			this->reserve(this->capacity() * 2);
		}
		if (position == this->end()) {
			for (size_t i = this->size() ; i < this->size() + n ; i++)
				this->_alloc.construct(&this->_ptrVector[i], x);
		}
		else {
			size_t pos = position - this->begin();
			for (size_t end = this->size() + n ; end > this->size() ; end--) {
				this->_alloc.construct(&this->_ptrVector[end], this->_ptrVector[this->size() - n]);
				this->_alloc.destroy(&this->_ptrVector[this->size() - n]);
			}
			for (; pos < n ; pos++) {
				this->_alloc.construct(&this->_ptrVector[pos], x);
			}
		}
		this->_size += n;
	}

	// template < class InputIterator >
	// void insert( iterator position,	InputIterator first, InputIterator last) {
		
		
	// }

	iterator erase( iterator position ) {
		
		size_t	pos = position - this->begin();
		
		this->_alloc.destroy(&this->_ptrVector[pos]);
		for (; pos < this->size() ; pos++) {
			this->_alloc.construct(&this->_ptrVector[pos], this->_ptrVector[pos + 1]);
			this->_alloc.destroy(&this->_ptrVector[pos + 1]);
		}
		this->_size -= 1;
	}

	iterator erase( iterator first, iterator last ) {
		
		size_t	pos = first - this->begin();
		size_t	i_last = last - this->begin();
		size_t	ret = i_last - pos;

		for (; pos < this->size() ; pos++) {
			this->_alloc.destroy(&this->_ptrVector[pos]);
			if (pos <= i_last && i_last + 1 != this->size())
				this->_alloc.construct(&this->_ptrVector[pos], this->_ptrVector[i_last + 1]);
		}

		this->_size -= ret;
	}

	void swap( self &x ) {
		
		self	tmp;
		tmp = x;
		x = *this;
		*this = tmp;
		
	}

	void clear( void ) {
		for (size_t i = 0 ; i != this->size() ; i++)
			this->_alloc.destroy(&_ptrVector[i]);
		// this->_alloc.deallocate(this->_ptrVector, this->_capacity);
		// utiliser aue si on a deja utiliser allocate
		this->_size = 0;
	}

	friend
	bool	operator==( const self &x, const self &y ) {
		
		if (x.size() != y.size())
			return false;
		for (size_t i = 0 ; i < x.size() ; i++) {
			if (x._ptrVector[i] != y._ptrVector[i])
				return false;
		}
		return true;
	}

	friend
	bool	operator!=( const self &x, const self &y ) {
		return (!(x == y));
	}

	friend
	bool	operator<( const self &x, const self &y ) {
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	friend
	bool	operator>( const self &x, const self &y ) {
		return (!(x < y) && x != y);
	}

	friend
	bool	operator>=( const self &x, const self &y ) {
		return (!(x < y));
	}

	friend
	bool	operator<=( const self &x, const self &y ) {
		return (!(x > y));
	}

	// specialized algorithms:
	friend
	void	swap( self &x, self &y) {
		x.swap(y);
	}

};

STOP

#endif