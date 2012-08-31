#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <string>

//#define NULL 0
namespace grammar
{
using namespace std;
enum Token {
        EQUAL,
        PRINT, // ;
        MULT, // *
        PLUS, // +
        DIVIDE, // /
        MINUS, // -
        LPARAM, //(
        RPARAM, //)
        NUMBER,
        PROGRAM, //-
        EXPR_LIST, //-
        TERM,
        PRIMARY, //-
        NAME, //-
        EXPRESSION,
        NULLT,
        END, //
        ILEGIVEL
};
const string TOKEN[15]={
		"=",
		";",
		"*",
		"+",
		"/",
		"-",
		"(",
		")",
		"",
		"",
		"",
		"",
		"",
		"",
		"\n"
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
            ~Node();
            Node(Token type);
            Node* getRight();
            void setRight(Node &right);
            Node* getLeft();
            void setLeft(Node &left);
            Node* getAbove();
            void setAbove(Node &above);
            int getIvalue();
            void setIvalue(Node &above);
            double getValue();
            void setValue(double above);
            Node* getCenter();
            void setCenter(Node &center);
            std::string getName();
            void setName(std::string name);
            Token getType();
            void setType(Token type);
            static Node* Parse(std::string frase);
};
}
#endif

