#include "node.hpp"
#include "Map.hpp"
#include <map>
#include <string>
#include "pair.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20
// #include <map>
// #include <vector>
// #include <memory>
// #include <utility>
// #include <iostream>
#include <sys/time.h>
#define MAX_RAM 42941
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))
// int main()
// {
//   int *x = NULL;
//   int *y =  new int(10);

//   std::cout << (x ? *x : 0) << " "<<*y <<std::endl;
// }
template <typename Iter1, typename Iter2>
bool comparemaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}
long get_time()
{
	struct timeval	time;
	long long		t;
	gettimeofday(&time, NULL);
	t = (time.tv_usec) + (time.tv_sec * 1000000);
	return t;
}
// time_t get_time(void)
// {
//     struct timeval time_now;

//     gettimeofday(&time_now, NULL);
//     time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
//     return (msecs_time);
// }

int main() {
  std::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  std::map<char,int>::iterator rit =  mymap.begin();
  std::map<char,int>::iterator eit =  mymap.end();
//   for (; rit!= eit; rit++)
    std::cout << eit->first << " => \n";
    eit--;
    std::cout << eit->first << " => \n";
    eit--;
    std::cout << eit->first << " => \n";
// std::cout << rit->first << " => " << rit->second << '\n';

  return 0;
//  ft::map<char,int> mymap;

//   mymap['x']=100;
//   mymap['y']=200;
//   mymap['z']=300;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   mymap.clear();
//   mymap['a']=1101;
//   mymap['b']=2202;

//   std::cout << "mymap contains:\n";
//   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
    
//   return 0;
      
} 