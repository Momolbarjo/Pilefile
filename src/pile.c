#include <stdio.h>
#include "pile.h"


DynStack initializeStack(void)
{

	return NULL;
}

DynStack stack(int value,DynStack sstack)
{

    
    DynStackElement *element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Error of memory allocation\n");
        exit(1);

    }

    element->nb = value;
    element->next = sstack;

    return element;
}	

void printStack(DynStack sstack) {
    if(sstack== NULL)
    {
        return;
    }

    printf("%d\n",sstack->nb);
    printStack(sstack->next);

}	

DynStack destack(DynStack sstack, int* pvalue)
{
    if(sstack== NULL)
    {
        *pvalue=0;
        return NULL;
    }

    DynStack tmp =sstack;
    *pvalue = tmp->nb;
    sstack = sstack->next;

    free(tmp);
    return sstack;
}


void initializeStaticStack(StaticStack* stack){

    stack->head =-1;
}

bool isStackEmpty(StaticStack* stack) {

    return stack->head == -1;
}

int pop(StaticStack* stack){
    if(!isStackEmpty(stack)){
        return stack->items[stack->head--];
    }
    else{
        printf("The stack is empty");
        return -1;
    }
}

StaticStack* push( StaticStack *stack, int item){

    if(stack->head < NB -1){
        stack->items[++stack->head] = item;
    }
    else{
        printf("There is no more place in the stack");
    }
    return stack;
}

void printStaticStack(StaticStack *stack){
    for(int i=0;i <=stack->head;i++){
        printf("%d",stack->items[i]);
        printf("\n");
    }
    printf("\n");
}
