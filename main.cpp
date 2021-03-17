#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <stack>

#include "vector.hpp"
#include "list.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "utils/pair.hpp"

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
		std::map<char, int> a;
		a.insert(std::pair<char, int>('a', 42));
		a.insert(std::pair<char, int>('b', 24));
		a.insert(std::pair<char, int>('c', 4242));
	}
	std::cout << "------------------------------" << std::endl;
	{
		ft::map<char, int> a;
		a.insert(ft::pair<char, int>('a', 42));
		a.insert(ft::pair<char, int>('b', 24));
		a.insert(ft::pair<char, int>('c', 4242));
	}
}