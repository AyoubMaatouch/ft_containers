#pragma once
#include <iostream>
#include <vector>

std::vector<int *>::iterator *it;

namespace ft
{

    template <class T>
    class _Iterator //: public iterBase<std::random_access_iterator_tag, T>
    {

    public:
        typedef     T                               value_type;
        typedef     ptrdiff_t                       difference_type; //ptrdiff_t is sigend and size_t not
        typedef     T&                                  reference;
        typedef     T*                                  pointer;
        typedef     std::random_access_iterator_tag     iterator_category;

        _Iterator(): _ptrBase() {}
        
        _Iterator(pointer p)
        {
            _ptrBase = p;
        }
        ~_Iterator() {}

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
        _Iterator operator++(int)
        {
            _Iterator tmp(*this);
            this->_ptrBase++; 
            return tmp;
        }
        _Iterator operator--(int)
        {
            _Iterator tmp(*this);
            this->_ptrBase--; 
            return tmp;
        }
        
        //Comparisions Operators : “==”, “!=”, “>”, “<”, “>=”,  “<=”
        
        bool operator==(_Iterator const &src)
        {
            return ((this->_ptrBase) == src._ptrBase);
        }
        bool operator!=(_Iterator const &src)
        {
            return ((this->_ptrBase) != src._ptrBase);
        }
        bool operator>(_Iterator const &src)
        {
            return ((this->_ptrBase) > src._ptrBase);
        }
        bool operator <(_Iterator const &src)
        {
            return ((this->_ptrBase) < src._ptrBase);
        }
        bool operator <=(_Iterator const &src)
        {
            return ((this->_ptrBase) <= src._ptrBase);
        }
        bool operator >=(_Iterator const &src)
        {
            return ((this->_ptrBase) >= src._ptrBase);
        }

        //arithmetic operators (+, +=, -=, -, [])
        _Iterator operator+(difference_type index)
        {
// return value calles constructor so noo need to call it again
            return (_Iterator(_ptrBase + index));
        }
        void operator+=(difference_type index)
        {
            this->_ptrBase + index;
        }
        void operator-=(difference_type index)
        {
            this->_ptrBase - index;
        }
        _Iterator operator-(difference_type index)
        { 
            return (_ptrBase - index);
        }
        
        _Iterator operator-(_Iterator const &sr)
        { 
            return (_Iterator(this->_ptrBase - sr._ptrBase));
        }
        reference operator[](difference_type index)
        { 
            return (this->_ptrBase[index]);
        }
        pointer operator->()
        { 
            return ((this->_ptrBase));
        }
        reference operator*()
        { 
            return (*(this->_ptrBase));
        }
        
    private:
        pointer _ptrBase;
    };

template <class T>
_Iterator<T> operator+(ptrdiff_t index, _Iterator<T> sr)
        {
            return (_Iterator<T>(sr._ptrBase + index));
        }
}