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
void reverseStack(Stack *s);

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


int main5()
{
    int c, value;

    Stack s;

    //initialize the stack
	s.ll.head =NULL;
	s.ll.size =0;


    c =1;

    printf("1: Insert an integer into the stack;\n");
    printf("2: Reverse the stack;\n");
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
			reverseStack(&s); // You need to code this function
			printf("The resulting stack after reversing its elements is: ");
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


void reverseStack(Stack *s)
{
	/* add your code here */
	Queue q;
	q.ll.head =NULL;
	q.ll.size =0;

	while(!isEmptyStack(s)) {
        enqueue(&q, pop(s));
	}
	while(!isEmptyQueue(&q)) {
        push(s, dequeue(&q));
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   int item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

int peek(Stack *s){
   return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
   if ((s->ll).size == 0)
      return 1;
   return 0;
}

void enqueue(Queue *q, int item){
   insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
   int item;
   item = ((q->ll).head)->item;
   removeNode(&(q->ll), 0);
   return item;
}

int isEmptyQueue(Queue *q){
   if ((q->ll).size == 0)
      return 1;
   return 0;
}
