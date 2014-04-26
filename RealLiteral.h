/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef RealLiteral_H
#define RealLiteral_H

#include "Literal.h" // Literal class definition#include <sstream>class RealLiteral: public Literal {
public:

	RealLiteral(const double pDouble);

	virtual string getType();

private:
	string convertToString(double pDouble);

	double aDouble;

};
// end class RealLiteral

#endif // RealLiteral_H
