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
#include "Identifier.h"

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
	void printToken(Identifier *token);
	int getLineCount();
	void printTree(Identifier *identifier);
	void printTreeRecursive(Identifier *identifier);
};

#endif /* defined(__Lab5__Print__) */
