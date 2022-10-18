/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:40:01 by ldermign          #+#    #+#             */
/*   Updated: 2022/10/18 15:48:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include "ft_containers.hpp"

START

template<class T, T v >
struct integral_constant {
	static constexpr T value = v;
	using value_type = T;
	using type = integral_constant; // using injected-class-name
	constexpr operator value_type() const noexcept { return value; }
};

STOP

#endif