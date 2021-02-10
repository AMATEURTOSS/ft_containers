/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:57:06 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/05 21:20:15 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <exception>
#include "iterator.hpp"

template < class T, class Alloc = std::allocator<T> >
class vector
{
public:

	class VectorIterator
	{
	public:

		typedef random_access_iterator_tag iterator_category;

	private:

		T *			_pointer;

	public:

		VectorIterator(): _pointer(NULL) {};

		VectorIterator(T * pointer): _pointer(pointer) {};

		VectorIterator(const typename vector<T>::VectorIterator & ref): _pointer(ref._pointer) {};

		VectorIterator & operator = (const typename vector<T>::VectorIterator & ref)
		{
			this->_pointer = ref._pointer;
			return (*this);
		};

		virtual ~VectorIterator() {};

	public:

		bool operator == (const typename vector<T>::VectorIterator & ref) const
		{
			return (this->_pointer == ref._pointer);
		};

		bool operator != (const typename vector<T>::VectorIterator & ref) const
		{
			return (this->_pointer != ref._pointer);
		};

		T & operator * () const
		{
			return (*this->_pointer);
		};

		T & operator -> () const
		{
			return (*this->_pointer); // 미완
		};

		VectorIterator & operator ++ (/* Prefix increment operator. */)
		{
			++this->_pointer;
			return (*this);
		};

		VectorIterator operator ++ (int/* Postfix increment operator. */)
		{
			VectorIterator tmp = *this;
			++this->_pointer;
			return (tmp);
		};

		VectorIterator & operator -- (/* Prefix decrement operator. */)
		{
			--this->_pointer;
			return (*this);
		};

		VectorIterator operator -- (int/* Postfix decrement operator. */)
		{
			VectorIterator tmp = *this;
			--this->_pointer;
			return (tmp);
		};

		bool operator < (const VectorIterator & ref) const
		{
			return (this->_pointer < ref._pointer);
		};

		bool operator > (const VectorIterator & ref) const
		{
			return (this->_pointer > ref._pointer);
		};

		bool operator <= (const VectorIterator & ref) const
		{
			return (this->_pointer <= ref._pointer);
		};

		bool operator >= (const VectorIterator & ref) const
		{
			return (this->_pointer >= ref._pointer);
		};

		VectorIterator operator += (int value)
		{
			this->_pointer += value;
			return (*this);
		};

		VectorIterator operator -= (int value)
		{
			this->_pointer -= value;
			return (*this);
		};

		T & operator [] (int value) const
		{
			return (*(this->_pointer + value));
		};

	};

public:

	typedef T											value_type;
	typedef std::size_t									size_type;
	typedef T &											reference;
	typedef const T &									const_reference;
	typedef T *											pointer;
	typedef const T *									const_pointer;
	typedef typename vector<T>::VectorIterator			iterator;
	typedef const typename vector<T>::VectorIterator	const_iterator;

private:

	pointer		_data;
	size_type	_size;
	size_type	_capacity;

public: /* MEMBER_FUNCTIONS */

	explicit vector (): _data(NULL), _size(0), _capacity(0)
	{
	};

	explicit vector (size_type n, value_type init_value = value_type()): _data(new T[n]), _size(n), _capacity(n)
	{
		size_type i;

		for (i = 0; i < n; ++i)
			this->_data[i] = init_value;
	};

	/*template < class InputIterator >
	vector (InputIterator first, InputIterator last)
	{
		return ; 주석처리하지 않을 시 위의 생성자가 호출이 안되는 문제
	};*/

	vector (const vector & ref): _data(new value_type[ref._size]), _size(ref._size)
	{
		size_type i;

		for (i = 0; i < ref._size; ++i)
			this->_data[i] = ref._data[i];
	};

	vector & operator = (const vector & ref)
	{
		size_type i;

		if (this->_capacity < ref._capacity)
		{
			if (this->_data != NULL)
				delete[] this->_data;
		}
		this->_size = ref._size;
		this->_data = new T[ref._size];
		for (i = 0; i < ref._size; ++i)
			this->_data[i] = ref._data[i];
		return (*this);
	};

