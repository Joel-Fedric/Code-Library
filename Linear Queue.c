#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 5
#define TRUE 1
#define FALSE 0

struct queue
{
    int front;
    int rear;
    int items[QUEUESIZE];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *);
void dequeue(QUEUE *);
void display(QUEUE *);
int full(QUEUE *);
int empty(QUEUE *);

int main()
{
    QUEUE q;
    q.front = 0;
    q.rear = -1;

    int choice;

    while(1){
        printf("MENU\n");
        printf("1-Enqueue\n");
        printf("2-Dequeue\n");
        printf("3-Display\n");
        printf("4-Exit\n");

        printf("\nEnter your choice\n ");
        scanf("%d", &choice);

        switch(choice){
            case 1: enqueue(&q);
                    break;
            case 2: dequeue(&q);
                    break;
            case 3: display(&q);
                    break;
            case 4: printf("Terminating\n");
                    exit(0);
        }
    }

    return 0;
}

int full(QUEUE *q)
{
    if(q->rear == QUEUESIZE - 1)
        return TRUE;
    else
        return FALSE;
}

void enqueue(QUEUE *q)
{
    if(full(q)){
        printf("Queue full\n");
        return;
    }
    int x;
    printf("Enter the enqueue item\n");
    scanf("%d", &x);

    q->rear++;
    q->items[q->rear] = x;
}

int empty(QUEUE *q)
{
    if(q->front > q->rear)
        return TRUE;
    else
        return FALSE;
}

void dequeue(QUEUE *q)
{
    if(empty(q)){
        printf("Empty queue\n");
        return;
    }
    int x;
    x = q->items[q->front];
    printf("Dequeued Item is %d\n", x);
    q->front++;
}

void display(QUEUE *q)
{
    if(empty(q)){
        printf("Empty Queue\n");
        return;
    }
    int i;
    for(i = q->front; i<= q->rear; i++)
        printf("%d\n", q->