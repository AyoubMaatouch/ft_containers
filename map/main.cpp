#include "node.hpp"
#include "Map.hpp"
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
    ft::map<int ,char> mmap;
    // ft::map<int, char> mymap;
     mmap.insert (ft::make_pair (1,'a'));
     mmap.insert (ft::make_pair (2,'b'));
     mmap.insert (ft::make_pair (3,'c'));
     mmap.insert (ft::make_pair (4,'d'));
     mmap.insert (ft::make_pair (5,'f'));
     mmap.insert (ft::make_pair (6,'e'));
     mmap.insert (ft::make_pair (7,'j'));
    ft::map<int, char>::iterator it = mmap.begin();
    // it++;
    // ++it;
     mmap.insert (ft::make_pair (8,'k'));

    
    // mymap.insert(a);
    ft::map<int, char>::iterator en = mmap.end();
    
    for (; en != it; it++)
        std::cout << it->first << std::endl;
    // std::cout << en->first << std::endl;

    //  std::cout << (*en) << std::endl;
    // std::cout << (*en) << std::endl;
    // en++;
    // std::cout << en->first << std::endl;
    // it--;
    // en--;
    // std::cout << it->first << " + "<<it->second<<std::endl;
} 