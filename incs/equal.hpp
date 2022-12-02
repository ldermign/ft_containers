/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:05:24 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/02 14:26:48 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

#include "ft_containers.hpp"

START

template< class InputIt1, class InputIt2 >
bool
equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ) {

	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
			return false;
		}
	}

	return true;
}

STOP

#endif