//Program to implement stack by linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node*ptr;
}*top,*top1,*temp;

int count=0;

//Function to create empty stack
void create()
{
    top=NULL;
}

//Function to push elements into stack
void push()
{
    int data;
    if(top==NULL)
    {
        printf("\nEnter data to push into stack: ");
        scanf("%d",&data);
        top=(struct node *)malloc(1*sizeof (struct node));
        top->ptr=NULL;
        top->info=data;
    }
    else
    {
         printf("\nEnter data to push into stack: ");
        scanf("%d",&data);
        temp=(struct node *)malloc(1*sizeof (struct node));
        temp->ptr=top;
        temp->info=data;
        top=temp;
    }
    count++;
}

//Function to pop stack elements
void pop()
{
    top1=top;
    if(top1==NULL)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        top1=top1->ptr;
        printf("\nPopped element is: %d",top->info);
        free(top);
        top=top1;
        count--;
    }
}

//Function to display stack elements
void display()
{
    top1=top;
    if(top1==NULL)
    {
        printf("Stack has no element");
        return;
    }
    printf("Stack elements are: ");
    while(top1!=NULL)
    {
        printf("%d,",top1->info);
        top1=top1->ptr;
    }
}

//Function for program execution

int main()
{
    int choice;
    printf("\tIMPLEMENTING STACK USING LINK LIST\n");
    printf("\t----------------------------------\n");
    printf("1. Create Stack\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Display Stack\n");
    printf("5. Size of Stack\n");
    printf("6. Top of Stack\n");
    printf("7. EXIT\n");


    while(1)
    {
        printf("\nEnter a number: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("\nStack created ");
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            if(top==NULL)
            {
                printf("\nStack has no element");
            }
            else
            {
                printf("Size of Stack is: %d",count);
            }
            break;
        case 6:
            if(top==NULL)
            {
                printf("\nStack has no element");
            }
            else
            {
                printf("Top of Stack is: %d",top->info);
            }
            break;
        case 7:
            exit(0);
        default :
            printf("Error!!! Enter a correct choice");
            break;
    }
}
}
