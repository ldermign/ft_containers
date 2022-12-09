/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:22 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/09 11:04:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "ft_containers.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

// long long int	get_time_ms( void ) {

// 	struct timeval		tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

// long long int get_prog_time( long long int first_time ) {

// 	return (get_time_ms() - first_time);
// }

int main( void ) {

	// long long int first_time = get_time_ms();

	test_vector();
	test_stack();
	test_map();
	test_set();

	// for the time
	// p1 BOLDMAGENTA << "End after " << get_prog_time(first_time) << "ms" << RESET p2

	p3 p3
	p1 BOLDMAGENTA << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END TESTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << RESET p2
	p3

	return 0;
}
