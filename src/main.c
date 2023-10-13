#include <stdio.h>
#include "pile.h"


int main(void)
{ 	

	char sentence[SIZE];

	printf("Give me a sentence\n");
	scanf("%s",sentence);

	isSetenceCorrect(sentence);




	/*
	srand(time(NULL));

	Queue q1,q2;

	initializeQueue(&q1);
	initializeQueue(&q2);
	
	
	for(int i =0;i<3; i++){

		int nb_items=rand()%50+1;
		enqueue(&q1,nb_items);
	}

	while(1){
		if(!isQueueEmpty(&q1)){

			printQueue(&q1);
			int itemsInFront = 0;

			DynQueue tmp= q1.head;
			DynQueue prev;
			while(tmp!=NULL){
				 if (tmp->next == NULL) {
                break; 
            }
				itemsInFront += tmp->data;
				prev=tmp;
				tmp= tmp->next;
			}

			 if (itemsInFront > MAX_ITEMS) {
            
            if (prev != NULL) {
                
                int movedCustomerData = tmp->data;
                prev->next = NULL; 
                enqueue(&q2, movedCustomerData);
                printf("%d waited too much , he is now in queue 2\n", movedCustomerData);
            }
        }

		int leavingCustomer = dequeue(&q1);
		printf("%d paid , goodbye \n",leavingCustomer);

			
			printf("The next customers are: \n");
			printQueue(&q1);
			
		if(rand()%3==1){
			for(int i=0;i<rand()%3+1;i++){
			int nb_items=rand()%50+1;
			enqueue(&q1,nb_items);
			printf("Adding %d to the Queue\n",nb_items);
		  }
		  printf("\n");
		}
		
		}
		else{
			printf("There is no more customers! \n");
			break;
		}
	}
	

	
	StaticStack myEvenStackk,myOddStackk,myStackk;
	DynStack myStack= initializeStack();
	DynStack myEvenStack = initializeStack();
	DynStack myOddStack = initializeStack();
	int valdestack;
	int val=1;
	
	initializeStaticStack(&myEvenStackk);
	initializeStaticStack(&myOddStackk);
	initializeStaticStack(&myStackk);
	
	for(int i=0 ; i<NB ; i++)
	{
		myStack=stack(val,myStack);
		val++;
	}
	
	printStack(myStack);

	while(myStack != NULL){
	myStack=destack(myStack,&valdestack);


        //printf("Value destacked: %d\n", valdestack);
    if(valdestack%2==0){
		myEvenStack=stack(valdestack,myEvenStack);
	}
	else{
		myOddStack=stack(valdestack,myOddStack);
		}

	}

if (myStack == NULL) {

        printf("The stack is empty...\n");
	  }
    
	printf("Even stack:\n");
	printStack(myEvenStack);
	printf("\n");
	printf("Odd stack:\n");
	printStack(myOddStack);
	

	
	while (myEvenStack != NULL) 
	{
        DynStack temp = myEvenStack;
        myEvenStack = myEvenStack->next;
        free(temp);
    }
	while (myOddStack != NULL) 
	{
        DynStack temp = myOddStack;
        myOddStack = myOddStack->next;
        free(temp);
    }
	while (myStack != NULL) 
	{
        DynStack temp = myStack;
        myStack = myStack->next;
        free(temp);
    }
	
	for(int i=0 ; i<NB ; i++)
	{
		push(&myStackk,val);
		val++;
	}

	while(!isStackEmpty(&myStackk)){
		int elmt=pop(&myStackk);
		if(elmt %2 ==0){
			push(&myEvenStackk,elmt);
		}
		else{
			push(&myOddStackk,elmt);
		}
	}

	printf("EvenStack : \n");
	printStaticStack(&myEvenStackk);

	printf("\n");

	printf("OddStack : \n");
	printStaticStack(&myOddStackk);*/


	return 0;
}

/* Ex1:

1)
   a) [2,5,9,10,8,7]
   b) [2,5,9,10,1,-3]
   
2)
   a) [10,1,-3,12,8,7]
   b) [10,1,-3,7,8,12]
   
  
3) Il faut une pile pour enfiler les elements  et une autre pour defiler les elements(retirer de la file principale).


Ex 3:

1) Une file dynamique
*/

