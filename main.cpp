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
        ft::vector<int> _vec(5, 15);
    
        std::cout << vec.capacity() <<  vec.size()<<std::endl;
        std::cout << _vec.capacity()<< _vec.size() <<std::endl;
        std::cout << &(*vec.begin())<<std::endl;
        std::cout << &(*_vec.begin()) <<std::endl;
        vec.resize(4, 20);
        _vec.resize(4, 20);
        std::vector<int> hego = vec;
        ft::vector<int> _hego = _vec;

        // std::cout << vec.capacity() <<  vec.size()<<std::endl;
        std::cout << &(*hego.begin())<<std::endl;
        std::cout << &(*_hego.begin())<<std::endl;
        std::cout << hego.capacity()<< hego.size() <<std::endl;
        // std::cout << _vec.capacity() << _vec.size()<<std::endl;
        std::cout << _hego.capacity()<< _hego.size() <<std::endl;
        // std::cout << &(*vec.begin())<<std::endl;
        // std::cout << &(*_vec.begin()) <<std::endl;

        

    

   return 0;
}