#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;


void printList(ListNode *cur);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
void deleteList(ListNode **ptrHead);
int duplicateReverse(ListNode *cur,ListNode **ptrNewHead);

int main3()
{
    ListNode *head=NULL;
    ListNode *dupRevHead=NULL;
    int size =0;
    int item;

    printf("Enter a list of numbers, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
        if(insertNode(&head,size, item)) size++;
    scanf("%*s");

    printf("\nBefore duplicateReverse() is called:\n");
    printList(head);

    duplicateReverse(head,&dupRevHead);

    printf("\nAfter duplicateReverse() was called:\n");
    printf("The original list:\n");
    printList(head);
    printf("The duplicated reverse list:\n");
    printList(dupRevHead);

    if(head!=NULL)
       deleteList(&head);
    if(dupRevHead)
       deleteList(&dupRevHead);

    return 0;
}


int duplicateReverse(ListNode *cur,ListNode **ptrNewHead) {
    /* Write your program code here*/
    while (cur!=NULL){
        insertNode(ptrNewHead, 0, cur->item);
        cur=cur->next;
    }

}
