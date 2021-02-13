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

class test
{
public:
	test()
	{
	};
	virtual ~test()
	{
		std::cout << "test destroyed" << std::endl;
	};
};

int main(void)
{
	/*{
		vector<test> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		a.push_back(40);
		a.pop_back();
		std::cout << a[0] << ' ' << a.capacity() << std::endl;
		std::cout << a[1] << ' ' << a.capacity() << std::endl;
		std::cout << a[2] << ' ' << a.capacity() << std::endl;
		std::cout << a[3] << ' ' << a.capacity() << std::endl;
	}
	std::cout << "------------------" << std::endl;
	{
		std::vector<test> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		a.push_back(40);
		a.pop_back();
		std::cout << a[0] << ' ' << a.capacity() << std::endl;
		std::cout << a[1] << ' ' << a.capacity() << std::endl;
		std::cout << a[2] << ' ' << a.capacity() << std::endl;
		std::cout << a[3] << ' ' << a.capacity() << std::endl;
	}*/
	{
		test sss;
		vector<test> a;
		a.push_back(sss);
		a.pop_back();
	}
	std::cout << "------------------" << std::endl;
	{
		test sss;
		std::vector<test> a;
		a.push_back(sss);
		a.pop_back();
	}
}