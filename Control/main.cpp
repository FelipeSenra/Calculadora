#include<iostream>
#include<string>
#include"" 
//----------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  string frase ;
  cout<<"Calculadora de terminal\n"<<endl;
  Node arvore;
  while (true)
  {
    try
    {	
	::disablePrint()
	cin >> frase;
	arvore = Node::Parse(string frase);
	Core::ExecuteOp(arvore);
	if(Control::ToPrint()){
	cout << ;		
	}	
    }
    catch (...)
    {
      break;
    }
    catch(...){

    }
  }
  return 0;
}

//----------------------------------------------------------------------------------------------------------