	virtual ~vector()
	{
		if (this->_data != NULL)
			delete[] this->_data;
	};

public: /* ITERATORS */

	iterator begin()
	{
		return (iterator(&this->_data[0]));
	};

	const_iterator begin() const
	{
		return (iterator(&this->_data[0]));
	};

	iterator end()
	{
		return (iterator(&this->_data[this->_size]));
	};

	const_iterator end() const
	{
		return (iterator(&this->_data[this->_size]));
	};

	//rbegin, rend 미완

public: /* CAPACITY */

	size_type size ()
	{
		return (this->_size);
	};

	size_type max_size() const
	{
		return (size_type(-1) / sizeof(value_type));
	};

	void resize (size_type n, T val = 0)
	{
		size_type			i = 0;
		vector<T, Alloc>	tmp(n, val);

		if (this->_size == n)
			return ;
		while (i < this->_size)
		{
			tmp[i] = this->_data[i];
			++i;
		}
		*this = tmp;
	};

	size_type capacity() const
	{
		return (this->_size); //미완
	};

	bool empty() const
	{
		return (this->_size == 0 ? true : false);
	};

	void reserve(size_type n)
	{
		pointer tmp;

		if (_capacity >= n || n == 0)
			return;
		tmp = new T[n];
		for (size_type i = 0; i < _size; i++)
			new_arr[i] = _data[i];
		delete[] _data;
		_data = new_arr;
		_capacity = n;
	}

public: /* ELEMENT_ACCESS */

	reference operator [] (size_type n)
	{
		return (this->_data[n]);
	};

	const_reference operator [] (size_type n) const
	{
		return (this->_data[n]);
	};

	reference at (size_type n)
	{
		if (n < 0 || n >= this->_size)
			throw std::out_of_range("vector: out of range");
		return (this->_data[n]);
	};

	const_reference at (size_type n) const
	{
		if (n < 0 || n >= this->_size)
			throw std::out_of_range("vector: out of range");
		return (this->_data[n]);
	};

	reference front()
	{
		return (this->_data[0]);
	};

	const_reference	front() const
	{
		return (this->_data[0]);
	};

	reference		back()
	{
		return (this->_data[this->_size - 1]);
	};

	const_reference	back() const
	{
		return (this->_data[this->_size - 1]);
	};

public: /* MODIFIERS */

	void insert(iterator pos, size_type count, const value_type &value)
	{
		size_type index = pos._e - _arr;
		if (!count)
			return;

		reserve(_len + count); // reserve after calculating the index!
		// (otherwhise iterator `pos` is invalidated)

		std::allocator<T> alloc;

		for (ptrdiff_t i = _len - 1; i >= (ptrdiff_t)index; i--)
		{
			// move elements count times to the right
			alloc.construct(&_arr[i + count], _arr[i]); // copy constructor
			alloc.destroy(&_arr[i]);					// call destructor
		}

		for (size_type i = index; i < index + count; i++)
			alloc.construct(&_arr[i], value); // copy constructor

		_len += count;
	}

};

template < class T >
typename vector<T>::VectorIterator operator + (int value, typename vector<T>::VectorIterator It)
{
	return (typename vector<T>::VectorIterator(It + value));
};

template < class T >
typename vector<T>::VectorIterator operator + (typename vector<T>::VectorIterator It, int value)
{
	return (typename vector<T>::VectorIterator(It + value));
};

template < class T >
typename vector<T>::VectorIterator operator - (int value, typename vector<T>::VectorIterator It)
{
	return (typename vector<T>::VectorIterator(It - value));
};

template < class T >
typename vector<T>::VectorIterator operator - (typename vector<T>::VectorIterator It, int value)
{
	return (typename vector<T>::VectorIterator(It - value));
};

#endif