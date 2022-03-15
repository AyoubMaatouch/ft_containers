#include <vector>
#include <iostream>
#include "iterators.hpp"

int main()
{
    int *vec = new int(10) ;
    for (int i = 0; i < 10; i++)
        vec[i]= i + 10;

    ft::_Iterator<int*> be(vec);
    
    ft::_Iterator<int*> ne(be);
    std::vector<int> bg(10,50);
    std::vector<int>::iterator nb = bg.begin();
     std::cout << *nb << std::endl;

    // if (be == ne)
    //     std::cout << "the same as you\n"; 
    // std::cout << *(be) << std::endl;
    // be = be + 5;
    // std::cout << *(be) << std::endl;
    ft::_Iterator<int> ne = be;
    
    if (be <= ne)
        std::cout << "the same as you\n"; 
    std::cout << *(be) << std::endl;
    be = be + 5;
    ne = be - 3;
    
    std::cout << *(ne) << std::endl;
}