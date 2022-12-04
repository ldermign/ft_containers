/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:02:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/04 15:41:50 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_HPP
# define NULLPTR_HPP

// https://stackoverflow.com/questions/1282295/what-exactly-is-nullptr

#include "ft_containers.hpp"

START

struct nullptr_vv {

	nullptr_vv( void ) {}

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

nullptr_vv nullptr_v;

STOP

#endif
