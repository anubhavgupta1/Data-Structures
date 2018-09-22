#include<stdio.h>
int main()
{
  int i,n,max,num;
  printf("How many numbers = ");
  scanf("%d",&n);
  if(n>0)
  {
    printf("\nEnter the first number = ");
    scanf("%d",&num);
    max = num;
    for(i=1;i<n;i++)
    {
       scanf("%d",&num);
       if(num>max)
       {
         max = num;
       }
    }
  }
  printf("The maximum number is = %d",max);
  return 0;
}
