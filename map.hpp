#ifndef MAP_HPP
#define MAP_HPP

#include "stack.hpp"
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

		struct node
		{
			node *	left;
			node *	right;
			ft::pair<Key, T> value;
			node(): left(NULL), right(NULL), value(ft::pair<Key, T>()) {}
			node(ft::pair<Key, T> val): left(NULL), right(NULL), value(val) {}
			node & operator = (const node & ref)
			{
				left = ref.left;
				right = ref.right;
				value = ref.value;
				return (*this);
			}
		};

	public:

		typedef Key								key_value;
		typedef T								mapped_type;
		typedef ft::pair<Key, T>				value_type;
		typedef std::less<Key>					key_compare;
		// typedef value_comp					value_compare;
		typedef Alloc							allocator_type;
		typedef value_type &					reference;
		typedef const value_type &				const_reference;
		typedef value_type *					pointer;
		typedef const value_type *				const_pointer;

	private:

		node *	_root;

	public:

		explicit map (): _root(NULL)
		{
		}

		map(const map & ref): _root(NULL)
		{
			copy_helper(_root, ref._root);
		}

		map & operator = (const map & ref)
		{
			if (this != &ref)
			{
				destroy_helper(_root);
				copy_helper(_root, ref._root);
			}
			return (*this);
		}

		~map()
		{
			destroy_helper(_root);
		}

	public:

		void insert (const value_type& val)
		{
			node * iter;

			iter = _root;
			if (_root == NULL)
			{
				_root = new node(val);
				return; // _root
			}
			while (iter)
			{
				if (iter->value <= val)
				{
					if (iter->right == NULL)
					{
						iter->right = new node(val);
						return; // iter->right;
					}
					iter = iter->right;
				}
				else
				{
					if (iter->left == NULL)
					{
						iter->left = new node(val);
						return; //iter->left;
					}
					iter = iter->left;
				}
			}
			return; // NULL, false
		}

		void Delete(T val)
		{
			node * target_parent = find_with_parent(_root, val).first;
			node * target = find_with_parent(_root, val).second;

			if (target->left == NULL && target->right == NULL) // if node is leaf
			{
				if (target_parent->right == target)
					target_parent->right = NULL;
				else
					target_parent->left = NULL;
				delete target;
			}
			else if (target->left != NULL && target->right != NULL) // if node has two child
			{
				node * minNode = find_min_value(target->right); // find target->rightTree->minNode
				minNode->left = target->left;
				*target = *minNode;
				delete minNode;
			}
			else // if node has only one child
			{
				node * child = target->left == NULL ? target->right : target->left;
				*target = *child;
				delete child;
			}
		}

	private:

		void copy_helper(node * &copy_to, const node * copy_from) const
		{
			if(copy_from == NULL)
			{
				copy_to = NULL;
			}
			else
			{
				copy_to = new node();
				copy_to->value = copy_from->value;
				copy_helper(copy_to->left, copy_from->left);
				copy_helper(copy_to->right, copy_from->right);
			}
		}

		void destroy_helper(node * root)
		{
			if (root == NULL)
				return ;
			destroy_helper(root->left);
			destroy_helper(root->right);
			delete root;
		}

		node * find_min_value(node * start_point)
		{
			if (start_point->left == NULL)
				return (start_point);
			return (find_min_value(start_point->left));
		}

		ft::pair<node *, node *> find_with_parent(node * start_point, T val)
		{
			node * parent;
			node * iter;

			// ret.first = parent;
			// ret.second = target;
			parent = NULL;
			iter = start_point;
			while (iter)
			{
				if (iter->value == val)
					return (ft::pair<node *, node *>(parent, iter));
				parent = iter;
				if (iter->value  <= val)
					iter = iter->right;
				else
					iter = iter->left;
			}
			return (ft::pair<node *, node *>());
		}

	};

};

#endif
