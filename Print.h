/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef __Lab5__Print__
#define __Lab5__Print__
#include <iostream>
#include "common.h"
#include "Token.h"

using namespace std;

class Print {
private:
	string sourceFileName;
	string currentDate;
	int pageNumber;
	int lineCount;

	void printPageHeader();

public:
	Print(char source_name[], char date[]);
	~Print();

	void printLine(char line[]);
	void printToken(Token *token);
	int getLineCount();
	void printTree(Token *identifier);
	void printTreeRecursive(Token *identifier);
};

#endif /* defined(__Lab5__Print__) */
