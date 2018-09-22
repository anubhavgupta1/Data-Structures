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
   
  /*computing tournament */
  for(i = (2 *n)-2; i>1;i=i-2)
  {
     tourn[i/2] = max(tourn[i], tourn[i+1]);
  }
  
  /*printing the tournament*/
  printf("\n-------------------\n");
  for(i=1;i<=(2*n)-1;i++)
  {
     printf("%d\t",tourn[i]); 
  } 
  printf("\n-------------------\n");
  
  //computing next maximum value
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
         next = max(tourn[i],next);
         i = (i + 1) * 2;

     }
  }
  printf("The result is %d ", next);
  return 0;
}
