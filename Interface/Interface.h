 #ifndef INTER
 #include <string>
 #include <iostream>
 #include <vector>

 namespace interface{
 using namespace std ;
 using namespace controlens ;

 class Interface{
public :
  Interface();
  std::string getString();
  void plot(std::string result);
private:
std::string frase ;

 }
 }
 #endif
