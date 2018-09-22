#include<stdio.h>
int swap(int *i, int *j)
{
   int t;
   t = *i;
   *i = *j;
   *j = t;
}
int main()
{
   int n, m, max, min, i, num1, num2;
   int large[100], small[100], index1 = 1, index2 = 1; 
   printf("----------------part1--------\n");   
   /* read N */
   printf("Give the value of n = ");
   scanf("%d",&n);
   printf("The number of elements are  = %d",n);

   printf("\n------------Part 2-----------\n");
   /*First number or first and second number intilization*/
   /* if n = odd scan ony one value */
   /* if n = even scan two values */
   printf("Enter the value = ");
   scanf("%d", &max);
   min = max ;
   /* we are telling we have read a number */
   m = n - 1 ;
   /* if n is even read one more number */
   if(n%2==0)
   {
      scanf("%d",&min);
      if(max<min)
      {
         swap(&max,&min);
      }
    //we are telling we have read two numbers 
      m = m - 1;
   }
   printf("The remaining characters are = %d",m);
   
   printf("\n ------------Part 3 ----------\n");
   /* Reading Remaining elements and comparing      		them in pairs*/
   for(i=1;i<=m/2;i++)
   {
      scanf("%d %d", &num1, &num2);
      if(num1<num2)
      {
          swap(&num1, &num2);
      }
      if(max<num1)
      {
          max = num1;
      }
      if(min>num2)
      {
          min = num2;
      }
   }
   printf("\n-------------Part 4 ----------\n");
   /*printing the results*/
   printf("\nThe largest value is  = %d", max);
   printf("\nThe smallest value is  = %d", min);
   return 0;
}

