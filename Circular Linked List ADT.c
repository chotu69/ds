//6B. Implement Circular Linked List ADT.
//Program:
#include<stdio.h>
#include<stdlib.h>
struct node

{
int data;
struct node *next;
};
struct node *head,*tail;
void createList(int n);
void insertBig();
void insertEnd();
void insert_after_given_position();
void del_from_beg();
void del_from_end();
void del_from_pos();
void displayList();
int main()
{
int n;
printf("\nEnter total no of nodes");
scanf("%d",&n);
createList(n);
printf("\nThe nodes are\n");
displayList();
insertBig();
printf("\nThe nodes are\n");
displayList();
insertEnd();
printf("\nThe nodes are\n");
displayList();
insert_after_given_position();
printf("\nThe nodes are\n");
displayList();
del_from_beg();
printf("\nThe nodes after deleting first node\n");
displayList();
del_from_end();
printf("\nThe nodes after deleting last node\n");
displayList();
del_from_pos();
displayList();
}
void createList(int n)
{

struct node *newnode;
int i;
head=0;
for(i=0;i<n;i++)

{
newnode=(struct node*)malloc(sizeof(struct node));
printf("\n enter new node");
scanf("%d",&newnode->data);
newnode->next=0;
if(head==0)
{
head=tail=newnode;

tail->next=head;
}
else
{
tail->next=newnode;
tail=newnode;

tail->next=head;
}

}
}
void insertBig()
{
//Create new node
struct node *newNode, *temp;
newNode = (struct node*)malloc(sizeof(struct node));
printf("\n Enter data to insert at begin\n");
scanf("%d",&newNode->data);
//Checks if the list is empty.
if(head == NULL){
//If list is empty, both head and tail would point to new node.
head = newNode;
tail = newNode;
newNode->next = head;
}
else {
temp = head;
newNode->next = temp;
head = newNode;
//Since, it is circular linked list tail will point to head.
tail->next = head;
}
}

void insertEnd()
{
//Create new node
struct node *newNode, *temp;
newNode = (struct node*)malloc(sizeof(struct node));
printf("\n Enter data to insert at end\n");
scanf("%d",&newNode->data);
tail->next=newNode;
tail=newNode;
tail->next=head;
}
void insert_after_given_position()
{
int i=1,pos;
struct node *newNode, *temp;
newNode = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the node
printf("\nEnter position\n");
scanf("%d", &pos);
/*if(position>count)
{
printf("\n Invalid Position");
}
else
{*/
temp = head;
// Traverse to the given position in the list
while(i<pos)
{
temp=temp->next;
i++;
}
printf("\nEnter data to insert after position %d of the list: ",pos);
scanf("%d", &newNode->data);
newNode->next = temp->next; //Link the inserted node with the next node
temp->next = newNode; // Link the previous node and the inserted node
tail->next=head;
}
void del_from_beg()
{
struct node* temp;
temp = head; // bringing temp at starting

head=head->next; //link between head and second node
free(temp); //relese memory
tail->next=head;
}
void del_from_end()
{
struct node* temp1,*prev;
temp1=head;
while(temp1 -> next != head)
{
prev = temp1;
temp1 = temp1 -> next;
}
prev -> next = head;
free(temp1);
}
void del_from_pos()
{
struct node* temp,*nextnode;
int pos,i=1;
temp = head; // bringing temp at starting
printf("\n Enter position");
scanf("%d",&pos);
/* if(pos>count)
{
printf("\nInvalid Position");
}
*/
while(i<pos-1)
{
temp=temp->next;
i++;
}
nextnode=temp->next;
temp->next=nextnode->next;
free(nextnode);
printf("\n\nThe List after deleting position %d node is \n",pos);
}

void displayList()
{

struct node *temp;
if(head == NULL)
{
printf("List is empty.");
}
else
{
temp = head;
while(temp -> next != head)
{
printf("%d\t", temp->data);
temp = temp->next;
}
printf("%d\t", temp->data);
}
printf("Circular Print %d",tail->next->data);
}

