#pragma once

namespace ft
{
#include "iterator_traits.hpp"
#include <iostream>
#include <vector>

	template <class T>
	class _Iterator //: public iterBase<std::random_access_iterator_tag, T>
	{

	public:
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::difference_type difference_type; // ptrdiff_t is sigend and size_t not
		typedef typename ft::iterator_traits<T>::reference reference;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;

		_Iterator() : _ptrBase() {}

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
		_Iterator &operator=(_Iterator const &src)
		{
			_ptrBase = src._ptrBase;
			return (*this);
		}
		// pre
		_Iterator &operator++(void)
		{
			this->_ptrBase++;
			return (*this);
		}
		_Iterator &operator--(void)
		{
			this->_ptrBase--;
			return (*this);
		}

		// post
		_Iterator operator++(int)
		{
			_Iterator tmp(*this);
			this->_ptrBase++;
			return tmp;
		}
		_Iterator &operator--(int)
		{
			_Iterator tmp(*this);
			this->_ptrBase--;
			return tmp;
		}

		// Comparisions Operators : “==”, “!=”, “>”, “<”, “>=”,  “<=”

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
		bool operator<(_Iterator const &src)
		{
			return ((this->_ptrBase) < src._ptrBase);
		}
		bool operator<=(_Iterator const &src)
		{
			return ((this->_ptrBase) <= src._ptrBase);
		}
		bool operator>=(_Iterator const &src)
		{
			return ((this->_ptrBase) >= src._ptrBase);
		}

		// arithmetic operators (+, +=, -=, -, [])
		_Iterator operator+(difference_type index)
		{
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
			return (_Iterator(_ptrBase - index));
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

	// REVERSE ITERATOR
	template <class T>
	class _revIterator //: public iterBase<std::random_access_iterator_tag, T>
	{

	public:
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::difference_type difference_type; // ptrdiff_t is sigend and size_t not
		typedef typename ft::iterator_traits<T>::reference reference;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::iterator_category iterator_category;

		_revIterator() : _revptr() {}

		_revIterator(pointer p)
		{
			_revptr = p;
		}
		~_revIterator() {}

		_revIterator(_revIterator const &src)
		{
			_revptr = src._revptr;
		}

		// operator OverLoad
		_revIterator &operator=(_revIterator const &src)
		{
			_revptr = src._revptr;
			return (*this);
		}
		// pre
		_revIterator &operator--(void)
		{
			this->_revptr++;
			return (*this);
		}
		_revIterator &operator++(void)
		{
			this->_revptr--;
			return (*this);
		}

		// post
		_revIterator operator--(int)
		{
			_revIterator tmp(*this);
			this->_revptr++;
			return tmp;
		}
		_revIterator &operator++(int)
		{
			_revIterator tmp(*this);
			this->_revptr--;
			return tmp;
		}

		// Comparisions Operators : “==”, “!=”, “>”, “<”, “>=”,  “<=”

		bool operator==(_revIterator const &src)
		{
			return ((this->_revptr) == src._revptr);
		}
		bool operator!=(_revIterator const &src)
		{
			return ((this->_revptr) != src._revptr);
		}
		bool operator<(_revIterator const &src)
		{
			return ((this->_revptr) > src._revptr);
		}
		bool operator<(_revIterator const &src)
		{
			return ((this->_revptr) < src._revptr);
		}
		bool operator>=(_revIterator const &src)
		{
			return ((this->_revptr) <= src._revptr);
		}
		bool operator<=(_revIterator const &src)
		{
			return ((this->_revptr) >= src._revptr);
		}

		// arithmetic operators (+, +=, -=, -, [])
		_revIterator operator-(difference_type index)
		{
			return (_revIterator(_revptr + index));
		}
		void operator-=(difference_type index)
		{
			this->_revptr + index;
		}
		void operator+=(difference_type index)
		{
			this->_revptr - index;
		}
		_revIterator operator+(difference_type index)
		{
			return (_revIterator(_revptr - index));
		}

		_revIterator operator+(_revIterator const &sr)
		{
			return (_revIterator(this->_revptr - sr._revptr));
		}
		reference operator[](difference_type index)
		{
			return (this->_revptr[index]);
		}
		pointer operator->()
		{
			return ((this->_revptr));
		}
		reference operator*()
		{
			return (*(this->_revptr));
		}

	private:
		pointer _revptr;
	};
	template <class T>
	_Iterator<T> operator+(ptrdiff_t index, _revIterator<T> sr)
	{
		return (_Iterator<T>(sr._ptrBase - index));
	}
	
}