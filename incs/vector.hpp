/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/05 16:12:23 by ldermign         ###   ########.fr       */
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

template< class T, class Allocator = std::allocator< T > >
class vector {

private:

	T				*_ptrVector;

	Allocator		_alloc;
	unsigned int	_size;
	unsigned int	_capacity;

public:
// types:

	typedef vector< T, Allocator >  self;

	typedef T								value_type;
	typedef value_type &					reference;
	typedef const value_type &				const_reference;
	typedef ft::random_iterator< T >		iterator;
	typedef ft::random_iterator< const T >	const_iterator;
	typedef size_t							size_type;


	typedef Allocator							allocator_type;
typedef	typename allocator_type::difference_type	difference_type;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;

	typedef ft::reverse_iterator< iterator >		reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >	const_reverse_iterator;


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

	template < class InputIterator >
	vector( InputIterator first, InputIterator last, const Allocator &x = Allocator(),
		typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type * = NULL )
		: _ptrVector(NULL), _alloc(x), _size(0), _capacity(0) {

		size_t	new_size = ft::distance(first, last);
		reserve(new_size);
		for (size_t i = 0 ; i < new_size ; i++) {
			this->_alloc.construct(&this->_ptrVector[i], *first);
			first++;
		}
		this->_size = new_size;
	}

	vector( const self &x )
		: _alloc(x._alloc) {

		size_t    i = 0;
		this->_ptrVector = this->_alloc.allocate(x.capacity());
		while (i < x.size()) {
			this->_alloc.construct(&(this->_ptrVector[i]), x._ptrVector[i]);
			i++;
		}
		this->_size = x.size();
		this->_capacity = x.capacity();
	}

	self
	&operator=( const self &rhs ) {

		if (this == &rhs)
			return (*this);

		this->~vector();
		this->_size = rhs.size();
		this->_capacity = rhs.capacity();
		this->_ptrVector = this->_alloc.allocate(rhs.capacity());

		if (&rhs != this)
			for (size_t i = 0 ; i < this->_size ; i++)
				this->_alloc.construct(&(this->_ptrVector[i]), rhs._ptrVector[i]);

		return (*this);
	}

/* ~~~~~ DESTRUCTOR ~~~~~ */

	~vector( void ) {
		
		this->clear();
		if (this->_ptrVector != NULL)
			this->_alloc.deallocate(this->_ptrVector, this->capacity());
	}





/* ~~~~~ ASSIGN ~~~~~ */

	void
	assign( size_t count, const T &value ) {

		this->clear();
		// if (this->_ptrVector != NULL)
		// 	this->_alloc.deallocate(this->_ptrVector, this->capacity());
		if (count > this->size())
			this->reserve(count);
		for (size_t i = 0 ; i < count ; i++)
			this->_alloc.construct(&(this->_ptrVector[i]), value);
		this->_size = count;
	}

	template < class InputIterator >
	void
	assign( InputIterator first, InputIterator last,
	typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type * = NULL ) {
		// Replaces the contents with copies of those in the range [first, last).
		// The behavior is undefined if either argument is an iterator into *this.
		// This overload has the same effect as overload (1) if InputIt is an int type.

		size_t	length = ft::distance(first, last);
		this->clear();
		
		if (length > this->size())
			this->reserve(length);
		for (size_t i = 0 ; i < length ; i++) {			
			this->_alloc.construct(&(this->_ptrVector[i]), *first);
			first++;
		}
		this->_size = length;
	}





/* ~~~~~ ALLOCATOR ~~~~~ */

	allocator_type	get_allocator( void ) const { return (this->_alloc); }





/* ~~~~~ ITERATORS ~~~~~ */

	iterator
	begin( void ) {

		return (iterator(this->_ptrVector));
	}

	iterator
	end( void ) {

		return (iterator(&this->_ptrVector[this->_size]));
	}

	const_iterator
	begin( void ) const {

		return (const_iterator(this->_ptrVector));
	}

	const_iterator
	end( void ) const {

		return (const_iterator(&this->_ptrVector[this->_size]));
	}

	reverse_iterator
	rbegin( void ) {

		return (reverse_iterator(this->end()));
	}
	
	reverse_iterator
	rend( void ) {

		return (reverse_iterator(this->begin()));
	}
	
	const_reverse_iterator
	rbegin( void ) const {

		return (const_reverse_iterator(this->end()));
	}
	
	const_reverse_iterator
	rend( void ) const {

		return (const_reverse_iterator(this->begin()));
	}





/* ~~~~~ SIZE ~~~~~ */

	size_t
	size( void ) const {

		return (this->_size);
	}





/* ~~~~~ MAX_SIZE ~~~~~ */
	
