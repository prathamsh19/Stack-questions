#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack* next;
}S;
S* newnode(int d)
{
    S* n=(S*)malloc(sizeof(S));
    n->data=d;
    n->next=NULL;
    return n;
}
void push(S** h,int d)
{
    S* newn=newnode(d);
    newn->next=*h;
    *h=newn;
}
int empty(S *h)
{
    return !h;
}
void pop(S** h)
{
    if(*h==NULL)
    {
        printf("no");
    }
    else{
    S* temp=*h;
    *h=(*h)->next;
    free(temp);
    temp=NULL;
    }
}
int top(S* h)
{
    return h->data;
}
int main()
{
    S* h=NULL;
    int n,i=0;
    scanf("%d",&n);
    int a[n];
    int res[n];
    for(i=0;i<n;i++)
    {
        res[i]=-1;
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        if(empty(h)||a[i]>a[top(h)])
        {
            push(&h,i);
        }
        else
        {
            while((!empty(h))&&a[i]<a[top(h)])
            {
                res[top(h)]=a[i];
                pop(&h);
            }
            push(&h,i);
        }
    }
     for(i=0;i<n;i++)
    {
        printf("%d\n",res[i]);
    }

    return 0;
}
