/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"
#include "IdentifierBinaryTree.h"
#include "Identifier.h"

FILE *init_lister(const char *name, char source_file_name[], char dte[]);

int main(int argc, const char * argv[]) {
	Identifier *token = NULL;

	char source_name[MAX_FILE_NAME_LENGTH];
	char date[DATE_STRING_LENGTH];
	FILE *source_file = init_lister(argv[1], source_name, date);
	Print print(source_name, date);
	Scanner scanner(source_file, source_name, date, print);
	IdentifierBinaryTree tree;

	do {
		token = scanner.getToken();

		print.printToken(token);
		if (token->getCode() == IDENTIFIER) {
			tree.addIdentifier((Identifier*) token, scanner.getLineNumber()); //`
		} else if (token->getCode() != PERIOD
				&& token->getCode() != END_OF_FILE) {
			delete token;
		}
	} while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);

	print.printTree(tree.getTreeRoot());
	delete token;
	fclose(source_file);
	return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[]) {
	time_t timer;
	FILE *file;

	strcpy(source_file_name, name);
	file = fopen(source_file_name, "r");
	time(&timer);
	strcpy(dte, asctime(localtime(&timer)));
	return file;
}

