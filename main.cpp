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
        ft::vector<int> hego(5, 99);
        v.reserve(20);
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "size = " << v.size() << "\n";
        v.insert(v.begin() -1 , hego.begin() ,hego.end());
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "size = " << v.size() << "\n";
        std::cout  << "Address = " << &(*v.begin()) << "\n";
         ft::vector <int>::iterator lkabi =  v.erase(v.begin() + 4, v.begin() + 10);
        for (int i = 0; v.begin() + i != v.end(); i++)
        {
            std::cout << *(v.begin() + i) << " ";
        }
         std::cout << std::endl;
         std::cout << *lkabi <<  std::endl;
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "size = " << v.size() << "\n";
        std::cout  << "Address = " << &(*v.begin()) << "\n";
}