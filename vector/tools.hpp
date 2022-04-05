#pragma once

  template <class Iterator, class T, class Allo>
      void fill(Iterator first, Iterator last, const T &val, Allo alloc)
      {
          while (first != last)
          {
            //   *first = val;
              alloc.construct(&(*first), val);
              ++first;
          }
      }
      template<class Iterator1, class Iterator2, class Allo>
      void copy(Iterator1 first, Iterator1 last, Iterator2 result, Allo alloc)
      {
          while (first != last)
          {
            //   *result = *first;
              alloc.construct(&(*result), *first);
              ++result; ++first;
          }
      }
      template<class Iterator1, class Iterator2, class Allo>
      void copy_backward(Iterator1 first, Iterator1 last, Iterator2 result, Allo alloc)
      {
          while(last!=first)
                alloc.construct(&*(--result), *(--last));
            // *(--result) = *(--last);
      }

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
      if (first2 == last2 || *first2 < *first1)
          return false;
      else if (*first1 < *first2)
          return true;
      first1++;
      first2++;
  }
  return (first2!=last2);   
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
  while (first1!=last1)
  {
      if (first2 == last2 || comp(*first2, *first1))
          return false;
      else if (comp(*first1, *first2))
          return true;
      first1++;
      first2++;
  }
  return (first2!=last2);
}

template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    while (first1 != last1)
    {
        if(!(*first1 == *first2))
            return false;
        first1++;
        first2++;
    }
    return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
    while (first1 != last1)
    {
        if (!pred(*first1, *first2))
            return false;
        first1++;
        first2++;
    }
    return true;
}