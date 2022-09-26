/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:58:43 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/26 11:46:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS.HPP
# define ITERATOR_TRAITS.HPP

#include "ft_containers.hpp"

START

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template< class Iter > struct iterator_traits {
	typedef	difference_type = Iter::difference_type;
	typedef	value_type = Iter::value_type;
	typedef	pointer = Iter::pointer;
	typedef	reference = Iter::reference;
	typedef	iterator_category = Iter::iterator_category;
};

template< class T > struct iterator_traits< T * > {
	typedef	ptrdiff_t difference_type;
	typedef	typename T value_type;
	typedef	T *pointer;
	typedef	T &reference;
	typedef	random_access_iterator_tag iterator_category;
};

template< class T > struct iterator_traits< const T* > {
	typedef	ptrdiff_t difference_type;
	typedef	typename T value_type;
	typedef	T *pointer;
	typedef	T &reference;
	typedef	random_access_iterator_tag iterator_category;
};

STOP

#endif