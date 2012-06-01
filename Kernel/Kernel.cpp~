 #include "Kernel/Kernel.h"
 #include "../Grammar/Grammar.h"
 
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
Node Core::ExecuteOp(Node tree){
  Node Result new Result(); 
   switch (tree){
		case PROGRAM:
			if(tree.getType() == Token.END)
				return Result;
			else{
				return ExecuteOp((ArvoreLexica)Result.Right());
			}
		break;
		case EXPR_LIST:
			if(tree == END){
				return ExecuteOp((ArvoreLexica)Result.Right());
			}
			else{
				ExecuteOp((ArvoreLexica)Result.Right());
				if()
				return ExecuteOp((ArvoreLexica)Result.Left());
			}
		break;
		case EXPRESSION:
			if(tree.middle() == PLUS){
				return ;
			}else{
			 if(tree.middle() == MINUS){
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

void Core::SetVariable(int i, Node value){
 swi listV.at(i) = value;
 }

void Core::Warning(){
 if(this.Error && Controle.isReady()){
 
 }
}

Variable::Variable(){

}


