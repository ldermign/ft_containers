/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:45:47 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/17 14:58:43 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
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

	// typedef typename	ft::random_iterator< const T >::const_iterator const_iterator;

	typedef Allocator allocator_type;
	typedef typename Allocator::pointer pointer;
	typedef typename Allocator::const_pointer const_pointer;
	typedef ft::reverse_iterator< iterator > reverse_iterator;
	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator;

//cat ft.txt && cat std.txt
// make && ./ft_containers > ft.txt && ./std_containers > std.txt && diff -y -W 60 --suppress-common-lines ft.txt std.txt

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
		while (i < x._size)
		{
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

	self &operator=( const self &x ) {
		
	}
	
	template < class InputIterator >
	void assign( InputIterator first, InputIterator last ) {
		// Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument is an iterator into *this.
		// This overload has the same effect as overload (1) if InputIt is an integral type.
		(void)firstl;(void)last;

	}

	void assign( size_t n, const T &u ) {
		// Replaces the contents with count copies of value value
		(void)u;(void)n;
		
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
		// if (index < 0 || index > this->size())
		// 	throw std::out_of_range();
		return this->_ptrVector[index];
	}

	const_reference at( size_t index ) const {
		// if (index < 0 || index > this->size())
		// 	throw std::out_of_range();
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
			// p1 "dernier cas ?" p2
			this->reserve(this->size() + 1);
		}
		else if (this->size() + 1 > this->capacity()) {
			// p1 "normalement ok" p2
			// p1 "this->size() + 1 = " << this->size() << " et this->capacity() = " << this->capacity() p2
			this->reserve(this->capacity() * 2);
		}
		// p1 "next for i = " << size() p2
		this->insert(this->end(), 1, x);
		// (void)x;
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
	// (void)x;(void)position;
		// if (this->capacity() == 0) {
		// 	this->reserve(1);
		// 	// this->_size++;
		// }
		this->insert(position, 1, x);
	}

// insere n element avant position 
	void insert( iterator position, size_t n, const T &x ) {

		// p1 "au debut" p2
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
		// p1 "position = " << *position << " et this->end() = " << *this->end() p2
		if (position == this->end()) {
			// std::cout << "MAIS POURQUOI CA PASSE PAS LA i = " << this->size() << " n = " << n << " x = " << x << std::endl;
			for (size_t i = this->size() ; i < this->size() + n ; i++) {
				// p1 "i = " << i << " this->size() = " << this->size() << " n = " << n p2
				this->_alloc.construct(&this->_ptrVector[i], x);
				// p1 "FOR THE FIRST ONE " << this->_ptrVector[i] p2;
			}
		}
		else {
			// p1 "ca deconne ici position = " << *position << " et begin = " << *this->begin() p2
			// size_t	pos = std::distance(this->begin(), position);
			size_t pos = position - this->begin();
			// size_t pos = std::distance(this->begin(), position);
			// p1 "pos = " << pos p2
			// size_t	next = std::distance(position, this->begin());
			// T		ret;
			for (size_t end = this->size() + n ; end > this->size() ; end--) {
				this->_alloc.construct(&this->_ptrVector[end], this->_ptrVector[this->size() - n]);
				this->_alloc.destroy(&this->_ptrVector[this->size() - n]);
			}
			for (; pos < n ; pos++) {
				// ret = _ptrVector[next];
				// this->_alloc.destroy(&_ptrVector[next]);
				this->_alloc.construct(&this->_ptrVector[pos], x);
				// pos++;
			}
			// for (; next < this->size() + n ; next++) {
				
			// 	this->_alloc.construct(&this->_ptrVector[next], x);
			// }
		}
			
		this->_size += n;
		// p1 " A LA FFFFFFFFFFFFFFFFFFFFFFIN DE LA BOUCLE = " << this->size() p2
	}

//
	// template < class InputIterator >
	// void insert( iterator position,	InputIterator first, InputIterator last) {
		
		
	// }
	
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