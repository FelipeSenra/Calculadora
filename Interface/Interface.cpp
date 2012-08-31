#include <string>
#include <iostream>
#include <vector>
#include "Interface.h"
 #include "../Control/Control.h"
using namespace interface;
using namespace grammar;
Interface::Interface(): texto(1){
 i = 0;
 it = texto.begin();
}

void Interface::MakeTitle(){
    std::cout<<"-------------------Calculadora de terminal------------------\n";
    std::cout<<"| Trabalho 2: Calculadora de Termical                      |\n";
    std::cout<<"| Alunos: Felipe Senra Ribeiro                             |\n";
    std::cout<<"|         Luiz Gomes Ribeiro Neto                          |\n";
    std::cout<<"|         Nelson de Melo Guimarães Junior                  |\n";
    std::cout<<"|         Thays Cristina Farias Vercoza Costa              |\n";
    std::cout<<"| Comandos:                                                |\n";
    std::cout<<"| exit - sair do Programa                                  |\n";
    std::cout<<"| help - ajuda do Programa                                 |\n";
    std::cout<<"------------------------------------------------------------\n";
}
string Interface::getString(){
    i++;
    return texto[i-1] ;
}

void Interface::readConsole(){
    std::string frase,temp ;
    int pos;
    cout<< ">>";
    getline( std::cin,frase, '\n' );
    do{
        pos = frase.find(";");
        if(pos == -1)
        {
        texto.push_back(frase);
        break;
        }
        temp = frase.substr(0,pos+1);
        texto.push_back(temp);
        frase = frase.substr(pos+1,frase.size());
    }while((frase.size() != 0)&&(pos != -1));

}
void Interface::printTree(Node *no)
{
    Node temp =*no;
    cout<< "No --------"<< std::endl;
    if(no->getName().size() != 0)
        cout<< "No : "+no->getName()<< std::endl;
    if(no->getType() != NULLT)
        cout<< " Tipo : "+no->getType()<< std::endl;
    if(no->getAbove() != NULL)
        cout<< "Pai : "+no->getAbove()->getName()<< std::endl;
    if(no->getCenter() != NULL)
        Interface::printTree(no->getCenter());
    if(no->getRight() != NULL)
        Interface::printTree(no->getRight());
    if(no->getLeft() != NULL)
        Interface::printTree(no->getLeft());
}

void Interface::increment(){
    i++;
}

int Interface::getindex(){
    return i;
}

int Interface::getsize(){
    return texto.size();
}
/**
Plota a ajuda do programa
*/
void Interface::PlotHelp(){
    std::cout<<" Ajuda do programa                                           \n";
    std::cout<<" Variaveis : Nomes e Numeros                                 \n";
    std::cout<<" Operadores: +-\\*                                           \n";
    std::cout<<" Parenteses: Aop(BopC)opD e ((...)op())                      \n";

}
/**
Plota o resultado
*/
void Interface::plot(std::string result){
   std::cout << result;
}
