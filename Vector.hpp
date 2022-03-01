#pragma once
#include <memory>

namespace ft {

 template < class T, class Alloc = std::allocator<T> > class vector // generic template
{
            typedef Alloc allocator_type;
            //  Contracture
            explicit vector (const allocator_type& alloc = allocator_type());
            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type());

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());	
            //  Copy Contracture
            vector (const vector& x);
            private:
                allocator_type _allocator;      
};