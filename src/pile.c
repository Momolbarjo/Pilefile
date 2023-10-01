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
        printf("The stack is empty\n");
        return -1;
    }
}

StaticStack* push( StaticStack *stack, int item){

    if(stack->head < NB -1){
        stack->items[++stack->head] = item;
    }
    else{
        printf("There is no more place in the stack\n");
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


bool isQueueEmpty(void){
    if(last == NULL && first == NULL){
        return true;
    }
    return false;
}

int Queue_length(void){
    return NbQueueElems;
}

int Queue_first(void){
    if(isQueueEmpty()){
        exit(1);
    }
    return first->data;
}

int Queue_last(void){
    if(isQueueEmpty()){
        exit(1);
    }
    return last->data;
}

void print_Queue(void){
    if(isQueueEmpty()){
        printf("The Queue is empty\n");
        return;
    }
    QueueElement* tmp=first;
    
    while(tmp != NULL){
        printf("%d", tmp->data);
        tmp=tmp->next;
    }
    printf("\n");
}

void Enqueue(int x){
   QueueElement* element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Error of memory allocation\n");
        exit(1);

    }

    element->data = x;
    element->next = NULL;

    if(isQueueEmpty()){
        first = element;
        last = element;
    }
    else{
        last->next = element;
        last = element;
    }
        NbQueueElems++;
}

void Dequeue(void){
    if(isQueueEmpty()){
        printf("The Queue is empty\n");
        return;
    }

    QueueElement* tmp = first;

    if(first == last){
        first = NULL;
        last = NULL;
    }
    else{
        first = first->next;
    }
    free(tmp);
    NbQueueElems--;
}

void clear_Queue(void){
    if(isQueueEmpty()){
        printf("The Queue is empty\n");
        return;
    }
    while(!isQueueEmpty()){
        Dequeue();
    }

}
