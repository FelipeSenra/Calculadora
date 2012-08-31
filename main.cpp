#include <iostream>
#include <string>
#include <exception>
#include "Grammar/Grammar.h"
#include "Interface/Interface.h"
#include "Control/Control.h"
#include "Kernel/Kernel.h"

using namespace std;
using namespace controlens;
using namespace grammar;
using namespace kernel;
using namespace interface;
//----------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  string frase ;
  grammar::Node arvore;
  kernel::Core core;
  Interface inter ;
  Control::getInstance();
  inter.MakeTitle();
  while (true)
  {
    try
    {
//	Control::getInstance()->disablePrint();
	inter.readConsole();
    do{
        Control::getInstance()->disablePrint();
        frase = inter.getString();
        if((frase == "EXIT")||(frase == "exit"))
            return 0;
        if((frase == "HELP")||(frase == "help")){
            inter.PlotHelp();
        break;
        }
        if(frase.size() != 0)
            arvore = *Node::Parse(frase);
        if(Control::getInstance()->ToPrint()){
            cout << "ans:"<<core.ExecuteOp(&arvore)<<std::endl;
        }else{
        core.ExecuteOp(&arvore);
        }
    }while(inter.getindex() < inter.getsize());
    }catch(int e){
    cout << "erro"<<endl ;
    }
  }



  return 0;
}

//----------------------------------------------------------------------------------------------------------
