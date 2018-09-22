#include<stdio.h>
int swap(int *i, int *j)
{
   int t;
   t  = *i;
   *i = *j;
   *j = t;
}
int maxi(int arr[], int max, int index)
{
    int i;
    for(i = 1;i<index;i++)
    {
      if(max<arr[i])
      {
        max = arr[i];
      }
    }
    return max; 
}
int mini(int arr[], int min, int index)
{   
    int i;
    for(i = 1;i<index;i++)
    {
       if(min>arr[i])
       {
          min = arr[i];
       }
    }
    return min;
}
int main()
{
   int n, m, max, min, i, num1, num2;
   int large[100], small[100], index1 = 1, index2 = 1;
   int largest, smallest;
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
      if(num1>=num2)
      {
         large[index1] = num1;
         index1 ++ ;
         small[index2] = num2;
         index2 ++ ;
      }
      else
      {
        large[index1 ++] = num2;
        small[index2 ++] = num1;
      }
   }
   printf("\n-------------Part 4 ----------\n");
   /*printing the results*/
   largest  = maxi(large,max, index1);
   smallest = mini(small,min,index2);
   printf("\nThe largest value is  = %d", largest);
   printf("\nThe smallest value is  = %d", smallest);
   return 0;
}

