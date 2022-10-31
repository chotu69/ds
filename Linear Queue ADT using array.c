//4. Implement (Menu Driven Program) Linear Queue ADT using array.
//Program:
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void insert();
void deleteq();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
int main()
{
	int choice;
	while(1)
	{
		printf("1.Insert element to queue\n");
		printf("2.Delete element from queue\n");
        printf("3.Display all elements of queue\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
     switch(choice)
      {
    	case 1:
    		insert();
    		break;
    		case 2:
    		    deleteq();
    		     break;
    		     case 3:
    		         display();
    		         break;
    		         case 4:
    		         	exit(1);
    		         	default:
    		         		printf("Wrong choice\n");    		         	   		
	  }
	}
}
void insert()
{
 int item;
 if(rear == MAX-1)
    printf("queue overflow\n");
 else
 {
 	if(front == -1)
 	front = 0;
 	printf("insert the element in queue :");
 	scanf("%d",&item);
 	rear = rear+1;
 	queue_array[rear] = item; 	
 }
 
}
void deleteq()
{
	if(front == -1 || front > rear)
	{
	  printf("queue overflow\n");
	  return;
    }
	else
	{
	  printf("Element deleted from the queue is :%d\n",queue_array[front]);
	  front = front + 1;
    }	
}
void display()
{
	int i;
    if(front == - 1)
      printf("Queue is empty\n");
    else
    {
      printf("queue is :");
      for(i=front;i<=rear;i++)
	  {
        printf("%d ",queue_array[i]);
        
       }
	}
	printf("\n");
}

