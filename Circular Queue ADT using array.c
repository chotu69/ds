//5.Program to Implement Circular Queue ADT using array.
//Program:
#include<stdio.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

int main()
{
  int choice,item;
  do
	{
	
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Quit\n");
	printf("Enter your choice :");
	scanf("%d",&choice);
	switch(choice)
	  {
	  	case 1:
	  		printf("Input the element for element for insertion in queue:");
	  		scanf("%d",&item);
	  		insert(item);
	  		break;
	  		case 2:
	  			deletion();
	  			break;
	  			case 3:
	  				display();
	  				break;
	  				case 4:
	  					exit(0);
	  					break;
	  					default:
	  						printf("Wrong choice\n");	  	
	  }
   }
   while(choice!=4);
   return 0;
}

