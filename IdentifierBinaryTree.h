/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef __Lab5__IdentifierBinaryTree__
#define __Lab5__IdentifierBinaryTree__

#include <iostream>
#include "Identifier.h"

class IdentifierBinaryTree {
	Identifier *treeRoot;

	void depthFirstDeleteTree(Identifier *tok);

public:

	IdentifierBinaryTree();
	~IdentifierBinaryTree();
	void setTreeRoot(Identifier *root);
	Identifier *getTreeRoot();
	bool addIdentifier(Identifier *tok, int lineNum);

};

#endif /* defined(__Lab5__IdentifierBinaryTree__) */
