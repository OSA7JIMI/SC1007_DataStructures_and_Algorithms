
#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);

int removeNode(ListNode **ptrHead,int index);

int main4()
{
    ListNode *head=NULL;
    int size =0;
    int item;
    int index;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printList(head);

    while(1){
        printf("Enter the index of the node to be removed: ");
        scanf("%d",&index);

        if(removeNode(&head,index))
            size--;
        else{
            printf("The node cannot be removed.\n");
            break;
        }

        printf("After the removal operation,\n");
        printList(head);
    }

    printList(head);
    return 0;
}

int removeNode(ListNode **ptrHead,int index)
{
/* Write your program code here */
    ListNode *pre, *cur=*ptrHead;

    if (index==0) {
        *ptrHead=cur->next;
        free(cur);
        return 1;
    }

    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        cur = findNode(*ptrHead, index);
        pre->next=cur->next;
        free(cur);
        return 1;
    }

    else return 0;
}
