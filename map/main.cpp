#include "node.hpp"
#include <map>
#include <memory>
#include <utility>
#include <iostream>

// int main()
// {
//   int *x = NULL;
//   int *y =  new int(10);

//   std::cout << (x ? *x : 0) << " "<<*y <<std::endl;
// }

int main() {

    ft::pair <int,char> a = ft::make_pair (1,'a');
    ft::pair <int,char> b = ft::make_pair (2,'b');
    ft::pair <int,char> c = ft::make_pair (3,'c');
    ft::pair <int,char> d = ft::make_pair (4,'d');
    ft::pair <int,char> f = ft::make_pair (5,'f');
    ft::pair <int,char> e = ft::make_pair (6,'e');
    ft::pair <int,char> j = ft::make_pair (7,'j');
    ft::pair <int,char> k = ft::make_pair (8,'k');
    
    AVLTree<ft::pair <int,char>, ft::less<int> , std::allocator<ft::pair<int, char> > > tree ;
    tree.root = tree.insertNode(tree.root,NULL ,a);
    tree.root = tree.insertNode(tree.root,NULL ,b);
    tree.root = tree.insertNode(tree.root,NULL ,c);
    tree.root = tree.insertNode(tree.root,NULL ,d);
    tree.root = tree.insertNode(tree.root,NULL ,e);
    tree.root = tree.insertNode(tree.root,NULL ,j);
    tree.root = tree.insertNode(tree.root,NULL ,k);
    

    tree.printpreorder(tree.root);



} 