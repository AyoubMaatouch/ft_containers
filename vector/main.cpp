#include "vector.hpp"
#include <vector>


int		main(void)
{
	const int size = 5;
    std::vector<int> vct(size);
    std::vector<int>::iterator it_ = vct.begin();
    std::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	// printSize(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}
