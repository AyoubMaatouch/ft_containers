#pragma once


namespace ft
{
#include "iterator_traits.hpp"

template <class T>
class Iterator
{

public :
	typedef T	value_type;
    typedef ptrdiff_t	difference_type;
    typedef T*	pointer;
    typedef T&	reference;
	typedef typename std::random_access_iterator_tag iterator_category;

private:
	pointer ptr;

public:

	Iterator() : ptr() {}
	Iterator(pointer p) : ptr(p) {}
	template <typename S>
	Iterator(const Iterator<S> &it) : ptr(it.base()) {}
	template <typename S>
	Iterator &operator=(const Iterator<S> &it)
	{
		ptr = it.base();
		return *this;
	}
	template <typename S>
	Iterator operator=(const Iterator<S> &it) const
	{
		Iterator i(it);
		return i;
	}
	~Iterator() {}

	// Compare operator
	template <typename S>
	bool operator==(const Iterator<S> &it)
	{
		return (this->ptr == it.base());
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it)
	{
		return (this->ptr != it.base());
		
	}
	template <typename S>
	bool operator<(const Iterator<S> &it)
	{
		return (this->ptr < it.base());
	}
	template <typename S>
	bool operator>(const Iterator<S> &it)
	{
		return (this->ptr > it.base());
		
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it)
	{
		return (this->ptr >= it.base());
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it)
	{
		return (this->ptr <= it.base());
	}
	// // Overload Compare operators
	template <typename S>
	bool operator==(const Iterator<S> &it) const
	{
		return (this->ptr == it.base());
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it) const
	{
		return (this->ptr != it.base());
	}
	template <typename S>
	bool operator<(const Iterator<S> &it) const
	{
		return (this->ptr < it.base());
	}
	template <typename S>
	bool operator>(const Iterator<S> &it) const
	{
		return (this->ptr > it.base());
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it) const
	{
		return (this->ptr >= it.base());
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it) const
	{
		return (this->ptr <= it.base());
	}

	// Dereference
	reference operator*() { return *ptr; }
	reference operator*() const { return *ptr; }

	void operator*(T ptr_val) { *ptr = ptr_val; }
	pointer operator->() { return ptr; }
	pointer operator->() const { return ptr; } // Needs correction
	// increament operators post and pre
	Iterator &operator++()
	{
		ptr++;
		return *this;
	} // pre
	Iterator operator++(int)
	{
		Iterator tmp;
		tmp = *this;
		this->ptr++;
		return (tmp);
	}
	Iterator &operator--()
	{
		this->ptr--;
		return *this;
	}
	Iterator operator--(int)
	{
		Iterator tmp;
		tmp = *this;
		this->ptr--;
		return (tmp);
	} // post

