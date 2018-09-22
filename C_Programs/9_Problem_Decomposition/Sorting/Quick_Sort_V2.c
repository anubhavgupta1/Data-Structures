#include<stdio.h>
int part(int a[], int left,int right)
{
   int i,j,t,p;
   i = left;
   j = right;
   p = a[i];
   while(i<j)
   {
      while((i<j)&&(a[i]<p))
      {
        i++;
      }
      while((i<j)&&(a[j]>=p))
      {
        j--;
      }
      if(i<j)
      {
        t   = a[i];
        a[i]= a[j];
        a[j]=    t;
      }
   }
   if(a[j]<=p)
   {
      return j;
   }
   else
   {
       return (j-1);
   }
}
 int qsort(int a[],int i,int j)
 {
    int p;
    if(i<j)
    {
       p = part(a,i,j);
       qsort(a,i,p);
       qsort(a,p+1,j);
    }
 }
int main()
{
   int a[100],n,i;
   printf("Enter the number of Elements = ");
   scanf("%d",&n);
   printf("\nEnter the values = ");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   
   printf("\n----Array is----------\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
   qsort(a,0,n-1);
   printf("\n----Sorted Array is--------\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
   return 0;
}
