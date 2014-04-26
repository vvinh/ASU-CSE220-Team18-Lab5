/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef IntegerLiteral_H
#define IntegerLiteral_H

#include "Literal.h" // Literal class definition#include <sstream>
class IntegerLiteral: public Literal {
public:

	IntegerLiteral(const int pInt);
	virtual string getType(); // pure virtual

private:
	string convertToString(int anInteger);
	int anInteger;

};
// end class IntegerLiteral

#endif // IntegerLiteral_H
