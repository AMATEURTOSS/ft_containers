/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 02:18:38 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/08 02:18:38 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

template < class vector >
void print_all_vector(vector a)
{
	typename vector::iterator begin = a.begin();
	typename vector::iterator end = a.end();
	for (; begin != end; ++begin)
		std::cout << *begin << ' ';
	std::cout << std::endl;
	std::cout << "size: " << a.size() << std::endl << "capacity: " << a.capacity() << std::endl;
}

int main ()
{
	{
		std::vector<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		std::vector<int> b(a.begin(), a.end());
		print_all_vector(b);
	}
	std::cout << "-------------------" << std::endl;
	{
		ft::vector<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		ft::vector<int> b(a.begin(), a.end());
		print_all_vector(b);
	}
}