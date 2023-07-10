#include<stdio.h>
#define MAX 7
    int Queue[MAX];
    int head=-1, end=-1;
void enqueue(int n){
    if(head==-1 && end==-1){
    head=0, end=0;
    Queue[end]=n;
    }
    else if((end+1)%MAX==head){
     printf("The Queue is FULL\n");
    }
    else {
     end=(end+1)%MAX;
    Queue[end]=n;
    }
}
int dequeue(){
    if((head==-1)&&(end==-1)){
     printf("The Queue is EMPTY\n");
    }
    else if(head==end){
    printf("The dequeued element is : %d\n", Queue[head]);
    head=-1, end=-1;
    }
    else {
     printf("The dequeued element is : %d\n", Queue[head]);
    head=(head+1)%MAX;
    }
}
void display (){
    int i=head;
    if (head==-1&&end==-1){
     printf("The queue is EMPTY");
    }
    else{
     printf("Element in the Queue are\n");
    while(i<=end){
     printf("\t%d", Queue[i]);
      i=(i+1)%MAX;
    }
    }}
void sizeOfqueue(){
  int a, b, c;
if(head<=end){
    printf("\nThe size of the queue is : %d\n", end-head+1);
}
else{
    if(head>end&&head<=MAX-1&&end>=0){
     b=MAX-head;
     c=(end+1)%MAX;
     a=b+c;
    printf("\nQueue size is : %d ", a);
    }
}}
int main(){
    int choice = 1, x;
    printf("\tImplementation of a Queue using Circular Array\n");
    printf("\t----------------------------------------------\n");
    printf("1: ENQUEUE\n");
    printf("2: DEQUEUE\n");
    printf("3: DISPLAY\n");
    printf("4: SIZEOFQUEUE\n");
    printf("5: HEADOFQUEUE\n");
    printf("6: ENDOFQUEUE\n");
    printf("7: EXIT\n");
    while(1){
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch(choice){
    case 1:
        printf("\nEnter the element to be enqueued : ");
        scanf("%d", &x);
        enqueue(x);
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        sizeOfqueue();
        break;
    case 5:
        printf("\nThe element at head of queue is %d\n ", Queue[head]);
        break;
    case 6:
        printf("\nThe element at end of queue is %d\n ", Queue[end]);
        break;
    case 7:
        printf("\nExit successfully\n");
        exit(1);
        break;
    default:
        printf("\nWrong inputs\n");

    }}
    return 0;
}