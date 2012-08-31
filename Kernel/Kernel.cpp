#include "Kernel.h"
#include "../Grammar/Grammar.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace grammar;
using namespace kernel;
using namespace std;

/**
Calcula o Valor da expressão
Node *tree - arvore da expressão
double - Valor da expressão
*/
double Core::ExecuteOp(Node *tree){
  double divide ;
  Variable  temp2;
  Node *Result = tree;
  Node temp = *tree;
  Node temp3;

   switch (temp.getType() ){
        case PROGRAM:
                return ExecuteOp(Result->getLeft());
        break;
        case EXPR_LIST:
                ExecuteOp(Result->getCenter());
                ExecuteOp(Result->getRight());
                return ExecuteOp(Result->getLeft());
        break;
        case END:
                return 0.0;
        break;
        case EXPRESSION:
                if(Result->getCenter()->getType() == PLUS){
                    return ExecuteOp(Result->getLeft())+ExecuteOp(Result->getRight()) ;
                }
                else{
                if(Result->getCenter()->getType() == MINUS){
                    return ExecuteOp(Result->getLeft())-ExecuteOp(Result->getRight()) ;
                }
                else{
                    return ExecuteOp(Result->getCenter());
                }
        }
        break;
        case TERM:
            if(Result->getCenter()->getType() == DIVIDE){
                 divide = ExecuteOp(Result->getRight());
                 if(divide != 0)
                 return ExecuteOp(Result->getLeft())/divide ;
            }
            else{
                if(Result->getCenter()->getType() == MULT){
                    return ExecuteOp(Result->getLeft())*ExecuteOp(Result->getRight());

            }
            else
                    return ExecuteOp(Result->getCenter());
        }
        break;
        case PRIMARY:
        if(Result->getCenter()->getType() == NAME){
            return ExecuteOp(Result->getCenter());
        }if(Result->getCenter()->getType() == NUMBER){
            return Result->getValue();
        }
        break;
        case NUMBER:
            return temp.getValue();
        break;
        case NAME:
            if((temp.getRight() != NULL)&&(temp.getRight()->getType() == EQUAL)){
                divide=ExecuteOp(temp.getRight());
                SetVariable(temp.getName(),divide);
                return divide;}
            else if ((temp.getCenter() != NULL)&&(temp.getCenter()->getType() == EXPRESSION))
                return ExecuteOp(temp.getCenter());
            else
                temp2 = GetVariable(temp.getName());
               return temp2.getValueD();
                //return temp.getValue();
        break;
        case ILEGIVEL:
            return 0;
        case EQUAL:
        divide = ExecuteOp(temp.getRight());
        temp3 = *temp.getLeft();
        if((temp.getLeft() != NULL)&&(temp.getLeft()->getType() == NAME))
            SetVariable(temp.getLeft()->getName(),divide);
        return ExecuteOp(temp.getRight());
        break;
}
  return 0.0;
}

/**
Retorna a variavel com um certo nome
string name- nome da variavel
Variable - a variavel com um certo nome

*/
Variable Core::GetVariable(string name){
  Variable var;
  var = listV[name];
  return var;
 }
/**
Define uma variavel com um certo nome
string name - nome da variavel
double value - valor da variavel
*/
void Core::SetVariable(string name, double value){
  Variable *var;
  try{
   var = &listV[name];
   var->setValueD(value);
   var->setName(name);
   listV[name] = *var ;
  }
  catch (out_of_range& oor) {
   Variable *var = new Variable(name);
   var->setValueD(value);
   listV[name] = *var ;
  }
 }
/**
Define uma variavel com um certo nome
string name - nome da variavel
double value - valor da variavel
*/

void Core::Warning(){

}
/**
Define uma variavel com um certo nome
string name - nome da variavel
double value - valor da variavel
*/
Variable::Variable(std::string name){
this->type = name;
}
/**
Retorna tipo da variavel
*/
std::string Variable::getType(){
    return this->type;
}
/**
Retorna valor da variavel
*/
double Variable::getValueD(){
 return this->dreal;
}
/**
Retorna valor da variavel
*/
float Variable::getValueF(){
 return this->real;
}
/**
Define o valor da variavel
double d = valor da variavel
*/
void Variable::setValueD(double d){
 this->dreal = d;
}
/**
operador de comparação da varaivel.
*/
bool Variable::operator==  (Variable &cP1)
{

    return (this->name == cP1.name);
}
/**
Retorna o nome da variavel
*/
std::string Variable::getName(){
return name ;
}
/**
Define o nome da variavel
string d - nome da variavel
*/
void Variable::setName(std::string d){
 this->name = d;
}

/**
Destrutor da Variavel
*/
Variable::~Variable(){

}
 Core::~Core(){
 }

