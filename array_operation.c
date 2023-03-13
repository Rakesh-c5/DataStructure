#include<stdio.h>
#include<stdlib.h>

void insert_at_begin(int [],int *,int);
void insert_at_end(int [],int *,int);
void insert_at_specified_position(int [],int *,int );
void display(int [],int *);
void sort(int [],int *);
void search(int [],int *);
void delete_at_begin(int [],int *);
void delete_at_end(int [],int *);
void delete_at_specified_position(int [],int *);
void min(int [],int *);
void max(int [],int *);
void sum(int [],int *);

int main()
{
    int n;
    printf("enter an array size\n");
    scanf("%d",&n);
    int a[n];
    int count=0;
    while(1)
    {
        printf("\nselect array operation\n");
        printf("1.insert at begin\n2.insert at end\n3.insert at specified position\n4.display\n5.sort\n6.search\n7.delete at begin\n8.delete at end\n9.delete at specified position\n10.min\n11.max\n12.sum\n13.exit\n");
        int op;
        printf("select an operation\n");
        scanf("%d",&op);
        switch (op)
        {
            case 1:insert_at_begin(a,&count,n);
                    break;
            case 2:insert_at_end(a,&count,n);
                    break;
            case 3:insert_at_specified_position(a,&count,n);
                    break;
            case 4:display(a,&count);
                    break;
            case 5:sort(a,&count);
                    break;
            case 6:search(a,&count);
                    break;
            case 7:delete_at_begin(a,&count);
                    break;
            case 8:delete_at_end(a,&count);
                    break;
            case 9:delete_at_specified_position(a,&count);
                    break;
            case 10:min(a,&count);
                    break;
            case 11:max(a,&count);
                    break;
            case 12:sum(a,&count);
                    break;
            default:exit(1);
                    break;
        }
    }
}

void insert_at_begin(int a[],int *size,int n)
{
    
        if(*size == n)
        {
            printf("Overflow\n");
        }
        else if(*size==0)
        {
            int ele;
            printf("enter element to insert at begin\n");
            scanf("%d",&ele);
            
            a[*size]=ele;
            (*size)++;
        }
        else{
                int ele;
                printf("enter element to insert at begin\n");
                scanf("%d",&ele);
                printf("%d",*size);
                
                
                int i;
                for( i=*(size-1);i>=0;i--)
                {
                    a[i+1]=a[i];
                }
                a[i+1]=ele;
                (*size)++;
        }

}

void insert_at_end(int a[],int *size,int n)
{
    if(*size == n)
    {
        printf("Overflow\n");
    }
    else
    {
        int ele;
        printf("Enter element to insert at end\n");
        scanf("%d",&ele);
        a[*size]=ele;
        (*size)++;
    }
}

void insert_at_specified_position(int a[],int *size,int n)
{
    if(*size == n)
    {
        printf("Overflow\n");
    }
    else
    {
        int ele,pos;
        printf("enter positon and elements to insert\n");
        scanf("%d%d",&pos,&ele);
        int i;
        for(i=*size;i>=pos;i--)
        {
            a[i]=a[i-1];
        }
        a[i]=ele;
        (*size)++;
    }
}

void display(int a[],int *size)
{
    if(*size== 0)
    {
        printf("Array is empty\n");
    }
    else{
        int i;
        for(i=0;i<*size;i++)
        {
            printf("%d ",a[i]);
        }
    }
}

void sort(int a[],int *count)
{
    if(*count == 0)
    {
        printf("Array is empty\n");
        
    }
    else
    {
        int i;
        for(i=0;i<*count;i++)
        {
            for(int j=i+1;j<*count;j++)
            {
                if(a[i] > a[j])
                {
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
    }
}

void search(int a[],int *size)
{
    int ele;
    printf("enete element to search\n");
    scanf("%d",&ele);
    
    int flag=0,i;
    for( i=0;i<*size;i++)
    {
        if(a[i] == ele)
        {
            flag=1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Element found at %d position\n",i+1);
    }
    else
    {
        printf("Element not found in the array\n");
    }
}

void delete_at_begin(int a[],int *count)
{
    if(*count == 0)
    {
        printf("Underflow\n");
    }
    else
    {
        int i=0;
        for(i;i<*count;i++)
        {
            a[i]=a[i+1];
        }
        (*count)--;
    }
}

void delete_at_end(int a[],int *count)
{
    if(*count == 0)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The deleted element is %d",a[(*count)-1]);
        (*count)--;
    }
}

void delete_at_specified_position(int a[],int *count)
{
    if(*count == 0)
    {
        printf("Under flow\n");
    }
    else{
        int pos;
        printf("enter position to delete\n");
        scanf("%d",&pos);
    
        int i;
        for(i=pos-1;i<*count;i++)
        {
            a[i]=a[i+1];
        }
        (*count)--;
    }
}

void min(int a[],int *count)
{
    int mini=a[0];
    for(int i=1;i<*count;i++)
    {
        if(mini > a[i])
        {
            mini=a[i];
        }
    }
    printf("Minimum element is %d\n",mini);
}

void max(int a[],int *count)
{
    int maxi=a[0];
    for(int i=1;i<*count;i++)
    {
        if(maxi < a[i])
        {
            maxi=a[i];
        }
    }
    printf("Maximum element is %d\n",maxi);
}

void sum(int a[],int *count)
{
    int s=0;
    for(int i=0;i<*count;i++)
    {
        s=s+a[i];
    }
    printf("Totoal sum is %d\n",s);
}
