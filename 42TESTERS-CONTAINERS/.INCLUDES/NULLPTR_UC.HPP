/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:02:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/03 17:21:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_HPP
# define NULLPTR_HPP

// https://stackoverflow.com/questions/1282295/what-exactly-is-nullptr

#include "ft_containers.hpp"

START

struct nullptr_ {

	nullptr_( void ) {}

	void operator &() const;  // Can't take address of nullptr

	template< class T >
	inline operator T*() const {
		return (0);
	}

	template< class C, class T >
	inline operator T C::*() const {
		return (0);
	}
};

nullptr_ nullptr_t;

STOP

#endif
