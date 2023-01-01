#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100  // maximum number of tokens that can be stored
#define MAX_TOKEN_LENGTH 100    // maximum length of a single token

// enum to represent the types of tokens
enum TokenType
{
    CONSTANT,  // type 0: a constant (number)
    OPERATOR,  // type 1: an operator (+, -, *, /, =)
    IDENTIFIER,// type 2: an identifier (alphabetic string)
    OTHER      // type 3: any other character
};

// struct to represent a single token
typedef struct
{
    int C_LENGTH;   // length of the token's value
    enum TokenType type;    // the type of the token
    char value[MAX_TOKEN_LENGTH];   // the value of the token
} Token;

// Array to store the tokens
Token tokens[MAX_TOKENS];

// function to perform lexical analysis on the input string
void lex(char* input)
{
    int inputLength = strlen(input);     // length of the input string
    int tokenCount = 0; // number of tokens found so far



    int currentTokenLength = 0; // length of the current token

    // loop through the input character by character
    for (int i = 0; i < inputLength; i++)
    {
        char currentChar = input[i];    // current character being processed


        // if the current character is a digit, add it to the current token
        if (isdigit(currentChar))
        {
            // if the previous token was also a digit, append the current character to it
            if(isdigit(tokens[tokenCount-1].value[0]) )
            {
                tokens[tokenCount-1].value[tokens[tokenCount-1].C_LENGTH]=currentChar;
                tokens[tokenCount-1].C_LENGTH+=1;
            }
            // otherwise, create a new constant token with the current character
            else
            {

                Token newToken;
                newToken.C_LENGTH = 1;
                newToken.type = CONSTANT;
                memset(newToken.value, 0, MAX_TOKEN_LENGTH);    // reset the value array
                newToken.value[currentTokenLength] = currentChar;
                tokens[tokenCount] = newToken;
                tokenCount++;

            }



        }
        // if the current character is an alphabetical character, add it to the current token
        else if (isalpha(currentChar))
        {
            // if the previous token was also an alphabetical character, append the current character to it
            if(isalpha(tokens[tokenCount-1].value[0]) )
            {
                tokens[tokenCount-1].value[tokens[tokenCount-1].C_LENGTH]=currentChar;
                tokens[tokenCount-1].C_LENGTH+=1;
            }
            // otherwise, create a new identifier token with the current character
            else
            {

                Token newToken;
                newToken.C_LENGTH = 1;
                newToken.type = IDENTIFIER;
                memset(newToken.value, 0, MAX_TOKEN_LENGTH);    // reset the value array
                newToken.value[currentTokenLength] = currentChar;
                tokens[tokenCount] = newToken;
                tokenCount++;

            }
        }
        // if the current character is an operator (+, -, *, /, =), create a new operator token with it
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '=')
        {
            Token newToken;
            newToken.C_LENGTH = 1;
            newToken.type = OPERATOR;
            memset(newToken.value, 0, MAX_TOKEN_LENGTH);     // reset the value array
            newToken.value[currentTokenLength] = currentChar;
            tokens[tokenCount] = newToken;
            tokenCount++;

        }
        // if the current character is none of the above, create a new "other" token with it
        else
        {

            Token newToken;
            newToken.C_LENGTH = 1;
            newToken.type = OTHER;
            memset(newToken.value, 0, MAX_TOKEN_LENGTH);    // reset the value array
            newToken.value[currentTokenLength] = currentChar;
            tokens[tokenCount] = newToken;
            tokenCount++;
        }
    }
}