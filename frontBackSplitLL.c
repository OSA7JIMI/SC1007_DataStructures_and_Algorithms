//////////////////////////////////////////////////////////////////////////////////

/* CE1107/CZ1107 Data Structures
Assignment 1 - Linked List Questions
Purpose: Implementing the required functions for Question 4 */

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

// This is for question 4. You should not change the prototype of this function
void frontBackSplitLinkedList(LinkedList* ll, LinkedList *resultFrontList, LinkedList *resultBackList);

// You may use the following functions or you may write your own
void printList(LinkedList *ll);
void removeAllItems(LinkedList *l);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


///////////////////////////// main() /////////////////////////////////////////////

int main5()
{
	int c, i;
	LinkedList ll;
	LinkedList resultFrontList, resultBackList;

	//Initialize the linked list as an empty linked list
	ll.head = NULL;
	ll.size = 0;

	//Initialize the front linked list as an empty linked list
	resultFrontList.head = NULL;
	resultFrontList.size = 0;

	// Initialize the back linked list as an empty linked list
	resultBackList.head = NULL;
	resultBackList.size = 0;

	printf("1: Insert an integer to the linked list:\n");
	printf("2: Print the linked list:\n");
	printf("3: Split the linked list into two linked lists, frontList and backList:\n");
	printf("0: Quit:\n");
	printf("Please input your choice(1/2/3/0): ");
	scanf("%d", &c);

	while (c != 0)
	{
		switch (c)
		{
		case 1:
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i);
			insertNode(&ll, ll.size, i);
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 2:
			printf("The resulting linked list is: ");
			printList(&ll);
			break;
		case 3:
			printf("The resulting linked lists after splitting the given linked list are:\n");
			frontBackSplitLinkedList(&ll, &resultFrontList, &resultBackList); // You need to code this function
			printf("Front linked list: ");
			printList(&resultFrontList);
			printf("Back linked list: ");
			printList(&resultBackList);
			printf("\n");
			removeAllItems(&ll);
			removeAllItems(&resultFrontList);
			removeAllItems(&resultBackList);
			break;
		case 0:
			removeAllItems(&ll);
			removeAllItems(&resultFrontList);
			removeAllItems(&resultBackList);
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}

		printf("\nPlease input your choice(1/2/3/0): ");
		scanf("%d", &c);
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void frontBackSplitLinkedList(LinkedList *ll, LinkedList *resultFrontList, LinkedList *resultBackList)
{
	// add your code here
	ListNode *cur, *curF, *curB;
	cur = ll->head;
	curF=resultFrontList->head;
	curB=resultBackList->head;
	int i, half=ll->size/2, j;
	if (ll->size%2==0)  half--;

	for (i=0, j=0 ; i<ll->size; i++) {

        if (i<=half) insertNode(resultFrontList, i, cur->item);
        else
        {
            insertNode(resultBackList, j, cur->item);
            j++;
        }
        printf("%d", i);
        cur=cur->next;
	}
}

