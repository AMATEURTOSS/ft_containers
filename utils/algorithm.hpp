#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
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
	}

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
	}

	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		/* The first argument type */
		typedef Arg1 first_argument_type;

		/* The second arguement type */
		typedef Arg2 second_argument_type;

		/* The result type */
		typedef Result result_type;
	};

}

#endif
