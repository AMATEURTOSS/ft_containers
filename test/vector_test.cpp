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

#include "vector.hpp"
#include <iostream>
#include <vector>

/*
확인해야할 요소들
1. 생성자
-- vector<T> a;
-- vector<T> a(10);
-- vector<T> a(10, 3);
-- vector<T> a(It1, It2);
-- vector<T> a(b);
*/

int main(void)
{
	vector<int> v1(5);
	for (int i = 0; i < 4; ++i)
		v1[i] = i + 1;
	vector<int>::iterator it = v1.begin();
	it[3] = 100;
	std::cout << it[3] << std::endl;
}