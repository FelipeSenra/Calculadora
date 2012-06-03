#include <iostream>
#include "Control.h"
using namespace controlens;
using namespace std;

/*
* habilita o print
*/
void Control::enablePrint(){

	controlens::Control::getInstance()->toPrint =true;
}
/*
* desabilita o print
*/
void Control::disablePrint(){
	Control::instance->toPrint = false ;
}
/*
* Construtor do Controle
*/
Control::Control()
{
   this->toPrint = false ;
}
/*
Retorna se deve ou nao printar os resultados
*/
bool Control::ToPrint(){
  return Control::getInstance().toPrint;
}
/*
retorna a instancia de controle se caso existir ou cria e retorna essa instancia caso nao
*/
 Control Control::getInstance(){
     if (!instance) instance = new Control();
        return *instance;
}


