#pragma once
#include <memory>
#include <iostream>
#include "../vector/iterators.hpp"

namespace ft
{
  # include "pair.hpp"
  template <class Key, class T, class Compare = ft::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T> > >
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
    typedef "implementation defined" iterator;        // See 23.1
    typedef "implementation defined" const_iterator;  // See 23.1
    typedef  size_t size_type;       // See 23.1
    typedef  ptrdiff_t difference_type; // See 23.1
    typedef typename Allocator::pointer pointer;
    typedef typename Allocator::const_pointer const_pointer;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    //  khaaarita
    class value_compare : public binary_function<value_type, value_type, bool>
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
                 const Allocator & = Allocator());
    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const Compare &comp = Compare(), const Allocator & = Allocator());
    map(const map<Key, T, Compare, Allocator> &x);
    ~map();
    map<Key, T, Compare, Allocator> &operator=(const map<Key, T, Compare, Allocator> &x);
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;
    // capacity:
    bool empty() const;
    size_type size() const;
    size_type max_size() const;
    // 23.3.1.2 element access:
    T &operator[](const key_type &x);
    // modifiers:
    pair<iterator, bool> insert(const value_type &x);
    iterator insert(iterator position, const value_type &x);
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(iterator position);
    size_type erase(const key_type &x);
    void erase(iterator first, iterator last);
    void swap(map<Key, T, Compare, Allocator> &);
    void clear();
    key_compare key_comp() const;
    value_compare value_comp() const;
    iterator find(const key_type &x);
    const_iterator find(const key_type &x) const;
    size_type count(const key_type &x) const;
    iterator lower_bound(const key_type &x);
    const_iterator lower_bound(const key_type &x) const;
    iterator upper_bound(const key_type &x);
    const_iterator upper_bound(const key_type &x) const;
    pair<iterator, iterator>
    equal_range(const key_type &x);
    pair<const_iterator, const_iterator>
    equal_range(const key_type &x) const;
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