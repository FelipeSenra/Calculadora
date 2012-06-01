#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <string>
namespace grammar
{
using namespace std; 
enum Token {
		EQUAL,
		PRINT, // ;
            	NUMBER,
                MULT,    // *
                PLUS,     // +
                DIV,          // /
                MINUS, //-
		END      // 
};

const string TOKEN[10]={
		"="
		";",
		"",
		"*",
		"+",
		"/",
		"-"
};

class Node
{
	private :
		Node *Left ;
		Node *Right;
		Node *Center;
		Node *Above;
		string Type ;
		string Name ;
		int Ivalue ;
		double Value;
	public :
		Node();
		Node(string type);
		Node getRight();
		void setRight(Node right);
		Node getLeft();
		void setLeft(Node left);
		Node getAbove();
		void setAbove(Node above);

		Node getCenter();
		void setCenter(Node center);
		std::string getType();
		void setType(std::string type);
		static Node Parse(std::string frase);
 };
}
#endif
 
