/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:44:31 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/04 17:18:06 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"


template <class T>
void	print(LIBRARY::vector<LIBRARY::vector<T> >& lst)
{
	for (typename LIBRARY::vector<LIBRARY::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename LIBRARY::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			p1 *it2 << ' ';
		p1 '\n';
	}
}

template <class T>
void	print(LIBRARY::vector<T>& lst)
{
	for (typename LIBRARY::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		p1 *it << ' ';
	p1 '\n';
}


void	test_vector( void ) {

	p3
		
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~ VECTOR CONTAINER ~~~~~~~~~~\n" p2
	p1 "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	
	{


  LIBRARY::vector<int> first;
  LIBRARY::vector<int> second;
  LIBRARY::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  LIBRARY::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  p1 "Size of first: " << int (first.size()) p2;
  p1 "Size of second: " << int (second.size()) p2;
  p1 "Size of third: " << int (third.size()) p2;




	p3

	}
	
}