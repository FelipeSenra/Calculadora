#include <iostream>
#include "Control.h"
using namespace controlens;
using namespace std;
void Control::enablePrint(){
	//Control::getInstance().toPrint =true;
	//Control::getInstance().toPrint= true;
	controlens::Control::instance->toPrint =true;
}

void Control::disablePrint(){
	Control::instance->toPrint = false ;
}
Control::Control()
{
   this->toPrint = false ;
}
bool Control::ToPrint(){
  return Control::getInstance().toPrint;
}

 Control Control::getInstance(){
     if (!instance) instance = new Control();
        return *instance;
}


