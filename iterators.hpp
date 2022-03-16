#pragma once

namespace ft
{
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>

	template <class Category, class T, class Distance = ptrdiff_t,
			  class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class T>
	class Iterator : public iterator<typename iterator_traits<T>::iterator_category,
									 typename iterator_traits<T>::value_type,
									 typename iterator_traits<T>::difference_type,
									 typename iterator_traits<T>::pointer,
									 typename iterator_traits<T>::reference>
	{
	public:
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::difference_type difference_type; // ptrdiff_t is sigend and size_t not
		typedef typename ft::iterator_traits<T>::reference reference;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;

		Iterator() : _ptrBase() {}

		Iterator(pointer p)
		{
			_ptrBase = p;
		}
		
		pointer base() const { return _ptrBase; }

		Iterator(Iterator const &src)
		{
			_ptrBase = src._ptrBase;
		}
		// operator overLoad
		Iterator &operator=(Iterator const &src)
		{
			_ptrBase = src._ptrBase;
			return (*this);
		}
		// pre
		Iterator &operator++(void)
		{
			this->_ptrBase++;
			return (*this);
		}
		Iterator &operator--(void)
		{
			this->_ptrBase--;
			return (*this);
		}

		Iterator operator++(int)
		{
			Iterator tmp(*this);
			this->_ptrBase++;
			return tmp;
		}
		Iterator &operator--(int)
		{
			Iterator tmp(*this);
			this->_ptrBase--;
			return tmp;
		}
		Iterator operator+(difference_type index)
		{
			return (Iterator(_ptrBase + index));
		}
		void operator+=(difference_type index)
		{
			this->_ptrBase + index;
		}
		void operator-=(difference_type index)
		{
			this->_ptrBase - index;
		}
		Iterator operator-(difference_type index)
		{
			return (Iterator(_ptrBase - index));
		}

		Iterator operator-(Iterator const &sr)
		{
			return (Iterator(this->_ptrBase - sr._ptrBase));
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
	bool operator==(Iterator<T> const &src)
	{
		return ((this->_ptrBase) == src._ptrBase);
	}
	template <class T>
	bool operator!=(Iterator<T> const &src)
	{
		return ((this->_ptrBase) != src._ptrBase);
	}
	template <class T>
	bool operator>(Iterator<T> const &src)
	{
		return ((this->_ptrBase) > src._ptrBase);
	}
	template <class T>
	bool operator<(Iterator<T> const &src)
	{
		return ((this->_ptrBase) < src._ptrBase);
	}
	template <class T>
	bool operator<=(Iterator<T> const &src)
	{
		return ((this->_ptrBase) <= src._ptrBase);
	}
	template <class T>
	bool operator>=(Iterator<T> const &src)
	{
		return ((this->_ptrBase) >= src._ptrBase);
	}
	template <class T>
	Iterator<T> operator+(ptrdiff_t index, Iterator<T> sr)
	{
		return (Iterator<T>(sr._ptrBase + index));
	}

	/**************************************************[Revere iterators]******************************************************/
	template <class Iterator>
	class reverse_iterator : public iterator<typename ft::iterator_traits<Iterator>::iterator_category,
											 typename ft::iterator_traits<Iterator>::value_type,
											 typename ft::iterator_traits<Iterator>::difference_type,
											 typename ft::iterator_traits<Iterator>::pointer,
											 typename ft::iterator_traits<Iterator>::reference>
	{
	protected:
		Iterator current;

	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::reference reference;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		reverse_iterator() : current() {}
		explicit reverse_iterator(Iterator x) { current = x; }

		template <class U>
		reverse_iterator(const reverse_iterator<U> &u) { current = u.current; }
		// explicit
		Iterator base() const { return current; }
		reference operator*() const
		{
			Iterator tmp = current;
			return *--tmp;
		}
		pointer operator->() const { return &(operator*()); }

		reverse_iterator &operator++()
		{
			--current;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}

		reverse_iterator &operator--()
		{
			++current;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++current;
			return tmp
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(current - n));
		}

		reverse_iterator &operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return current[n - 1];
		}
	};
	template <class Iterator>
	bool operator==(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current == y.current;
	}
	template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current > y.current;
	}
	template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current != y.current;
	}
	template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current < y.current;
	}
	template <class Iterator>
	bool operator>=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current <= y.current;
	}
	template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.current >= y.current;
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return y.current - x.current;
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &x)
	{
		return reverse_iterator<Iterator>(x.current - n);
	}
}