	size_t
	max_size( void ) const {

		return (this->_alloc.max_size());
// retourne le nombre d'element maximum que le container peut contenir
// avec les limitations du system / de la lib
	}





/* ~~~~~ RESIZE ~~~~~ */

	void
	resize( size_t nbr_element, T c = T() ) {

		if (nbr_element > this->max_size())
			throw std::length_error("vector::resize");

		size_t	end = this->end() - this->begin() - 1;

		if (nbr_element < this->size()) {
			for (; this->size() > nbr_element ; end--, this->_size--)
				this->_alloc.destroy(&this->_ptrVector[end]);
		}
		else {
			if (nbr_element > this->capacity()
				&& this->capacity() * 2 >= nbr_element)
				this->reserve(this->capacity() * 2);
			else if (nbr_element > this->capacity())
				this->reserve(nbr_element);
			for (; this->_size < nbr_element ; this->_size++)
				this->_alloc.construct(&this->_ptrVector[this->size()], c);
		}

	}





/* ~~~~~ CAPACITY ~~~~~ */

	size_t
	capacity( void ) const {

		// p1 "capacity = " << this->_capacity p2
		return (this->_capacity);
	}





/* ~~~~~ EMPTY ~~~~~ */
	
	bool
	empty( void ) const {

		return (this->size() == 0);
	}





/* ~~~~~ RESERVE ~~~~~ */
	
	void
	reserve( size_t new_cap ) {
		
		if (new_cap > this->max_size())
			throw (std::length_error("vector::reserve"));
		else if (new_cap <= this->capacity())
			return ;

		else {
			T	*new_vector;
			new_vector = this->_alloc.allocate(new_cap);
			for (size_t i = 0 ; i < this->size() ; i++) {
				this->_alloc.construct(&new_vector[i], this->_ptrVector[i]);
				this->_alloc.destroy(&this->_ptrVector[i]);
			}
			if (this->_ptrVector != NULL)
				this->_alloc.deallocate(this->_ptrVector, this->capacity());
			this->_capacity = new_cap;
			this->_ptrVector = new_vector;
		}
	}





/* ~~~~~ OPERATOR [] ~~~~~ */

	reference
	operator[]( size_t index ) {

		return (this->_ptrVector[index]);
	}
	
	const_reference
	operator[]( size_t index ) const {

		return (this->_ptrVector[index]);
	}





/* ~~~~~ AT ~~~~~ */

	reference
	at( size_t index ) {

		// pour la phrase de out_of_range
		// https://en.cppreference.com/w/cpp/container/vector/at
		// vector::_M_range_check: __n (which is 6) >= this->size() (which is 6)
		std::stringstream tmp;
		tmp << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << this->size() << ")";
		
		std::string string = tmp.str();
		if (index >= this->size())
			throw std::out_of_range(string);

		return (this->_ptrVector[index]);
	}

	const_reference
	at( size_t index ) const {

		std::stringstream tmp;
		tmp << "vector::_M_range_check: __n (which is " << index << ") >= this->size() (which is " << this->size() << ")";

		std::string string = tmp.str();
		if (index >= this->size())
			throw std::out_of_range(string);

		return (this->_ptrVector[index]);
	}





/* ~~~~~ FRONT ~~~~~ */

	reference
	front( void ) {

		return (this->_ptrVector[0]);
	}
	
	const_reference
	front( void ) const {

		return (this->_ptrVector[0]);	
	}





/* ~~~~~ BACK ~~~~~ */

	reference
	back( void ) {

		return (this->_ptrVector[this->size() - 1]);
	}
	
	const_reference
	back( void ) const {

		return (this->_ptrVector[this->size() - 1]);
	}





/* ~~~~~ PUSH_BACK ~~~~~ */
	
	void
	push_back( const T &x ) {

		this->insert(this->end(), x);
	}





/* ~~~~~ POP_BACK ~~~~~ */

	void
	pop_back( void ) {

		this->_alloc.destroy(this->_ptrVector + this->size() - 1);
		this->_size--;
	}





/* ~~~~~ INSERT ~~~~~ */

	iterator
	insert( iterator position, const T &value ) {

		insert(position, 1, value);
		return (position);
	}

