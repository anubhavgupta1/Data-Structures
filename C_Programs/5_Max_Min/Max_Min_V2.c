#include<stdio.h>
int main()
{
  int i,n,max,num,min;
  printf("How many numbers = ");
  scanf("%d",&n);
  if(n>0)
  {
    printf("\nEnter the first number = ");
    scanf("%d",&num);
    max = num;
    min = num;
    for(i=1;i<n;i++)
    /* Number of comparisons <= 2 * (n-1) comparisons */
    {
       scanf("%d",&num);
       if(num>max)
       {
         max = num;
       }
       else if(num<max)
       {
         min = num;
       }
    }
  }
  printf("\nThe maximum number is = %d",max);
  printf("\nThe minimum number is = %d",min);
  return 0;
}
