 #ifndef INTER
 #include "../Control/Control.h"
 #include "../Grammar/Grammar.h"
 #include <string>
 #include <iostream>
 #include <vector>

 namespace interface{
 using namespace std ;
 using namespace controlens ;
 using namespace grammar;

 class Interface{
public :
  Interface();
  std::string getString();
  void printTree(Node *no);
  void readConsole();
  void increment();
  int getindex();
  int getsize();
  void MakeTitle();
  void PlotHelp();

  void plot(std::string result);
private:
  std::vector<string> texto ;
  std::vector<string>::iterator it;
  int i;
 };
 }
 #endif
