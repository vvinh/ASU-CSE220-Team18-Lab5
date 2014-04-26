/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include <iostream>
#include "Identifier.h"
#include <stdlib.h>
#include <string.h>
#include <typeinfo>

using namespace std;

// constructor
Identifier::Identifier()
// explicitly call base-class constructor
:
		Token() {

	//What code do I need here to initialize everything.
	setLeftChild(NULL);
	setRightChild(NULL);
	list = NULL;

} // end Identifier constructor

Identifier::~Identifier() {
	//What code do I need here to free memory
	LineNumberList *root = getLineNumberList();
	LineNumberList *tmp = root;
	string s;

	while (root != NULL) {
		tmp = tmp->getNextLineNumber();
		delete root;
		root = tmp;
	}

	s = typeid(this->getType()).name();

	if (s.compare("StringLiteral") == 0) {
		free(this->literal.stringLiteral);
	}
}

void Identifier::setCode(TokenCode newCode) {
	this->code = newCode;
}
TokenCode Identifier::getCode() {
	return this->code;
}
void Identifier::setType(Literal* newType) {

	this->type = newType;

}
Literal* Identifier::getType() {
	return this->type;
}
void Identifier::setLiteral(int newInteger) {
	this->literal.integer = newInteger;
}
int Identifier::getIntLiteral() {
	return this->literal.integer;
}
void Identifier::setLiteral(float newReal) {
	this->literal.real = newReal;
}
float Identifier::getRealLiteral() {
	return this->literal.real;
}
void Identifier::setLiteral(string newString) {
	this->literal.stringLiteral = (char*) malloc(
			sizeof(char) * newString.length() + 1);
	strcpy(this->literal.stringLiteral, newString.c_str());
}
string Identifier::getStringLiteral() {
	return string(this->literal.stringLiteral);
}
void Identifier::setTokenString(string s) {
	this->tokenString = s;
}
string Identifier::getTokenString() {
	return this->tokenString;
}
//What methods am I missing to implement a binary tree.
void Identifier::setLeftChild(Identifier *tok) {
	this->leftChild = tok;
}
Identifier *Identifier::getLeftChild() {
	return this->leftChild;
}
void Identifier::setRightChild(Identifier *tok) {
	this->rightChild = tok;
}
Identifier *Identifier::getRightChild() {
	return this->rightChild;
}
void Identifier::addToLineNumberList(LineNumberList *listItem) {
	LineNumberList *tmp = getLineNumberList();

	if (tmp == NULL) {
		list = listItem;
	} else {
		while (tmp->getNextLineNumber() != NULL) {
			tmp = tmp->getNextLineNumber();
		}
		tmp->setNextLineNumber(listItem);
	}
}
LineNumberList *Identifier::getLineNumberList() {
	return this->list;
}
