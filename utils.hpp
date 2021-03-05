#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft
{

	namespace algorithm
	{
		template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
		{
			while (first1!=last1) {
				if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
					return false;
				++first1; ++first2;
			}
			return true;
		};

		template <class InputIterator1, class InputIterator2>
		static bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
											 InputIterator2 first2, InputIterator2 last2)
		{
			while (first1!=last1)
			{
				if ((first2 == last2) || (*first2 < *first1))
					return false;
				else if (*first1 < *first2)
					return true;
				++first1;
				++first2;
			}
			return (first2 != last2);
		};
	};

	namespace iterator
	{

		template < class Iterator >
		class reverse_iterator: public Iterator
		{
		public:

			reverse_iterator(): Iterator() {};

			reverse_iterator(typename Iterator::value_type * pointer): Iterator(pointer) {};

			reverse_iterator(const reverse_iterator<Iterator> & ref): Iterator(ref) {};

			reverse_iterator & operator = (const reverse_iterator<Iterator> & ref)
			{
				this->_pointer = ref._pointer;
				return (*this);
			};

			virtual ~reverse_iterator() {};

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
	};

	namespace container
	{
		template <class T1, class T2>
		struct pair
		{
		public:

			typedef T1	first_type;
			typedef T2	second_type;

		public:

			T1 first;
			T2 second;

		public:

			pair(): first(T1()), second(T2())
			{
			};

			template<class U, class V>
			pair (const pair<U, V>& pr): first(pr.first), second(pr.second)
			{
			};

			pair (const first_type & a, const second_type & b): first(a), second(b)
			{
			};

			~pair()
			{
			};

		};

		template <class T1, class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return (pair<T1, T2>(x, y));
		};
	};

};

template <class T1, class T2>
bool operator == (const ft::container::pair<T1, T2>& lhs, const ft::container::pair<T1, T2>& rhs)
{
	return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
};

template <class T1, class T2>
bool operator != (const ft::container::pair<T1,T2>& lhs, const ft::container::pair<T1,T2>& rhs)
{
	return (!(lhs == rhs));
};

template <class T1, class T2>
bool operator < (const ft::container::pair<T1,T2>& lhs, const ft::container::pair<T1,T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator <= (const ft::container::pair<T1,T2>& lhs, const ft::container::pair<T1,T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool operator > (const ft::container::pair<T1,T2>& lhs, const ft::container::pair<T1,T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool operator >= (const ft::container::pair<T1,T2>& lhs, const ft::container::pair<T1,T2>& rhs)
{
	return (!(lhs < rhs));
}

#endif
