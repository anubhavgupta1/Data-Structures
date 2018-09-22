#include<stdio.h>
void tower(int m,char from, char to, char via)
{
  if(m==1)
  {
    printf("Move from %c to %c \n ",from,to);
  }
  else
  {
     tower(m-1,from,via,to);
     printf("Move from %c to %c \n ",from,to);
     tower(m-1,via,to,from);
  }
}
 int main()
 {
    int n ;
    printf("Enter the number of discs = ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
 }
     
