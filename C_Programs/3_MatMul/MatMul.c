#include<stdio.h>
int main()
{
  int a[10][10], b[10][10],r1[10][10],i,j,k;
  int r,c,p;
  printf("Enter the number of rows =  ");
  scanf("%d",&i);
  printf("Enter the number of columns = ");
  scanf("%d",&j);
  printf("\nEnter the elements of first array = ");
  for(r=0;r<i;r++)
  {
    for(c = 0; c<j;c++)
     {
        scanf("%d",&a[r][c]);
     }
  }
  printf("Enter the number of columns = ");
  scanf("%d",&k);
  printf("Enter the elements of second array = ");
  for(r=0;r<j;r++)
  {
    for(c = 0; c<k;c++)
     {
        scanf("%d",&b[r][c]);
     }
  }
 printf("\n___________________\n");
 for(r=0;r<i;r++)
 {
   for(c=0;c<k;c++)
   {
        r1[r][c]= 0;
       for(p=0;p<j;p++)
       {
         r1[r][c]=r1[r][c] + a[r][p]*b[p][c];  
       }
   }
 }
 printf("\nThe matrix a is \n");
  for(r=0;r<i;r++)
  {
    for(c = 0; c<j;c++)
     {
        printf("%d\t",a[r][c]);
     }
     printf("\n");
  }
  printf("\nThe matrix b is \n");
  for(r=0;r<j;r++)
  {
    for(c = 0; c<k;c++)
     {
        printf("%d\t",b[r][c]);
     }
     printf("\n");
  }
  printf("\nThe matrix c is \n");
  for(r=0;r<i;r++)
  {
    for(c = 0; c<k;c++)
     {
        printf("%d\t",r1[r][c]);
     }
     printf("\n");
  }
  return 0;
}
