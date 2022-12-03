/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:16:41 by ldermign          #+#    #+#             */
/*   Updated: 2022/11/08 11:20:27 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

#include <iostream>
#include "ft_containers.hpp"
#include "iterator.hpp"

START

template< class InputIt >
typename ft::iterator_traits< InputIt >::difference_type
distance( InputIt first, InputIt last ) {

	typename ft::iterator_traits< InputIt >::difference_type size = 0;

	for (; first != last; ++first) {
		size++;
	}
	return (size);
}

STOP

#endif
