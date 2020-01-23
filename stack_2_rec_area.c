#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
int d;
struct stack* n;
}S;

void push(S** h,int dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
if((*h)==NULL)
{(*h)=nn;}
else
{
nn->n=(*h);
(*h)=nn;
}
}

int Empty(S* h)
{
return !h;
}

int top(S* h)
{
    return h->d;
}
int pop(S** h)
{
S* temp=(*h);
int a=(*h)->d;
(*h)=(*h)->n;
free(temp);
temp=NULL;
return a;
}

int area(int n,int a[])
{
S* h=(S*)malloc(sizeof(S));
h=NULL;
push(&h,0);
int max=0;
int i=0;
for(i=1;i<n;i++)
{
if(Empty(h)||(a[i])>=a[top(h)])
{push(&h,i);}
else
{
int x=top(h);
int y=pop(&h);
int b=(Empty(h)?i:(i-top(h)-1));
int c=a[x]*b;
if(max<c)
{max=c;}
}
}
while(!Empty(h))
{
int x=top(h);
int y=pop(&h);
int b=(Empty(h)?i:(i-top(h)-1));
int c=b*a[x];
if(max<c)
{max=c;}
}
return max;
}

int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int res=area(n,a);
printf("%d",res);
return 0;
}
