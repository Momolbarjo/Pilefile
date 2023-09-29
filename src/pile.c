#include <stdio.h>
#include "pile.h"


PileDyn initializePile(void)
{

	return NULL;
}

PileDyn stack(int value,PileDyn ppile)
{

    
    PileDynelement *element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Error of memory allocation\n");
        exit(1);

    }

    element->nb = value;
    element->next = ppile;

    return element;
}	

void printPile(PileDyn ppile) {
    PileDynElement* current = ppile;

    printf("Contenu de la pile :\n");
    while (current != NULL) {
        printf("%d\n", current->nb);
        current = current->next;
    }
}	
