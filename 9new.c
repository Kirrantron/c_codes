#include<stdio.h>//imp:null is represented with zero. to create a null space in array use integer 0
int main()
{
 int i,b,flag,count_of_zeroes,length;
 length=0;//it is the total length of the string
 count_of_zeroes=0;
 char a[50]="000044521558";
 //scanf("%s",a);
 printf("The string entered is: %s\n",a);
 i=0;
 while(a[i]!=0)
 {
  b=a[i]-48;
  if(b>0)
  {
   break;
  }
  i++;
  count_of_zeroes++;
 }

 for(i=0;a[i]!=0;i++)
 {
  length++;
 }


 for(i=0;i<=length;i++)
 {
  if(i==length-count_of_zeroes)
  {
   for(i=length-count_of_zeroes;i<=length;i++)
   {
    a[i]=0;
   }
  }
  a[i]=a[count_of_zeroes+i];
 }

 printf("%s",a);
}
