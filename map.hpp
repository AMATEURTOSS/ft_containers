#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"

namespace ft
{

	template <	class Key,										// map::key_type
				class T,										// map::mapped_type
				class Compare = std::less<Key>,					// map::key_compare
				class Alloc = std::allocator<container::pair<const Key,T> >// map::allocator_type
	> class map
	{
	};

};

#endif
