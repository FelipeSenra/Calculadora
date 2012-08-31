#ifndef KERNEL
 #include "../Grammar/Grammar.h"
 #include "../Control/Control.h"
 #include <string>
 #include <map>
 namespace kernel{
 using namespace grammar ;
 using namespace controlens ;
 class Variable{
  // Lista de Variaveis
    std::string type ;
    std::string name ;
    int n ;
    float real ;
    double dreal ;
public :
    Variable():name(""),type("null"),real(0.0),dreal(0.0){};
    Variable(std::string name);
    ~Variable();
    std::string getType();
    std::string getName();
    void setName(std::string name);
    void setValueI(int n);
    int getValueI();
    void setValueF(float n);
    float getValueF();
    void setValueD(double n);
    double getValueD();
    bool operator==  (Variable &cP1);
    //bool operator!=  (Variable &cP1);

private :
protected :
 };


 class Core
 {
  // Lista de Variaveis
    //std::vector<Node> listadeNos ;
    Node ArvoreLexica;
    bool IsRead ;
int Error;
    map<string,Variable> listV ;
   public :
    //Core();
    //Core(controlens::Control *control);
    ~Core();
    double ExecuteOp(Node *ArvoreLexica);
    Variable GetVariable(string name);
    void SetVariable(string name,double value);
   private :
   protected:
    void Warning() ;
 };

 }

/*class vector<Variable>::reference {
friend class vector;
reference();
public:
~reference();
operator bool () const;
reference& operator= ( const bool x );
reference& operator= ( const reference& x );
void flip();
}*/
#endif
