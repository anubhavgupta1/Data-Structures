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
int main()
{
  int tourn[100], i, n,m;
  
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
  for(i=1;i<=(2*n)-1;i++)
  {
     printf("%d\t",tourn[i]); 
  } 
  return 0;
}
