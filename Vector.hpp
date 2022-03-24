#pragma once
#include <memory>

#include "iterators.hpp"
#include "enable_if.hpp"
#include "is_intergal.hpp"


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
			allocator_type	_allocater;
			size_type 		_size;
			size_type		_capacity;

		// construct/copy/destroy:
		public:
		explicit vector(const Allocator& alloc = Allocator()): _buffer(), _size(), _capacity()
		{
			_allocater = alloc;
		}
		explicit vector(size_type n, const T& value = T(),
            const Allocator& alloc = Allocator()): _allocater(alloc), _size(n), _capacity(n)
			{
				_buffer = _allocater.allocate(n);
				for (size_type i = 0; i < n ; i++)
					_allocater.construct((_buffer + i), value);
			}
        template <class InputIterator>
          vector(InputIterator first, InputIterator last,
            const Allocator& alloc = Allocator(), typename enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{

			}



	

/***
        vector(const vector<T,Allocator>& x);

       ~vector();
        vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
        template <class InputIterator>
          void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const T& u);
        allocator_type get_allocator() const;
	***//


		// iterators:
		iterator begin(){ return iterator(_buffer); }
		const_iterator begin() const { return iterator(_buffer); }
		iterator end() { return iterator((_buffer  + (_size ))); }
		const_iterator end() const (){ return iterator((_buffer  + (_size ))); }
		reverse_iterator rbegin() { return reverse_iterator( end() )} 
		const_reverse_iterator rbegin() const { return reverse_iterator( end() )}
		reverse_iterator rend() { return reverse_iterator( begin())} 
		const_reverse_iterator rend() const { return reverse_iterator( begin())} 
	/***

		// capacity:
		***/
		size_type size() const { return _size;}
		size_type max_size() const { return _allocater.max_size(); }
		bool empty()const ( return static_cast<bool>(_size); )
/***	
		void resize(size_type sz, T c = T()); size_type capacity() const;
		void reserve(size_type n);
		
	***/
		// element access:
		reference operator[](size_type n) { return *(begin() + n); }
		const_reference operator[](size_type n) { const return *(begin() + n); } 
		const_reference at(size_type n) const; 
		reference at(size_type n);
		reference front() {return *begin();}
		const_reference front() const {return *begin();}
		reference back() {return *(end() - 1);}
		const_reference back() const {return *(end() - 1);}
		/***
		// modifiers:
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
