#include<stdio.h>
int fib(int n)
{
   int x, y;
   if(n==0)
   {
     return 0;
   }
   else if(n==1)
   {
     return 1;
   }
   else
   {
     x = fib(n-1);
     y = fib(n-2);
     return x + y;
   } 
}
int main()
{
   int n, i, res;
   printf("Enter the position = ");
   scanf("%d",&n);
   for(i=0;i<=n;i++)
   {
      res = fib(i);
      printf("The result of fib(%d) is %d  \n",i,res);
   }
   return 0;
}
