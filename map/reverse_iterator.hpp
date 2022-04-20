#pragma once
template <class Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::iterator_category iterator_category;
	};
template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T 	value_type;
		typedef T* 	pointer;
		typedef T& 	reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef const T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};
// template <class Iterator>
// class reverse_iterator

// {

// public:
//     typedef Iterator iterator_type;
//     typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
//     typedef typename iterator_traits<Iterator>::value_type value_type;
//     typedef typename iterator_traits<Iterator>::difference_type difference_type;
//     typedef typename iterator_traits<Iterator>::pointer pointer;
//     typedef typename iterator_traits<Iterator>::reference reference;

// private:
//     iterator_type current;

// public:
//     reverse_iterator() : current() {}
//     reverse_iterator(Iterator x) : current(x) {}

//     template <class U>
//     reverse_iterator(const reverse_iterator<U> &u) : current(u.base()) {}
//     // explicit
//     Iterator base() const { return current; }
//     reference operator*() const
//     {
//         Iterator tmp = current;
//         return *--tmp;
//     }
//     pointer operator->() const { return &(operator*()); }

//     reverse_iterator &operator++()
//     {
//         --current;
//         return (*this);
//     }

//     reverse_iterator operator++(int)
//     {
//         reverse_iterator tmp(*this);
//         --current;
//         return tmp;
//     }

//     reverse_iterator &operator--()
//     {
//         ++current;
//         return (*this);
//     }

//     reverse_iterator operator--(int)
//     {
//         reverse_iterator tmp(*this);
//         ++current;
//         return tmp;
//     }

//     reverse_iterator operator+(difference_type a) { return current - a; }
//     reverse_iterator operator-(difference_type a) { return current + a; }

//     reverse_iterator &operator+=(difference_type n)
//     {
//         current -= n;
//         return (*this);
//     }

//     reverse_iterator &operator-=(difference_type n)
//     {
//         current += n;
//         return (*this);
//     }

//     reference operator[](difference_type n)
//     {
//         return current[n - 1];
//     }
// };
// template <class Iterator>
// bool operator==(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() == y.base();
// }
// template <class Iterator>
// bool operator<(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() > y.base();
// }
// template <class Iterator>
// bool operator!=(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() != y.base();
// }
// template <class Iterator>
// bool operator>(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() < y.base();
// }
// template <class Iterator>
// bool operator>=(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() <= y.base();
// }
// template <class Iterator>
// bool operator<=(
//     const reverse_iterator<Iterator> &x,
//     const reverse_iterator<Iterator> &y)
// {
//     return x.base() >= y.base();
// }
// template <class Iterator>
// reverse_iterator<Iterator> operator+(
//     typename reverse_iterator<Iterator>::difference_type n,
//     const reverse_iterator<Iterator> &rev_it)
// {
//     return reverse_iterator<Iterator>(rev_it.base() - n);
// }
// template <class Iterator>
// typename reverse_iterator<Iterator>::difference_type
// operator-(
//     const reverse_iterator<Iterator> &lhs,
//     const reverse_iterator<Iterator> &rhs)
// {
//     return rhs.base() - lhs.base();
// }

template <class Iterator>
class reverse_iterator {
	public:
		// + + + + + + + + + Member type
		typedef Iterator													iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type			difference_type;
		typedef typename iterator_traits<Iterator>::value_type				value_type;
		typedef typename iterator_traits<Iterator>::pointer					pointer;
		typedef typename iterator_traits<Iterator>::reference				reference;
		typedef typename iterator_traits<Iterator>::iterator_category		iterator_category;
	private:
		Iterator iter;
	public:
		// + + + + + + + + + Member functions
		//default constuctor
		reverse_iterator(void) : iter() {}
		//copy constuctor
		explicit reverse_iterator(Iterator x) : iter(x) {}
		template <class Ty>
		reverse_iterator(const reverse_iterator<Ty> &it) : iter(it.base()) {}
		// base
		Iterator base(void) const
		{
			return iter;
		}
		// + + + + + + + + + Operator overload
		//operator=
		reverse_iterator& operator=(reverse_iterator const &it)
		{
			iter = it.base();
			return (*this);
		}
		//operator*
		reference operator*(void) const
		{
			Iterator tmp = iter;
			return *--tmp;
		}
		//operator->
		pointer operator->(void) const
		{
			return &(operator*());
		}
		//operator++ (pre)
		reverse_iterator& operator++(void)
		{
			--iter;
			return (*this);
		}
		//operator++ (post)
		reverse_iterator operator++(int)
		{
			reverse_iterator temp(*this);
			--iter;
			return (temp);
		}
		//operator-- (pre)
		reverse_iterator& operator--(void)
		{
			++iter;
			return (*this);
		}
		//operator-- (post)
		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			++iter;
			return (temp);
		}
		bool operator==(const reverse_iterator& it)
		{
			return (iter == it.iter);
		}
		bool operator!=(const reverse_iterator& it)
		{
			return (iter != it.iter);
		}
};