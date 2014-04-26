/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef StringLiteral_H
#define StringLiteral_H

#include "Literal.h" // Literal class definitionclass StringLiteral: public Literal {
public:

	StringLiteral(const string pType);

	virtual string getType();

private:

	string aString;

};
// end class StringLiteral

#endif // StringLiteral_H
