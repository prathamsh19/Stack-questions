#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}Node;
Node* front=NULL;
Node* rear=NULL;
Node* create_new_node()
{
    return (Node*)malloc(sizeof(Node));
}
void add_at_last(int d)
{
    Node* newn=create_new_node();
    newn->data=d;
    newn->next=NULL;
    newn->prev=NULL;
    if(rear==NULL)
    {
        front=rear=newn;
    }
    else
    {
        newn->prev=rear;
        rear->next=newn;
        rear=newn;
    }
}
void delete_at_front()
{
    if(!front)
        return;
    else if(front->next==NULL)
    {
        Node* temp=front;
        front=rear=NULL;
        free(temp);
        temp=NULL;
    }
    else
    {
        Node* temp=front;
        front=front->next;
        front->prev=NULL;
        free(temp);
        temp=NULL;
    }
}
void delete_at_last()
{
    if(front&&!front->next)
        delete_at_front();
    else
    {
        Node* curr=rear->prev;
        Node* temp=curr->next;
        curr->next=NULL;
        rear=curr;
        free(temp);
        temp=NULL;
    }
}
int empty(Node* fro)
{
    return !front;
}
int main()
{
    int n,i;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int k,c=1;
    printf("enter size of window\n");
    scanf("%d",&k);
    add_at_last(0);
    for(i=1;i<k;++i)
    {
        while((!empty(front))&&a[i]>=a[rear->data])
        {
            delete_at_last();
        }
        add_at_last(i);
    }
    for(;i<n;++i)
    {
        printf("%d\n",a[front->data]);
        while((!empty(front))&&front->data<=i-k)
        {
            delete_at_front();
        }
        while((!empty(front))&&a[i]>=a[rear->data])
        {
            delete_at_last();
        }
        add_at_last(i);
    }
    printf("%d\n",a[front->data]);
    return 0;
}
