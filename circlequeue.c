#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int  item[MAX];
int front=-1,rear=-1;

int isfull()
{
    if(front==rear+1 || front==0 && rear==MAX-1)
    return 1;
    return 0;
}

int isempty()
{
    if(front==-1)
    return 1;
    return 0;
}

void enqueue(int element)
{
    if(isfull())
    {
        printf("The queue is full\n");
    }
    else
    {
        if(front==-1)
        front=0;
        rear=(rear+1)%MAX;
        item[rear]=element;
        printf("Entered element is %d\n", element);
    }
}

int dequeue()
{
    int element;
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        element=item[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
        printf("Deleted element is %d\n", element);
        return element;
    }
}

void display()
{
    int i;
    if(isempty())
    printf("Queue is empty\n");
    else
    {
        printf("Front is %d", front);
        printf("Items ->");
        for(i=front;i!=rear;i=(i+1)%MAX )
        {
            printf("%d",item[i]);
        }
        printf("%d",item[i]);
        printf("Rear->%d\n",rear);
    }
    
}

int main()
{
    int choice=1,x;
    while(choice<4 && choice!=0)
    {
        printf("Press 1: Insert an element\n");
        printf("Press 2: Delete an element\n");
        printf("Press 3: Display an element\n");
        printf("Enter your choice\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element which is to be inserted ");

                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default :printf("Invalid choice \n");

                    
        }       
}
  return 0;
}