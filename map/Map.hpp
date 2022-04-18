#pragma once
#include <memory>
#include <iostream>
#include "../vector/iterators.hpp"
#include "node.hpp"

namespace ft
{
  # include "map_iterator.hpp"
  # include "pair.hpp"
  template <class Key, class T, class Compare = less<Key>,
            class Allocator = std::allocator<pair<const Key, T> > >
  class map
  {

  public:
    // types:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef Compare key_compare;
    typedef Allocator allocator_type;
    typedef typename Allocator::reference reference;
    typedef typename Allocator::const_reference const_reference;
    typedef  size_t size_type;       
    typedef  ptrdiff_t difference_type;
    typedef typename Allocator::pointer pointer;
    typedef typename Allocator::const_pointer const_pointer;
    typedef bd_iterator<Node<value_type, Allocator>, value_type > iterator;       
    typedef bd_iterator<Node<value_type, Allocator>, value_type > const_iterator; 
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
                 const Allocator & = Allocator()): _tree(), _size() {}
  
    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const Compare &comp = Compare(), const Allocator & = Allocator()) : _tree(), _size(0)
        {
          for (; first != last; first++)
          {
            _tree.root = _tree.insertNode(_tree.root, NULL, (*first));
            _size++;
          }
        }

    map(const map<Key, T, Compare, Allocator> &x) :_tree(x.tree), _size(x._size) {}
    // ~map();
    map<Key, T, Compare, Allocator> &operator=(const map<Key, T, Compare, Allocator> &x);
   
    iterator begin() { 
      return iterator(_tree.nodeWithMimumValue(_tree.root)); }
    const_iterator begin() const { 
      return const_iterator(_tree.nodeWithMimumValue(_tree.root)); }
    iterator end() { 
       return iterator((_tree.nodeWithMaxValue(_tree.root))->right);
       }
    const_iterator end() const
    {
      return const_iterator((_tree.nodeWithMaxValue(_tree.root))->right);
    }
    reverse_iterator rbegin()
    {
      return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const
    {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend () { 
      return reverse_iterator(begin()); }
    const_reverse_iterator rend() const{ 
      return const_reverse_iterator(begin()); 
      }
    // capacity:
    bool empty() const { return !(size() > 0); }
    size_type size() const { return _size; }
    size_type max_size() const { _allocator.max_size(); }
    // element access:
    T &operator[](const key_type &x);
    // modifiers:
    pair<iterator, bool> insert(const value_type &x);
    {
      // find return position if not insert and 
      // return pair true and with new postion for it
      // if (find(v))
      _tree.root = _tree.insertNode(_tree.root, NULL, x);
    }
    iterator insert(iterator position, const value_type &x);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(iterator position);
    size_type erase(const key_type &x);
    void erase(iterator first, iterator last);
    void swap(map<Key, T, Compare, Allocator> &);
    void clear();
    key_compare key_comp() const {return  key_compare(); }
    value_compare value_comp() const { return value_compare();}
    iterator find(const key_type &x)
    {
      iterator be = begin();
      iterator ed = end();
      for (; be != ed; be++)
      {
          if (be->first == x)
            return (be);
      }
      return ed;
    }
    const_iterator find(const key_type &x) const
    {
      const_iterator be = begin();
      const_iterator ed = end();
      for (; be != ed; be++)
      {
          if (be->first == x)
            return (be);
      }
      return ed;
    }
    size_type count(const key_type &x) const;
    iterator lower_bound(const key_type &x);
    const_iterator lower_bound(const key_type &x) const;
    iterator upper_bound(const key_type &x);
    const_iterator upper_bound(const key_type &x) const;
    pair<iterator, iterator> equal_range(const key_type &x);
    pair<const_iterator, const_iterator> equal_range(const key_type &x) const;
    private:
      AVLTree<value_type, Compare, allocator_type> _tree;
      size_type       _size;
      allocator_type  _allocator;
      // value_compare   _vcompare;
  };
  template <class Key, class T, class Compare, class Allocator>
  bool operator==(const map<Key, T, Compare, Allocator> &x,
                  const map<Key, T, Compare, Allocator> &y);
  template <class Key, class T, class Compare, class Allocator>
  bool operator<(const map<Key, T, Compare, Allocator> &x,
                 const map<Key, T, Compare, Allocator> &y);
  template <class Key, class T, class Compare, class Allocator>
  bool operator!=(const map<Key, T, Compare, Allocator> &x,
                  const map<Key, T, Compare, Allocator> &y);
  template <class Key, class T, class Compare, class Allocator>
  bool operator>(const map<Key, T, Compare, Allocator> &x,
                 const map<Key, T, Compare, Allocator> &y);
  template <class Key, class T, class Compare, class Allocator>
  bool operator>=(const map<Key, T, Compare, Allocator> &x,
                  const map<Key, T, Compare, Allocator> &y);
  template <class Key, class T, class Compare, class Allocator>
  bool operator<=(const map<Key, T, Compare, Allocator> &x,
                  const map<Key, T, Compare, Allocator> &y);
  // specialized algorithms:
  template <class Key, class T, class Compare, class Allocator>
  void swap(map<Key, T, Compare, Allocator> &x,
            map<Key, T, Compare, Allocator> &y);
}