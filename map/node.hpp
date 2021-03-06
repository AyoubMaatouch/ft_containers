/***
 * AVL tree sources :
 * https://www.programiz.com/dsa/avl-tree
 * https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
 * */
#pragma once
#include <iostream>
#include <memory>
#include "pair.hpp"
#define print(X) std::cout << X << std::endl;

//  node
template <class T, class Alloc>
struct Node
{
  T *item;
  int height;
  Node<T, Alloc> *left;
  Node<T, Alloc> *parent;
  Node<T, Alloc> *right;
  Alloc _allocator;

  Node(T d, Node *par, Alloc _alloc) : height(1), left(NULL), parent(par), right(NULL), _allocator(_alloc)
  {
    item = _alloc.allocate(sizeof(T));
    _alloc.construct(item, d);
  }

  Node() : height(0), left(NULL), parent(NULL), right(NULL) {}
  ~Node() {}
};

// Tree class
template <class T, class Compare, class Alloc> 
struct AVLTree
{
  typedef T value_type;
  typedef Compare comp;
  typedef typename value_type::first_type key_type;
  typedef typename value_type::second_type mapped_type;
  typedef Node<value_type, Alloc> Node;
  typedef typename Alloc::template rebind<Node>::other alloc_type;
  Node *root;
  comp _comp;
  size_t _size;
  alloc_type _allocater;
  alloc_type _reb;

  AVLTree()
  {
    root = NULL;
  }

  int height(Node *N)
  {
    if (N == NULL)
      return 0;
    return N->height;
  }

  int max(int a, int b)
  {
    return (a > b) ? a : b;
  }

  void parent_correction(Node *&n, Node *p)
  {
    if (!n)
      return;
    parent_correction(n->right, n);
    n->parent = p;
    parent_correction(n->left, n);
  }

  Node *rightRotate(Node *y)
  {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    parent_correction(y, x->parent);
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
  }

  Node *leftRotate(Node *x)
  {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    parent_correction(y, x->parent);
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
  }

  // Get balance factor of a node
  int getBalanceFactor(Node *N)
  {
    if (N == NULL)
      return 0;
    return height(N->left) - height(N->right);
  }


  Node *insertNode(Node *node, Node *parent, T item)
  {

    // return (new Node(item, parent));
    if (node == NULL)
    {
      node = _allocater.allocate(sizeof(Node));
      _allocater.construct(node, Node(item, parent, _reb));
      return node;
    }
    if (_comp(item.first, (node->item->first)))
      node->left = insertNode(node->left, node, item);
    else if (_comp(node->item->first, item.first)) //(item > (node->item))
      node->right = insertNode(node->right, node, item);
    else
      return node;

    // Update the balance factor of each node
    // And, balance the tree
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
      if (_comp(item.first, node->left->item->first)) //(item < (node->left->item))
      {
        return rightRotate(node);
      }
      else if (_comp(node->left->item->first, item.first)) //(item > (node->left->item))
      {
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
    }
    if (balanceFactor < -1)
    {
      if (_comp(node->right->item->first, item.first)) //(item > (node->right->item))
      {
        return leftRotate(node);
      }
      else if (_comp(item.first, node->right->item->first)) //(item < (node->right->item))
      {
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }
    }
    if (node->left)
      node->left->parent = node;
    if (node->right)
      node->right->parent = node;
    return node;
  }

  Node *nodeWithMimumValue(Node *node) const
  {
    if (node)
    {

      Node *current = node;
      while (current->left != NULL)
        current = current->left;
      return current;
    }
    return NULL;
  }
  Node *nodeWithMaxValue(Node *node) const
  {
    if (node)
    {
      Node *current = node;
      while (current->right != NULL)
        current = current->right;
      current->right = NULL;
      current->left = NULL;
      return current;
    }

    return NULL;
  }
  // search Node
  Node *searchNode(Node *root, key_type key) const
  {
    // print("still")
    
    if (!root)
      return NULL;
    if (root->item->first == key)
      return root;
  
    Node *right = (searchNode(root->right, key));
    if (right)
      return right;
    Node *left = searchNode(root->left, key);
      return left;
    return NULL;
  }
  Node *removeAll(Node *root)
  {

    if (!root)
      return NULL;
    removeAll(root->right);
    removeAll(root->left);
    if (root)
    {
      _allocater.destroy(root);
      _allocater.deallocate(root, sizeof(Node));
    }
    return NULL;
  }

