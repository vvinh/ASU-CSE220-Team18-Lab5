/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <string> // C++ standard string class#include "Token.h" // Token class declaration
#include <iostream>
#include "common.h"
#include "LineNumberList.h"
#include "Literal.h"

using namespace std;



class Identifier: public Token {


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
	Identifier *leftChild;
	Identifier *rightChild;
	LineNumberList *list;

public:

	Identifier();
	~Identifier();

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
	void setLeftChild(Identifier *tok);
	Identifier *getLeftChild();
	void setRightChild(Identifier *tok);
	Identifier *getRightChild();
	void addToLineNumberList(LineNumberList *listItem);
	LineNumberList *getLineNumberList();

};
// end class Identifier

#endif

