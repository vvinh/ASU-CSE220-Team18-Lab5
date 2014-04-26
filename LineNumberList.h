/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef __Lab5__LineNumberList__
#define __Lab5__LineNumberList__

#include <iostream>

class LineNumberList
{
    int lineNumber;
    LineNumberList *nextLineNumber;
    
public:
    LineNumberList();
    ~LineNumberList();
    void setLineNumber(int num);
    int getLineNumber();
    void setNextLineNumber(LineNumberList *next);
    LineNumberList *getNextLineNumber();
};

#endif /* defined(__Lab5__LineNumberList__) */
