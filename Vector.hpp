#pragma once

namespace ft {

 class vector
    {
            //  Contracture
            explicit vector (const allocator_type& alloc = allocator_type());
            explicit vector (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type());

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());	
            //  Copy Contracture
            vector (const vector& x);
    }
}