#include "vector.hpp"
// #include "iterators.hpp"
#include <sys/time.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <unistd.h>
// #include <memory>
#include <vector>
// using namespace std;
// #include "is_intergal.hpp"
#define TIME_FAC 20
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
    int main() 
    {
         std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string> v1(1e6, "string2");
            start = get_time();
            v1.size();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string> ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");          // fill constructor
        std::vector<std::string> v2;                         // empty constructor
        std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string> v4(v3);                     // copy constructor
        std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string> ft_v4(ft_v1);
        ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.size() == ft_v1.size() && v2.size() == ft_v2.size() && v3.size() == ft_v3.size() && v4.size() == ft_v4.size() && v5.size() == ft_v5.size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " capacity method "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string> v1(1e6, "string2");
            start = get_time();
            v1.capacity();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string> ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.capacity();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v1(10, "string2");          // fill constructor
        std::vector<std::string> v2;                         // empty constructor
        std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string> v4(v3);                     // copy constructor
        std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<std::string> ft_v2;
        ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
        ft::vector<std::string> ft_v4(ft_v1);
        ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        std::cout << std::endl;
        // std::cout<< v1.capacity() <<" " <<  ft_v1.capacity() << std::endl;
        // std::cout<< v1.size() <<" " <<  ft_v1.size() << std::endl;
        // std::cout << v2.capacity() <<" " <<  ft_v2.capacity() << std::endl;
        // std::cout << v2.size() <<" " <<  ft_v2.size() << std::endl;
        std::cout << v3.capacity() <<" " <<  ft_v3.capacity() << std::endl;
        std::cout << v3.size() <<" " <<  ft_v3.size() << std::endl;
        // std::cout << v4.capacity() <<" " <<  ft_v4.capacity() << std::endl;
        // std::cout << v4.size() <<" " <<  ft_v4.size() << std::endl;
        std::cout << v5.capacity() <<" " <<  ft_v5.capacity() << std::endl;
        std::cout << v5.size() <<" " <<  ft_v5.size() << std::endl;
        EQUAL(v1.capacity() == ft_v1.capacity() && v2.capacity() == ft_v2.capacity() && v3.capacity() == ft_v3.capacity() && v4.capacity() == ft_v4.capacity() && v5.capacity() == ft_v5.capacity());
    }
     std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " max_size method "
              << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string> v1(1e6, "string2");
            start = get_time();
            v1.max_size();
            end = get_time();
            diff = end - start;
            diff = (diff) ? (diff * TIME_FAC) : TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::vector<std::string> ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.max_size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/

        std::vector<std::string> v1(10, "string");
        std::vector<int> v2;
        std::vector<double> v4;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::vector<std::string> ft_v1(10, "string2");
        ft::vector<int> ft_v2;
        ft::vector<double> ft_v4;
        /*----------------------------------------------------*/
        EQUAL(v1.max_size() == ft_v1.max_size() && v2.max_size() == ft_v2.max_size() && v4.max_size() == ft_v4.max_size());
    }
    //     {
    //     /*---------------------------------- time limit test --------------------------------------------*/
    //     {
    //         time_t start, end, diff;
    //         std::vector<std::string> v(1e5, "range constructor test");
    //         start = get_time();
    //         std::vector<std::string> v1(v.begin(), v.end());
    //         end = get_time();
    //         diff = end - start;
    //         diff = (diff) ? (diff * 20) : 20;

    //         ualarm(diff * 1e3, 0);
    //         ft::vector<std::string> my_v(v.begin(), v.end());
    //         ualarm(0, 0);
    //     }
    //     /*-----------------------------------------------------------------------------------------------*/
    //     /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
    //     std::vector<std::string> v(10, "range constructor test");
    //     ft::vector<std::string> my_v(10, "range constructor test");
    //     ft::vector<std::string> my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with ft::vector
    //     /*----------------------------------------------------------------------------------------------*/
    //     /*--------------- declare tow strings to store the results ------*/
    //     std::string res, my_res, my_res1;
    //     /*--------------------------------------------------------*/
    //     for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
    //         res += *it;

    //     for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
    //         my_res += *it;

    //     for (ft::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
    //         my_res1 += *it;
    //     EQUAL(res == my_res && my_res == my_res1);
    // }
        //  ft::vector<std::string> my_v(10, "fill constructor test");
        // std::vector<std::string> v(10, "fill constructor test");
        // /*---------------------------------------------------------*/
        // /*--------------- declare tow strings to store the results ------*/
        // std::string res, my_res;
        // /*---------------------------------------------------------*/
        // for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
        //     res += *it;

        // for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
        //     my_res += *it;
        // EQUAL(res == my_res);
        // ft::vector<int> v;
        // ft::vector<int> hego(5, 99);
        // // v.reserve(20);
        // std::cout  << "capacity = " << v.capacity() << "\n";
        // std::cout  << "size = " << v.size() << "\n";
        // v.insert(v.begin() , 1);
        // v.insert(v.begin() , 2);
        // v.insert(v.begin() , 3);
        // std::cout  << "capacity = " << v.capacity() << "\n";
    // {        std::string str, ft_str;
    //         std::vector<std::string> v(20, "string");
    //         ft::vector<std::string> ft_v(20, "string");

    //     std::cout  << "size = " << v.size() << "\n";
    //     std::cout  << "capacity = " << v.capacity() << "\n";
    //     std::cout  << "Address = " << &(*v.begin()) << "\n";

    //     std::cout  << "ft size = " << ft_v.size() << "\n";
    //     std::cout  << "ft capcity = " << ft_v.capacity() << "\n";
    //     std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
    //         v.insert(v.begin() + 10, 100, "hello");
    //         ft_v.insert(ft_v.begin() + 10, 100, "hello");
    //     std::cout  << "size = " << v.size() << "\n";
    //     std::cout  << "capacity = " << v.capacity() << "\n";
    //     std::cout  << "Address = " << &(*v.begin()) << "\n";

    //     std::cout  << "ft size = " << ft_v.size() << "\n";
    //     std::cout  << "ft capacity = " << ft_v.capacity() << "\n";
    //     std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
    //     //  ft::vector <int>::iterator lkabi =  v.erase(v.begin() + 4, v.begin() + 10);
    //     for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];

    //      std::cout << str<<  std::endl;
    //      std::cout << ft_str<<  std::endl;
    //      if (str == ft_str)
    //         std::cout<< "Wooorkssss" << std::endl;
    // }
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