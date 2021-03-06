/********************************************
 *
 * CSE220 LS 12166 Lab5 - Team18
 * Nicholas Murray
 * Vivian Vinh
 * Timothy Zamora
 *
 **********************************************/

#ifndef Lab5_Scanner_h
#define Lab5_Scanner_h

#include "common.h"
#include "Token.h"
#include "Print.h"
#include "Identifier.h"

#define CHAR_TABLE_SIZE 256

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE,
}
CharCode;

class Scanner
{
private:
    /*********************
     Private Variables for Scanner
     Must be initialized in the constructor.
     *********************/
    Print print;
    FILE *src_file;
    char src_name[MAX_FILE_NAME_LENGTH];
    char todays_date[DATE_STRING_LENGTH];
    CharCode char_table[CHAR_TABLE_SIZE];  // The character table
    char source_line[MAX_SOURCE_LINE_LENGTH];
    char *line_ptr = NULL;
    int line_number;
    
    bool getSourceLine(char source_buffer[]);
    char getChar(char source_buffer[]);
    void skipBlanks(char source_buffer[]);
    void skipComment(char source_buffer[]);
    void getWord(char *str, char *token_ptr, Identifier *tok);
    void getNumber(char *str, char *token_ptr, Identifier *tok);
    void getString(char *str, char *token_ptr, Identifier *tok);
    void getSpecial(char *str, char *token_ptr, Identifier *tok);
    void downshiftWord(char word[]);
    bool isReservedWord(char *str, Identifier *tok);
    
public:
    Scanner(FILE *source_file, char source_name[], char date[], Print printer);
    ~Scanner();
    Identifier* getToken();
    int getLineNumber();

};

#endif
