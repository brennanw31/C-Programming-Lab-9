#include "lab9.h"

/*This function returns a pointer to an empty Weather list ADT with dummy nodes on both the
head and tail*/
Weather* initListWithDummyNode()
{
	Weather *p = malloc(sizeof(Weather));
	if(!p){
		printf("*** Error: Memory could not be allocated ***\n");
		return(NULL);
	}
	p->temperature = 0;
	p->Ptr = malloc(sizeof(Weather));
	if(!(p->Ptr)){
		printf("*** Error: Memory could not be allocated ***\n");
		return(NULL);
	}
	p->Ptr->temperature = 0;
	p->Ptr = NULL;
	return(p);
}

/*This function creates a new node and appends it to the beginning of the list. The head dummy node
then points to the new node. The function returns 0 if the insertion failed, 
or 1 if the insertion was successful.*/
int insertToHead(Weather* p,float n)
{
	Weather *new = malloc(sizeof(Weather));
	if(!new){
		printf("*** Error: Memory could not be allocated ***\n");
		return(0);
	}
	new->temperature = n;
	new->Ptr = p->Ptr;
	p->Ptr = new;
	return(1);
}

/*This function creates a new node and appends it to the end of the list. The previous tail node will
point to the new node, and the new node will point to the tail end dummy node. The function returns 0 if
the insertion failed, or 1 if the insertion was successful*/
int insertToTail(Weather* p,float n)
{
	Weather *new = malloc(sizeof(Weather));
	if(!new){
		printf("*** Error: Memory could not be allocated ***\n");
		return(0);
	}
	new->temperature= n;
	new->Ptr = NULL;
	Weather *temp = p;
	while(temp->Ptr){
		temp = temp->Ptr;
	}
	temp->Ptr = new;
	return(1);
}

/*This function prints each member of the list, except dummy nodes, in rows of 5
floats with 2 decimal places of precision*/
void printList(Weather* p)
{
	Weather *temp = p->Ptr; int i = 0;
	printf("\t");
	while(temp->Ptr != NULL){
		if(i && i%5 == 0){
			printf("\n\t");
		}
		printf("%.2f ", temp->temperature);
		temp = temp->Ptr; i++;
	}
}

/*This function frees all real nodes in the list and returns a pointer to an
empty list with only head and tail dummy nodes*/
void emptyList(Weather* p)
{
	while(p->Ptr->Ptr){
		Weather *temp = p->Ptr;
		p->Ptr = p->Ptr->Ptr;
		free(temp);
	}
}

/*This function frees all previosuly allocated memories and sets the list to NULL*/
void freeList(Weather* p)
{
	while(p->Ptr){
		Weather *temp = p;
		p = p->Ptr;
		free(temp);
	}
	p = NULL;
}












