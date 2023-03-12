/******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void insert_at_begin();
void insert_at_end();
void insert_at_pos();
void insert_at_befor_ele();
void display();
void reverse_list();
void delete_at_begin();
void delete_at_end();
void delete_at_pos();
void delete_ele();
void sort();
void search();

struct node
{
    int data;
    struct node *next;
}*head=NULL,*tail=NULL,*p,*temp;

int main()
{
    while(1)
    {
        printf("\n1.insert at begin\n2.Insert at end\n3.insert at postition\n4.insert before element\n5.display\n6.reverse a linked list\n7.delete at begin\n8.delete at end\n9.delete at position\n10.delete element\n11.sort the list\n12.search\n13.exit\n");

        int op;
        printf("enter option to select a operation\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:insert_at_begin();
                break;
        case 2:insert_at_end();
                break;
        case 3:insert_at_pos();
                break;
        case 4:insert_at_befor_ele();
                break;
        case 5:display();
                break;
        case 6:reverse_list();
                break;
        case 7:delete_at_begin();
                break;
        case 8:delete_at_end();
                break;
        case 9:delete_at_pos();
                break;
        case 10:delete_ele();
                break;
        case 11:sort();
                break;
        case 12:search();
                break;
        default:exit(1);
        }
    }
    return 0;
}

void insert_at_begin()
{
    int ele;
    printf("enter element to insert at begin\n");
    scanf("%d",&ele);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
}

void insert_at_end()
{
    int ele;
    printf("enter element to insert at end\n");
    scanf("%d",&ele);
    p=(struct node*)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
    
}

void insert_at_pos()
{
    int ele,pos;
    printf("enter position to insert an ele\n");
    scanf("%d",&pos);
    printf("enter element to insert at %d position\n",pos);
    scanf("%d",&ele);
    
    p=(struct node *)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
    
    temp=head;
    int count=1;
    while(count!=pos-1)
    {
        count++;
        temp=temp->next;
        
    }
    p->next=temp->next;
    temp->next=p;
    
}

void insert_at_befor_ele()
{
    int prev,ele;
    printf("enter a element to insert before the eele\n");
    scanf("%d",&prev);
    printf("enter an element to insert\n");
    scanf("%d",&ele);
    p=(struct node *)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
    
    temp=head;
    if(temp->data == prev)
    {
        p->next=head;
        head=p;
    }
    else
    {
        while(temp->next->data !=prev)
        {
            temp=temp->next;
        }
        p->next=temp->next;
        temp->next=p;
    }
}

void display()
{
    temp=head;
    if(temp==NULL)
    {
        printf("\n list in empty\n");
        
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d-",temp->data);
            temp=temp->next;
        }
    }
}

void reverse_list()
{
    struct node *current=head;
    struct node *next=NULL;
    struct node *prev=NULL;
    while(current !=NULL)
    {
        next=current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head=prev;
}

void delete_at_begin()
{
    if(head==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        head=head->next;
    }
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
}

void delete_at_pos()
{
    int pos;
    printf("enter position to delete\n");
    scanf("%d",&pos);
    int count=1;
    temp=head;
    
    while(count != pos-1)
    {
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;
    
}

void delete_ele()
{
    int ele;
    printf("enter element to delete\n");
    scanf("%d",&ele);
    temp=head;
    while(temp->next->data != ele)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    
}

void sort()
{
    printf("Descending order\n");
    struct node *temp1;
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        for(temp1=temp->next;temp1!=NULL;temp1=temp1->next)
        {
            if(temp1->data > temp->data)
            {
                int data=temp->data;
                temp->data=temp1->data;
                temp1->data=data;
            }
        }
    }
}

void search()
{
    int ele;
    printf("enter element to search\n");
    scanf("%d",&ele);
    int flag=0;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data == ele)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("\nelement is found\n");
    }
    else
    {
        printf("\n element is not found\n");
    }
    
}
