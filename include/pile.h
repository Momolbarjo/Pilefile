#ifndef  PILE_H
#define PILE_H
#define NB 20
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct  DynStackElement
{
    int nb;
    struct DynStackElement* next;
}DynStackElement, *DynStack;

typedef struct {

    int items[NB];
    int head;
} StaticStack;

DynStack initializeStack(void);
DynStack stack(int nb,DynStack sstack);
void printStack(DynStack sstack);
void initializeStaticStack(StaticStack* stack);
DynStack destack(DynStack sstack, int* pvalue);
bool isStackEmpty(StaticStack* stack);
int pop(StaticStack* stack);
void initializeStaticStack(StaticStack* stack);
StaticStack* push( StaticStack *stack, int item);
void printStaticStack(StaticStack *stack);

#endif
