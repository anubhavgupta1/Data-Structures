#include<stdio.h>
int great(int a, int b)
{
   return a>b;

} 
int main()
{
   int a,b,c;
   printf("enter two integers = ");
   scanf("%d %d",&a,&b);
   c = great(a,b);
   printf("The value of c is = %d",c);
   return 0;
}
