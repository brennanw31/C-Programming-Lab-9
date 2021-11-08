#include "lab9.h"

int main(void)
{
	srand(time(NULL));
	Weather *head = initListWithDummyNode();
	int i = 0;
	for(i = 0; i<60; i++){
		int check = insertToHead(head, (float)((rand() % 64) + 32));
		check++;
	}
	printList(head);
	printf("\n\n");
	for(i = 0; i<60; i++){
		int check = insertToTail(head, (float)((rand() % 64) + 32));
		check++;
	}
	printList(head);
	emptyList(head);
	printList(head);
	freeList(head);
	printf("\n\t\tNO SEG FAULT!\n");
}