#include "node.hpp"

template <typename Node, typename value_type>
class bd_iterator
{

public:

	typedef value_type &reference;
	typedef value_type *pointer;
	typedef ptrdiff_t difference_type;
	typedef std::bidirectional_iterator_tag iterator_category;

private:

	Node *_root;

public:
	bd_iterator() : _root() {}
	bd_iterator(Node *x) : _root(x) {}

	reference operator*() const
	{
		return _root->item;
	}
	pointer operator->() const { return &(operator*()); }
	bd_iterator &operator++()
	{

		Node *p;
		if (_root->right != NULL)
		{
			_root = _root->right;

			while (_root->left != NULL)
			{
				_root = _root->left;
			}
		}
		else
		{
			p = _root->parent;
			while (p != NULL && _root == p->right)
			{
				_root = p;
				p = p->parent;
			}
			_root = p;
		}
		return *this;
	}
	bd_iterator operator++(int)
	{
		bd_iterator tmp(*this);
		operator++();
		return (tmp);
	}

	bd_iterator &operator--()
	{
		{
			Node *p;

			if (_root->left != NULL)
			{
				_root = _root->left;

				while (_root->right != NULL)
				{
					_root = _root->right;
				}
			}
			else
			{
				p = _root->parent;
				while (p != NULL && _root == p->left)
				{
					_root = p;
					p = p->parent;
				}
				_root = p;
			}
		}
		return *this;
	}

	bd_iterator operator--(int)
	{
		bd_iterator tmp(*this);
		operator--();
		return tmp;
	}

	template <typename S, typename V>
	bool operator!=(const bd_iterator<S, V> &it) const
	{
		return (_root != it._root);
	}
	template <typename S, typename V>
	bool operator==(const bd_iterator<S, V> &it) const
	{
		return (_root == it._root);
	}
	template <typename S, typename V>
	bool operator>(const bd_iterator<S, V> &it) const
	{
		return (_root > it._root);
	}
	template <typename S, typename V>
	bool operator<(const bd_iterator<S, V> &it) const
	{
		return (_root < it._root);
	}
	template <typename S, typename V>
	bool operator<=(const bd_iterator<S, V> &it) const
	{
		return (_root <= it._root);
	}
	template <typename S, typename V>
	bool operator>=(const bd_iterator<S, V> &it) const
	{
		return (_root >= it._root);
	}
};