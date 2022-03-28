#include "vector.hpp"
// #include "iterators.hpp"
#include <iostream>
// #include <memory>
#include <vector>
// using namespace std;
// #include "is_intergal.hpp"

    int main() 
    {
        ft::vector<int> v(10, 2);
        v.reserve(20);
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "size = " << v.size() << "\n";
        v.insert(v.end(), 11, 0);
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "size = " << v.size() << "\n";

}