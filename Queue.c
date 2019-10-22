#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define max 100

int main()
{
	int a;
	while(1)
	{
		printf("Queue Menu \n");
		printf("1.Enqueue \n");
		printf("2.Dequeue  \n");
		printf("3.Display  \n");
		printf("4.Exit  \n");
		printf("Enter your choice: \n");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			enqueue();
			break;
	
		case 2:
			dequeue();
			break;
	
		case 3:
			display();
			break;
	
		case 4:
			exit(0);
			break;
	
		default:
			printf("Invalid ! \n");
			break;
		}
	}
}

int queue[max];
int front=-1,rear=-1;
void enqueue()
{
	int x;
	if(rear==max-1)
	{
		printf("Queue is full");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("Enter the number to be inserted in the queue:\n");
		scanf("%d",&x);
		rear=rear+1;
		queue[rear]=x;
	}
}

void dequeue()
{
	int y;
	if(front==-1 || front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		y=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%max;
		}
		printf("the number deleted is %d\n",y);
	}
}
void display()
{
	int i;
	if(front==-1 || front>rear)
	{
		printf("QUEUE IS EMPTY");
	}
	else
	{
		printf("The queue is\n");
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\n",queue[i]);
			}
		}
		else if(rear<front)
		{
			for(i=rear;i<=max-1;i++)
			{
				printf("%d\n",queue[i]);
			}
			for(i=0;i<=front;i++)
			{
				printf("%d\n",queue[i]);
			}
		}
	}
}


