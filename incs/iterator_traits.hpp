/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:58:43 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/28 15:45:02 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include "ft_containers.hpp"

START

// TAG ITERATORS
// marking input iterators
struct input_iterator_tag {};
// marking output iterators
struct output_iterator_tag {};
// forward iterators qui prennent en charge un sur-ensemble d'input iterator
struct forward_iterator_tag       : public input_iterator_tag {};
// bidirectionnel iterators qui prennent en charge un sur-ensemble d'iterator forward
struct bidirectional_iterator_tag : public forward_iterator_tag {};
// random-access iterators qui prennent en charge un sur-ensemble d'iterator bi-directionnel
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// structure template pour definir les iterator traits
// elle contient tous les types qu'un iterator doit avoir
// T correspond au type de l'iterateur
template< class T > struct iterator_traits {
// entier signe utilise pour identifier la distance entre 2 iterateurs
// c'st une enveloppe autur d'un pointeur
// std::ptrdiff_t = entier signe qui est le resultat de la soustraction de 2 pointeurs
	typedef	difference_type = T::difference_type;
// type sur lequel l'iterateur opere (int, char, void...)
	typedef	value_type = T::value_type;
// pointeur vers le type itere
	typedef	pointer = T::pointer;
// reference vers le type itere
	typedef	reference = T::reference;
// input ? output ? bidirectionnel ? ...
	typedef	iterator_category = T::iterator_category;
};

// structure template d'iterateur pour tout type "pointeur vers T"
// definition du rype random-access
template< class T > struct iterator_traits< T * > {
	typedef	ptrdiff_t difference_type;
	typedef	typename T value_type;
	typedef	T *pointer;
	typedef	T &reference;
	typedef	random_access_iterator_tag iterator_category;
};

// specialisation partielle pour les pointeurs constant
template< class T > struct iterator_traits< const T* > {
	typedef	ptrdiff_t difference_type;
	typedef	typename T value_type;
	typedef	T *pointer;
	typedef	T &reference;
	typedef	random_access_iterator_tag iterator_category;
};

STOP

#endif