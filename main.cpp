#include <iostream>
#include "vector.hpp"
#include "list.hpp"
#include <list>
#include <vector>

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

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

class myClass {};

int main ()
{
	{
		std::list<myClass> a;
		std::cout << a.max_size() << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	{
		ft::list<myClass> a;
		std::cout << a.max_size() << std::endl;
	}
}