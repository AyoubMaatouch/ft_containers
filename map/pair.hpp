#pragma once
#include <iostream>
#include <string>


namespace ft
{

    template <class T>
    struct less
    {

        // Declaration of the less operation
        bool operator()(const T &x,
                        const T &y)
            const
        {
            return x < y;
        }

        typedef T first_argument_type;
        typedef T second_argument_type;
        typedef bool result_type;
    };

    template <class T1, class T2>
    struct pair
    {
        typedef  T1 first_type;
        typedef T2 second_type;
        T1 first;
        T2 second;
        pair() : first(first_type()), second(second_type()) {}
        pair(const first_type &x, const second_type &y) : first(x), second(y) {}
        
        template <class U, class V>
        pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
       
        pair &operator=(const pair &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return *this;
            // return make_pair(pr.first, pr.second);
        }
    };
     template <class T1, class T2>
    std::ostream &operator<<(std::ostream &stream, const pair<T1, T2> &B)
    {
        stream << "[" << B.first << "] [" << B.second << "]";
        return stream;
    }
    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }
    template <class T1, class T2>
    pair<T1, T2> make_pair(const T1 &x, const T2 &y)
    {
        return pair<T1, T2>(x, y);
    }

}