#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include <iterator>
# include <limits>
# include <iostream>
# include "utils/iterator.hpp"
# include "utils/algorithm.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:

		class VectorIterator
		{
		public:

			typedef T												value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef T &												reference;
			typedef const T &										const_reference;
			typedef T *												pointer;
			typedef const T *										const_pointer;
			typedef std::random_access_iterator_tag					iterator_category;

		protected:

			T *		_pointer;

		public:

			VectorIterator(): _pointer(NULL) {}

			VectorIterator(T * pointer): _pointer(pointer) {}

			VectorIterator(const typename vector<T>::VectorIterator & ref): _pointer(ref._pointer) {}

			VectorIterator & operator = (const typename vector<T>::VectorIterator & ref)
			{
				this->_pointer = ref._pointer;
				return (*this);
			}

			virtual ~VectorIterator() {}

		public:

			bool operator == (const typename vector<T>::VectorIterator & ref) const
			{
				return (this->_pointer == ref._pointer);
			}

			bool operator != (const typename vector<T>::VectorIterator & ref) const
			{
				return (this->_pointer != ref._pointer);
			}

			T & operator * () const
			{
				return (*this->_pointer);
			}

			T * operator -> () const
			{
				return (this->_pointer);
			}

			VectorIterator & operator ++ (/* Prefix increment operator. */)
			{
				++this->_pointer;
				return (*this);
			}

			VectorIterator operator ++ (int/* Postfix increment operator. */)
			{
				VectorIterator tmp = *this;
				++this->_pointer;
				return (tmp);
			}

			VectorIterator & operator -- (/* Prefix decrement operator. */)
			{
				--this->_pointer;
				return (*this);
			}

			VectorIterator operator -- (int/* Postfix decrement operator. */)
			{
				VectorIterator tmp = *this;
				--this->_pointer;
				return (tmp);
			}

			VectorIterator operator + (int rhs) const
			{
				return (VectorIterator(_pointer + rhs));
			}

			std::ptrdiff_t operator - (const VectorIterator & rhs) const
			{
				return (_pointer - rhs._pointer);
			}

			VectorIterator operator - (int rhs) const
			{
				return (VectorIterator(_pointer - rhs));
			}

			bool operator < (const VectorIterator & ref) const
			{
				return (this->_pointer < ref._pointer);
			}

			bool operator > (const VectorIterator & ref) const
			{
				return (this->_pointer > ref._pointer);
			}

			bool operator <= (const VectorIterator & ref) const
			{
				return (this->_pointer <= ref._pointer);
			}

			bool operator >= (const VectorIterator & ref) const
			{
				return (this->_pointer >= ref._pointer);
			}

			VectorIterator operator += (int value)
			{
				this->_pointer += value;
				return (*this);
			}

			VectorIterator operator -= (int value)
			{
				this->_pointer -= value;
				return (*this);
			}

			T & operator [] (int value)
			{
				return (*(this->_pointer + value));
			}

			const T & operator [] (int value) const
			{
				return (*(this->_pointer + value));
			}

		};

	public:

		typedef T											value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t                              difference_type;
		typedef T &											reference;
		typedef const T &									const_reference;
		typedef T *											pointer;
		typedef const T *									const_pointer;
		typedef typename vector<T>::VectorIterator			iterator;
		typedef const typename vector<T>::VectorIterator	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef const reverse_iterator                      const_reverse_iterator;

	private:

		Alloc		_al;
		pointer		_data;
		size_type	_size;
		size_type	_capacity;

	public: /* MEMBER_FUNCTIONS */

		explicit vector (): _al(Alloc()), _data(NULL), _size(0), _capacity(0)
		{
		}

		explicit vector (size_type n, value_type init_value = value_type()): _al(Alloc()), _data(_al.allocate(n)), _size(n), _capacity(n)
		{
			size_type i;

			for (i = 0; i < n; ++i)
				_al.construct(_data + i, init_value);
		}

		template < class InputIterator >
		vector (InputIterator first, InputIterator last): _al(Alloc())
		{
			this->private_iterator_constructor(first, last, typename ft::is_iterator<InputIterator>::val());
		}

		vector (const vector & ref): _al(Alloc()), _data(_al.allocate(ref._capacity)), _size(ref._size), _capacity(ref._capacity)
		{
			size_type i;

			for (i = 0; i < ref._size; ++i)
				this->_data[i] = ref._data[i];
		}

		vector & operator = (const vector & ref)
		{
			clear();
			_al.deallocate(_data, _capacity);
			_size = ref._size;
			_capacity = ref._capacity;
			_data = _al.allocate(_capacity);
			for (size_type i = 0; i < _size; ++i)
				_data[i] = ref._data[i];
			return (*this);
		}

		~vector()
		{
			clear();
			_al.deallocate(_data, _capacity);
		}

	public: /* ITERATORS */

		iterator begin()
		{
			return (iterator(_data));
		}

		const_iterator begin() const
		{
			return (iterator(_data));
		}

		iterator end()
		{
			return (iterator(_data + _size));
		}

		const_iterator end() const
		{
			return (iterator(_data + _size));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_data + _size - 1));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_data + _size - 1));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_data - 1));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_data - 1));
		}

	public: /* CAPACITY */

		size_type size () const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (std::allocator<value_type>().max_size());
		}

		void resize (size_type n, value_type val = value_type())
		{
			size_type			i;
			vector<T, Alloc>	tmp((_capacity > n ? _capacity : n));

			for (i = 0; i < this->_size; ++i)
				tmp[i] = _data[i];
			for (; i < n; ++i)
				tmp[i] = val;
			tmp._size = n;
			*this = tmp;
		}

		size_type capacity() const
		{
			return (this->_capacity);
		}

		bool empty() const
		{
			return (this->_size == 0);
		}

		void reserve(size_type n)
		{
			pointer tmp;

			if (n > this->max_size())
				throw std::length_error("length error in reserve");
			if (_capacity >= n)
				return ;
			if (n == 0)
				return ;
			tmp = _al.allocate(n);
			for (size_type i = 0; i < _size; ++i)
			{
				_al.construct(&tmp[i], _data[i]);
				_al.destroy(_data + i);
			}
			_al.deallocate(_data, _capacity);
			_capacity = n;
			_data = tmp;
		}

	public: /* ELEMENT_ACCESS */

		reference operator [] (size_type n)
		{
			return (this->_data[n]);
		}

		const_reference operator [] (size_type n) const
		{
			return (this->_data[n]);
		}

		reference at (size_type n)
		{
			if (n < 0 || n >= this->_size)
				throw std::out_of_range("vector: out of range");
			return (this->_data[n]);
		}

		const_reference at (size_type n) const
		{
			if (n < 0 || n >= this->_size)
				throw std::out_of_range("vector: out of range");
			return (this->_data[n]);
		}

		reference front()
		{
			return (this->_data[0]);
		}

		const_reference	front() const
		{
			return (this->_data[0]);
		}

		reference		back()
		{
			return (this->_data[this->_size - 1]);
		}

		const_reference	back() const
		{
			return (this->_data[this->_size - 1]);
		}

	public: /* MODIFIERS */

		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > _capacity)
			{
				_al.deallocate(_data, _capacity);
				_data = _al.allocate(n);
				_capacity = n;
			}
			for (size_type i = 0; i < n; ++i)
				_al.construct(_data + i, val);
			_size = n;
		}

		template < class InputIterator >
		void assign (InputIterator first, InputIterator last)
		{
			this->private_assign(first, last, typename ft::is_iterator<InputIterator>::val());
		}

		void push_back (const_reference val)
		{
			if (_size == _capacity)
				reserve((_capacity == 0 ? 1 : (_capacity * 2)));
			_data[_size] = val;
			_size += 1;
		}

		void pop_back()
		{
			if (_size)
			{
				_al.destroy(_data + (_size - 1));
				--_size;
			}
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type	position_i;

			position_i = &(*position) - _data;
			if (_capacity - _size < 1)
				reserve(_capacity * 2);
			for (size_type i = 0; i < _size - position_i; ++i)
			{
				_al.destroy(&_data[_size - i]);
				_al.construct(&_data[_size - i], _data[_size - i - 1]);
			}
			_al.destroy(_data + position_i);
			_al.construct(_data + position_i, val);
			++_size;
			return (iterator(_data + position_i));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type   position_i;

			position_i = &(*position) - _data;
			if (_capacity - _size < n)
				reserve(_size + n);
			for (size_type i = 0; i < _size - position_i; ++i)
			{
				_al.construct(_data + (_capacity - i - 1), _data[_capacity - i - n - 1]);
				_al.destroy(&_data[_capacity - i - n - 1]);
			}
			for (size_type i = 0; i < n; ++i)
			{
				_al.construct(_data + position_i, val);
				++position_i;
			}
			_size = _capacity;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			this->private_insert(position, first, last, typename ft::is_iterator<InputIterator>::val());
		}

		iterator erase (iterator position)
		{
			iterator end;

			end = this->end();
			_al.destroy(&(*position));
			for (size_type i = 0; (position + i) != end; ++i)
			{
				_al.construct(&(*(position + i)), *((position + i) + 1));
				_al.destroy(&(*((position + i) + 1)));
			}
			--_size;
			return (position);
		}

		iterator erase (iterator first, iterator last)
		{
			iterator tmp;

			tmp = first;
			for (; tmp != last; --last)
				erase(tmp);
			return (first);
		}

		void swap (vector& x)
		{
			vector<value_type> tmp;

			tmp = *this;
			*this = x;
			x = tmp;
		}

		void clear()
		{
			for (size_type i = 0; i < _size; ++i)
				_al.destroy(_data + i);
			_size = 0;
		}

	private:

		template < class InputIterator >
		void private_iterator_constructor(InputIterator first, InputIterator last, ft::truth)
		{
			int         i;
			size_type   len;

			i = 0;
			len = last - first;
			_data = _al.allocate(len);
			_size = len;
			_capacity = len;
			while (first != last)
			{
				_data[i] = *first;
				++first;
				++i;
			}
		}

		void private_iterator_constructor(size_type n, value_type init_value, ft::falsity)
		{
			size_type i;

			_data = _al.allocate(n);
			for (i = 0; i < n; ++i)
				_al.construct(_data + i, init_value);
			_size = n;
			_capacity = n;
		}

		template < class InputIterator >
		void private_assign(InputIterator first, InputIterator last, ft::truth)
		{
			pointer tmp;
			unsigned long len;

			len = last - first;
			tmp = _al.allocate((len > _capacity ? len : _capacity));
			for (size_type i = 0; first != last; ++first)
			{
				tmp[i] = *first;
				++i;
			}
			clear();
			_al.deallocate(_data, _capacity);
			_size = len;
			_capacity = (len > _capacity ? len : _capacity);
			_data = tmp;
		}

		void private_assign(size_type n, const value_type& val, ft::falsity)
		{
			this->assign(n, val);
		}

		template < class InputIterator >
		void private_insert(iterator position, InputIterator first, InputIterator last, ft::truth)
		{
			size_type position_i;
			size_type diff;

			diff = last - first;
			position_i = &(*position) - _data;
			if ((_capacity - _size) < diff)
				reserve(_size + diff);
			for (size_type i = 0; i < _capacity - diff - position_i; ++i)
			{
				_al.construct(_data + (_capacity - i - 1), _data[_capacity - diff - i - 1]);
				_al.destroy(_data + (_capacity - diff - i - 1));
			}
			for (; first != last; ++first)
			{
				_al.construct(_data + position_i, *first);
				++position_i;
			}
			_size = _capacity;
		}

		void private_insert(iterator position, size_type n, const value_type& val, ft::falsity)
		{
			this->insert(position, n, val);
		}

	public: /* NON-MEMBER_FUNCTION_OVERLOADS */

		friend iterator	operator + (int lhs, iterator rhs)							{ return (iterator(rhs._pointer + lhs)); }
		friend bool		operator == (const vector & lhs, const vector & rhs)		{ return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
		friend bool		operator != (const vector & lhs, const vector & rhs)		{ return (!(lhs == rhs)); }
		friend bool		operator < (const vector & lhs, const vector & rhs)			{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		friend bool		operator <= (const vector & lhs, const vector & rhs)		{ return (!(lhs < rhs)); }
		friend bool		operator > (const vector<T>& lhs, const vector<T>& rhs)		{ return (rhs < lhs); }
		friend bool		operator >= (const vector<T>& lhs, const vector<T>& rhs)	{ return (!(lhs > rhs)); }

	};

	template < class T >
	void swap (vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}

}

#endif
