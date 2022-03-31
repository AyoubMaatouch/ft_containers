#include "vector.hpp"
// #include "iterators.hpp"
#include <iostream>
// #include <memory>
#include <vector>
// using namespace std;
// #include "is_intergal.hpp"

    int main() 
    {
        // ft::vector<int> v;
        // ft::vector<int> hego(5, 99);
        // // v.reserve(20);
        // std::cout  << "capacity = " << v.capacity() << "\n";
        // std::cout  << "size = " << v.size() << "\n";
        // v.insert(v.begin() , 1);
        // v.insert(v.begin() , 2);
        // v.insert(v.begin() , 3);
        // std::cout  << "capacity = " << v.capacity() << "\n";
    {        std::string str, ft_str;
            std::vector<std::string> v(20, "string");
            ft::vector<std::string> ft_v(20, "string");

        std::cout  << "size = " << v.size() << "\n";
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "Address = " << &(*v.begin()) << "\n";

        std::cout  << "ft size = " << ft_v.size() << "\n";
        std::cout  << "ft capcity = " << ft_v.capacity() << "\n";
        std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
            v.insert(v.begin() + 10, 100, "hello");
            ft_v.insert(ft_v.begin() + 10, 100, "hello");
        std::cout  << "size = " << v.size() << "\n";
        std::cout  << "capacity = " << v.capacity() << "\n";
        std::cout  << "Address = " << &(*v.begin()) << "\n";

        std::cout  << "ft size = " << ft_v.size() << "\n";
        std::cout  << "ft capacity = " << ft_v.capacity() << "\n";
        std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
        //  ft::vector <int>::iterator lkabi =  v.erase(v.begin() + 4, v.begin() + 10);
        for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];

         std::cout << str<<  std::endl;
         std::cout << ft_str<<  std::endl;
         if (str == ft_str)
            std::cout<< "Wooorkssss" << std::endl;
    }
        // std::cout  << "capacity = " << v.capacity() << "\n";
        // std::cout  << "size = " << v.size() << "\n";
        // std::cout  << "Address = " << &(*v.begin()) << "\n";


            // str.clear();
            // ft_str.clear();
            // s = v.size();
            // ft_s = ft_v.size();
            // c = v.capacity();
            // ft_c = ft_v.capacity();
            // for (size_t i = 0; i < v.size(); ++i)
            //     str += v[i];
            // for (size_t i = 0; i < ft_v.size(); ++i)
            //     ft_str += ft_v[i];
            // cond = (cond && (str == ft_str) && (s == ft_s) && (c == ft_c));
}