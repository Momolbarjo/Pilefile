#ifndef  PILE_H
#define PILE_H
#define NB 20
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct  DynStackElement
{
    int nb;
    struct DynStackElement* next;
}DynStackElement, *DynStack;

DynStack initializeStack(void);
DynStack stack(int nb,DynStack sstack);
void printStack(DynStack sstack);
DynStack destack(DynStack sstack, int* pvalue);


#endif
