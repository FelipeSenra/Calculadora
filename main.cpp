#include <iostream>
#include <string>
#include <exception>
#include "Grammar/Grammar.h"
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
  cout<<"Calculadora de terminal\n"<<endl;
  grammar::Node arvore;
  kernel::Core *core = new Core();
  Control *control = new Control();
  while (true)
  {
    try
    {
	control->disablePrint();
	cin >> frase;
	arvore = Node::Parse(frase);
	core->ExecuteOp(arvore);
	if(control->ToPrint()){
	cout << "ans:";
	}
    }catch(){

    }
  /*  catch(ERROCT::CORE)
    {
      break;
    };
    catch(ERROCT::STRING){
 break;
    }*/
  }
  return 0;
}

//----------------------------------------------------------------------------------------------------------
