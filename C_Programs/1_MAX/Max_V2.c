#include<stdio.h>
int main()
{
   int a ,max ,i,n;
   printf("How many numbers = ");
   scanf("%d",&n);
   printf("Enter the first number = ");
   scanf("%d",&a);
   max = a;
   for(i = 1;i<n;i++)
   {
      scanf("%d",&a);
      if(a>max)
      {
          max = a;
      }
   }
   printf("The maximum value is  = %d",max);
   return 0;
}
