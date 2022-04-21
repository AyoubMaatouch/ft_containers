#include "Map.hpp"
#include <iostream>
#include <iomanip>
#include <map>

#define print(X) std::cout << X << std::endl;
// Reset
#define Color_Off "\e[0m"       // Text Reset
// Bold
#define BBlack "\e[1;30m"       // Black
#define BRed "\e[1;31m"         // Red
#define BGreen "\e[1;32m"       // Green
#define BYellow "\e[1;33m"      // Yellow
#define BBlue "\e[1;34m"        // Blue
#define BPurple "\e[1;35m"      // Purple
#define BCyan "\e[1;36m"        // Cyan
#define BWhite "\e[1;37m"       // White
// Background
#define On_Black "\e[40m"       // Black
#define On_Red "\e[41m"         // Red
#define On_Green "\e[42m"       // Green
#define On_Yellow "\e[43m"      // Yellow
#define On_Blue "\e[44m"        // Blue
#define On_Purple "\e[45m"      // Purple
#define On_Cyan "\e[46m"        // Cyan
#define On_White "\e[47m"       // White

// ======================================================== GLOBAL VARIABLES

int LENGTH = 50;

std::map<int, int> std_map;
ft::map<int, int> ft_map;

std::map<int, int>::iterator std_it;
ft::map<int, int>::iterator ft_it;

std::map<int, int>::const_iterator std_cit;
ft::map<int, int>::const_iterator ft_cit;

std::map<int, int>::reverse_iterator std_rit;
ft::map<int, int>::reverse_iterator ft_rit;

std::map<int, int>::const_reverse_iterator std_crit;
ft::map<int, int>::const_reverse_iterator ft_crit;

// ======================================================== HELP FUNCTIONS

void ok()
{
	std::cout << BGreen << "[OK]\n" << Color_Off;
}

void ko()
{
	std::cout << BRed << "[KO]\n" << Color_Off;
}

void title(std::string str)
{
	std::cout << BBlue << "+ " << std::setw(60) << std::left << str << Color_Off;
}

void big_title(std::string str)
{
	std::cout << On_Purple << BWhite << "\n-------------------- " << str << Color_Off << "\n\n";
}

void init_map()
{
	for (int i = 1; i <= LENGTH; i++)
	{
		std_map.insert(std::make_pair(i, i*10));
		ft_map.insert(ft::make_pair(i, i*10));
	}
}

void check_values(std::map<int, int> _std, ft::map<int, int> _ft)
{
	if (_std.size() != _ft.size())
	{
		std::cout << _std.size() << " != " << _ft.size() << "\n";
		ko();
		return ;
	}
	for (int i = 1; i <= LENGTH; i++)
	{
		if (_std[i] != _ft[i])
		{
			ko();
			return ;
		}
	}
	// print("yyy")
	ok();
}

