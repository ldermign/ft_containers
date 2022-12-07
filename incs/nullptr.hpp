/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:02:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/07 11:24:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_HPP
# define NULLPTR_HPP

// https://stackoverflow.com/questions/1282295/what-exactly-is-nullptr

#include "ft_containers.hpp"

START

struct nullptr_vv {

    void*	ptr;
	
    struct nat {int b;};

    nullptr_vv() : ptr(0) {}
    nullptr_vv(int nat::*) : ptr(0) {}
    operator int nat::*() const {return 0;}

    template <class T>
    operator T* () const {return 0;}

    template <class T, class P>
    operator T P::* () const {return 0;}

    friend bool operator==(nullptr_vv, nullptr_vv) {return true;}
    friend bool operator!=(nullptr_vv, nullptr_vv) {return false;}
};

// nullptr_vv nullptr_v;
# define nullptr_v nullptr_vv(0)


STOP

#endif
