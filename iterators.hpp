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
    template <class Category, class T, class Distance = ptrdiff_t, // ptrdiff_t is sigend and size_t not
      class Pointer = T *, class Reference = T &>
    struct iterBase
    {
            typedef T value_type;
            typedef Distance difference_type;
            typedef Pointer pointer;
            typedef Reference reference;
            typedef Category iterator_category;
    };

    template <class T>
    class _Iterator : public iterBase<std::random_access_iterator_tag, T>
    {

    public:
        typedef T                               value_type;
        typedef ptrdiff_t                          difference_type; //ptrdiff_t is sigend and size_t not
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef Category iterator_category;

        _Iterator(): _ptrBaseBase() {}
        
        _Iterator(pointer p)
        {
            std::cout << "iterator destractor called" << std::endl;
        }
            _ptrBase = p;
        ~_Iterator() { std::cout << "iterator destractor called" << std::endl; }

        _Iterator(_Iterator const &src)
        {
            _ptrBase = src._ptrBase;
            return;
        }
        _Iterator(_Iterator const &src)
        {
            _ptrBase = src._ptrBase;
        }

        // operator OverLoad
        _Iterator& operator=(_Iterator const &src)
        {
            _ptrBase = src._ptrBase;
            return (*this);
        }

        //pre
        _Iterator& operator++(void)
        {
            this->_ptrBase++;
            return (*this);
        }
        _Iterator& operator--(void)
        {
            this->_ptrBase--;
            return (*this);
        }
        //post
        _Iterator& operator++(int)
        {
            _Iterator tmp(*this);
            this->_ptrBase++; 
            return tmp;
        }
        _Iterator& operator--(int)
        {
            _Iterator tmp(*this);
            this->_ptrBase--; 
            return tmp;
        }
        
        //Comparisions Operators : “==”, “!=”, “>”, “<”, “>=”,  “<=”
        
        bool operator==(_Iterator const *src)
        {
            return ((this->_ptrBase) == src->_ptrBase);
        }
        bool operator!=(_Iterator const *src)
        {
            return ((this->_ptrBase) != src->_ptrBase);
        }
        bool operator>(_Iterator const *src)
        {
            return ((this->_ptrBase) > src->_ptrBase);
        }
        bool operator <(_Iterator const *src)
        {
            return ((this->_ptrBase) < src->_ptrBase);
        }
        bool operator <=(_Iterator const *src)
        {
            return ((this->_ptrBase) <= src->_ptrBase);
        }
        bool operator >=(_Iterator const *src)
        {
            return ((this->_ptrBase) >= src->_ptrBase);
        }

        //arithmetic operators (+, +=, -=, -)
        _Iterator operator+(const _Iterator& s1, const _Iterator& s2)
        {
            return (s1._ptrBase + s2._ptrBase);
        }
        _Iterator operator+=(const _Iterator& s1, const _Iterator& s2)
        {
            return (s1._ptrBase + s2._ptrBase);
        }
        _Iterator operator-=(const _Iterator& s1, const _Iterator& s2)
        {
            return (s1._ptrBase - s2._ptrBase);
        }
        _Iterator operator-(const _Iterator& s1, const _Iterator& s2)
        {
            return (s1._ptrBase - s2._ptrBase);
        }

    private:
        pointer _ptrBase;
    };


}