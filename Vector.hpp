#pragma once
#include <memory>

#include "iterators.hpp"
namespace ft
{

 template <class T, class Allocator = std::allocator<T> > class vector {
		   public:
			typedef typename Allocator::reference        	reference;
			typedef typename Allocator::const_reference   	const_reference;
			typedef std::size_t 							size_type;
			typedef std::ptrdiff_t 							diffrence_type;
			typedef T 										value_type;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef ::ft::Iterator<T>            				iterator;
			typedef ::ft::Iterator<const T>       			const_iterator;
			typedef ::ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ::ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

		   private :
		   	pointer 		_buffer;
			allocator_type _allocater;
			size_type _size;
			size_type _capacity;

		// construct/copy/destroy:
		public:
		explicit vector(const Allocator& alloc = Allocator()): _buffer(), _size(), _capacity()
		{
			_allocater = alloc;
		}
		explicit vector(size_type n, const T& value = T(),
            const Allocator& alloc = Allocator())
			{
				_allocater = alloc ;
				_size = n;
				_capacity = n;
				_buffer = _allocater.allocate(n);
				for (size_type i = 0; i < n ; i++)
					_allocater.construct((_buffer + i), value);
			}
		iterator begin()
		{
			return iterator(_buffer);
		}
/***
        template <class InputIterator>
          vector(InputIterator first, InputIterator last,
            const Allocator& = Allocator());

        vector(const vector<T,Allocator>& x);

       ~vector();
        vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
        template <class InputIterator>
          void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const T& u);
        allocator_type get_allocator() const;
		
		// iterators:
		iterator begin(); 
		const_iterator begin()const; 
		iterator end(); 
		const_iterator end()const; 
		reverse_iterator rbegin(); 
		const_reverse_iterator rbegin() const; 
		reverse_iterator rend(); 
		const_reverse_iterator rend() const;

		// 23.2.4.2 capacity:
		size_type size() const;
		size_type max_size() const;
		void resize(size_type sz, T c = T()); size_type capacity() const;
		bool empty()const;
		void reserve(size_typen);
		
		// element access:
		reference operator[](size_typen); const_reference operator[](size_type n) const; const_reference at(size_type n) const; reference at(size_typen);
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		
		// 23.2.4.3 modifiers:
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x); template <class InputIterator>
        void insert(iterator position,
                        InputIterator first, InputIterator last);
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);
        void     swap(vector<T,Allocator>&);
        void     clear();           
		*/
		};
}
