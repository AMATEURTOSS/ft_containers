/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:49:50 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/05 21:17:47 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

int main(void)
{
	vector<int> v1(10);
	for (int i = 0; i < 10; ++i)
		v1[i] = i + 1;
	v1.resize(15, 100);
	for (int i = 0; i < 15; ++i)
		std::cout << v1[i] << ' ';
	std::cout << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.at(20) << std::endl;
}