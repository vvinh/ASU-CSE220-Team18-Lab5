/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include "IdentifierBinaryTree.h"
#include "LineNumberList.h"

using namespace std;

IdentifierBinaryTree::IdentifierBinaryTree() {
	setTreeRoot(NULL);
}
IdentifierBinaryTree::~IdentifierBinaryTree() {
	Identifier *root = getTreeRoot();

	if (root != NULL) {
		depthFirstDeleteTree(root);
	}
}
void IdentifierBinaryTree::depthFirstDeleteTree(Identifier *tok) {
	if (tok->getLeftChild() != NULL) {
		depthFirstDeleteTree((Identifier *) tok->getLeftChild());  //`
	}

	if (tok->getRightChild() != NULL) {
		depthFirstDeleteTree((Identifier *) tok->getRightChild());
	}
	delete tok;
}

void IdentifierBinaryTree::setTreeRoot(Identifier *root) {
	this->treeRoot = root;
}

Identifier *IdentifierBinaryTree::getTreeRoot() {
	return this->treeRoot;
}

bool IdentifierBinaryTree::addIdentifier(Identifier *tok, int lineNum) {
	bool success = false;
	LineNumberList *listItem = new LineNumberList();

	listItem->setLineNumber(lineNum);
	if (getTreeRoot() == NULL) {
		setTreeRoot(tok);
		tok->addToLineNumberList(listItem);
		success = true;
	} else {
		string tokenName = tok->getTokenString();
		Identifier *parentNode = getTreeRoot();
		string treeNodeName;
		int stringComparison;

		while (parentNode != NULL) {
			treeNodeName = parentNode->getTokenString();
			stringComparison = tokenName.compare(treeNodeName);
			if (stringComparison == 0) {
				//They are the same identifier token we just need to add a new line number to the list.
				parentNode->addToLineNumberList(listItem);
				parentNode = NULL; //Exit the loop
				delete tok; //We won't need tok and it won't be deleted in main.
				success = true;
			} else if (stringComparison < 0) {
				//Go to the left.
				if (parentNode->getLeftChild() == NULL) {
					//Add tok to the left
					tok->addToLineNumberList(listItem);
					parentNode->setLeftChild(tok);
					parentNode = NULL;
					success = true;
				} else {
					parentNode = (Identifier *) parentNode->getLeftChild(); //`

				}
			} else {
				//Go to the right.
				if (parentNode->getRightChild() == NULL) {
					//Add tok to the right
					tok->addToLineNumberList(listItem);
					parentNode->setRightChild(tok);
					parentNode = NULL;
					success = true;
				} else {
					parentNode = (Identifier *) parentNode->getRightChild(); //`
				}
			}
		}
	}
	return success;
}
