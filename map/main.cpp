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
//     ft::map<char,std::string> mymap;

//   mymap['a']="an element";
//   mymap['b']="another element";
//   mymap['c']=mymap['b'];
//   mymap['d']=mymap['b'];

//   std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//   std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//   std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//   std::cout << "mymap['d'] is " << mymap['d'] << '\n';

//   std::cout << "mymap now contains " << mymap.size() << " elements.\n";
//     mymap.erase('b');
//     mymap.erase('a');
//     mymap.erase('c');
//     mymap.erase('d');
//   std::cout << "mymap now contains " << mymap.size() << " elements.\n";
//     ft::map<char,std::string>::iterator it = mymap.begin();
//     ft::map<char,std::string>::iterator en = mymap.end();
//     for (; it != en; it++)
//         std::cout << it->first ;
// std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//   std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//   std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//   std::cout << "mymap['d'] is " << mymap['d'] << '\n';

std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " insert method "
              << "] --------------------]\t\t\033[0m";
    {
        bool cond(false);
        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            start = get_time();
            for (size_t i = 0; i < 100; i++)
                m1.insert(std::make_pair(i, std::string("string2")));
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            for (size_t i = 0; i < 100; i++)
                ft_m1.insert(ft::make_pair(i, std::string("string2")));

            ualarm(0, 0);
            /*----------------------------------------------------*/
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m_range;
            ft::map<int, std::string> ft_m_range;

            start = get_time();
            m_range.insert(m1.begin(), m1.end());
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m_range.insert(ft_m1.begin(), ft_m1.end());
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }

        {
            time_t start, end, diff;
            /*------------------ std::maps ---------------------*/
            std::map<int, std::string> m1;
            ft::map<int, std::string> ft_m1;

            start = get_time();
            m1.insert(std::make_pair(100, "string2"));
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::maps ---------------------*/
            ualarm(diff * 1e3, 0);
            ft_m1.insert(ft::make_pair(100, std::string("string2")));
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }

        std::map<char, int> m;
        ft::map<char, int> ft_m;

        cond = m.size() == ft_m.size() && m.empty() == ft_m.empty();
        std::cout << std::endl << m.size() << " "<< ft_m.size() <<" "<< m.empty() <<" " <<  ft_m.empty() <<std::endl;
        // first insert function version (single parameter):
        m.insert(std::pair<char, int>('a', 100));
        m.insert(std::pair<char, int>('z', 200));

        ft_m.insert(ft::pair<char, int>('a', 100));
        ft_m.insert(ft::pair<char, int>('z', 200));

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());
        std::cout << m.size() << " "<< ft_m.size() <<" "<< m.empty() <<" " <<  ft_m.empty() <<std::endl;

        std::pair<std::map<char, int>::iterator, bool> ret;
        ft::pair<ft::map<char, int>::iterator, bool> ft_ret;

        ret = m.insert(std::pair<char, int>('z', 500));
        ft_ret = ft_m.insert(ft::pair<char, int>('z', 500));

        cond = cond && ret.second == ft_ret.second;
        std::cout << cond << " " << ret.second << " " << ft_ret.second << std::endl;
        // second insert function version (with hint position):
        std::map<char, int>::iterator it = m.begin();
        ft::map<char, int>::iterator ft_it = ft_m.begin();
        m.insert(it, std::pair<char, int>('b', 300));
        m.insert(it, std::pair<char, int>('c', 400));

        ft_m.insert(ft_it, ft::pair<char, int>('b', 300));
        ft_m.insert(ft_it, ft::pair<char, int>('c', 400));

        cond = cond && (m.size() == ft_m.size() && m.empty() == ft_m.empty());
        std::cout << m.size() << " "<< ft_m.size() <<" "<< m.empty() <<" " <<  ft_m.empty() <<std::endl;

        // third insert function version (range insertion):
        std::map<char, int> anothermap;
        ft::map<char, int> ft_anothermap;
        anothermap.insert(m.begin(), m.find('c'));
        ft_anothermap.insert(ft_m.begin(), ft_m.find('c'));
        cond = cond && (anothermap.size() == ft_anothermap.size() && anothermap.empty() == ft_anothermap.empty());

        std::cout << anothermap.size() << " "<< ft_anothermap.size() <<" "<< anothermap.empty() <<" " <<  ft_anothermap.empty() <<std::endl;

        cond = cond && comparemaps(ft_m.begin(), ft_m.end(), m.begin(), m.end()) && comparemaps(ft_anothermap.begin(), ft_anothermap.end(), anothermap.begin(), anothermap.end());
        EQUAL(cond);
    }
        
} 