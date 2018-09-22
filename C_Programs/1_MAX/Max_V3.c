#include<stdio.h>
int main()
{
   int max, num;
   printf("Enter the first number");
   scanf("%d",&num);
   max = num;
   printf("Enter the numbers till non integer = ");
   while(scanf("%d",&num)==1)
   {
       if(num>max)
       {
          max = num;
       }

   }
 printf("THe maximum value is = %d",max);
 return 0;
}
