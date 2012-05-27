 #ifndef KERNEL
 #include "../Grammar/Grammar.h"
 #include "../Control/Control.h"
 #include <string>
 #include <vector>
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
	Variable(std::string name);
	~Variable();
  	std::string getType();
	void setValueI(int n);
	int getValueI();
  	void setValueF(float n);
  	float getValueF();
  	void setValueD(double n);
  	double getValueD();
  private :
  protected :
 };
 class Core
 {
  // Lista de Variaveis
   	std::vector<Node> listadeNos ;
   	Node ArvoreLexica;
   	bool IsRead ;
	int Error;
   	std::vector<Variable> listV ;
   public :
	Core();

	Core(controlens::Control control);
	~Core();
    	double ExecuteOp(Node ArvoreLexica);
    	Variable GetVariable(int i);
    	void SetVariable(int i, Node *value);
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
