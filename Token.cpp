/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include "Token.h"
#include <stdlib.h>
#include <string.h>
#include <typeinfo>

Token::Token() {
	//What code do I need here to initialize everything.
	setLeftChild(NULL);
	setRightChild(NULL);
	list = NULL;
}
Token::~Token() {
	//What code do I need here to free memory
	LineNumberList *root = getLineNumberList();
	LineNumberList *tmp = root;
	string s;
	Literal* vtmp;

	while (root != NULL) {
		tmp = tmp->getNextLineNumber();
		delete root;
		root = tmp;
	}

	s = typeid(this->getType()).name();  //`
	//s = typeid(this->type->getType()).name();  //`
	//s = typeid(*this->getType()).name(); //`
	//s = typeid((*(this->getType())).getType()).name();  //`
	//`vtmp = this->getType();
	//vtmp = (this->getType()&);

	//if (s.compare("14IntegerLiteral") == 0)
	if (s.compare("StringLiteral") == 0) {
		free(this->literal.stringLiteral);
	}
}
void Token::setCode(TokenCode newCode) {
	this->code = newCode;
}
TokenCode Token::getCode() {
	return this->code;
}
void Token::setType(Literal* newType) {

	this->type = newType;

}
Literal* Token::getType() {
	return this->type;
}
void Token::setLiteral(int newInteger) {
	this->literal.integer = newInteger;
}
int Token::getIntLiteral() {
	return this->literal.integer;
}
void Token::setLiteral(float newReal) {
	this->literal.real = newReal;
}
float Token::getRealLiteral() {
	return this->literal.real;
}
void Token::setLiteral(string newString) {
	this->literal.stringLiteral = (char*) malloc(
			sizeof(char) * newString.length() + 1);
	strcpy(this->literal.stringLiteral, newString.c_str());
}
string Token::getStringLiteral() {
	return string(this->literal.stringLiteral);
}
void Token::setTokenString(string s) {
	this->tokenString = s;
}
string Token::getTokenString() {
	return this->tokenString;
}
//What methods am I missing to implement a binary tree.
void Token::setLeftChild(Token *tok) {
	this->leftChild = tok;
}
Token *Token::getLeftChild() {
	return this->leftChild;
}
void Token::setRightChild(Token *tok) {
	this->rightChild = tok;
}
Token *Token::getRightChild() {
	return this->rightChild;
}
void Token::addToLineNumberList(LineNumberList *listItem) {
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
LineNumberList *Token::getLineNumberList() {
	return this->list;
}
