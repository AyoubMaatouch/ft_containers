// #include "vector.hpp"
// #include "iterators.hpp"
#include <iostream>
// #include <memory>
// #include <vector>
// using namespace std;
#include "is_intergal.hpp"

    int main() {
    std::cout << std::boolalpha;
    std::cout << "is_integral:" << std::endl;
    std::cout << "char: " << (bool)is_integral<char>::value << std::endl;
    std::cout << "int: " << (bool)is_integral<int>::value << std::endl;
    std::cout << "float: " << is_integral<float>::value << std::endl;
 
    // allocator for integer values
    // allocator<int> myAllocator;
  
    // allocate space for five ints
    // ::ft::vector<int*> here(5, 100);
    // std::vector<int> hego(10, 10);
    // std::vector<int>::iterator it = hego.begin();
    // std::vector<int>::iterator en = hego.end();
    
    // for (; it != en; it++)
    //     std::cout << &it <<" - "<<(*it) << std::endl;
    
    
    // int* arr = myAllocator.allocate(5);
  
    // // construct arr[0] and arr[3]
    // for (int i = 0 ; i < 4; i++)
    //     myAllocator.construct(arr + i, 100);

  
    // cout << arr[3] << endl;
    // cout << arr[4] << endl;
    // cout << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;
  
    // deallocate space for five ints
    // myAllocator.deallocate(arr, 5);
  
    return 0;
}