  // Delete a node
  Node *deleteNode(Node *root, key_type item)
  {

    // Find the node to be deleted and remove it
    if (root == NULL)
      return NULL;
    if (_comp(item, (root->item)->first))
      root->left = deleteNode(root->left, item);
    else if (_comp((root->item)->first, item))
      root->right = deleteNode(root->right, item);
    else
    {
      if ((root->left == NULL) || (root->right == NULL))
      {
        Node *temp = NULL;
        if (temp == root->left)
          temp = root->right;
        else
          temp = root->left;
        if (temp == NULL)
        {
          temp = root;
          root = NULL;
        }
        else
        {
          _allocater.construct(root, *temp);
        }
      }
      else
      {
        Node *temp = nodeWithMimumValue(root->right);
        _allocater.construct(root->item, *temp->item);
        root->right = deleteNode(root->right, temp->item->first);
      }
    }
    if (root == NULL)
      return root;

    // Update the balance factor of each node and balance the tree
    root->height = max(height(root->left), height(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1)
    {
      if (getBalanceFactor(root->left) >= 0)
      {
        return rightRotate(root);
      }
      else
      {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    }
    if (balanceFactor < -1)
    {
      if (getBalanceFactor(root->right) <= 0)
      {
        return leftRotate(root);
      }
      else
      {
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }
    }
    if (root->left)
      root->left->parent = root;
    if (root->right)
      root->right->parent = root;
    return root;
  }

  void printTree(Node *currPtr, std::string indent, bool last)
  {
    if (currPtr != nullptr)
    {
      std::cout << indent;
      if (last)
      {
        std::cout << "R----";
        indent += "   ";
      }
      else
      {
        std::cout << "L---- ";
        indent += "|  ";
      }
      std::cout << *(currPtr->item) << std::endl;
      printTree(currPtr->left, indent, false);
      printTree(currPtr->right, indent, true);
    }
  }
  // void
  /*****************************************/
  Node *current_node() { return this->root; }
  /*****************************************/

  Node *inorder_Sec(Node *nodePtr)
  {
    Node *p;
    if (nodePtr == NULL)
    {
      nodePtr = this->root;

      while (nodePtr->left != NULL)
      {
        nodePtr = nodePtr->left;
      }
    }
    else
    {

      if (nodePtr->right != NULL)
      {
        nodePtr = nodePtr->right;

        while (nodePtr->left != NULL)
        {
          nodePtr = nodePtr->left;
        }
      }
      else
      {
        p = nodePtr->parent;
        while (p != NULL && nodePtr == p->right)
        {
          nodePtr = p;
          p = p->parent;
        }
        nodePtr = p;
      }
    }

    return nodePtr;
  }

  Node *inorder_Pre(Node *nodePtr)
  {
    Node *p;
    //  Node *
    if (nodePtr == NULL)
    {
      nodePtr = this->root;
      while (nodePtr->right != NULL)
      {
        nodePtr = nodePtr->right;
      }
    }
    else
    {

      if (nodePtr->left != NULL)
      {
        nodePtr = nodePtr->left;

        while (nodePtr->right != NULL)
        {
          nodePtr = nodePtr->right;
        }
      }
      else
      {
        p = nodePtr->parent;
        while (p != NULL && nodePtr == p->left)
        {
          nodePtr = p;
          p = p->parent;
        }
        nodePtr = p;
      }
    }

    return nodePtr;
  }
  /*****************************************/

  void printpreorder(Node *root)
  {
    // Print the node's value along
    // with its parent value
    std::cout << "Node: " << *(root->item)
              << ", Parent Node: ";

    if (root->parent != NULL)
      std::cout << *(root->parent->item) << std::endl;
    else
      std::cout << "NULL" << std::endl;

    // Recur to the left subtree
    if (root->left != NULL)
    {
      printpreorder(root->left);
    }

    // Recur to the right subtree
    if (root->right != NULL)
    {
      printpreorder(root->right);
    }
  }
};