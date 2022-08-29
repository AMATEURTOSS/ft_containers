#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <exception>
# include <iterator>
# include <limits>
# include <algorithm>
# include "utils/iterator.hpp"
# include "utils/algorithm.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
	private:

		class node
		{
		public:
			node * prev;
			node * next;
			T val;
		public:
			node(): prev(NULL), next(NULL), val(T()) {};
		};

	public:

		class ListIterator
		{
		public:

			typedef node											value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef T &												reference;
			typedef const T &										const_reference;
			typedef T *												pointer;
			typedef const T *										const_pointer;
			typedef std::bidirectional_iterator_tag					iterator_category;

		protected:

			node *		_pointer;

		public:

			ListIterator(): _pointer(NULL) {}

			ListIterator(node * pointer): _pointer(pointer) {}

			ListIterator(const typename list<T>::ListIterator & ref): _pointer(ref._pointer) {}

			ListIterator & operator = (const typename list<T>::ListIterator & ref)
			{
				this->_pointer = ref._pointer;
				return (*this);
			}

			virtual ~ListIterator() {}

		public:

			bool operator == (const typename list<T>::ListIterator & ref) const
			{
				return (_pointer == ref._pointer);
			}

			bool operator != (const typename list<T>::ListIterator & ref) const
			{
				return (_pointer != ref._pointer);
			}

			T & operator * () const
			{
				return (_pointer->val);
			}

			node * operator -> () const
			{
				return (_pointer);
			}

			ListIterator & operator ++ (/* Prefix increment operator. */)
			{
				if (_pointer != NULL)
					_pointer = _pointer->next;
				return (*this);
			}

			ListIterator operator ++ (int/* Postfix increment operator. */)
			{
				ListIterator ret = *this;
				if (_pointer != NULL)
					_pointer = _pointer->next;
				return (ret);
			}

			ListIterator & operator -- (/* Prefix decrement operator. */)
			{
				if (_pointer != NULL)
					_pointer = _pointer->prev;
				return (*this);
			}

			ListIterator operator -- (int/* Postfix decrement operator. */)
			{
				ListIterator ret = *this;
				if (_pointer != NULL)
					_pointer = _pointer->prev;
				return (ret);
			}

			node * get_pointer()
			{
				return (_pointer);
			}

		};

	public:

		typedef T												value_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef T &												reference;
		typedef const T &										const_reference;
		typedef T *												pointer;
		typedef const T *										const_pointer;
		typedef typename list<value_type>::ListIterator			iterator;
		typedef const typename list<value_type>::ListIterator	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef const reverse_iterator                      	const_reverse_iterator;

	public:

		node *		_head;
		node *		_tail;
		size_type	_size;

	public: /* MEMBER_FUNCTIONS */

		explicit list (): _head	(new node()), _tail(new node()), _size(0)
		{
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
		}

		explicit list (size_type n, const value_type& val = value_type()): _head(new node()), _tail(new node()), _size(0)
		{
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
			this->assign(n, val);
		}

		template <class InputIterator>
		list (InputIterator first, InputIterator last): _head(new node()), _tail(new node()), _size(0)
		{
			this->private_iterator_constructor(first, last, typename ft::is_iterator<InputIterator>::val());
		}

	public:

		list (const list & x): _head(new node()), _tail(new node()), _size(0)
		{
			iterator first;
			iterator last;

			first = x.begin();
			last = x.end();
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
			this->assign(first, last);
		}

		list& operator = (const list& x)
		{
			iterator first;
			iterator last;

			clear();
			first = x.begin();
			last = x.end();
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
			this->assign(first, last);
			return (*this);
		}

		~list()
		{
			clear();
			delete _head;
			delete _tail;
			_head = NULL;
			_tail = NULL;
		}

	public: /* ITERATORS */

		iterator begin()
		{
			return (iterator(_head->next));
		}

		const_iterator begin() const
		{
			return (iterator(_head->next));
		}

		iterator end()
		{
			return (iterator(_tail));
		}

		const_iterator end() const
		{
			return (iterator(_tail));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_tail->prev));
		}

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(_tail->prev));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(_head));
		}

		const_reverse_iterator rend() const
		{
			return (reverse_iterator(_head));
		}

	public: /* CAPACITY */

		bool empty() const
		{
			return (_size == 0);
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (std::allocator<node>().max_size());
		}

	public: /* ELEMENT_ACCESS */

		reference front()
		{
			return (_head->next->val);
		}

		const_reference front() const
		{
			return (_head->next->val);
		}

		reference back()
		{
			return (_tail->prev->val);
		}

		const_reference back() const
		{
			return (_tail->prev->val);
		}

	public: /* MODIFIERS */

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			this->private_assign(first, last, typename ft::is_iterator<InputIterator>::val());
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			node * iter;
			node * prev;

			_head->next = new node();
			iter = _head->next;
			iter->prev = _head;
			iter->val = val;
			prev = iter;
			for (size_type i = 1; i < n; ++i)
			{
				iter->next = new node();
				iter = iter->next;
				iter->prev = prev;
				iter->next = NULL;
				iter->val = val;
				prev = iter;
			}
			iter->next = _tail;
			_tail->prev = iter;
			_size = n;
		}

	public:

		void push_front (const value_type& val)
		{
			node * new_node;

			new_node = new node();
			new_node->next = _head->next;
			new_node->prev = _head;
			new_node->val = val;
			_head->next = new_node;
			new_node->next->prev = new_node;
			_size += 1;
		}

		void pop_front()
		{
			node * next;

			next = _head->next->next;
			delete _head->next;
			_head->next = next;
			next->prev = _head;
			_size -= 1;
		}

		void push_back (const value_type& val)
		{
			node * new_node;

			new_node = new node();
			new_node->next = _tail;
			new_node->prev = _tail->prev;
			new_node->val = val;
			_tail->prev = new_node;
			new_node->prev->next = new_node;
			_size += 1;
		}

		void pop_back ()
		{
			node * prev;

			prev = _tail->prev->prev;
			delete _tail->prev;
			_tail->prev = prev;
			prev->next= _tail;
			_size -= 1;
		}

		iterator insert (iterator position, const value_type& val)
		{
			node * new_node;

			new_node = new node();
			new_node->val = val;
			new_node->next = position.get_pointer();
			new_node->prev = position->prev;
			position->prev = new_node;
			new_node->prev->next = new_node;
			++_size;
			return (position->prev);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			for (size_type i = 0; i < n; ++i)
				this->insert(position, val);
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
			   typename InputIterator::iterator_category isIter = typename InputIterator::iterator_category())
		{
			(void)isIter;
			for (; first != last;)
				this->insert(position, *first++);
		}

		iterator erase (iterator position)
		{
			node * dest;
			
			if (position == NULL)
				return (NULL);
			dest = position->next->prev;
			position->next->prev = position->prev;
			position->prev->next = position->next;
			delete dest;
			_size -= 1;
			return (position->next);
		}

		iterator erase (iterator first, iterator last)
		{
			if (first == NULL || last == NULL )
				return (NULL);
			for (; first != last;)
				this->erase(first++);
			return (last);
		}

		void swap (list& x)
		{
			std::swap(_head, x._head);
			std::swap(_tail, x._tail);
			std::swap(_size, x._size);
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (_size == n)
				return ;
			if (_size > n)
				for (; _size > n;)
					this->erase(--(this->end()));
			if (_size < n)
				for (size_type i = 0; i < n - _size; ++i)
					this->insert(this->end(), val);
		}

		void clear()
		{
			iterator begin;
			iterator end;

			begin = this->begin();
			end = this->end();
			while (begin != end)
			{
				delete (begin++.get_pointer());
			}
			_size = 0;
			_head->next = _tail;
			_tail->prev = _head;
		}

	public: /* OPERATIONS */

		void splice (iterator position, list& x)
		{
			this->insert(position, x.begin(), x.end());
			x.clear();
		}

		void splice (iterator position, list& x, iterator i)
		{
			this->insert(position, *i);
			x.erase(i);
		}

		void splice (iterator position, list& x, iterator first, iterator last)
		{
			this->insert(position, first, last);
			x.erase(first, last);
		}

		void remove (const value_type& val)
		{
			iterator first;
			iterator last;

			first = this->begin();
			last = this->end();
			while (first != last)
			{
				if (first->val == val)
					erase(first++);
				else
					++first;
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred)
		{
			iterator first;
			iterator last;

			first = this->begin();
			last = this->end();
			while (first != last)
			{
				if (pred(*first))
					erase(first++);
				else
					++first;
			}
		}

		void unique ()
		{
			iterator first;
			iterator last;

			first = this->begin();
			last = this->end();
			while (first != last)
			{
				if (*first == first->next->val)
					this->erase(iterator(first->next));
				else
					++first;
			}
		}

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred)
		{
			iterator first;
			iterator last;

			first = this->begin();
			last = this->end();
			while (first != last)
			{
				if (binary_pred(*first, first->next->val))
					this->erase(iterator(first->next));
				else
					++first;
			}
		}

		void merge (list& x)
		{
			this->splice(this->end(), x);
			this->sort();
		}

		template <class Compare>
		void merge (list& x, Compare comp)
		{
			this->splice(this->end(), x);
			this->sort(comp);
		}

		void sort()
		{
			node *first = this->begin().get_pointer();
			node *next = first->next;
			node *before;
			node *after;
			while (next != _tail)
			{
				if (next->val < first->val)
				{
					before = first->prev;
					after = next->next;
					before->next = next;
					next->prev = before;
					next->next = first;
					first->prev = next;
					first->next = after;
					after->prev = first;
					first = this->begin().get_pointer();
					next = first->next;
				}
				else
				{
					first = first->next;
					next = next->next;
				}
			}
		}

		template <class Compare>
		void sort (Compare comp)
		{
			node *first = this->begin().get_pointer();
			node *next = first->next;
			node *before;
			node *after;
			while (next != _tail)
			{
				if (comp(next->val, first->val))
				{
					before = first->prev;
					after = next->next;
					before->next = next;
					next->prev = before;
					next->next = first;
					first->prev = next;
					first->next = after;
					after->prev = first;
					first = this->begin().get_pointer();
					next = first->next;
				}
				else
				{
					first = first->next;
					next = next->next;
				}
			}
		}

		void reverse()
		{
			reverse_iterator rfirst;
			reverse_iterator rend;
			list tmp;

			rfirst = this->rbegin();
			rend = this->rend();
			while (rfirst != rend)
			{
				tmp.push_back(*rfirst);
				++rfirst;
			}
			*this = tmp;
		}

	private:

		template < class InputIterator >
		void private_iterator_constructor(InputIterator first, InputIterator last, ft::truth)
		{
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
			this->template assign(first, last);
		}

		void private_iterator_constructor(size_type n, const value_type & val, ft::falsity)
		{
			_head->prev = _tail;
			_head->next = _tail;
			_tail->prev = _head;
			_tail->next = _head;
			this->assign(n, val);
		}

		template < class InputIterator >
		void private_assign(InputIterator first, InputIterator last, ft::truth)
		{
			clear();
			node * iter;
			node * prev;

			clear();
			iter = _head;
			prev = _head;
			while (first != last)
			{
				iter->next = new node();
				iter = iter->next;
				iter->prev = prev;
				iter->val = *first;
				prev = iter;
				++first;
				++_size;
			}
			iter->next = _tail;
			_tail->prev = iter;
		}

		void private_assign(size_type n, const value_type& val, ft::falsity)
		{
			this->assign(n, val);
		}

		/* NON-MEMBER_FUNCTION_OVERLOADS */

		friend bool		operator == (const list & lhs, const list & rhs)	{ return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
		friend bool		operator != (const list & lhs, const list & rhs)	{ return (!(lhs == rhs)); }
		friend bool		operator < (const list & lhs, const list & rhs)		{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
		friend bool		operator <= (const list & lhs, const list & rhs)	{ return (!(rhs < lhs)); }
		friend bool		operator > (const list & lhs, const list & rhs)		{ return (rhs < lhs); }
		friend bool		operator >= (const list & lhs, const list & rhs)	{ return (!(lhs < rhs)); }

	};

	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
