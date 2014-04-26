/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef __Lab5__Token__
#define __Lab5__Token__

#include <iostream>
#include "common.h"
#include "LineNumberList.h"
#include "Literal.h"

using namespace std;

/**************
 this is a valid Pascal token.  A token must have a literal type,
 a literal value, and a token code.
 ***************/
class Token {
private:
	TokenCode code;
	Literal* type;
	union {
		int integer;
		float real;
		char *stringLiteral;
	} literal;
	string tokenString;
	//What variables and methods am I missing to implement a binary tree.
	Token *leftChild;
	Token *rightChild;
	LineNumberList *list;

public:
	Token();
	~Token();
	void setCode(TokenCode newCode);
	TokenCode getCode();

	void setType(Literal* newType);
	Literal* getType();

	void setLiteral(int newInteger);
	int getIntLiteral();
	void setLiteral(float newReal);
	float getRealLiteral();
	void setLiteral(string newString);
	string getStringLiteral();
	void setTokenString(string s);
	string getTokenString();
	void setLeftChild(Token *tok);
	Token *getLeftChild();
	void setRightChild(Token *tok);
	Token *getRightChild();
	void addToLineNumberList(LineNumberList *listItem);
	LineNumberList *getLineNumberList();
};

#endif /* defined(__Lab5__Token__) */
