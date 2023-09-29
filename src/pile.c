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
