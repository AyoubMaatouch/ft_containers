//! The below iterators (Base random_access_iterator and iterator_traits) are not mandatory, but needed in the subject
//* The base class for all the iterators.

// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>
//   struct iteratorBase {
//     typedef T         value_type;
//     typedef Distance  difference_type;
//     typedef Pointer   pointer;
//     typedef Reference reference;
//     typedef Category  iterator_category;
//   };

// template <class Category, class T, class Distance = ptrdiff_t,
//           class Pointer = T*, class Reference = T&>

#include <iostream>
#include <vector>

std::vector<int *>::iterator *it;

namespace ft
{

    // i think this not as important
    // template <class Category, class T, class Distance = size_t, // ptrdiff_t is sigend and size_t not
    //   class Pointer = T *, class Reference = T &>
    // struct iterBase
    // {
    // typedef T value_type;
    // typedef Distance difference_type;
    // typedef Pointer pointer;
    // typedef Reference reference;
    // typedef Category iterator_category;
    // };

    template <class T>
    class _Iterator //: public iterBase<std::random_access_iterator_tag, T>
    {

    public:
        typedef T value_type;
        typedef size_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;

        _Iterator(pointer p = NULL)
        {
            std::cout << "iterator destractor called" << std::endl;
            _ptr = p;
        }
        ~_Iterator() { std::cout << "iterator destractor called" << std::endl; }

        _Iterator(_Iterator const &src)
        {
            _ptr = src._ptr;
            return;
        }
        _Iterator(_Iterator const &src)
        {
            _ptr = src._ptr;
            return;
        }

        // operator OverLoad
        _Iterator& operator=(_Iterator const &src)
        {
            _ptr = src._ptr;
            return (*this);
        }
        _Iterator& operator=(_Iterator const &src)
        {
            _ptr = src._ptr;
            return (*this);
        }

        _Iterator& operator++(void)
        {
            this->_ptr++;
            return (*this);
        }
        _Iterator& operator++(int)
        {
            _Iterator tmp(*this);
            this->src._ptr; 
            return tmp;
        }

    protected:
        pointer _ptr;
    };
}