/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef LITERAL_H
#define LITERAL_H

#include <string>
using namespace std;

class Literal {
public:
	Literal();

	virtual string getType() = 0; // pure virtual

private:

};
// end class Literal

#endif // LITERAL_H
