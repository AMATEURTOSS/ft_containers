#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template < class Iterator >
	class reverse_iterator: public Iterator
	{
	public:

		reverse_iterator(): Iterator() {};

		reverse_iterator(typename Iterator::value_type * pointer): Iterator(pointer) {}

		reverse_iterator(const reverse_iterator & ref): Iterator(ref) {}

		reverse_iterator & operator = (const reverse_iterator & ref)
		{
			this->_pointer = ref._pointer;
			return (*this);
		}

		~reverse_iterator() {}

	public:

		Iterator operator++(int/* Postfix increment operator. */)
		{
			return (Iterator::operator--(int()));
		}

		Iterator &operator++(/* Prefix increment operator. */)
		{
			return (Iterator::operator--());
		}

		Iterator operator--(int/* Postfix decrement operator. */)
		{
			return (Iterator::operator++(int()));
		}

		Iterator &operator--(/* Prefix decrement operator. */)
		{
			return (Iterator::operator++());
		}

	};

	struct truth
	{
	};
	struct falsity
	{
	};

	template< class T > struct is_iterator			{ typedef truth val; };

	template<> struct is_iterator<unsigned char>	{ typedef falsity val; };
	template<> struct is_iterator<char>				{ typedef falsity val; };
	template<> struct is_iterator<unsigned int> 	{ typedef falsity val; };
	template<> struct is_iterator<int>				{ typedef falsity val; };
	template<> struct is_iterator<bool>				{ typedef falsity val; };
	template<> struct is_iterator<float>			{ typedef falsity val; };
	template<> struct is_iterator<double>			{ typedef falsity val; };
}

#endif
