//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototype of this function
void removeDuplicatesSortedLL(LinkedList *ll);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main4()
{
	LinkedList ll;
	int c, i, j;
	c = 1;

	//Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	printf("1: Insert an integer to the linked list:\n");
	printf("2: Remove duplicates from a sorted linked list:\n");
	printf("0: Quit:\n");;

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			j = insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			removeDuplicatesSortedLL(&ll); // You need to code this function
			printf("The resulting linked list after removing duplicate values from the sorted linked list is: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void removeDuplicatesSortedLL(LinkedList *ll)
{
	/* add your code here */
	ListNode *cur;

	if (ll == NULL)
		return;
	cur = ll->head;
	if(cur==NULL) return;
	int temp=cur->item, i=0, size=ll->size, count=0;
	printf("%d\n", temp);
	if (size==1) return;

	while (i<size)	{
        if (temp==cur->next->item){
            cur = cur->next;
            temp = cur->item;
            removeNode(ll, i);
            count++;
        }
        else{
            cur = cur->next;
            temp = cur->item;
        }
        printf("%d\n", temp);
        printf("%d\n", cur);
		i++;
		printf("%d\n", i);
		size=ll->size;
		if(i==size-2 && count==0) break;
	}
}
