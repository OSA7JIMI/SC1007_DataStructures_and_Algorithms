//////////////////////////////////////////////////////////////////////////////////

/* CE1107/CZ1107 Data Structures
Assignment 1 - Linked List Questions
Purpose: Implementing the required functions for Question 2 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


//////////////////////// function prototypes /////////////////////////////////////

// You should not change the prototype of this function
void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main3()
{
	LinkedList ll1, ll2;
	int c, i, j;
	c = 1;
	//Initialize the linked list 1 as an empty linked list
	ll1.head = NULL;
	ll1.size = 0;

	//Initialize the linked list 2 as an empty linked list
	ll2.head = NULL;
	ll2.size = 0;

	printf("1: Insert an integer to the linked list 1:\n");
	printf("2: Insert an integer to the linked list 2:\n");
	printf("3: Create the alternate merged linked list:\n");
	printf("0: Quit:\n");

	while (c != 0)
	{
		printf("Please input your choice(1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list 1: ");
			scanf("%d", &i);
			j = insertNode(&ll1, ll1.size, i);
			printf("Linked list 1: ");
			printList(&ll1);
			break;
		case 2:
			printf("Input an integer that you want to add to the linked list 2: ");
			scanf("%d", &i);
			j = insertNode(&ll2, ll2.size, i);
			printf("Linked list 2: ");
			printList(&ll2);
			break;
		case 3:
		    printf("The resulting linked lists after merging the given linked list are:\n");
			alternateMergeLinkedList(&ll1, &ll2); // You need to code this function
			printf("The resulting linked list 1: ");
			printList(&ll1);
			printf("The resulting linked list 2: ");
			printList(&ll2);
			removeAllItems(&ll1);
			removeAllItems(&ll2);
			break;
		case 0:
			removeAllItems(&ll1);
			removeAllItems(&ll2);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2)
{
	// add your code here
	ListNode *cur1, *cur2;
	if (ll1==NULL) return;
	if (ll2==NULL) return;
	cur1 = ll1->head;
	cur2 = ll2->head;
	int size1=ll1->size, size2=ll2->size, i, temp, j, count=0;

	for (i=1; i<=2*size1; i+=2) {
            if (cur2!=NULL) {
                    temp=cur2->item;
                    insertNode(ll1, i, temp);
                    count++;
                    cur2=cur2->next;
            }
            else break;
	}

	for (i=0; i<count; i++) {
        removeNode(ll2, 0);
        //printf("%d ", i);
	}
}

///////////////////////////////////////////////////////////////////////////////////
