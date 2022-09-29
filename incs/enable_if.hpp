/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:57:09 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/29 10:40:24 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include "ft_containers.hpp"

START

template< bool B, class T = void >
struct enable_if {};
 
template< class T >
struct enable_if< true, T > {
	typedef T type;
};

STOP

#endif
