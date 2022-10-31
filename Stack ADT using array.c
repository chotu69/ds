//1.Program to Implement Stack ADT using array.

//Program:

#include<stdio.h>
#define MAX 50
char stack[MAX];
int TOP=-1;

int pop(int[]);
int display(int[]);
int push(int[],int);

int main(){
	int choice,num;
	while(1){
	printf("Enter your choice:\n1)Display\n2)Push\n3)Pop\n4)Exit\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				display(stack);
				break;
			case 2:
				printf("Enter number to enter\n");
				scanf("%d",&num);
				push(stack,num);
				break;
			case 3:
				pop(stack);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid choice");
		}
	}
	return 0;
}

int display(int stack[]){
	int i;
	if(TOP==-1)
		printf("Stack is empty\n");
	else{
	printf("%d <--TOP\n",stack[TOP]);
	for(i=(TOP-1);i>=0;i--){
		printf("%d",stack[i]);
		printf("\n");
		}
	}
}

int push(int stack[],int num){
	if((TOP-1)==MAX)
		printf("Stack is full\n");
	else{
		TOP++;
		stack[TOP]=num;
	}
}

int pop(int stack[]){
	int del;
	if(TOP==-1)
		printf("Stack is empty\n");
	else{
		del=stack[TOP];
		TOP--;
		printf("Deleted number is %d\n",del);
	}
}

