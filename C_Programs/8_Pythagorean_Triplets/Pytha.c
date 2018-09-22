#include<stdio.h>
int main()
{
  int curr,prev,pprev;
  int n, i, count = 0;
  printf("Number of elements = ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    
    scanf("%d",&curr);
    
    /* skip negative integers */
    if(curr<0)
    {
       continue ;
    }
    
    if(count = 0)
    {
      pprev = curr;
      count = 1;
    } 
    else
    {
       if(count == 1)
       {
          prev = curr;
          count = 2;
       }
       else
       {
          if(pprev*pprev + prev*prev == curr*curr)
          {
printf("%d %d %d are pythagorean triplet",pprev,prev,curr);
          }
          pprev = prev;
          prev  = curr;
       }
    } 
  }
  return 0;
}
