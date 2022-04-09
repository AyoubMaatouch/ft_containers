template <class T> struct less {

  // Declaration of the less operation
  bool operator() (const T& x,
                   const T& y) 
       const 
  {
     return x  < y;
  }

  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};


template <class T1, class T2>
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;
    T1 first;
    T2 second;
    pair() : first(T1()), second(T2()) {}
    pair(const T1 &x, const T2 &y) first(x), second(y) {}
    template <class U, class V>
    pair(const pair<U, V> &p)
    {
        first = p.first;
        second = p.second;
    }
    pair &operator=(const pair &pr)
    {
        if (this == pr)
            return *this
        first = p.first;
        second = p.second;
        return *this
    }
};

template <class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return !(lhs < rhs);
}

template <class T1, class T2>
pair<T1, T2> make_pair(const T1 &x, const T2 &y)
{
    return pair<T1, T2>(x, y);
}