#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
struct stacknode{
char data;
struct stacknode* next;
};
struct stacknode* newNode(char d)
{
    struct stacknode* node=(struct stacknode*)malloc(sizeof(struct stacknode));
    node->data=d;
    node->next=NULL;
    return node;
}
void push(struct stacknode** head,char d)
{
    struct stacknode* node=newNode(d);
    node->next=*head;
    *head=node;
}
int isEmpty(struct StackNode* root)
{
    return !root;
}
char pop(struct stacknode** head)
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
    char s[20];
    gets(s);
    printf("%s\n",s);
    int n=strlen(s);
    char t;
    if(n%2!=0)
    {
        printf("not balanced\n");
    }
    else{
            int i=0;
        while(s[i]!='\0')
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                {
                    push(&head,s[i]);
                    i++;
                }
            else
            {
                if(isEmpty(head))
                {
                    return 0;
                }
                switch(s[i])
                {
                case ')':
                    t=pop(&head);
                    if(t=='{'||t=='[')
                        return 0;
                    break;
                case '}':
                    t=pop(&head);
                    if(t=='('||t=='[')
                        return 0;
                    break;
                case ']':
                    t=pop(&head);
                    if(t=='{'||t=='(')
                        return 0;
                    break;
                }
                i++;
            }
        }
        printf("balanced\n");
    }
    return 0;
}
