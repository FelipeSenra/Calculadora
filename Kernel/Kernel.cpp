 #include "Kernel.h"
 #include "../Grammar/Grammar.h"
  #include <string>
 #include <vector>
 #include <iostream>
#include <stdexcept>
#include <vector>
using namespace grammar;
using namespace kernel;
using namespace std;

Core::Core(){

}
/*
program:
END
expr_list END // END é ENTER
expr_list:
expression PRINT        // Print é “;”
expression PRINT expr_list
expression:
expression + term
expression - term
term
term:
term / primary
term * primary
primary
primary:
 NUMBER
NAME
NAME
NAME = expression - primary
( expression )
*/
double Core::ExecuteOp(Node tree){
  Node *Result = new Node(tree);
   switch (tree.getType() ){
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
			if(Result->getCenter() == PLUS){
				return ;
			}else{
			 if(Result->getCenter()  == MINUS){
				return ;
			 }
			 else{
				return ExecuteOp((ArvoreLexica)Result.middle());
 			 }
			}
		break;
		case TERM:
			if(tree.middle() == DIVIDE){

			}else{
			 if(tree.middle() == MULT){

			 }
			 else{

 			 }
			}
		break;
		case PRIMARY:
			if(tree.middle() == Token.NUMBER){

			}else{
				tree.middle().setValue(Core::GetVariable(tree.middle().getValue().index()));
			}
		break;

		case NAME:

		break;
	}
  return Result;
 }

 Variable Core::GetVariable(int i){
  return listV.at(i);
 }

void Core::SetVariable(int i, Node *value){
  try{
  listV.at(i);

  }
  catch (out_of_range& oor) {
   Variable *var = new Variable(value->getName());
   var->getType();
  // listV.insert(listV.size+1,var) ;
  }
 }

void Core::Warning(){
/* if(this.Error && Controle.isReady()){

 }*/
}

Variable::Variable(std::string name){
this->type = name;
}

std::string Variable::getType(){
    return this->type;
}

double Variable::getValueD(){
 return this->dreal;
}

float Variable::getValueF(){
 return this->real;
}
