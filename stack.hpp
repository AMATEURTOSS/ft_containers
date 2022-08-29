#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:

		typedef T			value_type;
		typedef Container	container_type;
		typedef std::size_t	size_type;

	private:

		container_type _ctnr;

	public: /* MEMBER_FUNCTIONS */

		explicit stack (const container_type& ctnr = container_type()): _ctnr(ctnr)
		{
		};

		bool empty() const
		{
			return (_ctnr.empty());
		};

		size_type size() const
		{
			return (_ctnr.size());
		};

		value_type& top()
		{
			return (_ctnr[_ctnr.size() - 1]);
		};

		const value_type& top() const
		{
			return (_ctnr[_ctnr.size() - 1]);
		};

		void push (const value_type& val)
		{
			_ctnr.push_back(val);
		};

		void pop()
		{
			_ctnr.pop_back();
		};

	public: /* NON-MEMBER_FUNCTION_OVERLOADS */

		friend bool operator == (const stack& lhs, const stack& rhs)	{ return (lhs._ctnr == rhs._ctnr); };
		friend bool operator != (const stack& lhs, const stack& rhs)	{ return (lhs._ctnr != rhs._ctnr); };
		friend bool operator < (const stack& lhs, const stack& rhs)		{ return (lhs._ctnr < rhs._ctnr); };
		friend bool operator <= (const stack& lhs, const stack& rhs)	{ return (lhs._ctnr <= rhs._ctnr); };
		friend bool operator > (const stack& lhs, const stack& rhs)		{ return (lhs._ctnr > rhs._ctnr); };
		friend bool operator >= (const stack& lhs, const stack& rhs)	{ return (lhs._ctnr >= rhs._ctnr); };

	};

};

#endif
