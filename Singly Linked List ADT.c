//6A. Implement Singly Linked List ADT.
//Program:
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data ;
struct node *next ;
}*head ;
void createList (int n) ;
void insert_after_pos (int data) ;
void insert_before_pos (int pos) ;
void displayList ();
void insertBeginning (int data);

void insertEnd (int data) ;
void delete_beginning () ;
void delete_end () ;
void delete_from_pos ();
void reverse ();
int count=0 ;

int main ()
{
int n ,pos,data,i ;
printf ("\nEnter the number of the nodes:\t");
scanf ("%d",&n);
for (i=0;i<=n;i++)
{
count++ ;
}
createList(n);
printf ("\nList is :");
displayList();
insertBeginning (data) ;
printf ("\nList after inserting the begginning :");
displayList();
insertEnd (data);
printf ("\nList after entering at end:");
displayList();
insert_after_pos (data);
printf ("\nThe new list after entering after given position");
displayList();
insert_before_pos (pos) ;
printf ("\nThe new list after entering before given position");
displayList();
delete_beginning ();
printf ("\nList after deleting at beginning :");
displayList();
delete_end ();
printf ("\nList after deleting at end :");
displayList();
delete_from_pos ();

printf ("\nList afetr deleting after the given position :");
displayList();
reverse();
printf ("\nReversed list is :");
displayList();

}
void createList (int n)
{
struct node *newnode , *temp ;
int i ;
head = 0 ;
for (i = 0; i<n ; i++)
{
newnode = (struct node*)malloc(sizeof(struct node));
printf ("\nEnter the new node");
scanf ("%d",&newnode->data);
newnode->next = 0 ;
if (head == 0)
{
head = temp = newnode ;
temp = newnode ;
}
else
{
temp->next = newnode ;
temp = newnode ;
}
}
}
void displayList()
{
struct node *temp ;
int count = 0 ;
if (head == NULL)
{
printf("\nList is empty");
}
else
{
temp = head ;

while (temp != NULL)
{
printf("\n%d",temp->data);
temp = temp->next ;
count++ ;
}
printf("\n");
printf("\nCOUNT IS %d",count);

}
}

void insert_after_pos (int pos)
{
int i=1;
struct node *temp,*newnode;
newnode = (struct node*)malloc(sizeof(struct node));
printf ("\nEnter the position after which the new node to be inserted");
scanf("\n%d",&pos) ;
if (pos>count)
{
printf("\nInvalid position");
}
else
{
temp = head ;

while (i < pos)
{
temp = temp->next ;
i++ ;
}
printf ("\nEnter data to insert after position %d of the list :",pos);
scanf("%d",&newnode->data);
newnode->next = temp->next ;
temp->next = newnode ;

}
}
void insert_before_pos (int pos)
{

int i=1;
struct node *temp,*newnode;
newnode = (struct node*)malloc(sizeof(struct node));
printf ("\nEnter the position before which the new node to be inserted");
scanf("\n%d",&pos) ;
if (pos>count)
{
printf("\nInvalid position");
}
else
{
temp = head ;

while (i < pos-1)
{
temp = temp->next ;
i++ ;
}
printf ("\nEnter data to insert before position %d of the list :",pos);
scanf("%d",&newnode->data);
newnode->next = temp->next ;
temp->next = newnode ;

}
}
void insertBeginning (int data)
{
printf ("\nEnter the data at the beginning of the list :");
scanf ("\n%d",&data);
struct node *temp ;
temp = (struct node*)malloc(sizeof(struct node));
temp->data = data ;
temp->next = head ;
head = temp ;
}
void insertEnd (int data)
{
printf ("\nEnter the data at the end of the list :");
scanf ("\n%d",&data);
struct node *temp,*newnode ;
newnode = (struct node*)malloc(sizeof(struct node));
if (newnode== NULL)
{
printf("\nUnable to allocate the memory");

}
else
{
newnode->data = data ;
newnode->next = NULL ;
temp = head ;
//Now travesring through the list
while (temp->next != NULL )
{
temp = temp->next ;
}
temp->next = newnode ;
}
}
void delete_beginning()
{
struct node *temp ;
temp = head ; //bringing the temp at starting
head = head->next ; // linking the head to second node and discard the first node
free(temp); //clearing the memory at first node whicj is temp
}
void delete_end()
{
struct node *temp,*prevnode ;
temp = head ; //bringing the temp at starting
while (temp->next != 0 )
{
prevnode = temp ; //prevnode is pointing to the node befpre the temp node
temp = temp->next ;
}
if (temp == head )
{
head = 0 ;
}
else
{
prevnode->next = 0 ; //set the next of prevnode to 0 so it will be the last element of the list
}
free (temp);
}
void delete_from_pos ()
{
struct node *temp, *nextnode ;

int pos, i=1;
temp = head ; //bringing temp at starting
printf("\nEnter position");
scanf("\n%d",&pos);
if (pos > count)
{
printf ("\nInvalid position");
}
else
{

while (i<pos-1)
{
temp = temp->next ;
i++ ;
}
nextnode = temp->next ;
temp->next = nextnode->next ;
free (nextnode) ;
}
}
void reverse ()
{
struct node *prevnode , *currentnode, *nextnode ;
prevnode = 0 ;
currentnode = nextnode = head ;
while (nextnode!=0)
{
nextnode = nextnode->next ;
currentnode->next = prevnode ;
prevnode = currentnode ;
currentnode = nextnode ;
}
head = prevnode ;
}

