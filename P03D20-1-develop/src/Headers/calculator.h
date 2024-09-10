#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "type.h"

double evaluateRPN(char rpn[MAX_EXPR_SIZE][MAX_EXPR_SIZE], int rpnLength, double x);

#endif