	//arithmetic operation
	Iterator operator+(difference_type n)
	{
		Iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	const Iterator operator+(difference_type n) const
	{
		Iterator tmp = *this;
		tmp += n;
		return tmp;
	}
	Iterator operator-(difference_type n)
	{
		Iterator tmp = *this;
		tmp -= n;
		return tmp;
	}
	const Iterator operator-(difference_type n) const
	{
		Iterator tmp = *this;
		tmp -= n;
		return tmp;
	}
	template <typename S>
	difference_type operator-(const Iterator<S> &it)
	{
		return ptr - it.base();
	}

	Iterator &operator+=(difference_type n)
	{
		ptr += n;
		return (*this);
	}
	Iterator operator+=(difference_type n) const
	{
		Iterator iter = *this;
		iter += n;
		return (iter);
	}
	Iterator &operator-=(difference_type n)
	{
		ptr -= n;
		return (*this);
	}
	Iterator operator-=(difference_type n) const
	{
		Iterator iter = *this;
		iter -= n;
		return (iter);
	}
	reference operator[](difference_type n)
	{
		return ptr[n];
	}
	const T& operator[](difference_type n) const
	{
		return ptr[n];
	}

	const value_type*	base() const
	{
		return ptr;
	}
	value_type*	base()
	{
		return ptr;
	}
};
template<class T>
Iterator<T> operator+(int a,Iterator<T> it) { Iterator<T> tmp = it; return tmp + a; }

// template<typename T>
// Iterator<T>	operator+(ptrdiff_t n, const Iterator<T> &it)
// {
// 	return it + n;
// }

// template<typename T>
// Iterator<T>	operator-(ptrdiff_t n, const Iterator<T> &it)
// {
// 	return it - n;
// }
	/***
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
		Iterator(pointer p) : _ptrBase(p) 
		{
			// _ptrBase = p;
		}
		
		template <class U>
		Iterator(const Iterator<U> &u): _ptrBase(u.base()) { 
			// _ptrBase = u.base(); 
			}
		
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
		Iterator operator--(int)
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
			this->_ptrBase += index;
		}
		void operator-=(difference_type index)
		{
			this->_ptrBase -= index;
		}
		Iterator operator-(difference_type index)
		{
			return (Iterator(_ptrBase - index));
		}

		difference_type operator-(const Iterator  &sr)
		{
			return this->_ptrBase - sr._ptrBase;
		}
		reference operator[](difference_type index) const
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
	public:
		template <typename S>
	bool operator==(const Iterator<S> &it)
	{
		if (this->_ptrBase == it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it)
	{
		if (this->_ptrBase != it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<(const Iterator<S> &it)
	{
		if (this->_ptrBase < it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>(const Iterator<S> &it)
	{
		if (this->_ptrBase > it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it)
	{
		if (this->_ptrBase >= it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it)
	{
		if (this->_ptrBase <= it.base())
			return true;
		return false;
	}
	// // Overload Compare operators
	template <typename S>
	bool operator==(const Iterator<S> &it) const
	{
		if (this->_ptrBase == it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator!=(const Iterator<S> &it) const
	{
		if (this->_ptrBase != it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<(const Iterator<S> &it) const
	{
		if (this->_ptrBase < it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>(const Iterator<S> &it) const
	{
		if (this->_ptrBase > it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator>=(const Iterator<S> &it) const
	{
		if (this->_ptrBase >= it.base())
			return true;
		return false;
	}
	template <typename S>
	bool operator<=(const Iterator<S> &it) const
	{
		if (this->_ptrBase <= it.base())
			return true;
		return false;
	}

	};
***/
	// template <class T>
	// bool operator==(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return ((y.base()) == x.base());
	// }
	// template <class T>
	// bool operator!=(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return ((y.base()) != x.base());
	// }
	// template <class T>
	// bool operator>(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return (y.base()) > x.base();
	// }
	// template <class T>
	// bool operator<(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return (y.base()) < x.base();
	// }
	// template <class T>
	// bool operator<=(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return ((y.base()) <= x.base());
	// }
	// template <class T>
	// bool operator>=(Iterator<T> const &y, Iterator<T> const &x)
	// {
	// 	return ((y.base()) >= x.base());
	// }
	// template <class T>
	// Iterator<T> operator+(ptrdiff_t index, Iterator<T> sr)
	// {
	// 	return (Iterator<T>(sr.base() + index));
	// }

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
		 reverse_iterator(Iterator x ): current(x) {  }

		template <class U>
		reverse_iterator(const reverse_iterator<U> &u): current (u.base()) {  }
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
			reverse_iterator tmp(*this);
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
			reverse_iterator tmp (*this);
			++current;
			return tmp;
		}

  		reverse_iterator operator+(difference_type a) { return current - a; }
    	reverse_iterator operator-(difference_type a) { return current + a; }
		
		reverse_iterator& operator+=(difference_type n)
		{
			current -= n;
			return (*this);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}

		reference operator[](difference_type n)
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
  reverse_iterator<Iterator> operator+ (
             typename reverse_iterator<Iterator>::difference_type n,
             const reverse_iterator<Iterator>& rev_it)
{
	return reverse_iterator<Iterator> (rev_it.base() - n);
}
template <class Iterator>
  typename reverse_iterator<Iterator>::difference_type 
  operator-(
    const reverse_iterator<Iterator>& lhs,
    const reverse_iterator<Iterator>& rhs)
{
	return rhs.base() - lhs.base();
}
}