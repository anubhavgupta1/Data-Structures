#include<stdio.h>
int partition(int a[], int i,int j,int *l)
{
   int b[50], p,q,m,n,count,temp;
   p = a[i];
   m = i+1;
   n = j;
   count = 0;
   for(q=i+1;q<=j;q++)
   {
     if(a[q]>=p)
     {
        b[m++] = a[q];
        count ++;
     }
     else
     {
        b[n--] = a[q];
     }
   }
   b[i] = b[i+count];
   b[i+count] = p;
   *l = i+ count;
   for(q=i;q<=j;q++)
   {
     a[q]=b[q];
   }
}
 int qsort(int a[],int i,int j)
 {
    printf("\n I = %d J = %d",i, j);
    int l;
    if(i<j)
    {
       partition(a,i,j,&l);
       qsort(a,i,l-1);
       qsort(a,l+1,j);
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
