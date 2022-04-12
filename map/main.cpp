#include "node.hpp"
#include <map>

int main() {
     ft::pair <int,char> foo = ft::make_pair (10,'b');
     ft::pair <int,char> bar = ft::make_pair (12,'B');
     ft::pair <int,char> xo = ft::make_pair (12,'A');
    
    AVLTree<ft::pair <int,char> > tree ;
    // std::map<int,char> x;
    // x.insert(foo);
    // x.insert(bar);
    // x.insert(xo);

    std::map<int,char>::iterator it;

    // for (it=x.begin(); it!=x.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';
  // first insert function version (single parameter):

    tree.root = tree.insertNode(tree.root, foo);
    tree.root = tree.insertNode(tree.root, bar);
    tree.root = tree.insertNode(tree.root, xo);
    // tree.root = tree.insertNode(tree.root, 9);
    // tree.root = tree.insertNode(tree.root, 21);
    // tree.root = tree.insertNode(tree.root, 61);
    // tree.root = tree.insertNode(tree.root, 8);
    // tree.root = tree.insertNode(tree.root, 11);
    tree.printTree(tree.root, "", true);
}