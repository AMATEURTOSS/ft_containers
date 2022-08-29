#ifndef MAP_HPP
#define MAP_HPP

#include "stack.hpp"
#include "utils/BST.hpp"
#include "utils/pair.hpp"

namespace ft
{

	template <	class Key,										// map::key_type
				class T,										// map::mapped_type
				class Compare = std::less<Key>,					// map::key_compare
				class Alloc = std::allocator<ft::pair<const Key,T> >// map::allocator_type
	> class map
	{
	public:

		class MapIterator
		{
		public:

			typedef typename BST<Key, T>::node	value_type;

		protected:

			value_type * _pointer;

		public:

			MapIterator(): _pointer(NULL) {};

			MapIterator(value_type * ptr): _pointer(ptr) {};
			
			MapIterator(const typename ft::map<Key, T>::MapIterator & ref): _pointer(ref._pointer) {};

			MapIterator & operator = (const typename ft::map<Key, T>::MapIterator & ref)
			{
				_pointer = ref._pointer;
				return (*this);
			};

			virtual ~MapIterator() {};

		public:

			bool operator == (const typename ft::map<Key, T>::MapIterator & ref) const
			{
				return (_pointer == ref._pointer);
			};

			bool operator != (const typename ft::map<Key, T>::MapIterator & ref) const
			{
				return (_pointer != ref._pointer);
			};

		public:
		
			ft::pair<Key, T> & operator * ()
			{
				return (_pointer->value);
			};

			ft::pair<Key, T> * operator -> ()
			{
				return (&_pointer->value);
			};

		public:

			MapIterator & operator ++ (/* Prefix increment operator. */)
			{
				if (_pointer->right)
				{
					_pointer = _pointer->right;
					while (_pointer && _pointer->left)
						_pointer = _pointer->left;
				}
				else
				{
					value_type * tmp;
					do
					{
						tmp = _pointer;
						_pointer = _pointer->parent;
					} while (_pointer && tmp == _pointer->right);
				}
				return (*this);
			};

			MapIterator operator ++ (int/* Postfix increment operator. */)
			{
				MapIterator tmp = *this;
				this->operator++();
				return (tmp);
			};

			MapIterator &operator--(/* Prefix increment operator. */)
			{
				if (_pointer->left)
				{
					_pointer = _pointer->left;
					while (_pointer && _pointer->right)
						_pointer = _pointer->right;
				}
				else
				{
					value_type * tmp;
					do
					{
						tmp = _pointer;
						_pointer = _pointer->parent;
					} while (_pointer && tmp == _pointer->left);
				}
				return (*this);
			};

			MapIterator operator--(int/* Postfix increment operator. */)
			{
				MapIterator tmp = *this;
				this->operator--();
				return (tmp);
			};

		};
	
	public:

		class value_compare : public binary_function< ft::pair<Key, T>, ft::pair<Key, T>, bool>
		{
		protected:
			Compare comp;
		public:
			value_compare(Compare c) : comp(c) {}
			bool operator()(const ft::pair<Key, T>& left, const ft::pair<Key, T>& right) const
			{
				return (comp(left.first, right.first));
			};
		};

	public:

		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<Key, T>							value_type;
		typedef Compare										key_compare;
		typedef value_compare								value_compare;
		typedef Alloc										allocator_type;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef value_type *								pointer;
		typedef const value_type *							const_pointer;
		typedef typename ft::map<Key, T>::MapIterator		iterator;
		typedef const typename ft::map<Key, T>::MapIterator	const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef const reverse_iterator                      const_reverse_iterator;
		typedef size_t										size_type;

	private:

		BST<Key, T> _root;
		key_compare _comp;
		allocator_type _alloc;

	public: /* MEMBER_FUNCTIONS */

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		: _root(BST<Key, T>()), _comp(comp), _alloc(alloc) {};

		template <class InputIterator>
		map (InputIterator first, InputIterator last, \
		const key_compare& comp = key_compare(), \
		const allocator_type& alloc = allocator_type()): _root(BST<Key, T>()), _comp(comp), _alloc(alloc)
		{
			_root.destroy_helper(_root._root);
			while (first != last)
			{
				_root.Insert(*first);
				++first;
			}
		};

		map (const map &x): _root(x._root), _comp(key_compare()), _alloc(allocator_type()) {};

		map & operator = (const map & x)
		{
			_root = x._root;
			return (*this);
		};

		~map() {};

	public: /* ITERATORS */

		iterator begin()
		{
			if (_root._root == NULL)
				return (iterator());
			return (iterator(_root.find_min_value(_root._root)));
		};

		const_iterator begin() const
		{
			if (_root._root == NULL)
				return (const_iterator());
			return (const_iterator(_root.find_min_value(_root._root)));
		};

		iterator end()
		{
			if (_root._root == NULL)
				return (iterator());
			return (iterator(_root.find_max_value(_root._root)->right));
		};

		const_iterator end() const
		{
			if (_root._root == NULL)
				return (const_iterator());
			return (const_iterator(_root.find_max_value(_root._root)->right));
		};

		reverse_iterator rbegin()
		{
			if (_root._root == NULL)
				return (reverse_iterator());
			return (reverse_iterator(_root.find_max_value(_root._root)));
		};

		const_reverse_iterator rbegin() const
		{
			if (_root._root == NULL)
				return (const_reverse_iterator());
			return (const_reverse_iterator(_root.find_max_value(_root._root)));
		};

		reverse_iterator rend()
		{
			if (_root._root == NULL)
				return (reverse_iterator());
			return (reverse_iterator(_root.find_min_value(_root._root)->left));
		};

		const_reverse_iterator rend() const
		{
			if (_root._root == NULL)
				return (const_reverse_iterator());
			return (const_reverse_iterator(_root.find_min_value(_root._root)->left));
		};

	public: /* CAPACITY */

		bool empty() const
		{
			if (_root._root == NULL)
				return (true);
			return (false);
		};

		size_type size() const
		{
			size_type i = 0;
			for (iterator first = begin(); first != end(); ++first)
				++i;
			return (i);
		};

		size_type max_size() const
		{
			return (std::allocator<value_type>().max_size());
		};

	public: /* ELEMENT_ACCESS */

		mapped_type & operator[] (const key_type & k)
		{
			_root.Insert(ft::pair<Key, T>(k, T()));
			return (_root.find(_root._root, k)->value.second);
		};

	public: /* MODIFIERS */

		ft::pair<iterator,bool> insert(const value_type & val)
		{
			ft::pair<iterator, bool> ret;
			ret.second = _root.Insert(val);
			ret.first = this->find(val.first);
			return (ret);
		};

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			_root.Insert(val);
			return (this->find(val.first));
		};

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				_root.Insert(*first);
				++first;
			}
		};

		void erase (iterator position)
		{
			_root.Delete(position->first);
		};

		size_type erase (const key_type & k)
		{
			_root.Delete(k);
			return (1);
		};

		void erase(iterator first, iterator last)
		{
			BST<Key, T> tmp = _root;
			while (first != last)
			{
				tmp.Delete(first->first);
				++first;
			}
			_root = tmp;
		};

		void swap (map& x)
		{
			ft::BST<Key, T> tmp;
			tmp = x._root;
			x._root = _root;
			_root = tmp;
		};

		void clear ()
		{
			_root.disconnect_end_node();
			_root.destroy_helper(_root._root);
		};

	public: /* OBSERVERS */

		key_compare key_comp() const
		{
			return (key_compare());
		};

		value_compare value_comp() const
		{
			return (value_compare(key_compare()));
		};

	public: /* OPERATIONS */

		iterator find (const key_type& k)
		{
			if (_root.find(_root._root, k) == NULL)
				return (end());
			return (iterator(_root.find(_root._root, k)));
		};

		const_iterator find (const key_type& k) const
		{
			if (_root.find(_root._root, k) == NULL)
				return (end());
			return (iterator(_root.find(_root._root, k)));
		};

		size_type count (const key_type& k) const
		{
			if (find(k) != end())
				return (1);
			return (0);
		};

		iterator lower_bound (const key_type& k)
		{
			iterator first = begin();
			for (; first != end(); ++first)
			{
				if (Compare()(first->first, k) == false)
					break;
			}
			return (first);
		};
		
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator first = begin();
			for (; first != end(); ++first)
			{
				if (Compare()(first->first, k) == false)
					break;
			}
			return (first);
		};

		iterator upper_bound (const key_type& k)
		{
			iterator first = this->begin();
			for (; first != end(); ++first)
			{
				if (Compare()(k, first->first))
					break;
			}
			return (first);
		};

		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator first = this->begin();
			for (; first != end(); ++first)
			{
				if (Compare()(k, first->first))
					break;
			}
			return (first);
		};

		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		};

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
		};

	};

};

#endif