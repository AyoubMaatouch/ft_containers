
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
Iterator<T> operator+( size_t n, Iterator<T> it) { Iterator<T> tmp = it; return tmp + n; }

