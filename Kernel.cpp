 #include "Kernel.h"
 #include "Grammar.h"
 
 class Core 
 {
  // Lista de Variaveis
   Node listadeNos ;
   Tree ArvoreLexica;  
   bool IsRead ; 
   Variable listV ;
   
   public :
    Node ExecuteOp(ArvoreLexica);
    Variable GetVariable(int i);
    void SetVariable(int i, Node value);
   private :
   protected:
   void Warning() ;
 };
 
 Node ExecuteOp(ArvoreLexica){
  Node Result new Result(); 
   
  return Result;  
 }
 Variable GetVariable(int i){
  return listV[i]   
 }

void SetVariable(int i, Node value){
 listV[i] = value
 }