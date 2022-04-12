#include "node.hpp"
#include <map>
#include <memory>
#include <utility>
#include <iostream>


int main() {

    //  std::allocator<std::pair<const int, int> > alloc;
    //  std::pair <const int,int> *foo = alloc.allocate(sizeof(std::pair<const int, int>));
    //  const int x = 10;
    //  int i = 9;
    //  alloc.construct(foo, std::make_pair(x,i));;
     
    // std::cout << foo->first <<std::endl;
     ft::pair <int,char> bar = ft::make_pair (12,'B');
     ft::pair <int,char> xo = ft::make_pair (12,'A');
    
    AVLTree<ft::pair <int,char>, ft::less<int> > tree ;
    // std::map<int,char> x;
    // x.insert(foo);
    // x.insert(bar);
    // x.insert(xo);

    // std::map<int,char>::iterator it;

    // for (it=x.begin(); it!=x.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
  // first insert function version (single parameter):

    // tree.root = tree.insertNode(tree.root, foo);
    tree.root = tree.insertNode(tree.root, bar);
    tree.root = tree.insertNode(tree.root, xo);
    // tree.root = tree.insertNode(tree.root, 9);
    // tree.root = tree.insertNode(tree.root, 21);
    // tree.root = tree.insertNode(tree.root, 61);
    // tree.root = tree.insertNode(tree.root, 8);
    // tree.root = tree.insertNode(tree.root, 11);
    tree.printTree(tree.root, "", true);
}