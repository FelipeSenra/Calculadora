#include "Grammar.h"

using namespace grammar ;
using namespace std; 
using namespace controle ;
/*
Construtor da classe Node
*/
Node::Node(string type){
this->Type = type;
};
/*
Retorna no direito
*/
Node Node::getRight(){
 return *(this->Right) ;
}

/*
define no direito
*/
void Node::setRight(Node right){
  this->Right = &right;
}
/*
Retorna no direito
*/
Node Node::getAbove(){
 return *(this->Above) ;
}
/*
Retorna no direito
*/
void Node::setAbove(Node above){
  this->Above = &above;
}

void Node::setLeft(Node left){
  this->Left = &left;
}

Node Node::getLeft(){
 return *(this->Left) ;
}

Node Node::getCenter(){
 return *(this->Center) ;
}

void Node::setCenter(Node center){
  this->Center = &center;
};

std::string Node::getType(){	
  return this->Type;
}

void Node::setType(string type){
   this->Type = type;
}

/*
Gera a Arvore a partir da string
*/
// supos que = copia o conteudo
 Node Node::Parse(string frase){
	string str = frase;
	string Temp,Temp2;
	Node No,depois;
	int pos ;
	while(str.size() != 0){	
	if(string::npos != str.find(TOKEN[PLUS])){
		pos =str.find(TOKEN[PLUS]);
		Temp = str.substr (pos);
		Temp2 = str.substr (0,pos);
		No = *(new Node(TOKEN[PLUS]));
		depois = Parse(Temp2);
		No.setLeft(depois);
		depois.setAbove(No);
		depois = Parse(Temp);
		No.setRight(depois);
		depois.setAbove(No);		
	}
	if(string::npos != str.find(TOKEN[MINUS])){
		pos =str.find(TOKEN[MINUS]);
		Temp = str.substr (pos);
		Temp2 = str.substr (0,pos);
		No = *(new Node(TOKEN[MINUS]));
		depois = Parse(Temp2);
		No.setLeft(depois);
		depois.setAbove(No);
		depois = Parse(Temp);
		No.setRight(depois);
		depois.setAbove(No);		
	}
	if(string::npos != str.find(TOKEN[MULT])){
		pos =str.find(TOKEN[MULT]);
		Temp = str.substr (pos);
		Temp2 = str.substr (0,pos);
		No = *(new Node(TOKEN[MULT]));
		depois = Parse(Temp2);
		No.setLeft(depois);
		depois.setAbove(No);
		depois = Parse(Temp);
		No.setRight(depois);
		depois.setAbove(No);		
	}
	if(string::npos != str.find(TOKEN[DIV])){
		pos =str.find(TOKEN[DIV]);
		Temp = str.substr (pos);
		Temp2 = str.substr (0,pos);
		No = *(new Node(TOKEN[DIV]));
		depois = Parse(Temp2);
		No.setLeft(depois);
		depois.setAbove(No);
		depois = Parse(Temp);
		No.setRight(depois);
		depois.setAbove(No);		
	}
	if(string::npos != str.find(TOKEN[EQUAL])){
		pos =str.find(TOKEN[EQUAL]);
		Temp = str.substr (pos);
		Temp2 = str.substr (0,pos);
		No = *(new Node(TOKEN[EQUAL]));
		depois = Parse(Temp2);
		No.setLeft(depois);
		depois.setAbove(No);
		depois = Parse(Temp);
		No.setRight(depois);
		depois.setAbove(No);		
	}
	if(string::npos != str.find(TOKEN[PRINT])){
		controle::Control::getInstance().enablePrint();		
	}

	}
	return No;
}
