#ifndef DEC_TO_BIN_H
#define DEC_TO_BIN_H

#include "inc/stack.h"

Stack* binaryStack(unsigned int n);
char* stackToString(Stack* s);
char* decToBin(unsigned int n);

#endif