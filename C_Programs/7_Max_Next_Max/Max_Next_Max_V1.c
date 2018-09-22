#include<stdio.h>
int swap(int *max, int *next_max)
{
   int t;
   t    = *max;
   *max = *next_max;
   *next_max = t;
}
int main()
{
   int i,n,num,max,next_max;
   printf("Enter the number of elements = ");
   scanf("%d",&n);
   printf("Enter first two integers = ");
   scanf("%d %d",&max,&next_max);
   if(max<next_max)
   {
      swap(&max,&next_max);
   }
   for(i=0;i<n-2;i++)
   {
      scanf("%d",&num); 
      if(max<num)
      {
          next_max = max;
          max = num;
      }
      else if(next_max<num)
      {
          next_max = num ;
      }
   }
   printf("\nThe maximum value is = %d",max);
   printf("\n The next maximum is = %d", next_max);
   return 0;
}
