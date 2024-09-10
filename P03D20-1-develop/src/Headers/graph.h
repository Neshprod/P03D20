#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

#include "calculator.h"
#include "stack.h"

#define WIDTH 80
#define HEIGHT 25
//#define M_PI 3.14159265358979323846

void drawGraph(char rpn[MAX_EXPR_SIZE][MAX_EXPR_SIZE], int rpnLength);

#endif