#include <stdio.h>
#define MAX 100

void enqueue(int);
void dequeue();
void display();

int queue[MAX],rear =-1,front=-1;

void main()
{int value,choice,n;
    printf("\nEnter the size of QUEUE[MAX=100]:");
    scanf("%d",&n);
    printf("\nImplementation of a queue using a simple array");
    printf("\n----------------------------------------------");
    printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.SIZEOFQUEUE\n 5.HEADOFQUEUE\n 6.ENDOFQUEUE\n 7.EXIT\n");

 while(1){

        printf("\n Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
 {
     case 1 : printf("Enter the value to be enqueued: ");
             scanf("%d",&value);
             enqueue(value);
             break;
     case 2 :
                dequeue();
                break;
     case 3 :
                display();
                break;
     case 4 :
                printf("%d",front+rear+1);
                break;
     case 5 :
                printf(" %d",queue[front]);
                break;
     case 6 :
                printf("% d",queue[rear]);
                break;
     case 7 :
                exit(0);
     default :
                 printf ("\n Please enter a number in the range (1 - 7)");
 }
 }
}
    void enqueue(int value)
    {
        if (rear == MAX-1)
            printf("\n There's an overflow");
        else{
            if(front==-1)
                front=0;
            rear+=1;
            queue[rear] = value ;
        }
    }
    void dequeue(){
        if(front==-1&&rear==-1)
         printf("\n There's an underflow or queue is empty");
    else if(rear==front){
        printf("The dequeued element is : %d\n", queue[front]);
        front=rear=-1;
    }
    else{
      printf("The dequeued element is : %d\n",queue[front]);
       front++;
        }
    }
    void display() {
    if(front==-1&&rear==-1)
        printf("\n The QUEUE is empty");
    else{
            int i;
    printf("\n The elements in QUEUE \n");
    for(i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
}    }

