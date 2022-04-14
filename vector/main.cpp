#include "vector.hpp"
#include <vector>


int		main(void)
{
	ft::vector<int> myvec(10);
    ft::vector<const int> myvec1(10);
    ft::vector<int>::iterator it = myvec.begin();
    ft::vector<const int>::const_iterator it2 = myvec1.begin();

    if (it == it2)
        std::cout << "it == it2" << std::endl;
    else
        std::cout << "it != it2" << std::endl;


    std::cout << "Before" << std::endl;
    std::cout << "size of myvec: " << myvec.size() << std::endl;
    std::cout << "capacity of myvec: " << myvec.capacity() << std::endl;


    for (int i = 0; i < myvec.size(); i++)
    {
        std::cout << myvec[i] << std::endl;
    }

    myvec.push_back(3);
    std::cout << "After" << std::endl;
    std::cout << "size of myvec: " << myvec.size() << std::endl;
    std::cout << "capacity of myvec: " << myvec.capacity() << std::endl;
	// const int size = 5;
    // std::vector<int> vct(size);
    // std::vector<int>::iterator it_ = vct.begin();
    // std::vector<int>::reverse_iterator it(it_);

	// for (int i = 0; i < size; ++i)
	// 	vct[i] = (i + 1) * 5;
	// // printSize(vct);

	// std::cout << (it_ == it.base()) << std::endl;
	// std::cout << (it_ == (it + 3).base()) << std::endl;

	// std::cout << *(it.base() + 1) << std::endl;
	// std::cout << *(it - 3) << std::endl;
	// std::cout << *(it - 3).base() << std::endl;
	// it -= 3;
	// std::cout << *it.base() << std::endl;

	// std::cout << "TEST OFFSET" << std::endl;
	// std::cout << *(it) << std::endl;
	// std::cout << *(it).base() << std::endl;
	// std::cout << *(it - 0) << std::endl;
	// std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}
