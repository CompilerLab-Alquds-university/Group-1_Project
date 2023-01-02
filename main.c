#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include "Lexical Analysis.c"
#include "Syntax Analysis.c"

int main()
{
    // Input string
    char input[] = "var=100+5*3";
    
   
    // perform lexical analysis on the input string
    lex(input);
    // perform Syntax analysis on the tokens
    parser(tokens);

    // Print the tokens
    for (int i = 0; i < MAX_TOKENS; i++)
    {
        // If the current token is empty, stop the loop
        if (tokens[i].value[0] == '\0')
        {
            break;
        }

        // Print the type and value of the current token
        printf("TOKEN: %d, %s\n", tokens[i].type, tokens[i].value);
       
    }

    return 0;
}
