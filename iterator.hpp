#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};

	template < class Iterator >
	class reverse_iterator: public Iterator
	{
	public:

		reverse_iterator(): Iterator() {};

		reverse_iterator(typename Iterator::value_type * pointer): Iterator(pointer) {};

		reverse_iterator(const reverse_iterator<Iterator> & ref): Iterator(ref) {};

		reverse_iterator & operator = (const reverse_iterator<Iterator> & ref)
		{
			this->_pointer = ref._pointer;
			return (*this);
		};

		virtual ~reverse_iterator() {};

	public:

		Iterator operator++(int/* Postfix increment operator. */)
		{
			return (Iterator::operator--(int()));
		}

		Iterator &operator++(/* Prefix increment operator. */)
		{
			return (Iterator::operator--());
		}

		Iterator operator--(int/* Postfix decrement operator. */)
		{
			return (Iterator::operator++(int()));
		}

		Iterator &operator--(/* Prefix decrement operator. */)
		{
			return (Iterator::operator++());
		}

	};
};

#endif
