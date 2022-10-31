//Program (Queue with Linked List):
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
 {
  int data;
  struct node*next;
 };
 struct node *front=0,*rear=0;
 void enqueue(int n);
 void dequeue();
 void display();
 int main()
  {
   int i=1,select,item;
   while(i)
    {       
      printf("\nMainMenu");
      printf("\n1:ENQUEUE");
      printf("\n2:DEQUEUE");
      printf("\n3:DISPLAY");
      printf("\n4:EXIT");
      printf("\nEnteryourchoice :");
      scanf("\n%d",&select);
      switch(select)
       {
        case 1:
           printf("\nEnter the data to insert in the Queue from rear:");
           scanf("\n%d",&item);
           enqueue(item);
           break;
           case 2:
              printf("\nDeletingfromthefront:");
              dequeue();
              break;
              case 3:
                  printf("\nThe list is:");
                  display();
                  break;
                  case 4:
                    exit(0);
                    break;
                    default:
                      printf("\nInvalid Choice");
                      break;
        }
      printf("\n Do u want to continue, please enter 1 or 0\n");
      scanf("%d", &i);
    }
  return 0;
 }
 
 void enqueue(int n)
 {
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next=0;
  if(front==0&&rear==0)
   {
    front=rear=newnode;
   }
  else
   {
    rear->next=newnode;
    rear=newnode;
   }
 }
 
 void dequeue()
 {
  struct node *temp;
  if(front==0&&rear==0)
   {
    printf("\nUnderflow");
   }
  else
   {
    temp=front;
    printf("\nDeleted item is %d",front->data);
    front=front->next;
    free(temp);
   }
 }
 
 void display()
 {
  struct node *temp;
  temp=front;
  if(front==NULL)
   {
    printf("\nUnderflow");
   }
  else
   {
    while(temp!=NULL)
     {
      printf("\t%d",temp->data);
      temp=temp->next;
     }
   }
 }

