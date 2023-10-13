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


void initializeQueue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->length=0;
    
}

bool isQueueEmpty(Queue* queue) {
    return queue->head == NULL;
}

int getQueueLength(Queue* queue) {
    return queue->length;
}

void enqueue(Queue* queue, int x) {
    DynQueue element = malloc(sizeof(DynQueue));
    if (element == NULL) {
        fprintf(stderr, "Error of memory allocation\n");
        exit(1);
    }
    element->data = x;
    element->next = NULL;

    if (isQueueEmpty(queue)) {
       queue->head = element;
    } else {
        queue->tail->next = element;
    }
    queue->tail = element;
    queue->length++;
    
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        fprintf(stderr, "The Queue is empty\n");
        exit(1);
    }
    DynQueue tmp = queue->head;
    int result = tmp->data;
    queue->head=queue->head->next;

    if (queue->head ==NULL){
        queue->tail=NULL;
    }
    free(tmp);
    queue->length--; 
   return result;
}

void clearQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

void printQueue(Queue* queue){

    if (isQueueEmpty(queue)){
        printf("The Queue is empty\nj");
        return; 
    }
    DynQueue current = queue->head;
    printf("#################################\n");
    printf("Queue elements: \n");
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}


DynStackSentence initializeSentence(void){
    return NULL;
}

DynStackSentence stackSentence(char letter , DynStackSentence sentence){

     DynStackSentence element;

    element= malloc(sizeof(DynStackletter));

    if(element == NULL)
    {
        fprintf(stderr,"Error of memory allocation\n");
        exit(1);

    }

    element->phrase = letter;
    element->next = sentence;

    return element;

}

DynStackSentence destackSen(DynStackSentence sentence){
    if(sentence== NULL)
    {
        
        return NULL;
    }

    DynStackSentence tmp =sentence;
    sentence = sentence->next;

    free(tmp);
    return sentence;
}

bool isSentenceEmpty(DynStackSentence stack){
    if(stack == NULL){
        return true;
    }
    return false;
}

void isSetenceCorrect(char sentence[SIZE]) {
    DynStackSentence phrase = initializeSentence();
    int i = 0;
    int roundpossible=0;
    int squarepossible=0;

    while (sentence[i] != '\0') {
        if (sentence[i] == '(') {
            phrase = stackSentence(sentence[i], phrase);
            roundpossible=1;
        } else if (sentence[i] == ')') {
            if (roundpossible==0 || isSentenceEmpty(phrase) || phrase->phrase != '(') {
                printf("There is a parenthesis problem\n");
                exit(1);
            } else {
                phrase = destackSen(phrase);
                roundpossible=0;
            }
            } else if (sentence[i] == '[') {
            phrase = stackSentence(sentence[i], phrase);
            squarepossible = 1;
        } else if (sentence[i] == ']') {
            if (squarepossible == 0 || isSentenceEmpty(phrase) || phrase->phrase != '[') {
                printf("There is a parenthesis problem\n");
                exit(1);
            } else {
                phrase = destackSen(phrase);
                squarepossible = 0;
            }
        }
        i++;
    }

    if (!isSentenceEmpty(phrase) || roundpossible!=0 || squarepossible!=0) {
        printf("There is a parenthesis issue\n");
        exit(1);
    }

    printf("Parentheses are correctly balanced.\n");

    while (phrase != NULL) {
        phrase = destackSen(phrase);
    }
}

