/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:49:16 by ldermign          #+#    #+#             */
/*   Updated: 2022/09/28 13:40:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR.HPP
# define RANDOM_ITERATOR.HPP

#include "ft_containers.hpp"
#include "iterator_traits.hpp"

START

template< class T > struct random_iterator : public bidirectional_iterator_tag {
	
private:

	T		*ptr_it;

public:

	// using	value_T = T;
	// using	reference = value_T &;
	// using	pointer = value_T *;
	// using	iterator_category = std::random_access_iterator_tag;
	// using	difference_T = std::ptrdiff_t;

	constexpr iterator(T *iter = nullptr) : m_iterator{ iter } {}

	constexpr bool			operator==(const iterator &other) const noexcept { return m_iterator == other.m_iterator; }
	constexpr bool			operator!=(const iterator &other) const noexcept { return m_iterator != other.m_iterator; }
	constexpr reference		operator*() const noexcept { return *m_iterator; }
	constexpr pointer		operator->() const noexcept { return m_iterator; }
	constexpr iterator&		operator++() noexcept { ++m_iterator; return *this; }
	constexpr iterator		operator++(int) noexcept { iterator tmp(*this); ++(*this); return tmp; }
	constexpr iterator&		operator--() noexcept { --m_iterator; return *this; }
	constexpr iterator		operator--(int) noexcept { iterator tmp(*this); --(*this); return tmp; }
	constexpr iterator&		operator+=(const difference_T other) noexcept { m_iterator += other; return *this; }
	constexpr iterator&		operator-=(const difference_T other) noexcept { m_iterator -= other; return *this; }
	constexpr iterator		operator+(const difference_T other) const noexcept { return iterator(m_iterator + other); }
	constexpr iterator		operator-(const difference_T other) const noexcept { return iterator(m_iterator - other); }
	constexpr iterator		operator+(const iterator& other) const noexcept { return iterator(*this + other.m_iterator); }
	constexpr difference_T	operator-(const iterator& other) const noexcept { return std::distance(m_iterator, other.m_iterator); }
	constexpr reference		operator[](std::size_t index) const { return m_iterator[index]; }
	constexpr bool			operator<(const iterator& other) const noexcept { return m_iterator < other.m_iterator; }
	constexpr bool			operator>(const iterator& other) const noexcept { return m_iterator > other.m_iterator; }
	constexpr bool			operator<=(const iterator& other) const noexcept { return m_iterator <= other.m_iterator; }
	constexpr bool			operator>=(const iterator& other) const noexcept { return m_iterator >= other.m_iterator; }

};

STOP

#endif