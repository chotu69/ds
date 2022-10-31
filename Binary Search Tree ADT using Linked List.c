//8. Implement Binary Search Tree ADT using Linked List.
//Program:
#include <stdio.h>
#include <stdlib.h>

struct node
 {
  int data; 
  struct node *right_child; 
  struct node *left_child; 
 };

 void search(int i, struct node *n) 
 {
 if (n == NULL)
  printf("\nValue does not exist in tree!");
 else if(n->data == i)
  printf("\nValue found!");
 else if(i > n->data)
  search(i, n->right_child);
 else
  search(i, n->left_child);
 }

 struct node* smallest(struct node *root)
 {
  while(root != NULL && root->left_child != NULL)
  {
   root = root->left_child;
  }
  return root;
 }
 
 struct node* largest(struct node *root)
 {
  while (root != NULL && root->right_child != NULL)
   {
    root = root->right_child;
   }
  return root;
 }


 struct node* new_node(int x)
 {
  struct node *p;
  p = malloc(sizeof(struct node));
  p->data = x;
  p->left_child = NULL;
  p->right_child = NULL;
  return p;
 }

 struct node* insert(struct node *root, int x)
 {
  if(root==NULL)
  return new_node(x);
  else if(x>root->data) 
   root->right_child = insert(root->right_child, x);
  else 
   root->left_child = insert(root->left_child,x);
  return root;
 }

 struct node* delete(struct node *root, int x)
 {
  if(root==NULL)
  return NULL;
  if (x>root->data)
   root->right_child = delete(root->right_child, x);
  else if(x<root->data)
   root->left_child = delete(root->left_child, x);
  else
  {
   if(root->left_child==NULL && root->right_child==NULL)
    {
     free(root);
      return NULL;
    }
  else if(root->left_child==NULL || root->right_child==NULL)
   {
    struct node *temp;
    if(root->left_child==NULL)
    temp = root->right_child;
    else
    temp = root->left_child;
    free(root);
    return temp;
  }
  else
  {
   struct node *temp = smallest(root->right_child);
   root->data = temp->data;
   root->right_child = delete(root->right_child, temp->data);
  }
 }
  return root;
 }

 void inorder(struct node *root)
 {
  if(root!=NULL) 
  {
   inorder(root->left_child); 
   printf(" %d ", root->data); 
   inorder(root->right_child);
  }
 }

int main()
{
 struct node *root,*min,*max;
 int x;
 root = new_node(20);
 insert(root,5);
 insert(root,1);
 insert(root,15);
 insert(root,9);
 insert(root,7);
 insert(root,12);
 insert(root,30);
 insert(root,25);
 insert(root,40);
 insert(root, 45);
 insert(root, 42);

 inorder(root);
 printf("\n");

 root = delete(root, 1);
 root = delete(root, 40);


 root = delete(root, 45);

 root = delete(root, 9);
 inorder(root);

 printf("\n");
 min=smallest(root);

 printf("\nSmallest value is %d\n", min->data);
 max=largest(root);
 printf("\nlargest value is %d\n", max->data);
 printf("\n enter element to search\n");
 scanf("%d",&x);
 search(x,root);
 return 0;
 }

