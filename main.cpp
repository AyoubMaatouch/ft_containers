#include "vector.hpp"
#include "iterators.hpp"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
int main()
{
  
    // allocator for integer values
    // allocator<int> myAllocator;
  
    // allocate space for five ints
    // ::ft::vector<int*> here(5, 100);
    ft::vector<int> hego(100, 10);
    ft::vector<int>::iterator it = hego.begin();
    std::cout << (*it) << std::endl;
    it++;
    std::cout << (*it) << std::endl;
    
    
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