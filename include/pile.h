#ifndef  PILE_H
#define PILE_H
#define NB 20
#define SIZE 30
#define MAX_ITEMS 35
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct  DynStackElement
{
    int nb;
    struct DynStackElement* next;
}DynStackElement, *DynStack;

typedef struct  DynStackletter
{
    char phrase;
    struct DynStackletter* next;
}DynStackletter, *DynStackSentence;

typedef struct {

    int items[NB];
    int head;
} StaticStack;

typedef struct QueueElement {
    int data;
    struct QueueElement* next;
} QueueElement, *DynQueue;

typedef struct {
    DynQueue head;
    DynQueue tail;
    int length;
} Queue;



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
void initializeQueue(Queue* queue);
bool isQueueEmpty(Queue* queue);
int getQueueLength(Queue* queue);
void enqueue(Queue* queue, int x);
int dequeue(Queue* queue);
void clearQueue(Queue* queue);
void printQueue(Queue* queue);
DynStackSentence initializeSentence(void);
DynStackSentence stackSentence(char letter , DynStackSentence sentence);
bool isSentenceEmpty(DynStackSentence sentence);
DynStackSentence destackSen(DynStackSentence sentence);
void isSetenceCorrect(char sentence[SIZE]);




#endif
