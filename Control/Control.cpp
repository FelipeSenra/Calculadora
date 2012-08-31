#include <iostream>
#include "Control.h"
using namespace controlens;
using namespace std;



bool Control::instanceFlag = false;
Control* Control::instance = NULL;

void Control::enablePrint(){
//Control::getInstance().toPrint =true;
//Control::getInstance().toPrint= true;
controlens::Control::getInstance()->toPrint =true;
}

void Control::disablePrint(){
controlens::Control::getInstance()->toPrint =false;
}

Control::Control()
{
   this->toPrint = false ;
}
bool Control::ToPrint(){
  return Control::getInstance()->toPrint;
}


 Control* Control::getInstance(){
     if (!instanceFlag){ instance = new Control();instanceFlag = true;}
        return instance;
}
