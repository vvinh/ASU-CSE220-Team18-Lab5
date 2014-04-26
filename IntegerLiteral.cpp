/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include <iostream>
#include "IntegerLiteral.h" // IntegerLiteral class definition
using namespace std;

// constructor 
IntegerLiteral::IntegerLiteral(const int pInt) :
		Literal() {
	anInteger = pInt;
} // end IntegerLiteral constructor

string IntegerLiteral::convertToString(int anInteger) {

	stringstream ss;
	ss << anInteger;
	return ss.str();

}

string IntegerLiteral::getType() {

	return convertToString(anInteger);
} // end function earnings

