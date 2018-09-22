#include<stdio.h>
int merge(int a[], int i, int j)
{
   int b[100],start,l,mid,k;
   l     = i;
   start = i; 
   mid = (i + j)/2;
   k = mid +1;
  
   //form array
   while(i<=mid && k<=j)
   {
     if(a[i]>=a[k])
     {
       b[l++] = a[i++];
     }
     else
     {
        b[l++] = a[k++];
     }
   }
   if(i>mid)
   {
     while(k<=j)
     {
       b[l++] = a[k++];
     }
   }
   else if(k>j)
   {
     while(i<=mid)
     {
        b[l++] = a[i++];
     }
   }
   for(l= start;l<=j;l++)
   {
     a[l] = b[l];
   }
}
int mergesort(int a[],int i, int j)
{
  printf("I = %d J = %d\n",i,j);
  int mid;
  if(i<j)
  {
     mid = (i+j)/2;
     mergesort(a,i,mid);
     mergesort(a,mid+1,j);
     merge(a,i,j);
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
   mergesort(a,0,n-1);
   printf("\n----Sorted Array is--------\n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",a[i]);
   }
    return 0;
}
