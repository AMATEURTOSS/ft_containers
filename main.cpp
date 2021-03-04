#include <iostream>
#include "vector.hpp"
#include "list.hpp"
#include "map.hpp"
#include <list>
#include <vector>
#include <map>

template < class vector >
void print_all_vector(vector a)
{
	typename vector::iterator begin = a.begin();
	typename vector::iterator end = a.end();
	for (; begin != end; ++begin)
		std::cout << *begin << ' ';
	std::cout << std::endl;
	std::cout << "size: " << a.size()<< std::endl << "capacity: " << a.capacity() << std::endl;
}

template < class list >
void print_all_list(list & a)
{
	typename list::iterator begin = a.begin();
	typename list::iterator end = a.end();
	for (; begin != end; ++begin)
	{
		std::cout << *begin << ' ';
	}
	std::cout << std::endl;
	std::cout << "size: " << a.size() <<  std::endl;
}

int main ()
{
	{
		std::list<int> a(10, 0);
		std::list<int> b(4, 100);
		print_all_list(a);
		print_all_list(b);
		std::cout << (a < b) << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	{
		int ptr[] = {1, 2, 3, 4, 5};
		ft::list<int> a(ptr, ptr + 3);
		a.push_back(10);
		a.push_back(*a.begin());
		ft::list<int> b(ptr, ptr + 3);
		b.push_back(10);
		b.push_back(*++a.begin());
		print_all_list(a);
		print_all_list(b);
		std::cout << (a == b) << std::endl;
	}
}