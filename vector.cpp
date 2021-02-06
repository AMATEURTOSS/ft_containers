/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:29:10 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/05 21:20:08 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

/*
** MEMBER_FUNCTIONS
*/

template < class T, class Alloc >
vector<T, Alloc>::vector (): _data(NULL), _size(0)
{
}

template < class T, class Alloc >
vector<T, Alloc>::vector (std::size_t n): _data(new T[n]), _size(n)
{
	std::size_t i;

	for (i = 0; i < n; ++i)
		this->_data[i] = 0;
}

template < class T, class Alloc >
vector<T, Alloc>::vector (std::size_t n, T init_value): _data(new T[n]), _size(n)
{
	std::size_t i;

	for (i = 0; i < n; ++i)
		this->_data[i] = init_value;
}

template < class T, class Alloc >
vector<T, Alloc>::vector (const vector & ref): _data(new T[ref._size]), _size(ref._size)
{
	std::size_t i;

	for (i = 0; i < ref._size; ++i)
		this->_data[i] = ref._data[i];
}

template < class T, class Alloc >
vector<T, Alloc> & vector<T, Alloc>::operator = (const vector & ref)
{
	std::size_t i;

	if (this->_data != NULL)
		delete[] this->_data;
	this->_size = ref._size;
	this->_data = new T[ref._size];
	for (i = 0; i < ref._size; ++i)
		this->_data[i] = ref._data[i];
	return (*this);
}

template < class T, class Alloc >
vector<T, Alloc>::~vector ()
{
	if (this->_data != NULL)
		delete[] this->_data;
}

/*
** ITERATORS
*/

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
{
	return (typename vector<T>::iterator(&this->_data[0]));
}

template < class T, class Alloc >
const typename vector<T, Alloc>::iterator vector<T, Alloc>::begin() const
{
	return (typename vector<T>::iterator(&this->_data[0]));
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
{
	return (typename vector<T>::iterator(&this->_data[this->_size]));
}

template < class T, class Alloc >
const typename vector<T, Alloc>::iterator vector<T, Alloc>::end() const
{
	return (typename vector<T>::iterator(&this->_data[this->_size]));
}

/*
** CAPACITY
*/

template < class T, class Alloc >
std::size_t vector<T, Alloc>::size ()
{
	return (this->_size);
}

template < class T, class Alloc >
std::size_t vector<T, Alloc>::max_size() const
{
	//미완
	return (1);
}

template < class T, class Alloc >
void vector<T, Alloc>::resize (std::size_t n, T val)
{
	std::size_t	i = 0;
	vector<T, Alloc> tmp(n, val);

	if (this->_size == n)
		return ;
	while (i < this->_size)
	{
		tmp[i] = this->_data[i];
		++i;
	}
	*this = tmp;
}

/*
** ELEMENT_ACCESS
*/

template < class T, class Alloc >
T & vector<T, Alloc>::operator [] (std::size_t n)
{
	return (this->_data[n]);
}

template < class T, class Alloc >
const T & vector<T, Alloc>::operator [] (std::size_t n) const
{
	return (this->_data[n]);
}

template < class T, class Alloc >
T & vector<T, Alloc>::at (std::size_t n)
{
	if (n < 0 || n >= this->_size)
		throw vector_out_of_range();
	return (this->_data[n]);
}

template < class T, class Alloc >
const T & vector<T, Alloc>::at (std::size_t n) const
{
	if (n < 0 || n >= this->_size)
		throw vector_out_of_range();
	return (this->_data[n]);
}

template < class T, class Alloc >
T & vector<T, Alloc>::front()
{
	return (this->_data[0]);
}

template < class T, class Alloc >
const T & vector<T, Alloc>::front() const
{
	return (this->_data[0]);
}

template < class T, class Alloc >
T & vector<T, Alloc>::back()
{
	return (this->_data[this->_size - 1]);
}

template < class T, class Alloc >
const T & vector<T, Alloc>::back() const
{
	return (this->_data[this->_size - 1]);
}

template class vector<int>;

/*
** iterator
*/

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(): _pointer(NULL)
{
}

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(T * pointer): _pointer(pointer)
{
}

template < class T, class Alloc >
vector<T, Alloc>::iterator::iterator(const iterator & ref): _pointer(ref._pointer)
{
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator & vector<T, Alloc>::iterator::operator = (const iterator & ref)
{
	this->_pointer = ref._pointer;
	return (*this);
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator == (const iterator & ref) const
{
	return (this->_pointer == ref._pointer);
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator != (const iterator & ref) const
{
	return (this->_pointer != ref._pointer);
}

template < class T, class Alloc >
T & vector<T, Alloc>::iterator::operator * () const
{
	return (*this->_pointer);
}

template < class T, class Alloc >
T & vector<T, Alloc>::iterator::operator -> ()
{
	//미완
	return (*this->_pointer);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator & vector<T, Alloc>::iterator::operator++()
{
	++this->_pointer;
	return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator++(int)
{
	vector<T, Alloc>::iterator tmp = *this;
	++this->_pointer;
	return (tmp);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator & vector<T, Alloc>::iterator::operator--()
{
	--this->_pointer;
	return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator--(int)
{
	vector<T, Alloc>::iterator tmp = *this;
	--this->_pointer;
	return (tmp);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator + (int value) const
{
	return (vector<T, Alloc>::iterator(this->_pointer + value));
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator - (int value) const
{
	return (vector<T, Alloc>::iterator(this->_pointer - value));
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator < (const iterator & ref) const
{
	return (this->_pointer < ref._pointer);
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator > (const iterator & ref) const
{
	return (this->_pointer > ref._pointer);
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator <= (const iterator & ref) const
{
	return (this->_pointer <= ref._pointer);
}

template < class T, class Alloc >
bool vector<T, Alloc>::iterator::operator >= (const iterator & ref) const
{
	return (this->_pointer >= ref._pointer);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator += (int value)
{
	this->_pointer += value;
	return (*this);
}

template < class T, class Alloc >
typename vector<T, Alloc>::iterator vector<T, Alloc>::iterator::operator -= (int value)
{
	this->_pointer -= value;
	return (*this);
}

template < class T, class Alloc >
T & vector<T, Alloc>::iterator::operator [] (int value) const
{
	return (*(this->_pointer + value));
}

template < class T, class Alloc >
vector<T, Alloc>::iterator::~iterator()
{
}