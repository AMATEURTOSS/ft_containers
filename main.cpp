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
#include <vector>

int main(void)
{
	vector<int> v1(5);
	for (int i = 0; i < 4; ++i)
		v1[i] = i + 1;
	const vector<int>::iterator it = v1.begin();
	it[3] = 100;
	std::cout << it[3] << std::endl;
}