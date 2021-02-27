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

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

int main ()
{
	{
		std::list<std::string> mylist;
		std::list<std::string>::iterator it;
		mylist.push_back("one");
		mylist.push_back("two");
		mylist.push_back("Three");

		mylist.sort();

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "------------------------------" << std::endl;
	{
		ft::list<std::string> mylist;
		ft::list<std::string>::iterator it;
		mylist.push_back("one");
		mylist.push_back("two");
		mylist.push_back("Three");

		mylist.sort();

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it = mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}