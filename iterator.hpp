/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochoi <yochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:01:27 by yochoi            #+#    #+#             */
/*   Updated: 2021/02/07 17:01:27 by yochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#ifndef NULL
# define NULL 0
#endif

/*
** iterator_tag
*/

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template < class Iter >
struct iterator_traits
{
	typedef typename Iter::iterator_category iterator_category;
};

template < class Iter >
typename Iter::iterator_category get_iter_category(Iter & iterator)
{
	(void)iterator;
	return (typename Iter::iterator_category());
};

#endif