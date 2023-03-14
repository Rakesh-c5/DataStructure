//stack implementation


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
}*top=NULL;

struct stack
{
    char s;
    struct stack *next;
}*top1=NULL;

void push();
void peek();
void pop();
void display();
void count();
void search();
void sort();
void reverse();
void paranthesis_check();

int main()
{
    while(1)
    {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.count\n6.search\n7.paranthesis_check\n8.soriting\n9.reverse\nto exit\n");
        printf("\n enter options\n");
        int op;
        scanf("%d",&op);
        switch(op)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:count();
                    break;
            case 6:search();
                    break;
            case 7:paranthesis_check();
                    break;
            case 8:sort();
                    break;
            case 9:reverse();
                    break;
            
            default:printf("\n options out of range\n");
                    exit(0);
        }
    }
    
}

void push()
{
    int ele;
    printf("enter element to push into stack\n");
    scanf("%d",&ele);
    struct node *p=(struct node *)malloc(sizeof(struct node *));
    p->data=ele;
    p->next=NULL;
    
    if(top==NULL)
    {
        top =p;
    }
    else
    {
        p->next=top;
        top=p;
    }
    printf("\n push is done\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\n stack underflow\n");
    }
    else
    {
        printf("  %d is deleted\n",top->data);
        top=top->next;
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d ",top->data);
        
    }
}

void display()
{
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void count()
{
    int c=0;
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        c=c+1;
        temp=temp->next;

    }
    printf("\ntotal elements in the stack is %d",c);
}

void search()
{
    
    int se;
    printf("enter element to search\n");
    scanf("%d",&se);
    struct node *temp;
    temp=top;
    int f=0;
    while(temp!=NULL)
    {
        if(temp->data == se)
        {
            printf("\nelement is found\n");
            f=1;
            break;
        }
    }
    if(f==0)
    {
        printf("Eleement is not found\n");
    }
}


void paranthesis_check()
{
  
    char str[100];
    printf("\nenter a string to check \n");
    scanf("%s",str);
    
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='{' || str[i]=='[' || str=="(")
        {
            struct stack *p=(struct stack *)malloc(sizeof(struct stack ));
            p->s=str[i];
            p->next=NULL;
            if(top1!=NULL)
            {
                top1=p;
            }
            else
            {
                p->next=top1;
                top1=p;
            }
        }
        else if(str[i]==')')
        {
            if(top1!=NULL && top1->s=='(')
            {
                top1=top1->next;
            }
        }
        else if(str[i] == ']')
        {
            if(top1!=NULL && top1->s == '[')
            {
                top1=top1->next;

            }
        }
        else if(str[i] == '}')
        {
            if(top1!=NULL && top1->s == '{')
            {
                top1=top1->next;
            }
        }
    }
    if(top1 == NULL)
    {
        printf("\n given string matches with give conditions\n");
    }
    else
    {
        printf("\nstring does not matches\n");
    }
}


void sort()
{
    struct node *temp,*temp1;
    for(temp=top;temp!=NULL;temp=temp->next)
    {
        for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if(temp1->data > temp->data)
            {
                int g=temp->data;
                temp->data=temp1->data;
                temp1->data=g;
            }
            
        }
    }
    
   printf("\nsorting is done\n");
}


void reverse()
{
    struct node *current;
    current=top;
    
    struct node *prev=NULL;
    struct node *next=NULL;
    
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    top=prev;
    
}


