#pragma once


namespace ft
{
#include "iterator_traits.hpp"

	template <class T>
	class Iterator 
	{
	public:
		typedef T	value_type;
    	typedef ptrdiff_t	difference_type;
    	typedef T*	pointer;
    	typedef T&	reference;
		typedef typename std::random_access_iterator_tag iterator_category;
		
		Iterator(void) : _ptrBase() {}	
		Iterator(pointer p)
		{
			_ptrBase = p;
		}
		
		template <class U>
		Iterator(const Iterator<U> &u) { _ptrBase = u.base(); }
		
		pointer base() const { return _ptrBase; }

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

		difference_type operator-(const Iterator  &sr)
		{
			return this->_ptrBase - sr._ptrBase;
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
	bool operator==(Iterator<T> const &y, Iterator<T> const &x)
	{
		return ((y._ptrBase) == x._ptrBase);
	}
	template <class T>
	bool operator!=(Iterator<T> const &y, Iterator<T> const &x)
	{
		return ((y.base()) != x.base());
	}
	template <class T>
	bool operator>(Iterator<T> const &y, Iterator<T> const &x)
	{
		return (y.base()) > x.base();
	}
	template <class T>
	bool operator<(Iterator<T> const &y, Iterator<T> const &x)
	{
		return (y.base()) < x.base();
	}
	template <class T>
	bool operator<=(Iterator<T> const &y, Iterator<T> const &x)
	{
		return ((y.base()) <= x.base());
	}
	template <class T>
	bool operator>=(Iterator<T> const &y, Iterator<T> const &x)
	{
		return ((y.base()) >= x.base());
	}
	template <class T>
	Iterator<T> operator+(ptrdiff_t index, Iterator<T> sr)
	{
		return (Iterator<T>(sr.base() + index));
	}

	/**************************************************[Revere iterators]******************************************************/
	template <class Iterator>
	class reverse_iterator 
	
	{

	public:
		typedef	Iterator	iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::pointer	pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
	private:
		iterator_type current;
	public:
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
			return tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(current - n));
		}

		reverse_iterator& operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(current + n);
		}

		reverse_iterator& operator-=(difference_type n)
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
		return x.base() == y.base();
	}
	template <class Iterator>
	bool operator<(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.base() > y.base();
	}
	template <class Iterator>
	bool operator!=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.base() != y.base();
	}
	template <class Iterator>
	bool operator>(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.base() < y.base();
	}
	template <class Iterator>
	bool operator>=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.base() <= y.base();
	}
	template <class Iterator>
	bool operator<=(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return x.base() >= y.base();
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &x,
		const reverse_iterator<Iterator> &y)
	{
		return y.base() - x.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &x)
	{
		return reverse_iterator<Iterator>(x.base() - n);
	}
}