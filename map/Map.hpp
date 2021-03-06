#pragma once

#include <memory>
#include <iostream>
#include "../vector/iterators.hpp"
#include "node.hpp"
#define print(X) std::cout << X << std::endl;

namespace ft
{
#include "../vector/tools.hpp"
#include "map_iterator.hpp"
#include "pair.hpp"

  template <class Key, class T, class Compare = less<Key>,
            class Allocator = std::allocator<pair<const Key, T> > >
  class map
  {
    // types:
  public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
    typedef Allocator allocator_type;
    typedef typename Allocator::reference reference;
    typedef typename Allocator::const_reference const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef typename Allocator::pointer pointer;
    typedef typename Allocator::const_pointer const_pointer;
    typedef bd_iterator <Node<value_type , Allocator>, value_type> iterator;
    typedef bd_iterator <Node<value_type , Allocator>, value_type> const_iterator;
    typedef ::ft::reverse_iterator<iterator> reverse_iterator;
    typedef ::ft::reverse_iterator<const_iterator> const_reverse_iterator;

    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
      friend class map;

    protected:
      Compare comp;
      value_compare(Compare c) : comp(c) {}

    public:
      bool operator()(const value_type &x, const value_type &y) const
      {
        return comp(x.first, y.first);
      }
    };
    // 23.3.1.1 construct/copy/destroy:
    explicit map(const Compare &comp = Compare(),
                 const Allocator & = Allocator()) : _tree(), _size(0), _allocator() , comp(comp) {}

    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const Compare &comp = Compare(), const Allocator & = Allocator()) : _tree(), _size(0), _allocator() , comp(comp)
    {
      insert(first, last);
    }

    map(const map<Key, T, Compare, Allocator> &x) : _tree(), _size(), _allocator()
    {
      insert(x.begin(), x.end());
    }
    ~map()
    {
      clear();
    }
    map<Key, T, Compare, Allocator> &operator=(const map<Key, T, Compare, Allocator> &x)
    {
      clear();
      insert(x.begin(), x.end());
      return *this;
    }

    iterator begin()
    {
      return iterator(_tree.nodeWithMimumValue(_tree.root), _tree.root);
    }
    const_iterator begin() const
    {
      return const_iterator(_tree.nodeWithMimumValue(_tree.root), _tree.root);
    }
    iterator end()
    {
          return iterator(NULL,_tree.root);
        }
    const_iterator end() const
    {
          return const_iterator(NULL,_tree.root);
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const
    {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend()
    {
      return reverse_iterator(begin());
    }
    const_reverse_iterator rend() const
    {
      return const_reverse_iterator(begin());
    }
    // capacity:
    bool empty() const { return !(size() > 0); }
    size_type size() const { return _size; }
    size_type max_size() const { return _allocator.max_size(); }
    // element access:
    T &operator[](const key_type &x)
    {
      return (*((this->insert(ft::make_pair(x, mapped_type()))).first)).second;
    }
    // modifiers:
    ft::pair<iterator, bool> insert(const value_type &x)
    {
      iterator en = end();
      if (!_size || find(x.first) == en)
      {
        _size++;
        _tree.root = _tree.insertNode(_tree.root, NULL, x);
        return (ft::make_pair(find(x.first), true));
      }
      return (ft::make_pair(find(x.first), false));
    }
    iterator insert(iterator position, const value_type &x)
    {
      (void)(position);
      return insert(x).first;
    }
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
      for (; first != last; first++)
      {
        insert(*first);
      }
    }
    size_type erase(const key_type &x)
    {
      if (size())
      {
        if (find(x) == end())
          return 0;
        _size--;
        _tree.root = _tree.deleteNode(_tree.root, x);
        return 1;
      }
      return 0;
    }
    void erase(iterator position)
    {
      erase(position->first);
    }
    void erase(iterator first, iterator last)
    {

      if (size())
      {
        if (first != last)
        {
          iterator it = first;
          erase(++first, last);
          erase(it);
        }
      }
    }
    void swap(map<Key, T, Compare, Allocator> &x)
    {
      ft::swap(x._size, this->_size);
      ft::swap(x._allocator, this->_allocator);
      ft::swap(x._tree, this->_tree);
      ft::swap(x.comp, this->comp);

    }
    void clear()
    {
      _tree.root = _tree.removeAll(_tree.root);
      _size = 0;
    }
    key_compare key_comp() const
    {
      return (comp);
    }
    value_compare value_comp() const
    {
      return (value_compare(key_comp()));
    }

    iterator find(const key_type &x)
    {
      iterator be = iterator(_tree.searchNode(_tree.root, x), _tree.root);
      return be;
    }
    const_iterator find(const key_type &x) const
    {
      const_iterator  be = const_iterator(_tree.searchNode(_tree.root, x), _tree.root);
      return be;
    }
    size_type count(const key_type &x) const
    {
      if (find(x) != end())
        return (1);
      return (0);
    }
    iterator lower_bound(const key_type &x)
    {
      iterator it = begin();
      iterator bg = end();
			while (it != bg)
			{
				if (comp(it->first, x) == false)
					break ;
				++it;
			}
			return (it);
    }
    const_iterator lower_bound(const key_type &x) const
    {
      const_iterator it = begin();
      const_iterator bg = end();
			while (it != bg)
			{
				if (comp(it->first, x) == false)
					break ;
				++it;
			}
			return (it);
      }
  
    iterator upper_bound(const key_type &x)
    {
      iterator it = begin();
      iterator bg = end();
			while (it != bg)
			{
				if (comp(x, it->first) == true)
					break ;
				++it;
			}
			return (it);
    }
    const_iterator upper_bound(const key_type &x) const
    {
      const_iterator it = begin();
      const_iterator bg = end();
			while (it != bg)
			{
				if (comp(x, it->first) == true)
					break ;
				++it;
			}
			return (it);;
    }
    pair<iterator, iterator> equal_range(const key_type &x)
    {
      return (ft::make_pair(lower_bound(x), upper_bound(x)));
    }
    pair<const_iterator, const_iterator> equal_range(const key_type &x) const
    {
      return (ft::make_pair(lower_bound(x), upper_bound(x)));
    }
    allocator_type get_allocator() const
    {
      return (_allocator);
    }

  private:
    AVLTree<value_type, Compare, allocator_type> _tree;
    size_type _size;
    allocator_type _allocator;
    key_compare comp;
  };

}
template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (lhs.size() != rhs.size() || !ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (lhs < rhs || lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
  return (lhs > rhs || lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{
  x.swap(y);
}