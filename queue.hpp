#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> > class queue
	{
	public:

		typedef	T			value_type;
		typedef	Container	container_type;
		typedef std::size_t	size_type;

	private:

		container_type _ctnr;

	public:

		explicit queue (const container_type& ctnr = container_type()): _ctnr(ctnr)
		{
		};

	public: /* MEMBER_FUNCTIONS */

		bool empty() const
		{
			return (_ctnr.empty());
		};

		size_type size() const
		{
			return (_ctnr.size());
		};

		value_type& front()
		{
			return (_ctnr.front());
		};

		const value_type& front() const
		{
			return (_ctnr.front());
		};

		value_type& back()
		{
			return (_ctnr.back());
		};

		const value_type& back() const
		{
			return (_ctnr.back());
		};

		void push (const value_type& val)
		{
			_ctnr.push_back(val);
		};

		void pop()
		{
			_ctnr.erase(_ctnr.begin());
		};

	public: /* NON-MEMBER_FUNCTION_OVERLOADS */

		friend bool operator == (const queue& lhs, const queue& rhs)	{ return (lhs._ctnr == rhs._ctnr); };
		friend bool operator != (const queue& lhs, const queue& rhs)	{ return (lhs._ctnr != rhs._ctnr); };
		friend bool operator < (const queue& lhs, const queue& rhs)		{ return (lhs._ctnr < rhs._ctnr); };
		friend bool operator <= (const queue& lhs, const queue& rhs)	{ return (lhs._ctnr <= rhs._ctnr); };
		friend bool operator > (const queue& lhs, const queue& rhs)		{ return (lhs._ctnr > rhs._ctnr); };
		friend bool operator >= (const queue& lhs, const queue& rhs)	{ return (lhs._ctnr >= rhs._ctnr); };

	};
}

#endif