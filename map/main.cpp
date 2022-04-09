// #include "node.hpp"
#include<map>
#include<iostream>
#include<utility>


int main() {
      std::pair<int, std::string> p (5, "helllllo");
      std::pair<int, std::string> l (6, "helllllo");
      std::map<int, std::string> kharita;
      kharita.insert(p);
      kharita.insert(l);

       for (std::map<int, std::string>::iterator it=kharita.begin(); it!=kharita.end(); ++it)
          std::cout << it->first << " => " << it->second << '\n';
}