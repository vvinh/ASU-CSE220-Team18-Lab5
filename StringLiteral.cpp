/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include <iostream>
#include "StringLiteral.h" // StringLiteral class definition
using namespace std;

// constructor 
StringLiteral::StringLiteral(const string pString) :
		Literal() {
	aString = pString;
} // end StringLiteral constructor

string StringLiteral::getType() {

	return aString;
} // end function earnings

