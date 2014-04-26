/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include <iostream>
#include "RealLiteral.h" // RealLiteral class definitionusing namespace std;

// constructor 
RealLiteral::RealLiteral(const double pDouble) :
		Literal() {
	aDouble = pDouble;
} // end RealLiteral constructor

string RealLiteral::convertToString(double pDouble) {

	stringstream ss;
	ss << pDouble;
	return ss.str();

}

string RealLiteral::getType() {

	return convertToString(aDouble);
} // end function earnings

