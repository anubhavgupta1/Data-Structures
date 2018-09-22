#include<stdio.h>
int main()
{
  int i,j,n,a[20],t;
  printf("Enter the number of elements = ");
  scanf("%d", &n);
  printf("\nEnter the integers in an array = ");
  for(i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
       if(a[i]<a[j])
       {
          t = a[i];
          a[i] = a[j];
          a[j] = t;
       }
    }
  }
 printf("\nThe sorted array is \n");
 for(i=0;i<n;i++)
 {
    printf("%d\t",a[i]);
 }
 return 0;
}
