#include "node.hpp"
#include "map.hpp"
#include <map>
#include <vector>
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

    // std::vector<int> here (10, 10);
    // std::map<int ,char> mmap;
    //  mmap.insert (std::make_pair (1,'a'));
    //  mmap.insert (std::make_pair (2,'b'));
    //  mmap.insert (std::make_pair (3,'c'));
    //  mmap.insert (std::make_pair (4,'d'));
    //  mmap.insert (std::make_pair (5,'f'));
    //  mmap.insert (std::make_pair (6,'e'));
    //  mmap.insert (std::make_pair (7,'j'));
    //  mmap.insert (std::make_pair (8,'k'));
    ft::map<int, char> mymap;
    
    // mymap.insert(a);
    ft::map<int, char>::iterator it = mymap.begin();
    ft::map<int, char>::iterator en = mymap.end();
    
    for (; it != en; it++)
        std::cout << it->first << std::endl;
    it--;
    // en--;
    // std::cout << it->first << std::endl;
    // std::cout << it->first << std::endl;

    // std::cout << *(it) << std::endl;
    // ++it;
    // std::cout << *(it) << std::endl;
    // ++it;
    // std::cout << *(it) << std::endl;
    // it++;
    // ++it;
    // // it++;
    // // it++;
    // // it++;
    // std::cout << *(it) << std::endl;
    // it--;
    // // it--;
    // std::cout << *(it) << std::endl;

    // std::map<int, int > mymap(here.begin(), here.end());

    // for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //     std::cout << it->first << " => " << it->second << '\n';

    // ft::pair <int,char> b = ft::make_pair (2,'b');
    // ft::pair <int,char> c = ft::make_pair (3,'c');
    // ft::pair <int,char> d = ft::make_pair (4,'d');
    // ft::pair <int,char> f = ft::make_pair (5,'f');
    // ft::pair <int,char> e = ft::make_pair (6,'e');
    // ft::pair <int,char> j = ft::make_pair (7,'j');
    // ft::pair <int,char> k = ft::make_pair (8,'k');
    
    // AVLTree<ft::pair <int,char>, ft::less<int> , std::allocator<ft::pair<int, char> > > tree ;
    // tree.root = tree.insertNode(tree.root,NULL ,a);
    // tree.root = tree.insertNode(tree.root,NULL ,b);
    // tree.root = tree.insertNode(tree.root,NULL ,c);
    // tree.root = tree.insertNode(tree.root,NULL ,d);
    // tree.root = tree.insertNode(tree.root,NULL ,e);
    // tree.root = tree.insertNode(tree.root,NULL ,j);
    // tree.root = tree.insertNode(tree.root,NULL ,k);
    // Node<ft::pair <int,char> ,std::allocator<ft::pair<int, char> > > *root = NULL;
    // root = tree.inorder_Pre(root);
    // std::cout << root->item<< std::endl;
    // root = tree.inorder_Pre(root);
    // std::cout << root->item<< std::endl;
    // root = tree.inorder_Sec(root);
    // std::cout << root->item<< std::endl;
    // root = tree.inorder_Sec(root);
    // std::cout << root->item<< std::endl;
    // root = tree.inorder_Sec(root);
    // std::cout << root->item<< std::endl;
    // tree.printpreorder(tree.root);



} 