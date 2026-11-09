#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = item;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }

    return queue[front++];
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Removed element is %d\n", dequeue());

    display();

    return 0;
}