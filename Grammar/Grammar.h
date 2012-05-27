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
        DIVIDE,          // /
        MINUS, // -
        PROGRAM, //-
        EXPR_LIST, //-
        PRIMARY, //-
        NAME, //-
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
		Token Type ;
		string Name ;
		int Ivalue ;
		double Value;
	public :
		Node();
		Node(Token type);
		Node getRight();
		void setRight(Node right);
		Node getLeft();
		void setLeft(Node left);
		Node getAbove();
		void setAbove(Node above);
        Node getIvalue();
		void setIvalue(Node above);
		Node getValue();
		void setValue(Node above);
		Node getCenter();
		void setCenter(Node center);
		std::string getName();
		void setCenter(std::string name);
		Token getType();
		void setType(Token type);
		static Node Parse(std::string frase);
 };
}
#endif

