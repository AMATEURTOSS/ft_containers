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
public: /* CAPACITY */
	std::size_t size ();
	std::size_t max_size() const; // yet
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

#endif