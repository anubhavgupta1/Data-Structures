#include<stdio.h>
int max(int a, int b)
{
  if(a>b)
  {
    return a; 
  }
  else
  {
     return b;
  }
}
int min(int a, int b)
{
  if(a<b)
  {
    return a; 
  }
  else
  {
     return b;
  }
}
int build_tourn(int tourn[], int n)
{
   int i;
   /*computing tournament */
  for(i = (2 *n)-2; i>1;i=i-2)
  {
     tourn[i/2] = max(tourn[i], tourn[i+1]);
  }
}
int next_max(int tourn[],int n)
{
   int i, next;
    
   /* Downward Traversal till i= 2*n-1 */
   next = min(tourn[2],tourn[3]);
   if(tourn[2]>tourn[3])
   {
      i = 4;
   }
   else
   {
      i = 6;
   }
   while(i<=(2*n)-1)
   {
      if(tourn[i]>tourn[i+1])
      {
         next = max(tourn[i+1],next);
         i = i * 2;
      }
      else
      {
         next = max(tourn[i], next);
         i = (i+1) * 2 ;
      }
   }
   return next;
}
int main()
{
  int tourn[100], i, n,m,next;
  
  /*Read N */
  printf("Give N = ");
  scanf("%d",&n);
  printf("The number of elements are  = %d",n);
  
  /* Storing the data */

  printf("\nEnter the elements = ");
  for(i=n;i<=(2*n)-1; i++)
  {
     scanf("%d",&tourn[i]);
  }  
  
  build_tourn(tourn,n);
  
  /*printing the tournament*/
  printf("\n-------------------\n");
  for(i=1;i<=(2*n)-1;i++)
  {
     printf("%d\t",tourn[i]); 
  } 
  printf("\n-------------------\n");
  
  next = next_max(tourn,n);
  printf("The result is %d ", next);
  return 0;
}
