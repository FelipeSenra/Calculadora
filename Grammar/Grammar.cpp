#include "Grammar.h"
#include <cctype>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "..\Control\Control.h"
using namespace grammar ;
using namespace controlens;
using namespace std;
//using namespace controle ;
/**
Construtor de No
*/
Node::Node(){
this->Name = "";
this->Type = NULLT;
this->Above = 0 ;
this->Left = 0 ;
this->Center = 0 ;
this->Right = 0;
};
/**
Construtor de No
Token type - tipo do no
*/
Node::Node(Token type){
this->Name = "";
this->Type = type;
this->Above = 0 ;
this->Left = 0 ;
this->Center = 0 ;
this->Right = 0;
};

Node* Node::getRight(){
 return this->Right ;
 }

void Node::setRight(Node &right){
  Right = &right;
}

Node* Node::getAbove(){
 return this->Above ;
}

double Node::getValue(){
 return this->Value ;
}

void Node::setValue(double above){
  this->Value = above;
}

void Node::setAbove(Node &above){
  this->Above = &above;
}

void Node::setLeft(Node &left){
  this->Left = &left;
}

Node* Node::getLeft(){
 return this->Left ;
}

Node* Node::getCenter(){
 return this->Center ;
}

void Node::setCenter(Node &center){
  this->Center = &center;
};

std::string Node::getName(){
  return Name ;
}

void Node::setName(std::string name){
  Name = name ;
}

Token Node::getType(){
  return this->Type;
}

void Node::setType(Token type){
   this->Type = type;
}

/**
Transforma a String em uma arvore para ser executada
string frase - String de commando
return Node - Arvore que criada a partir da string
*/
 Node* Node::Parse(string frase){
double d;
int pos,pos2,count,count2 ;
std::istringstream stm;
string str = frase;
string Temp,Temp2;
grammar::Node *No;
grammar::Node *depois;
grammar::Node temp,temp2;
//str = TOKEN[END];
//int pos = str.find_first_of("0123456789.,");
while(str.size() != 0){
    if(string::npos != str.find(TOKEN[EQUAL])){
            pos =str.find(TOKEN[EQUAL]);
            Temp = str.substr (pos+1,str.size());
            Temp2 = str.substr (0,pos);
            No = new Node(EQUAL);
            if( 0!=Temp2.size()){
                depois = Parse(Temp2);
                No->setLeft(*depois);
                depois->setAbove(*No);}
            if( 0!=Temp.size())
                depois = Parse(Temp);
                No->setRight(*depois);
                depois->setAbove(*No);
            break ;
    }
    if(string::npos != str.find(TOKEN[LPARAM])){
            pos = str.find(TOKEN[LPARAM]);
            count = 1;
            count2 = pos+1 ;
            do{
                char temp3 = str.at(count2);
                if('(' == temp3)
                {
                    count++;
                }
                if(')' == temp3){
                    pos2 = count2;
                    count--;
                }
                count2++;
            }
            while(count > 0);
            Temp = str.substr (pos+1,pos2);
            Temp2 = str.substr (0,pos);
            str = str.substr (pos2+1,str.size());
            if( 0!= Temp.size())
            depois = Parse(Temp);
            if( 0!= str.size()){
            No = Parse(str);
            if(No->getType() != PRINT){
            No->setLeft(*depois);
            depois->setAbove(*No);
            depois = No;
            }
            else
             No = depois;
            }
            if( 0!= Temp2.size()){
            No = Parse(Temp2);
            No->setRight(*depois);
            depois->setAbove(*No);}
            break ;
    }
    if(string::npos != str.find(TOKEN[PLUS])){
            pos =str.find(TOKEN[PLUS]);
            Temp = str.substr (pos+1,str.size());
            Temp2 = str.substr (0,pos);
            No = new Node(EXPRESSION);
            depois = new Node(PLUS);
            No->setCenter(*depois);
            if( 0!=Temp2.size()){
            depois = Parse(Temp2);
            No->setLeft(*depois);
            depois->setAbove(*No);}
            if( 0!=Temp.size())
            depois = Parse(Temp);
            No->setRight(*depois);
            depois->setAbove(*No);
            break ;
    }
    if(string::npos != str.find(TOKEN[MINUS])){
            pos =str.find(TOKEN[MINUS]);
            Temp = str.substr (pos+1,str.size());
            Temp2 = str.substr (0,pos);
            No = new Node(EXPRESSION);
            depois = new Node(MINUS);
            No->setCenter(*depois);
            if( 0!=Temp2.size()){
            depois = Parse(Temp2);
            No->setLeft(*depois);
            depois->setAbove(*No);}
            if( 0!=Temp.size())
            depois = Parse(Temp);
            No->setRight(*depois);
            depois->setAbove(*No);
            break ;    }
    if(string::npos != str.find(TOKEN[MULT])){
            pos =str.find(TOKEN[MULT]);
            Temp = str.substr (pos+1,str.size());
            Temp2 = str.substr (0,pos);
            No = new Node(TERM);
            depois = new Node(MULT);
            No->setCenter(*depois);
            if( 0!=Temp2.size()){
            depois = Parse(Temp2);
            No->setLeft(*depois);
            depois->setAbove(*No);}
            if( 0!=Temp.size())
            depois = Parse(Temp);
            No->setRight(*depois);
            depois->setAbove(*No);
            break ;
    }
     if(string::npos != str.find(TOKEN[DIVIDE])){
            pos =str.find(TOKEN[DIVIDE]);
            Temp = str.substr (pos+1,str.size());
            Temp2 = str.substr (0,pos);
            No = new Node(TERM);
            depois = new Node(DIVIDE);
            No->setCenter(*depois);
            if( 0!=Temp2.size()){
            depois = Parse(Temp2);
            No->setLeft(*depois);
            depois->setAbove(*No);}
            if( 0!=Temp.size())
            depois = Parse(Temp);
            No->setRight(*depois);
            depois->setAbove(*No);
            break ;
    }

    if(isalpha(str.at(0))){
        pos =str.find_first_of("() =:;");
        No = new Node(NAME);
        No->setName(str.substr (0,pos));
        try{
        Temp = str.substr(pos,str.size());
        }catch(exception& e){

        }
        if(( 0!=Temp.size())&&( pos > 0)){
        depois = Parse(Temp);
        No->setRight(*depois);
        depois->setAbove(*No);}
        break;
    }
    if(str.find_first_of("0123456789.,") != string::npos){
        Temp = str.substr(str.find_first_of("0123456789.,"),str.find_first_not_of("0123456789.,"));
        try{
        Temp2 = str.substr (str.find_first_not_of("0123456789.,"),str.size());
        }
        catch(exception& e){

        }
        No = new Node(NUMBER);
        stm.str(Temp);
        stm >>d;
        No->setValue(d);
        if( 0!=Temp2.size()){
        depois = Parse(Temp2);
        No->setRight(*depois);
        depois->setAbove(*No);}
    //    temp = *No->getRight();
    //    temp2 = *depois;
        break;
    }
    if(string::npos != str.find(TOKEN[PRINT])){
        controlens::Control::getInstance()->enablePrint();
        No = new Node(PRINT);
    break;
    }
    else
    No = new Node(ILEGIVEL);
    break;
    }
//temp = *No;

return No;
}

Node::~Node(){
//delete this.Center;
//delete this.Left;
//delete this.Right;
}
