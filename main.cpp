#include "vector.hpp"
// #include "iterators.hpp"
#include <iostream>
// #include <memory>
#include <vector>
// using namespace std;
// #include "is_intergal.hpp"

    int main() 
    {
        ft::vector<int> vec(150, 15);
        std::cout << vec.capacity() <<"-" << vec.size()<<std::endl;
        std::cout << &(*vec.begin())<<std::endl;
        ft::vector<int> _vec(vec.begin(), vec.begin() + 19);
        std::cout << _vec.capacity() <<"-" << _vec.size()<<std::endl;
        std::cout << &(*_vec.begin())<<std::endl;
    
        // ft::vector<int> hego(170, 20);
        // std::cout << &(*hego.begin())<<std::endl;
        // std::cout << hego.capacity()<<"-" <<hego.size() <<std::endl;
        // hego = vec;
        // std::cout << &(*hego.begin())<<std::endl;
        // std::cout << hego.capacity()<<"-" <<hego.size() <<std::endl;

        

    

   return 0;
}