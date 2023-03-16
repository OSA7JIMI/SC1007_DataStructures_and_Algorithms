//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////   linked list /////////////////////////////////

typedef struct _listnode{
   int item;
   struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
   ListNode *tail;
} LinkedList;

////////////////////////////////// stack    ///////////////////////////////////////////////////////

typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

///////////////////////// function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
void sortStack(Stack *s);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////////////////////////////////////////


int main7()
{
    int c, value;

    Stack s;

    //initialize the stack
	s.ll.head =NULL;
	s.ll.size =0;


    c =1;

    printf("1: Insert an integer into the stack;\n");
    printf("2: Sort the stack in ascending order ;\n");
    printf("0: Quit;\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the stack: ");
			scanf("%d", &value);
			push(&s, value);
			printf("The resulting stack is: ");
			printList(&(s.ll));
			break;
		case 2:
			sortStack(&s); // You need to code this function
			printf("The resulting stack after sorting it in ascending order is: ");
			printList(&(s.ll));
			removeAllItems(&(s.ll));
			break;
		case 0:
			removeAllItems(&(s.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void sortStack(Stack *s)
{
    /* add your code here */
    Stack s2;
    s2.ll.head =NULL;
	s2.ll.size =0;
	int temp;

	while (!isEmptyStack(s)){
        temp = pop(s);
        while (!isEmptyStack(&s2) && peek(&s2) > temp) push(s, pop(&s2));
        push(&s2, temp);
	}

	while(!isEmptyStack(&s2)) push(s, pop(&s2));
}

