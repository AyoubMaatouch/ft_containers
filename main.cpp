#include "vector.hpp"
// #include "iterators.hpp"
#include <iostream>
// #include <memory>
#include <vector>
// using namespace std;
#include "is_intergal.hpp"

    int main() 
    {
        std::vector<int> vec(5, 15);
        // ft::vector<int> _vec(5, 15);
    
        std::cout << vec.capacity()<<std::endl;
        vec.resize(14, 20);
        
        std::cout << vec.capacity() <<std::endl;

        

    

   return 0;
}