#include<stdio.h>
int fact(int);
int main()
{
  int n;
  printf("Enter the value of n = ");
  scanf("%d",&n);
  printf("The factorial is %d",fact(n));
  return 0;
}
 int fact(int n)
 {
   int res = 1;
   if(n>1)
   {
     res = n * fact(n-1);
   } 
   return res;
 }