void check_iterator()
{
	if (std_it->first != ft_it->first || std_it->second != ft_it->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_const_iterator()
{
	if (std_cit->first != ft_cit->first || std_cit->second != ft_cit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_reverse_iterator()
{
	if (std_rit->first != ft_rit->first || std_rit->second != ft_rit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_const_reverse_iterator()
{
	if (std_crit->first != ft_crit->first || std_crit->second != ft_crit->second)
	{
		ko();
		return ;
	}
	ok();
}

void check_capacity(bool results)
{

	if (!results)
	{
		ko();
	
		return ;
	}
	ok();
}

// ======================================================== TEST FUNCTIONS

void member_functions()
{
	big_title("Member functions");
	
	title("default constructor");
	std::map<int, int> std_map_default;
	ft::map<int, int> ft_map_default;
	check_values(std_map_default, ft_map_default);

	title("copy constructor");
	std::map<int, int> std_map_copy(std_map);
	ft::map<int, int> ft_map_copy(ft_map);
	check_values(std_map_copy, ft_map_copy);
	
	title("range constructor");
	std::map<int, int> std_map_range(std_map.begin(), std_map.end());
	ft::map<int, int> ft_map_range(ft_map.begin(), ft_map.end());
	check_values(std_map_range, ft_map_range);
	
	{
		title("destructor");
		std::map<int, int> std_map_destructor;
		ft::map<int, int> ft_map_destructor;
		check_values(std_map_destructor, ft_map_destructor);
	}

	title("operator=");
	std::map<int, int> std_map_operator = std_map;
	ft::map<int, int> ft_map_operator = ft_map;
	check_values(std_map_operator, ft_map_operator);
}

void iterators()
{
	big_title("Iterators");
	
	title("begin - [iterator]");
	std_it = std_map.begin();
	ft_it = ft_map.begin();
	check_iterator();

	title("begin - [const iterator]");
	std_cit = std_map.begin();
	ft_cit = ft_map.begin();
	check_const_iterator();

	title("end - [iterator]");
	std_it = --std_map.end();
	ft_it = --ft_map.end();
	check_iterator();

	title("end - [const iterator]");
	std_cit = --std_map.end();
	ft_cit = --ft_map.end();
	check_const_iterator();

	title("rbegin - [reverse iterator]");
	std_rit = std_map.rbegin();
	ft_rit = ft_map.rbegin();
	check_reverse_iterator();

	title("rbegin - [const reverse iterator]");
	std_crit = std_map.rbegin();
	ft_crit = ft_map.rbegin();
	check_const_reverse_iterator();

	title("rend - [reverse iterator]");
	std_rit = --std_map.rend();
	ft_rit = --ft_map.rend();
	check_reverse_iterator();

	title("rend - [const reverse iterator]");
	std_crit = --std_map.rend();
	ft_crit = --ft_map.rend();
	check_const_reverse_iterator();
}

void capacity()
{
	big_title("Capacity");
	title("empty [empty maps]");
	std::map<int, int> std_map_default;
	ft::map<int, int> ft_map_default;
	check_capacity(std_map_default.empty() == ft_map_default.empty());

	title("empty [filled maps]");
	check_capacity(std_map.empty() == ft_map.empty());

	// std::cout << std_map[10] << " " << ft_map[10] << std::endl;
	title("size");
	std_map.erase(1);
	std_map.erase(2);
	std_map.erase(-4);
	ft_map.erase(1);
	// print(ft_map[4])
	// s_map.erase(-4);
	ft_map.erase(2);
	// std::cout << "are u here" << std::endl;
	ft_map.erase(-4);
	LENGTH -= 3;
	// std::cout << ft_map.size() << std::endl;
	check_capacity(std_map.size() == ft_map.size());

	// title("max_size");
	// check_capacity(std_map.max_size() == ft_map.max_size());
}

void element_access()
{
	big_title("Element access");
	title("operator[] - [example 1]");
	check_capacity(std_map[10] == ft_map[10]);
	// print("waaaa3")
	title("operator[] - [example 2]");
	check_capacity(std_map[-10] == ft_map[-10]);
}

void modifiers()
{
	big_title("Modifiers");
	
	title("insert - [single new element]");
	bool val_std = std_map.insert(std::make_pair(LENGTH + 1, 33)).second;
	bool val_ft = ft_map.insert(ft::make_pair(LENGTH + 1, 33)).second;
	LENGTH += 1;
	check_values(std_map, ft_map);
	
	title("insert - [single new element result]");
	check_capacity(val_std == val_ft);

	// title("insert - [single new multiple elements]");
	// std_map.insert(std::make_pair(LENGTH + 1, 343));
	// std_map.insert(std::make_pair(LENGTH + 1, 3123));
	// std_map.insert(std::make_pair(LENGTH + 1, 33));
	// ft_map.insert(ft::make_pair(LENGTH + 1, 343));
	// ft_map.insert(ft::make_pair(LENGTH + 1, 3123));
	// ft_map.insert(ft::make_pair(LENGTH + 1, 33));
	// LENGTH += 3;
	// check_values(std_map, ft_map);
// 
	// title("insert - [single existing element]");
	// val_std = std_map.insert(std::make_pair(1, 33)).second;
	// val_ft = ft_map.insert(ft::make_pair(1, 33)).second;
	// check_values(std_map, ft_map);
	// print("xxx")
// 
	// title("insert - [single existing element result]");
	// check_capacity(val_std == val_ft);
// 
	// title("insert - [single existing multiple elements]");
	// std_map.insert(std::make_pair(6, 343));
	// std_map.insert(std::make_pair(10, 3123));
	// std_map.insert(std::make_pair(3, 33));
	// ft_map.insert(ft::make_pair(6, 343));
	// ft_map.insert(ft::make_pair(10, 3123));
	// ft_map.insert(ft::make_pair(3, 33));
	// check_values(std_map, ft_map);
// 
	title("insert - [with hint]");
	std_map.insert(std_map.begin(), std::make_pair(LENGTH + 1, 67543));
	ft_map.insert(ft_map.begin(), ft::make_pair(LENGTH + 1, 67543));
	LENGTH += 1;
	check_values(std_map, ft_map);

	title("insert - [range]");
	std::map<int, int> std_map_default;
	ft::map<int, int> ft_map_default;
	std_map_default.insert(++std_map.begin(), --std_map.end());
	ft_map_default.insert(++ft_map.begin(), --ft_map.end());
	check_values(std_map_default, ft_map_default);

	title("erase - [single existing element]");
	size_t size_std = std_map.erase(10);
	size_t size_ft = ft_map.erase(10);
	LENGTH -= 1;
	check_values(std_map, ft_map);

	title("erase - [single other element]");
	size_std = std_map.erase(-10);
	size_ft = ft_map.erase(-10);
	check_values(std_map, ft_map);
	
	title("erase - [iterator example 1]");
	std_map.erase(++std_map.begin());
	ft_map.erase(++ft_map.begin());
	LENGTH -= 1;
	check_capacity(val_std == val_ft);

	title("erase - [iterator example 2]");
	std_map.erase(--std_map.end());
	ft_map.erase(--ft_map.end());
	LENGTH -= 1;
	check_values(std_map, ft_map);

	title("erase - [range]");
	std_map_default.erase(std_map_default.begin(), std_map_default.end());
	ft_map_default.erase(ft_map_default.begin(), ft_map_default.end());
	check_values(std_map_default, ft_map_default);

	title("swap");
	std::map<int, int> std_map_swap;
	ft::map<int, int> ft_map_swap;
	std_map_default.insert(std_map.begin(), std_map.end());
	ft_map_default.insert(ft_map.begin(), ft_map.end());
	std_map_swap.swap(std_map_default);
	ft_map_swap.swap(ft_map_default);
	check_values(std_map_swap, ft_map_swap);

	title("clear");
	std_map.clear();
	std_map.clear();
	std_map.clear();
	ft_map.clear();
	ft_map.clear();
	ft_map.clear();
	LENGTH = 0;
	check_values(std_map_swap, ft_map_swap);
}

void observers()
{
	big_title("Observers");
	
	std::map<int,int> std_mymap;
	std::map<int,int>::key_compare std_mycomp = std_mymap.key_comp();
	std::map<int,int>::iterator std_myit;
	
	ft::map<int,int> ft_mymap;
	ft::map<int,int>::key_compare ft_mycomp = ft_mymap.key_comp();
	ft::map<int,int>::iterator ft_myit;

	std_mymap[1]=100;
	std_mymap[2]=200;
	std_mymap[3]=300;
	
	ft_mymap[1]=100;
	ft_mymap[2]=200;
	ft_mymap[3]=300;

	std_myit = std_mymap.begin();
	ft_myit = ft_mymap.begin();

	title("key_comp"); 
	{
		int std_highest = std_mymap.rbegin()->first; 
		int ft_highest = ft_mymap.rbegin()->first; 

		for (int i = 1; i <= 3; i++)
		{
			if (std_mycomp(std_mymap[i], std_highest) != ft_mycomp(ft_mymap[i], ft_highest))
			{
				ko();
				return;
			}
		}
		ok();
	}

	title("value_comp"); 
	{
		std::pair<int,int>  std_highest = *std_mymap.rbegin(); 
		ft::pair<int,int> ft_highest = *ft_mymap.rbegin(); 
		
		for (int i = 1; i <= 3; i++)
		{
			if (std_mymap.value_comp()(*std_myit++, std_highest) != ft_mymap.value_comp()(*ft_myit++, ft_highest))
			{
				ko();
				return;
			}
		}
		ok();
	}
}

void operations()
{
	big_title("Operations");
	
	std::map<int,int> std_mymap;
	ft::map<int,int> ft_mymap;

	std_mymap[1]=100;
	std_mymap[2]=200;
	std_mymap[3]=300;
	
	ft_mymap[1]=100;
	ft_mymap[2]=200;
	ft_mymap[3]=300;

	title("find"); 
	{
		for (int i = 1; i <= 3; i++)
		{
			if (std_mymap.find(i)->first != ft_mymap.find(i)->first)
			{
				ko();
				return;
			}
		}
		ok();
	}

	title("count"); 
	{
		for (int i = 1; i <= 3; i++)
		{
			if (std_mymap.count(i) != ft_mymap.count(i))
			{
				ko();
				return;
			}
		}
		ok();
	}

	title("lower_bound"); 
	{
		for (int i = 0; i <= 3; i++)
		{
			if (std_mymap.lower_bound(i)->second != ft_mymap.lower_bound(i)->second)
			{
				ko();
				return;
			}
		}
		ok();
	}

	title("upper_bound"); 
	{
		for (int i = 0; i <= 2; i++)
		{
			if (std_mymap.upper_bound(i)->second != ft_mymap.upper_bound(i)->second)
			{
				ko();
				return;
			}
		}
		ok();
	}

	title("equal_range"); 
	{
		for (int i = 0; i <= 2; i++)
		{
			if ((std_mymap.equal_range(i).first)->second != (ft_mymap.equal_range(i).first)->second
			|| (std_mymap.equal_range(i).second)->second != (ft_mymap.equal_range(i).second)->second)
			{
				ko();
				return;
			}
		}
		ok();
	}
}

void allocator()
{
	big_title("Allocator");
	
	std::map<int,int> std_mymap;
	ft::map<int,int> ft_mymap;

	std::pair<const int, int>* std_p;
	ft::pair<const int, int>* ft_p;

	title("get_allocator");
	std_p = std_mymap.get_allocator().allocate(5);
	ft_p = ft_mymap.get_allocator().allocate(5);

	std_mymap.get_allocator().deallocate(std_p, 5);
	ft_mymap.get_allocator().deallocate(ft_p, 5);

	ok();
}

int main()
{
    std::cout << On_Cyan << BBlack << "\n*********************************\n" << Color_Off;
    std::cout << On_Cyan << BBlack << "************** MAP **************\n" << Color_Off;
    std::cout << On_Cyan << BBlack << "*********************************\n" << Color_Off;

	init_map();
	member_functions();
	iterators();
	capacity();
	element_access();
	modifiers();
	observers();
	operations();
	allocator();

	std::cout << "\n";
}