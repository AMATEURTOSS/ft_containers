#ifndef IS_ITERATOR_HPP
#define IS_ITERATOR_HPP

#include <iterator>

namespace ft
{

	struct truth {};
	struct falsity {};

	template< class T >
	struct is_iterator
	{
		typedef truth val;
	};

	template<>
	struct is_iterator<unsigned char>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<char>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<unsigned int>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<int>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<bool>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<float>
	{
		typedef falsity val;
	};

	template<>
	struct is_iterator<double>
	{
		typedef falsity val;
	};

}

#endif
