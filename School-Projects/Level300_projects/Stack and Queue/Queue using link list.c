#include <stdio.h>
#include <stdlib.h>
// Structure to create a node with data and the next pointer
struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;
int i = 0;
// Function to create Queue
void create(){
    front = rear = NULL;
    printf("\nQueue created Successfully");
}
// Enqueue() operation on a queue
void enqueue(int value) {
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;
    } else {
        rear -> next = ptr;
        rear = ptr;
    }
    i++;
}

// Dequeue() operation on a queue
int dequeue() {
    if (front == NULL) {
        printf("\nUnderflow\n");
        return -1;
    } else {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        return temp_data;
    }
    i--;
}

// Display all elements of the queue
void display() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue element : ");
        temp = front;
        while (temp) {
            printf("_%d ", temp -> data);
            temp = temp -> next;
        }
    }
}

int main() {
    int choice, n, value;
    printf("\tImplementation of Queue using Linked List\n");
      printf("\t-----------------------------------------\n");
         printf("1.Create\n2.Enqueue\n3.Dequeue\n4.Display\n5.sizeOfQueue\n6.headOfQueue\n7.endOfQueue\n8.Exit\n");
        while (1) {
         printf("\nEnter your choice : ");
        scanf("%d", & choice);
        switch (choice) {
            case 1:
                    create();
            break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 3:
                printf("\nDequeued element is :%d\n", dequeue());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nThe size of Queue is : %d\n", i);
            case 6:
                printf("\nThe element at head of queue is %d ", front->data);
                break;
            case 7:
                printf("\nThe element at end of queue is %d ", rear->data);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}
