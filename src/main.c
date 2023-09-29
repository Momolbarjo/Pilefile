#include <stdio.h>
#include "pile.h"


int main(void)
{
	PileDyn myPile= NULL;
	int val=0;
	
	for(int i=0 ; i<NB ; i++)
	{
		myPile=stack(val,myPile);
		val++;
	}
	
	
	free(myPile);
	
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

*/
