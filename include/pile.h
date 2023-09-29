#ifndef  PILE_H
#define PILE_H
#define NB 20
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct  PileDyn
{
    int nb;
    struct PileDynelement* next;
}PileDynelement, *PileDyn;

PileDyn initializePile(void);
PileDyn stack(int nb,PileDyn ppile);
void printPile(PileDyn ppile);
PileDyn depile(PileDyn ppile, int* pvalue);


#endif
