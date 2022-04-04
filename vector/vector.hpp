#pragma once
#include <memory>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include "iterators.hpp"
#include "enable_if.hpp"
#include "is_intergal.hpp"

/***
 * TO-doo
 * adding try catch to copy and copy-backwords and allocater
 * fix fsanitize problem
 ***/

namespace ft
{
#include "tools.hpp"

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t diffrence_type;
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ::ft::Iterator<T> iterator;
		typedef ::ft::Iterator<const T> const_iterator;
		typedef ::ft::reverse_iterator<iterator> reverse_iterator;
		typedef ::ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		pointer _buffer;
		allocator_type _allocater;
		size_type _size;
		size_type _capacity;

		// construct/copy/destroy:
	public:
		explicit vector(const Allocator &alloc = Allocator()) : _buffer(nullptr), _size(0), _capacity(0), _allocater(alloc) {}
		explicit vector(size_type n, const T &value = T(),
						const Allocator &alloc = Allocator()) : _buffer(nullptr), _allocater(alloc), _size(n), _capacity(n)
		{
			_buffer = _allocater.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocater.construct((_buffer + i), value);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
			   const Allocator &alloc = Allocator(), typename enable_if<!is_integral<InputIterator>::value, bool>::type = false) : _buffer(nullptr), _allocater(alloc), _size(0), _capacity(0)
		{
			typedef typename iterator_traits<InputIterator>::iterator_category category;
			if (typeid(category()) != typeid(std::random_access_iterator_tag()) && typeid(category()) != typeid(std::bidirectional_iterator_tag()) && typeid(category()) != typeid(std::forward_iterator_tag()))
			{
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			else
			{
				_size = _capacity = std::distance(first, last);
				_buffer = _allocater.allocate(_capacity);
				std::copy(first, last, begin());
			}
		}
		~vector()
		{
			if (_buffer)
			{
				while (_size)
					pop_back();
				_allocater.deallocate(_buffer, _capacity);
			}
		}
		vector(const vector<T, Allocator> &x) : _buffer(),_capacity(0), _size(0), _allocater(x._allocater)
		{
			*this = x;
		}

		vector<T, Allocator> &operator=(const vector<T, Allocator> &x)
		{
			_allocater = x.get_allocator();
			reserve(x.capacity());
			_size = x.size();
			if (_size > 0)
				std::copy(x.begin(), x.end(), begin());
			return (*this);
		}
		void assign(size_type n, const T &u)
		{

			if (n < _capacity)
			{
				clear();
				_size = n;
				std::fill(begin(), end(), u);
			}
			else
			{
				this->~vector();
				_buffer = _allocater.allocate(n);
				_size = _capacity = n;
				std::fill(begin(), end(), u);
			}
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			_size = 0;
			typedef typename iterator_traits<InputIterator>::iterator_category category;
			if (typeid(category()) != typeid(std::random_access_iterator_tag()) && typeid(category()) != typeid(std::bidirectional_iterator_tag()) && typeid(category()) != typeid(std::forward_iterator_tag())) 
			{

				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			else
			{
				diffrence_type n = std::distance(first, last);
				if (n < _capacity)
				{
					clear();
					_size = n;
					std::copy(first, last, begin());
				}
				else
				{
					this->~vector();
					_buffer = _allocater.allocate(n);
					_size = _capacity = n;
					std::copy(first, last, begin());
				}
			}
		}

		allocator_type get_allocator() const { return _allocater; }

		// iterators:
		iterator begin() { return iterator(_buffer); }
		const_iterator begin() const { return const_iterator(_buffer); }
		iterator end() { return iterator((_buffer + (_size))); }
		const_iterator end() const { return const_iterator((_buffer + (_size))); }
		
		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/***
			// capacity:
			***/
		size_type size() const { return _size; }
		size_type max_size() const { return _allocater.max_size(); }
		bool empty() const { return !(size() > 0); }
		void reserve(size_type n)
		{
			if (n > max_size())
				throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
			if (n > _capacity)
			{
				pointer _temp = _allocater.allocate(n);
				size_type _tmp = _size;
				if (_size > 0)
				{
					for (size_type i = 0; i < _size; i++)
						_allocater.construct((_temp + i), *(begin() + i));
					this->~vector();
				}
				_capacity = n;
				_buffer = _temp;
				_size = _tmp;
			}
		}
		size_type capacity() const { return _capacity; }

		void resize(size_type sz, T c = T())
		{
			if (sz > _capacity)
			{
				(_capacity * 2) >= sz ? reserve(_capacity * 2) : reserve(sz);

				for (; _size < sz; _size++)
					_allocater.construct(_buffer + _size, c);
			}
			else
			{
				if (sz > _size)
				{
					for (; _size < sz; _size++)
						_allocater.construct(_buffer + _size, c);
				}
				else
					while (sz < _size)
						pop_back();
			}
		}

		/***

			***/
		// element access:
		reference operator[](size_type n) { return *(begin() + n); }
		const_reference operator[](size_type n) const { return *(begin() + n); }
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return _buffer[n];
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector");
			return _buffer[n];
		}
		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }
		reference back() { return *(end() - 1); }
		const_reference back() const { return *(end() - 1); }

