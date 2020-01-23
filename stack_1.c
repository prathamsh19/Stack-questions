#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stacknode{
    int data;
    struct stacknode* next;
};
struct stacknode* newNode(int data)
{
 struct stacknode* stackNode = (struct stacknode*)malloc(sizeof(struct stacknode));
 stackNode->data=data;
 stackNode->next=NULL;
 return stackNode;
}
void push(struct stacknode** head,int d)
{
    struct stacknode* stackNode = newNode(d);
    stackNode->next=*head;
    *head=stackNode;
}
int isEmpty(struct StackNode* root)
{
    return !root;
}
int pop(struct stacknode** head)
{
    if (isEmpty(*head))
        return INT_MIN;
    struct stacknode* temp = *head;
    *head = (*head)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}
int main()
{
    struct stacknode* head=NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        push(&head,a);
    }
    printf("pop\n");
    for(i=0;i<n;i++)
    {
        printf("popped element %d\n",pop(&head));
    }
    return 0;
}