	void
	insert( iterator position, size_t length, const T &x ) {

		if (length == 0)
			return ;

		size_t ret = position - this->begin();
		size_t	diff = this->size() - ret;

		if (this->capacity() < this->size() + length
			&& this->size() * 2 > this->size() + length)
			this->reserve(2 * this->size());
		else
			this->reserve(this->size() + length);

		if (iterator(&this->_ptrVector[ret]) == this->end()) {
			for (size_t i = this->size() ; i < this->size() + length ; i++)
				this->_alloc.construct(&this->_ptrVector[i], x);
		}
		else {
			size_t i_end = this->size() + length - 1;
			for (; diff > 0 ; diff--) {
				this->_alloc.construct(&this->_ptrVector[i_end], this->_ptrVector[i_end - length]);
				this->_alloc.destroy(&this->_ptrVector[i_end - length]);
				i_end--;
				p1 "ici ca tourne beaucoup" p2
			}
			i_end -= length;
			for (; i_end > ret ; i_end--) {
				this->_alloc.destroy(&this->_ptrVector[i_end]);
				p1 "la aussi j'imagine..." p2
			}
			for (size_t i = 0 ; i < length ; i++) {
				this->_alloc.construct(&this->_ptrVector[ret], x);
				ret++;
				p1 "et puis la tant qu'a faire" p2
			}
		}

		this->_size += length;
	}

	template < class InputIterator >
	void
	insert( iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type * = NULL ) {

		size_t		pos = position - this->begin();
		size_t		length = ft::distance(first, last);
		size_t		diff = this->size() - pos;

		if (length == 0)
			return ;

		if (this->capacity() < this->size() + length
			&& this->size() * 2 > this->size() + length)
			this->reserve(2 * this->size());
		else
			this->reserve(this->size() + length);


		// if (iterator(&this->_ptrVector[pos]) == this->end()) {
		// 	for (size_t i = this->size() ; i < this->size() + length ; i++)
		// 		this->_alloc.construct(&this->_ptrVector[i], x);
		// }
		// else {
		size_t i_end = this->size() + length - 1;
		for (; diff > 0 ; diff--) {
			this->_alloc.construct(&this->_ptrVector[i_end], this->_ptrVector[i_end - length]);
			this->_alloc.destroy(&this->_ptrVector[i_end - length]);
			i_end--;
		}
		i_end -= length;
		for (; i_end > pos ; i_end--)
			this->_alloc.destroy(&this->_ptrVector[i_end]);
		for (; first != last ; first++) {
			this->_alloc.construct(&this->_ptrVector[pos], *first);
			pos++;
		}
		// }

		this->_size += length;
	}





/* ~~~~~ ERASE ~~~~~ */

	iterator	erase( iterator position ) {
		
		size_t	pos = position - this->begin();

		for (; pos < this->size() ; pos++) {
			this->_alloc.destroy(&this->_ptrVector[pos]);
			if (iterator(&this->_ptrVector[pos + 1]) != this->end())
				this->_alloc.construct(&this->_ptrVector[pos], this->_ptrVector[pos + 1]);

		}
		this->_size -= 1;

		if (iterator(&this->_ptrVector[pos]) == this->end())
			return (this->end());

		return (position);		
	}

	iterator	erase( iterator first, iterator last ) {
		
		while (first != last) {
			this->erase(first);
			last--;
		}

		return first;
	}







/* ~~~~~ SWAP ~~~~~ */

	void
	swap( self &x ) {
		
		T				*type_tmp = x._ptrVector;
		Allocator		alloc_tmp = x._alloc;
		unsigned int	size_tmp = x._size;
		unsigned int	capacity_tmp = x._capacity;

		x._ptrVector = this->_ptrVector;
		x._alloc = this->_alloc;
		x._size = this->_size;
		x._capacity = this->_capacity;

		this->_ptrVector = type_tmp;
		this->_alloc = alloc_tmp;
		this->_size = size_tmp;
		this->_capacity = capacity_tmp;
	}

	friend void
	swap( self &x, self &y) {

		x.swap(y);
	}





/* ~~~~~ CLEAR ~~~~~ */

	void
	clear( void ) {

		for (size_t i = 0 ; i != this->size() ; i++)
			this->_alloc.destroy(&_ptrVector[i]);

		this->_size = 0;
	}





/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* ~~~~~ RELATIONNAL OPERATORS ~~~~~ */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

	friend bool
	operator==( const self &lhs, const self &rhs ) {

		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0 ; i < lhs.size() ; i++) {
			if (lhs._ptrVector[i] != rhs._ptrVector[i])
				return false;
		}
		return true;
	}

	friend bool
	operator!=( const self &lhs, const self &rhs ) {

		return (!(lhs == rhs));
	}

	friend bool
	operator<( const self &lhs, const self &rhs ) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	friend bool
	operator>( const self &lhs, const self &rhs ) {

		return (!(lhs < rhs) && (lhs != rhs));
	}

	friend bool
	operator<=( const self &lhs, const self &rhs ) {

		return (!(lhs > rhs));
	}

	friend bool
	operator>=( const self &lhs, const self &rhs ) {

		return (!(lhs < rhs));
	}

};

STOP

#endif