		// modifiers:

		void push_back(const value_type &val)
		{
			resize(size() + 1, val);
		}
		void pop_back()
		{
			if (_size)
			{
				try
				{
					/* code */
					_allocater.destroy(&_buffer[_size]);
					_size--;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				
			}
		}
		iterator insert(iterator position, const T &x)
		{
			diffrence_type dis = position > end() ? -1 : std::distance(begin(), position);
			if (_size == _capacity)
			{
				(!_capacity) ? reserve(1) : reserve(_capacity * 2);
			}

			std::copy_backward(begin() + (dis), end(), end() + 1);
			*(begin() + dis) = x;
			++_size;
			return begin() + (dis);
		}
		void insert(iterator position, size_type n, const T &x)
		{
			diffrence_type dis = position > end() ? -1 : std::distance(begin(), position);
			if ((_size + n) > _capacity)
			{
				(_capacity + n) < _capacity * 2 ? reserve(_capacity * 2) : reserve(_capacity + n);
			}
			std::copy_backward(begin() + (dis), end(), end() + n);

			std::fill(begin() + (dis), (begin() + dis) + n, x);
			_size += n;
		}
		template <class InputIterator>
		void insert(iterator position,
					InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)
		{
				diffrence_type dis = position > end() ? -1 : std::distance(begin(), position);
				diffrence_type len = std::distance(first, last);

				if (len > 0)
				{
					if ((_size + len) > _capacity)
					{
						(_capacity + len) < _capacity * 2 ? reserve(_capacity * 2) : reserve(_capacity + len);
					}
					std::copy_backward(begin() + (dis), end(), end() + len);
					std::copy(first, last, begin() + dis);
					_size += len;
				}
		}
		iterator erase(iterator position)
		{
			diffrence_type dis = std::distance(begin(), position);
			_allocater.destroy((_buffer + dis));
			std::copy(begin() + (dis + 1), end(), begin() + dis);
			--_size;
			return begin() + dis;
		}
		iterator erase(iterator first, iterator last)
		{
			diffrence_type dis = std::distance(begin(), first);
			diffrence_type len = std::distance(first, last);
			for (diffrence_type n = 0; n < len; n++)
				_allocater.destroy((_buffer + (dis + n)));
			std::copy(begin() + (dis + 1), end(), begin() + dis);
			_size -= len;
			return begin() + dis;
		}
		void swap(vector<T, Allocator> &x)
		{
			std::swap(_buffer, x._buffer);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_allocater, x._allocater);
		}
		/***
		 */
		void clear()
		{
			while (size())
				pop_back();
		}
		// void clear()
		// {
		// 	while (_size--)
		// 		_allocater.destroy((_buffer + _size));
		// }
	};

	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class T, class Allocator>
	bool operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return !(x == y);
	}

	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return x == y || x < y;
	}

	template <class T, class Allocator>
	bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
	}

	template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y)
	{
		return x == y || x > y;
	}

	/**specialized algorithms:***/
	template <class T, class Allocator>
	void swap(vector<T, Allocator> &x, vector<T, Allocator> &y)
	{
		x.swap(y);
	}
}
