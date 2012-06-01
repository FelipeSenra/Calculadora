#include <string>
#include <iostream>
#include <vector>
#include "Interface.h"
using namespace interface;
Interface::Interface(){

}
  std::string getString(){
    std::string frase ;
    std::cin >> frase;
    return frase;
  }
  void plot(std::string result){
   std::cout << result;
  }
