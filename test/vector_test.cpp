/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 01:26:53 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/08 01:26:53 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#include <iostream>
#include <vector>
#include <conio.h>

class test {};

template < class vector >
void print_all_vector(vector a)
{
	typename vector::iterator begin = a.begin();
	typename vector::iterator end = a.end();
	for (; begin != end; ++begin)
		std::cout << *begin << ' ';
	std::cout << std::endl;
}

void test_default_construct()
{
	if (system("CLS")) system("clear");
	std::cout << "CODE: " << std::endl;
	std::cout << "void test_default_construct()\n{\n\tstd::vector<test> a;\n\tft::vector<test> b;\n}" << std::endl;
	std::cout << "OUTPUT: " << std::endl;
	{
		std::vector<test> a;
		ft::vector<test> b;
	}
	std::cout << std::endl << std::endl << "press any key to continue..." << std::endl;
}

void test_n_construct()
{
	std::cout << "\ec";
	std::cout << "CODE: " << std::endl;
	std::cout << "void test_n_construct()\n{\n\tstd::vector<int> a(10);\n\tstd::vector<int> b(20, 30);"
			  "\n\tft::vector<int> c(10);\n\tft::vector<int> d(20, 30)\n\tprint_all_vector(a);\n\tprint_all_vector(b)\n\t"
	 "print_all_vector(c)\n\tprint_all_vector(d)\n}" << std::endl;
	std::cout << "OUTPUT: " << std::endl;
	{
		std::vector<int> a(10);
		std::vector<int> b(20, 30);
		ft::vector<int> c(10);
		ft::vector<int> d(20, 30);
		print_all_vector(a);
		print_all_vector(b);
		print_all_vector(c);
		print_all_vector(d);
	}
	std::cout << std::endl << std::endl << "press any key to continue..." << std::endl;
}

int main()
{
	test_default_construct();
	while (std::cin.get() != '\n');
	test_n_construct();
}