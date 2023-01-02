#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lexical Analysis.c"

// define the Node structure for the syntax tree
typedef struct Node
{
  char token[100];
  struct Node *leftChild;
  struct Node *rightChild;
} Node;

// define the parser function that checks for syntax errors in an array of tokens
void parser(Token tokens_list[])
{
  // check if the first token has a type of 2 and the second token is not an equal sign
  if (tokens_list[0].type == 2 && (int)tokens_list[1].value[0] != 61)
  {
    // print an error message and return if the above condition is not met
    printf("Syntax Error1 \n");
    return;
  }

  // check if the third token has a type of 0
  if (tokens_list[2].type != 0)
  {
    // print an error message and return if the above condition is not met
    printf("Syntax Error 2 \n");
    return;
  }
   
  // iterate through the tokens starting from the third token
  for (int i = 3; i < tokenCount - 1; i++)
  {
     // check if the current token has a type of 0 and the next token has a type of 1, 
     // or if the current token has a type of 1 and the next token has a type of 0
    if (tokens_list[i].type == 0 && tokens_list[i + 1].type != 1)
    {
      // print an error message and return if the above condition is not met
      printf("Syntax Error 3 \n");
      return;
    }
    else if (tokens_list[i].type == 1 && tokens_list[i + 1].type != 0)
    {
      // print an error message and return if the above condition is not met
      printf("Syntax Error 4 \n");
      return;
    }
  }
  // check if the last token has a type of 0
  if (tokens_list[tokenCount - 1].type != 0)
  {
    // print an error message and return if the above condition is not met
    printf("Syntax Error 5 \n");
    return;
  }
}
