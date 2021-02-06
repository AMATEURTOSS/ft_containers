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

#define NULL 0

#include <memory>

template < class T, class Alloc = std::allocator<T> >
class vector
{
public:
	class iterator
	{
	private:
		T *		_pointer;
	public:
		iterator ();
		iterator (T * pointer);
		iterator (const iterator & ref);
		iterator & operator = (const iterator & ref);
		virtual ~iterator ();
	public:
		bool operator == (const iterator & ref) const;
		bool operator != (const iterator & ref) const;
		T & operator * () const;
		T & operator -> (); // 미완
		vector<T, Alloc>::iterator & operator ++ ();         // Prefix increment operator.
		vector<T, Alloc>::iterator operator ++ (int);       // Postfix increment operator.
		vector<T, Alloc>::iterator & operator -- ();       // Prefix decrement operator.
		vector<T, Alloc>::iterator operator -- (int);     // Postfix decrement operator.
		vector<T, Alloc>::iterator operator + (int value) const;
		vector<T, Alloc>::iterator operator - (int value) const;
		bool operator < (const iterator & ref) const;
		bool operator > (const iterator & ref) const;
		bool operator <= (const iterator & ref) const;
		bool operator >= (const iterator & ref) const;
		vector<T, Alloc>::iterator operator += (int value);
		vector<T, Alloc>::iterator operator -= (int value);
		T & operator [] (int value) const;
	};
private:
	T *			_data;
	std::size_t	_size;
public: /* MEMBER_FUNCTIONS */
	explicit vector ();
	explicit vector (std::size_t n);
	explicit vector (std::size_t n, T init_value);
	explicit vector (const vector & ref);
	vector & operator = (const vector & ref);
	virtual ~vector();
public: /* ITERATORS */
	vector<T, Alloc>::iterator begin();
	const vector<T, Alloc>::iterator begin() const;
	vector<T, Alloc>::iterator end();
	const vector<T, Alloc>::iterator end() const;
public: /* CAPACITY */
	std::size_t size ();
	std::size_t max_size() const; // 미완
	void resize (std::size_t n, T val = 0);
public: /* ELEMENT_ACCESS */
	T & operator [] (std::size_t n);
	const T & operator [] (std::size_t n) const;
	T & at (std::size_t n);
	const T & at (std::size_t n) const;
	T & front();
	const T & front() const;
	T & back();
	const T & back() const;
public: /* EXCEPTION */
	class vector_out_of_range: public std::exception
	{
		const char * what () const throw ()
		{
			return ("Vector: Out of Range");
		};
	};
};

template < class T, class Alloc = std::allocator<T> >
typename vector<T, Alloc>::iterator operator + (T i, const typename vector<T, Alloc>::iterator & ref)
{
	return (ref + i);
};

#endif