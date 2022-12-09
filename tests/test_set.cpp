/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:09:39 by ldermign          #+#    #+#             */
/*   Updated: 2022/12/09 10:56:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "set.hpp"

template< class Key, class T >
void	printSet( std::string name, LIBRARY::set< Key, T > &tmp ) {

	p1 BLUE << "set " << name << RESET << " = ";
	p3
	p1 "empty = " << tmp.empty() p2
	p1 "size = " << tmp.size() p2
	p1 "max_size = " << tmp.max_size() p2
	for (typename LIBRARY::set< Key, T >::iterator it = tmp.begin(); it != tmp.end(); it++)
		p1 *it p2
}

template< class T >
void	cmp( const T &lhs, const T &rhs ) {

	static int i = 0;

	p1 "############### [" << i++ << "] ###############" p2
	p1 "equal -> " << (lhs == rhs) << " | different -> " << (lhs != rhs) p2
	p1 "inferior -> " << (lhs < rhs) << " | inferior and equal -> " << (lhs <= rhs) p2
	p1 "greater -> " << (lhs > rhs) << " | greater and equal -> " << (lhs >= rhs) p2
}

struct classCompare {

	bool operator() ( const char &lhs, const char &rhs ) const {
		return lhs < rhs;
	}
};

void set_constructor( void ) {

	p1 RED << "~~~~~~~~~~ CONSTRUCTOR ~~~~~~~~~~ " << RESET p2
	p3

	std::string	s1[] = {"stp, ", "me met ", " pas faux", " :("}; // 4
	std::string s2[] = {"Une ", "serie ", "de ", "phrases..."}; // 4
	std::string s3[] = {"Et puis encore une...", " (tant qu'a faire)"}; // 2

	p1 "constructor basic = " p2
	LIBRARY::set< std::string >	set1;
	printSet("set1", set1);
	set1.insert("test");
	set1.insert("ok");
	set1.insert("parfait");
	set1.insert("non");
	set1.insert("liena");
	set1.insert("dermigny");
	printSet("set1", set1);

	p1 "constructor by copy = " p2
	LIBRARY::set< std::string >	set2(set1);
	printSet("set2", set2);

	p1 "constructor by range of iterator = " p2
	LIBRARY::set< std::string >	set3(set1.begin(), set1.end());
	printSet("set3", set3);

	p1 "constructor with compare = " p2
	LIBRARY::set< std::string, classCompare >	set4;
	printSet("set3", set3);

	p3

}

void set_iterators( void ) {

	p1 RED << "~~~~~~~~~~ ITERATORS ~~~~~~~~~~ " << RESET p2
	p3

	p1 YELLOW << "~~~~~ ACCESSORS ~~~~~ " << RESET p2

	LIBRARY::set< char >	set1;
	set1.insert('l');
	set1.insert('d');
	set1.insert('e');
	set1.insert('r');
	set1.insert('m');
	set1.insert('i');
	set1.insert('g');
	set1.insert('n');
	printSet("set1", set1);

	LIBRARY::set< char >::iterator					it1 = set1.begin();
	LIBRARY::set< char >::const_iterator			it2 = set1.begin();
	LIBRARY::set< char >::iterator					it3 = set1.end();
	LIBRARY::set< char >::const_iterator			it4 = set1.end();
	LIBRARY::set< char >::reverse_iterator			it5 = set1.rbegin();
	LIBRARY::set< char >::const_reverse_iterator	it6 = set1.rbegin();
	LIBRARY::set< char >::reverse_iterator			it7 = set1.rend();
	LIBRARY::set< char >::const_reverse_iterator	it8 = set1.rend();

	it3--;it4--;it7--;it8--;
	p1 "\tBegin = [" << *it1 << "]" p2
	p1 "\tBegin const = [" << *it2 << "]" p2
	p1 "\tEnd = [" << *it3 << "]" p2
	p1 "\tEnd const = [" << *it4 << "]" p2
	p1 "\tReverse begin = [" << *it5 << "]" p2
	p1 "\tReverse begin const = [" << *it6 << "]" p2
	p1 "\tReverse end = [" << *it7 << "]" p2
	p1 "\tReverse end const = [" << *it8 << "]" p2

	p3
	p1 YELLOW << "~~~~~ MODIFIERS ~~~~~ " << RESET p2
	{
		LIBRARY::set< char >::iterator		first = set1.begin();
		LIBRARY::set< char >::iterator		second = set1.begin();
		LIBRARY::set< char >::iterator		last = set1.begin();
		second++;
		last++;
		last++;
		last++;

		printSet("set1", set1);
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << *(first) p2
		p1 "pre incrementation -> before [" << *(first) << "] - during [" << *(++first) << "] - after [" << *(first) << "]" p2
		first = set1.begin();
		p1 "post incrementation -> before [" << *(first) << "] - during [" << *(first++) << "] - after [" << *(first) << "]" p2
		first = set1.begin();
		p1 "pre decrementation second -> before [" << *(second) << "] - during [" << *(--second) << "] - after [" << *(second) << "]" p2
		second = set1.begin();second++;
		p1 "post decrementation second -> before [" << *(second) << "] - during [" << *(second--) << "] - after [" << *(second) << "]" p2
		second = set1.begin();second++;
	}

	p1 YELLOW << "~~~~~ REVERSE ~~~~~ " << RESET p2
	{
		LIBRARY::reverse_iterator< LIBRARY::set< char >::iterator >	ret = set1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::set< char >::iterator >	first = set1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::set< char >::iterator >	second = set1.rbegin();
		LIBRARY::reverse_iterator< LIBRARY::set< char >::iterator >	last = set1.rbegin();
		second++;
		last++;
		last++;
		last++;

		printSet("set1", set1);
		p3
		
		p1 "operator first == first -> " << (first == first) p2
		p1 "operator first != first -> " << (first != first) p2
		p1 "operator *first -> " << *(first) p2
		p1 "pre incrementation -> before [" << *(first) << "] - during [" << *(++first) << "] - after [" << *(first) << "]" p2
		first = ret;
		p1 "post incrementation -> before [" << *(first) << "] - during [" << *(first++) << "] - after [" << *(first) << "]" p2
		first = ret;
		p1 "pre decrementation second -> before [" << *(second) << "] - during [" << *(--second) << "] - after [" << *(second) << "]" p2
		second = ret;second++;
		p1 "post decrementation second -> before [" << *(second) << "] - during [" << *(second--) << "] - after [" << *(second) << "]" p2
		second = ret;second++;
	}

	p3
}

void set_capacity( void ) {

	p1 RED << "~~~~~~~~~~ CAPACITY ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< char >	set1;
	set1.insert('s');
	set1.insert('a');
	set1.insert('l');
	set1.insert('u');
	set1.insert('t');
	set1.insert(' ');
	set1.insert(':');
	set1.insert(')');

	p1 "set full" p2
	p1 "empty = " << set1.empty() p2
	p1 "size = " << set1.size() p2
	p1 "max_size = " << set1.max_size() p2

	p1 "set empty" p2
	LIBRARY::set< int >	set2;
	p1 "empty = " << set1.empty() p2
	p1 "size = " << set1.size() p2
	p1 "max_size = " << set1.max_size() p2

	p3
}

void set_modifiers( void ) {

	p1 RED << "~~~~~~~~~~ MODIFIERS ~~~~~~~~~~ " << RESET p2
	p3

	p1 YELLOW << "~~~~~ SWAP ~~~~~ " << RESET p2
	LIBRARY::set< std::string >	homme;
	LIBRARY::set< std::string >	femme;
	homme.insert("masculin");
	homme.insert("Jean-Claude");
	homme.insert("Van Damme");
	homme.insert("infini");
	homme.insert("adore (vraiment beaucoup) l'eau");
	femme.insert("feminin");
	femme.insert("Liena");
	femme.insert("Dermigny");
	femme.insert("24");
	femme.insert("aime bien l'eau (mais d'un facon saine)");
	p1 "before swap -> " p2
	printSet("homme", homme);
	printSet("femme", femme);
	homme.swap(femme);
	p1 "after swap -> " p2
	printSet("homme", homme);
	printSet("femme", femme);

	p1 YELLOW << "~~~~~ INSERT VALUE ~~~~~ " << RESET p2
	LIBRARY::set< std::string >	set1;
	LIBRARY::set< std::string >	set2;
	set1.insert("Marie");
	set1.insert("Petunia");
	set1.insert("Liena");
	set1.insert("Sirine");
	set1.insert("Elisa");
	set1.insert("Roxane");
	set1.insert("Angelina");
	p1 "before insert -> " p2
	printSet("set1", set1);
	set1.insert("Tasha");
	p1 "after insert -> " p2
	printSet("set1", set1);

	p1 YELLOW << "~~~~~ INSERT POSITION AND VALUE ~~~~~ " << RESET p2
	p1 "before insert -> " p2
	printSet("set1", set1);
	set1.insert(set1.begin(), "Ludmilla");
	p1 "after insert -> " p2
	printSet("set1", set1);

	p1 YELLOW << "~~~~~ INSERT RANGE ITERATOR ~~~~~ " << RESET p2
	LIBRARY::set< std::string >::iterator		it1 = set1.begin();
	LIBRARY::set< std::string >::iterator		it2 = set1.end();
	it1++;it2--;it1++;it2--;
	p1 "before insert -> " p2
	printSet("set1", set1);
	set1.insert(it1, it2);
	p1 "after insert -> " p2
	printSet("set1", set1);

	p3
}

void set_key_and_value_comp( void ) {

	p1 RED << "~~~~~~~~~~ KEY AND VALUE COMP ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< char >					set1;
	LIBRARY::set< char >::key_compare		set1Key = set1.key_comp();
	LIBRARY::set< char >::value_compare		set1Val = set1.value_comp();
	set1.insert('a');
	set1.insert('c');
	set1.insert('l');
	set1.insert('z');
	printSet("set1", set1);
	char 					low = *set1.begin();
	char 					high = *set1.rbegin();
	

	p1 YELLOW << "~~~~~ KEY COMP ~~~~~ " << RESET p2
	LIBRARY::set< char >::iterator		it = set1.begin();
	for (; it != set1.end() && set1Key(*it, low) ; it++) {
		p1 *it << " is greater than " << low p2
	}
	if (it != set1.end())
		p1 *it << " is not lower than " << low p2

	p3
	p1 YELLOW << "~~~~~ VALUE COMP ~~~~~ " << RESET p2
	LIBRARY::set< char >::iterator		it2 = set1.begin();
	for (; it2 != set1.end() && set1Val(*it2, high) ; it2++) {
		p1 *it2 << " is greater than " << high p2
	}
	if (it2 != set1.end())
		p1 *it2 << " is not higher than " << high p2
	p3
}

void set_operations( void ) {

	p1 RED << "~~~~~~~~~~ OPERATIONS ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< std::string >	amis;
	amis.insert("Elisa");
	amis.insert("Sirine");
	amis.insert("Sarra");
	amis.insert("Delphine");
	amis.insert("Lenny");
	amis.insert("Roxane");
	amis.insert("Joan");
	amis.insert("Matthieu");
	amis.insert("Mathias");
	amis.insert("Benji");
	amis.insert("Xavier");
	LIBRARY::set< std::string >::iterator			it;
	LIBRARY::set< std::string >::iterator			itNON;
	LIBRARY::set< std::string >::const_iterator	itC;
	LIBRARY::set< std::string >::const_iterator	itCNON;
	printSet("amis", amis);

	p1 YELLOW << "~~~~~ FIND ~~~~~ " << RESET p2
	p1 "iterator = " p2
	it = amis.find("Elisa");
	itNON = amis.find("Elise");
	p1 "const_iterator = " p2
	itC = amis.find("Lenny");
	itCNON = amis.find("Lennie");

	p1 YELLOW << "~~~~~ COUNT ~~~~~ " << RESET p2
	p1 "count = " << amis.count("Joan") p2
	p1 "count = " << amis.count("Jean") p2


	LIBRARY::set< std::string >	pays;
	pays.insert("France");
	pays.insert("Espagne");
	pays.insert("Angleterre");
	pays.insert("Italie");
	pays.insert("Chypres");
	pays.insert("Malte");
	pays.insert("Suisse");
	pays.insert("Allemagne");
	const LIBRARY::set< std::string >	pays2(pays);
	printSet("pays", pays);

	p1 YELLOW << "~~~~~ LOWER BOUND ~~~~~ " << RESET p2
	p1 "lower_bound(\"Malte\") = " << *(pays.lower_bound("Malte")) p2
	p1 "lower_bound(\"Inde\") = " << *(pays.lower_bound("Inde")) p2
	p1 "lower_bound(\"Espagne\") = " << *(pays.lower_bound("Espagne")) p2
	p1 "const -> " p2
	p1 "lower_bound(\"Malte\") = " << *(pays2.lower_bound("Malte")) p2
	p1 "lower_bound(\"Inde\") = " << *(pays2.lower_bound("Inde")) p2
	p1 "lower_bound(\"Espagne\") = " << *(pays2.lower_bound("Espagne")) p2
	p3

	p1 YELLOW << "~~~~~ UPPER BOUND ~~~~~ " << RESET p2
	p1 "upper_bound(\"Malte\") = " << *(pays.upper_bound("Malte")) p2
	p1 "upper_bound(\"Inde\") = " << *(pays.upper_bound("Inde")) p2
	p1 "upper_bound(\"Espagne\") = " << *(pays.upper_bound("Espagne")) p2
	p1 "const -> " p2
	p1 "upper_bound(\"Malte\") = " << *(pays2.upper_bound("Malte")) p2
	p1 "upper_bound(\"Inde\") = " << *(pays2.upper_bound("Inde")) p2
	p1 "upper_bound(\"Espagne\") = " << *(pays2.upper_bound("Espagne")) p2
	p3

	p1 YELLOW << "~~~~~ EQUAL RANGE ~~~~~ " << RESET p2
	LIBRARY::pair< LIBRARY::set< std::string >::iterator, LIBRARY::set< std::string >::iterator > ret;
	LIBRARY::pair< LIBRARY::set< std::string >::iterator, LIBRARY::set< std::string >::iterator > ret2;
	ret = pays.equal_range("France");
	ret2 = pays.equal_range("Pologne");
	p1 "equal range ok = " << *ret.first p2
	p1 "equal range not ok = " << *ret2.second p2

	p3
}

void set_allocator( void ) {

	p1 RED << "~~~~~~~~~~ ALLOCATOR ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< int > set;
	int *p;
	unsigned int i;

	// allocate an array of 5 elements using set's allocator:
	p = set.get_allocator().allocate(5);

	for (i = 0 ; i < 5 ; i++)
		p[i] = ( i + 1 ) * 10;

	p1 "The allocated array contains:";
	for (i = 0 ; i < 5 ; i++)
		p1 ' ' << p[i];
	p3
	set.get_allocator().deallocate(p, 5);

	p3
}

void set_clean ( void ) {

	p1 RED << "~~~~~~~~~~ CLEAN ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< std::string >	pays;
	pays.insert("France");
	pays.insert("Espagne");
	pays.insert("Angleterre");
	pays.insert("Italie");
	pays.insert("Chypres");
	pays.insert("Malte");
	pays.insert("Suisse");
	pays.insert("Allemagne");

	p1 YELLOW << "~~~~~ ERASE KEY ~~~~~ " << RESET p2
	p1 "pays before -> " p2
	printSet("pays", pays);
	pays.erase("France");
	p1 "pays after -> " p2
	printSet("pays", pays);

	p1 YELLOW << "~~~~~ ERASE ITERATOR POSITION ~~~~~ " << RESET p2
	LIBRARY::set< std::string >::iterator	second_to_del;
	second_to_del = pays.begin();
	second_to_del++;
	p1 "pays before -> " p2
	printSet("pays", pays);
	pays.erase(second_to_del);
	p1 "pays after -> " p2
	printSet("pays", pays);
	
	p1 YELLOW << "~~~~~ ERASE ITERATOR RANGE ~~~~~ " << RESET p2
	LIBRARY::set< std::string >::iterator	second;
	LIBRARY::set< std::string >::iterator	before_last;
	second = pays.begin();
	second++;
	before_last = pays.end();
	before_last--;
	before_last--;
	p1 "pays before -> " p2
	printSet("pays", pays);
	pays.erase(second, before_last);
	p1 "pays after -> " p2
	printSet("pays", pays);

	p1 YELLOW << "~~~~~ CLEAR ~~~~~ " << RESET p2
	p1 "pays before -> " p2
	printSet("pays", pays);
	pays.clear();
	p1 "pays after -> " p2
	printSet("pays", pays);
	p3

}

void set_relationnal_operator( void ) {

	p1 RED << "~~~~~~~~~~ RELATIONNAL OPERATOR ~~~~~~~~~~ " << RESET p2
	p3

	LIBRARY::set< std::string >	pays;
	pays.insert("France");
	pays.insert("Espagne");
	pays.insert("Angleterre");
	pays.insert("Italie");
	pays.insert("Chypres");
	pays.insert("Malte");
	pays.insert("Suisse");
	pays.insert("Allemagne");
	LIBRARY::set< std::string >	pays2;
	pays.insert("Portugal");
	pays.insert("Inde");
	pays.insert("Australie");
	pays.insert("Etats-Unis");
	pays.insert("Canada");
	pays.insert("Japon");
	pays.insert("Bresil");
	pays.insert("Luxembourg");

	cmp(pays, pays2);
	cmp(pays, pays);
	cmp(pays2, pays2);
	p3
}

void test_set( void ) {

	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~ SET CONTAINER ~~~~~~~~~~~~~~~~~~~~~\n" p2
	p1 RED << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << RESET p2


	set_constructor();
	set_iterators();
	set_capacity();
	set_modifiers();
	set_key_and_value_comp();
	set_operations();
	set_allocator();
	set_clean();
	set_relationnal_operator();

}