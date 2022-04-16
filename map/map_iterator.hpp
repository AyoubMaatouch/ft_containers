#include "node.hpp"

template <typename Node, typename value_type>
	class bd_iterator 
 {
	friend class AVLTree;
	public:
		// typedef NNode 								Node;
		typedef value_type& 					reference;
		typedef value_type* 					pointer;
		typedef ptrdiff_t 						difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
	private:
		// Node* __root;
		Node* _root;
		bool _last;
	public:
	bd_iterator() : _root() {}
	bd_iterator(Node* x)  : _root(x), _last(false) {}
	bd_iterator(Node* x, bool l)  : _root(x), _last(l) {}
	// explicit bd_iterator(Iterator x) : _root(x._root) {}

	// template <class U> bd_iterator(const bd_iterator<U>& u) _root(u._root) {}

	reference operator*() const  { 
		 if (_last)
		 {
			value_type *x;
		 	return *x;
		 }
		return  _root->item;
		}
	pointer operator->() const { return &(operator*());}
	bd_iterator& operator++()
	{
		
		Node *p;
    	if (_root->right != NULL)
    	  {
    	    _root = _root->right;
	
    	    while (_root->left != NULL) {
    	      _root = _root->left;
    	    }
    	  }
    	else
    	  {
    	    p = _root->parent;
    	    while (p != NULL && _root == p->right)
    	      {
    	        _root = p;
    	        p = p->parent;
    	      }
    	    _root = p;
    	  }
  		return *this;
	}
	bd_iterator operator++(int)
	{
		bd_iterator tmp(*this);
		operator++();
		return (tmp);
	}

	bd_iterator& operator--()
	{
	// Node *check = nodeWithMaxValue(_root);
	// if (_last) // for end()
	// {
	// 	bd_iterator *tmp;
	// 	std::cout << "hahaa" <<std::endl;
	// 	this->_last = false;
	// 	return *tmp;
	// }
	// else if ()
	//  if (_root == NULL)
    // {
    //   _root = this->_root->parent;
    // //   while (_root->right != NULL) {
    // //     _root = _root->right;
    // //   }
    // }
	// else
	{
	Node *p;

    if (_root->left != NULL)
      {
        _root = _root->left;
        
        while (_root->right != NULL) {
          _root = _root->right;
        }
      }
    else
      {
        p = _root->parent;
        while (p != NULL && _root == p->left)
          {
            _root = p;
            p = p->parent;
          }       
        _root = p;
      }
	}
  return *this;
  
  
	}

	bd_iterator operator--(int)
	{
		bd_iterator tmp (*this);
		operator--();
		return tmp;
	}

	// template <typename S>
	// bool operator==(const bd_iterator<S>& it) const
	// {
		// return (_root == it._root);
	// }
	template <typename S,typename V>
	bool operator!=(const bd_iterator<S, V>& it) const
	{
		return (_root != it._root);
	}
	// template <typename S>
	// bool operator>(const bd_iterator<S>& it) const
	// {
		// return (_root > it._root);
	// }
	// template <typename S>
	// bool operator<(const bd_iterator<S>& it) const
	// {
		// return (_root < it._root);
	// }
	// template <typename S>
	// bool operator<=(const bd_iterator<S>& it) const
	// {
		// return (_root <= it._root) ;
	// }
	// template <typename S>
	// bool operator>=(const bd_iterator<S>& it) const
	// {
		// return (_root >= it._root);
	// }
};