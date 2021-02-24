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

int main ()
{
	{
		std::list<int> mylist1, mylist2;
		std::list<int>::iterator it;
		for (int i = 0; i < 4; ++i)
			mylist1.push_back(i);
		for (int i = 5; i < 9; ++i)
			mylist2.push_back(i);
		mylist1.splice(mylist1.end(), mylist2, mylist2.begin(), mylist2.end());
		print_all_list(mylist1);
		print_all_list(mylist2);
	}
	std::cout << "-------------------" << std::endl;
	{
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;
		for (int i = 0; i < 4; ++i)
			mylist1.push_back(i);
		for (int i = 5; i < 9; ++i)
			mylist2.push_back(i);
		mylist1.splice(mylist1.end(), mylist2, mylist2.begin(), mylist2.end());
		print_all_list(mylist1);
		print_all_list(mylist2);
	}
}