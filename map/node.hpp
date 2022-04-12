// TO_DO 
/***
 * replace new with allocate
 * and replace comparision with alloc
 * 
 * */
#pragma once
#include <iostream> 
#include "pair.hpp"
// Create node
template <class T>
struct Node {
 
  T item; 
  int height;
  Node<T>* left;
  Node<T>* right;

  Node(T d) {
    item = d;
    height = 1;
    left = NULL;
    right = NULL;
  }

  Node() {
    item = 0;
    height = 0;
    left = NULL;
    right = NULL;
  }
};

// Tree class
template <class T, class Compare> // class Alloc
struct AVLTree {
  typedef Compare comp;
  typedef T value_type;
  typedef typename value_type::first_type key_type;
	typedef typename value_type::second_type mapped_type;
	// typedef std::allocator<ft::pair<const key_type, mapped_type> > Alloc;
	// typedef typename Alloc::template rebind<Node>::other  alloc_type;
	// alloc_type alloc;
  
  Node<value_type>* root;
 
  AVLTree()
  {
    root = NULL;
  } 
  int height(Node<value_type>* N) {
    if (N == NULL)
      return 0;
    return N->height;
  }

  int max(int a, int b) {
    return (a > b) ? a : b;
  }

  Node<value_type>* rightRotate(Node<value_type>* y) {
    Node<value_type>* x =  y->left;
    Node<value_type>* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
  }

  Node<value_type>* leftRotate(Node<value_type>* x) {
    Node<value_type>* y = x->right;
    Node<value_type>* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
  }

  // Get balance factor of a node
  int getBalanceFactor(Node<value_type>* N) {
    if (N == NULL)
      return 0;
    return height(N->left) - height(N->right);
  }


  Node<value_type>* insertNode(Node<value_type>* node, T item) {

    // Find the position and insert the node
    if (node == NULL)
      return (new Node<value_type>(item));
    // std::cout << << std::endl;
    if ((item < node->item))
      node->left = insertNode(node->left, item);
    else if (item > node->item)
      node->right = insertNode(node->right, item);
    else
      return node;

    // Update the balance factor of each node
    // And, balance the tree
    node->height = 1 + max(height(node->left), height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
      if (item < node->left->item) {
        return rightRotate(node);
      } else if (item > node->left->item) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
    }
    if (balanceFactor < -1) {
      if (item > node->right->item) {
        return leftRotate(node);
      } else if (item < node->right->item) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }
    }
    return node;
  }

  Node<value_type>* nodeWithMimumValue(Node<value_type>* node) {
    Node<value_type>* current = node;
    while (current->left != NULL)
      current = current->left;
    return current;
  }

  // Delete a node
  Node<value_type>* deleteNode(Node<value_type>* root, T item) {

    // Find the node to be deleted and remove it
    if (root == NULL)
      return new Node<value_type>();
    if (item < root->item)
      root->left = deleteNode(root->left, item);
    else if (item > root->item)
      root->right = deleteNode(root->right, item);
    else {
      if ((root->left == NULL) || (root->right == NULL)) {
        Node<value_type>* temp = NULL;
        if (temp == root->left)
          temp = root->right;
        else
          temp = root->left;
        if (temp == NULL) {
          temp = root;
          root = NULL;
        } else
          root = temp;
      } else {
        Node<value_type>* temp = nodeWithMimumValue(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item);
      }
    }
    if (root == NULL)
      return root;

    // Update the balance factor of each node and balance the tree
    root->height = max(height(root->left), height(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
      if (getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
      } else {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    }
    if (balanceFactor < -1) {
      if (getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
      } else {
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }
    }
    return root;
  }
  void preOrder(Node<value_type>* node) {
    if (node != NULL) {
      preOrder(node->right);
      preOrder(node->left);
    }
  }

  void printTree(Node<value_type>* currPtr, std::string indent, bool last) {
    if (currPtr != nullptr) {
      std::cout << indent ;
      if (last) {
      std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L---- ";
        indent += "|  ";
      }
      std::cout << (currPtr->item)<<std::endl;
      printTree(currPtr->left, indent, false);
      printTree(currPtr->right, indent, true);
    }
  }
};