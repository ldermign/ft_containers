/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:40:01 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/06 15:49:16 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include "ft_containers.hpp"

START

template< class T, T v >
struct integral_const {

	typedef T value_type;
	typedef integral_const< T, v > type; // using injected-class-name

	static const value_type value = v;

	operator value_type() const {
		return value;
	}

};

typedef integral_const< bool, true > true_type;
typedef integral_const< bool, false > false_type;

template< class T > struct is_integral : public false_type {};
template<> struct is_integral< unsigned char > : public true_type {};
template<> struct is_integral< unsigned short > : public true_type {};
template<> struct is_integral< unsigned int > : public true_type {};
template<> struct is_integral< unsigned long > : public true_type {};
template<> struct is_integral< signed char > : public true_type {};
template<> struct is_integral< short > : public true_type {};
template<> struct is_integral< int > : public true_type {};
template<> struct is_integral< long > : public true_type {};
template<> struct is_integral< char > : public true_type {};
template<> struct is_integral< bool > : public true_type {};

STOP

/* INFO

integral_const template :
https://cplusplus.com/reference/type_traits/integral_constant/
mix avec 
https://en.cppreference.com/w/cpp/types/integral_constant
(beaucoup moins le deuxieme, erreurs avec using)

template pour integral :
https://code.woboq.org/appleseed/include/boost/type_traits/is_integral.hpp.html

true and false type :
https://cplusplus.com/reference/type_traits/false_type/
https://cplusplus.com/reference/type_traits/true_type/

*/

#endif