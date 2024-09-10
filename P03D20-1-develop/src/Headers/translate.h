#ifndef TRANSLATE_H_
#define TRANSLATE_H_

#include "stack.h"
#include "type.h"

int precedence(char* op);
void infixToRPN(char* infix, char rpn[MAX_EXPR_SIZE][MAX_EXPR_SIZE], int* rpnLength);
void tokenize(const char* infix, char tokens[MAX_EXPR_SIZE][MAX_EXPR_SIZE], int* tokenCount);

#endif