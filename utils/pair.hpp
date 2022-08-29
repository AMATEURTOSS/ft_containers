#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template< class T1, class T2 >
	struct pair
	{
	public:

		typedef T1 first_type;

		typedef T2 second_type;

	public:

		first_type	first;

		second_type	second;

	public:

		pair() : first(T1()), second(T2()) {}

		pair(const pair<first_type , second_type> & pr): first(pr.first), second(pr.second) {}

		pair(const first_type & a, const second_type & b) : first(a), second(b) {}

		~pair() {}

	public: /* NON-MEMBER_FUNCTION_OVERLOADS */

		friend bool operator == (const pair & lhs, const pair & rhs)	{ return (lhs.first == rhs.first && lhs.second == rhs.second); }
		friend bool operator != (const pair & lhs, const pair & rhs)	{ return (!(lhs == rhs)); }
		friend bool operator < (const pair & lhs, const pair & rhs)		{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }
		friend bool operator <= (const pair & lhs, const pair & rhs)	{ return (!(rhs < lhs)); }
		friend bool operator > (const pair & lhs, const pair & rhs)		{ return (rhs < lhs); }
		friend bool operator >= (const pair & lhs, const pair & rhs)	{ return (!(lhs < rhs)); }

	};
}

template < class first_type, class second_type >
ft::pair<first_type, second_type>	make_pair(first_type first, second_type second)
{
	return (ft::pair<first_type, second_type>(first, second));
}

#endif
