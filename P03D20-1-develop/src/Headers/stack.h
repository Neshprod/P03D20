#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef struct {
    double items[MAX_STACK_SIZE];
    int top;
} Stack;

typedef struct {
    char items[MAX_STACK_SIZE][MAX_EXPR_SIZE];
    int top;
} StringStack;

// Экземпляры функций
void push(Stack *stack, double value);
double pop(Stack *stack);
void pushString(StringStack *stack, char *value);
char *popString(StringStack *stack);

#endif