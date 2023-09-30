#include <stdio.h>
#include "pile.h"


int main(void)
{ 	
	StaticStack myEvenStackk,myOddStackk,myStackk;
	DynStack myStack= initializeStack();
	DynStack myEvenStack = initializeStack();
	DynStack myOddStack = initializeStack();
	int valdestack;
	int val=1;
	
	initializeStaticStack(&myEvenStackk);
	initializeStaticStack(&myOddStackk);
	initializeStaticStack(&myStackk);
	
	/*for(int i=0 ; i<NB ; i++)
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
    }*/
	
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
	printStaticStack(&myOddStackk);
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
