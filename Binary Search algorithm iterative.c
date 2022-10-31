//Program: Binary Search algorithm
//Iterative Method
#include<stdio.h>
#include<conio.h>

int binary(int low,int high,int key,int a[100])
 {
  int mid,flag=0;
  while(low<=high)
  {
   mid=(low+high)/2;
   if(a[mid]==key)
    {
     flag=1;
     return mid;
    }
   else if(key<a[mid])
   {
    flag=0; high=mid-1;
    binary(low,high,key,a);
   }
   else
   {
    flag=0; low=mid+1;
    binary(low,high,key,a);
   }
  }
  if(flag==0) return-1;
 }
int main()
 {
  int a[100],high,low,i,n,key,result;
  printf("\n How many array elements?=");
  scanf("%d",&n);
  printf("\n Enter array element in ascending order=");
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  printf("\n Enter the number that you have to search=");
  scanf("%d",&key);
  low=0;high=n-1;
  result=binary(low,high,key,a);
  if(result==-1)
   printf("Element %d is not present",key);
  else
   printf("Element %d is at index=%d",key,result); getch();
}

