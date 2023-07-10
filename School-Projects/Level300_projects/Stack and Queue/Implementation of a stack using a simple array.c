#include <stdio.h>
#define MAX 100
void enqueue(int);
void dequeue();
void display();

int queue[MAX],rear =-1,front=-1;

void main()
{ int value,selection;

 while(1)
 {
 printf("\nMenu\n");
 printf("1.in\n 2.Deletion\n 3.Display\n4.SizeofQueue\n5.headofqueue\n6.endofqueue\n7.Exit");
 printf("\n Enter your choice: ");
 scanf("%d",&selection);
 switch(selection)
 {
     case 1 : printf("Enter the value to be entered: ");
             scanf("%d",&value);
             enqueue(value);
             break;
     case 2 : dequeue(); break;
     case 3 : display(); break;
     case 4 : printf("%d",front+rear+1);break;
     case 5 : printf(" %d",queue[front]);break;
     case 6 : printf("% d",queue[rear]);break;
     case 7 :    exit(0);
     default :printf("\n Wrong selection !");
 }
 }
}
    void enqueue(int value)
    {
        if (rear == size-1)
            printf("\nqueue is full! Insertion is impossible");
        else{
            if(front==-1)
                front=0;
            rear+=1;
            queue[rear] = value ;
            printf("Insertion successful");
        }
    }
    void dequeue(){
    if(front==rear){
    printf("\n Queue is Empty! Deletion not possible");
    }
    else{
       printf("\n Deleted : %d",queue[front]);
       front++;
       if(front==rear)
        front=rear-1;
        }
    }
    void display() {
    if(rear==-1)
        printf("\nqueue is Empty!!");
    else{
            int i;
    printf("\nqueue elements are: \n");
    for(i=rear;i>=0;i--)
        printf("%d\n",queue[i]);
}    }
