#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack{
char d;
struct stack* next;
}S;
void push(S** h,char c)
{
    S* n=(S*)malloc(sizeof(S));
    n->d=c;
    n->next=*h;
    *h=n;
}
int empty(S* h)
{
    return !h;
}
void pop(S** h)
{
    S* t=*h;
    *h=(*h)->next;
    free(t);
    t=NULL;
}
char peek(S* h)
{
    return h->d;
}
int prece(char c)
{
    if(c=='*'||c=='/')
        return 3;
    else if(c=='+'||c=='-')
        return 2;
    else
        return 0;
}
int main()
{
    S* h=NULL;
    int n;
    scanf("%d",&n);
    char str[n];
    char s1[n];
    scanf("%s",str);
    int l=strlen(str);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            push(&h,str[i]);
            //printf("%c",str[i]);
        }
        else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'||str[i]>='0'&&str[i]<='9')
        {
            s1[j]=str[i];
            //printf("%c",s1[j]);
            j++;
            //printf("%c",str[i]);
        }
        else if(str[i]==')')
        {
            while(peek(h)!='('&&(!empty(h)))
            {
                s1[j]=peek(h);
                //printf("%c",s1[j]);
                j++;
                pop(&h);
            }
            pop(&h);
        }
        else
        {
            if(prece(str[i])<=prece(peek(h)))
            {
                while(prece(str[i])<=prece(peek(h))&&!empty(h))
                {
                    s1[j]=peek(h);
                    j++;
                    pop(&h);
                }
                push(&h,str[i]);
            }
            else if(prece(str[i])>prece(peek(h)))
            {
                push(&h,str[i]);
            }
        }
    }
    while(!empty(h))
    {
        if(peek(h)=='(')
        {
            pop(&h);
        }
        else
        {
            s1[j]=peek(h);
            j++;
            pop(&h);
        }
    }
    printf("\n");
    for(int i=0;i<j;i++)
    printf("%c",s1[i]);
    return 0;
}
