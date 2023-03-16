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
void reverseFirstKItems(Queue *q, int k);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////////////////////////////////////////


int main6()
{
    int c, value;

    Queue q;

    //initialize the stack
	q.ll.head =NULL;
	q.ll.size =0;


    c =1;

    printf("1: Insert an integer into the queue;\n");
    printf("2: Reverse the elements of the queue until the given number;\n");
    printf("0: Quit;\n");

    while (c != 0)
	{
		printf("Please input your choice(1/2/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("Input an integer that you want to insert into the queue: ");
			scanf("%d", &value);
			enqueue(&q, value);
			printf("The resulting queue is: ");
			printList(&(q.ll));
			break;
		case 2:
			printf("Enter an integer to reverse the queue until that number: ");
            scanf("%d",&value);
			reverseFirstKItems(&q, value);// You need to code this function
			printf("The resulting queue after reversing first %d elements is: ", value);
			printList(&(q.ll));
			removeAllItems(&(q.ll));
			break;
		case 0:
			removeAllItems(&(q.ll));
			break;
		default:
			printf("Choice unknown;\n");
			break;
		}
	}

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////


void reverseFirstKItems(Queue *q, int k)
{
    /* add your code here */
    if(k>q->ll.size) {
        printf("Error input!!\n");
        return;
    }

    Stack s;
    s.ll.head =NULL;
	s.ll.size =0;
	int i, j, size=q->ll.size;

	for(i=0; i<k; i++) {
        push(&s, dequeue(q));
	}
	printList(&(s.ll));

	for(j=0; j<size; j++){ // cannot use q->ll.size when k==q->ll.size, it will reduce to 0
        printf("test\n");
        if(j<k) enqueue(q, pop(&s));
        else enqueue (q, dequeue(q));
        printList(&(q->ll));
	}
}
