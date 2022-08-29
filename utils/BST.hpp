#ifndef BST_HPP
#define BST_HPP

#include "pair.hpp"
#include <limits>

namespace ft
{

	template < class Key, class T >
	class BST
	{
	public:

		struct node
		{
			node *				left;
			node *				right;
			node *				parent;
			ft::pair<Key, T>	value;
			node(): left(NULL), right(NULL), parent(NULL), value(ft::pair<Key, T>()) {}
			node(ft::pair<Key, T> val): left(NULL), right(NULL), parent(NULL), value(val) {}
			node & operator = (const node & ref)
			{
				left = ref.left;
				right = ref.right;
				value = ref.value;
				return (*this);
			}
		};

	public:

		node *						_root;
		node *						_lend;
		node *						_rend;
		bool						_is_connected;

	public:

		explicit BST (): _root(NULL), _lend(NULL), _rend(NULL), _is_connected(false)
		{
			_lend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().min(), std::numeric_limits<T>().min()));
			_rend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().max(), std::numeric_limits<T>().max()));
		}

		BST(const BST & ref): _root(NULL), _lend(NULL), _rend(NULL), _is_connected(false)
		{
			node * min;
			node * max;
			_lend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().min(), std::numeric_limits<T>().min()));
			_rend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().max(), std::numeric_limits<T>().max()));
			copy_helper(_root, ref._root, NULL);
			if (ref._is_connected)
			{
				min = this->find(_root, std::numeric_limits<Key>().min());
				max = this->find(_root, std::numeric_limits<Key>().max());
				min->parent->left = NULL;
				max->parent->right = NULL;
				delete min;
				delete max;
			}
			connect_end_node();
		}

		BST & operator = (const BST & ref)
		{
			if (this != &ref)
			{
				disconnect_end_node();
				delete _lend;
				delete _rend;
				destroy_helper(_root);
				_lend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().min(), std::numeric_limits<T>().min()));
				_rend = new node(ft::pair<Key, T>(std::numeric_limits<Key>().max(), std::numeric_limits<T>().max()));
				copy_helper(_root, ref._root, NULL);
				if (ref._is_connected)
				{
					node * min = this->find(_root, std::numeric_limits<Key>().min());
					node * max = this->find(_root, std::numeric_limits<Key>().max());
					min->parent->left = NULL;
					max->parent->right = NULL;
					delete min;
					delete max;
				}
				connect_end_node();
			}
			return (*this);
		}

		~BST()
		{
			disconnect_end_node();
			delete _lend;
			delete _rend;
			destroy_helper(_root);
		}

	public:

		bool Insert (const ft::pair<Key, T> & val)
		{
			node * iter;

			iter = _root;
			if (find(_root, val.first) != NULL)
				return (false);
			if (_root == NULL)
			{
				_root = new node(val);
				connect_end_node();
				return (true);
			}
			disconnect_end_node();
			while (iter)
			{
				if (iter->value <= val)
				{
					if (iter->right == NULL)
					{
						iter->right = new node(val);
						iter->right->parent = iter;
						break ;
					}
					iter = iter->right;
				}
				else
				{
					if (iter->left == NULL)
					{
						iter->left = new node(val);
						iter->left->parent = iter;
						break ;
					}
					iter = iter->left;
				}
			}
			connect_end_node();
			return (true);
		}

		void Delete(const Key & k)
		{
			node * target = find(_root, k);

			disconnect_end_node();
			if (target->left == NULL && target->right == NULL) // if node is leaf
			{
				if (target == _root)
					_root = NULL;
				else if (target->parent->right == target)
					target->parent->right = NULL;
				else
					target->parent->left = NULL;
				delete target;
			}
			else if (target->left && target->right) // if node has two child
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
			connect_end_node();
		}

	public:

		void copy_helper(node * &copy_to, const node * copy_from, node * parent) const
		{
			if(copy_from == NULL)
			{
				copy_to = NULL;
			}
			else
			{
				copy_to = new node();
				copy_to->value = copy_from->value;
				copy_to->parent = parent;
				copy_helper(copy_to->left, copy_from->left, copy_to);
				copy_helper(copy_to->right, copy_from->right, copy_to);
			}
		}

		void destroy_helper(node * root)
		{
			if (root == NULL)
				return ;
			destroy_helper(root->left);
			destroy_helper(root->right);
			delete root;
			_root = NULL;
		}

		node * find_min_value(node * start_point) const
		{
			if (start_point->left == NULL)
				return (start_point->parent);
			return (find_min_value(start_point->left));
		}

		node * find_max_value(node * start_point) const
		{
			if (start_point->right == NULL)
				return (start_point->parent);
			return (find_max_value(start_point->right));
		}

		node * find(node * start_point, Key k) const
		{
			node * iter;

			// ret.first = parent;
			// ret.second = target;
			iter = start_point;
			while (iter)
			{
				if (iter->value.first == k)
					return (iter);
				if (iter->value.first <= k)
					iter = iter->right;
				else
					iter = iter->left;
			}
			return (NULL);
		}

		void connect_end_node()
		{
			if (_root == NULL)
				return ;
			if (_is_connected == true)
				return ;
			{ // make left end node
				node * tmp = _root;
				while (tmp->left)
					tmp = tmp->left;
				tmp->left = _lend;
				tmp->left->parent = tmp;
			}
			{ // make right end node
				node * tmp = _root;
				while (tmp->right)
					tmp = tmp->right;
				tmp->right = _rend;
				tmp->right->parent = tmp;
			}
			_is_connected = true;
		}

		void disconnect_end_node()
		{
			if (_is_connected == false)
				return ;
			node * min = find_min_value(_root);
			node * max = find_max_value(_root);
			min->left = NULL;
			max->right = NULL;
			_is_connected = false;
		}

	};

};

#endif
