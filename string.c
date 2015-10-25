/*=======================================================================================

    Author : Arvind Mishra 
    Roll No :14CE7029
    Batch : C2
 
 This program implements a menu driven string operational program :) in C
 https://github.com/Arvind2222/string_without_lfunction
 
 The program is copyright under the GNU GPL v2.0
 
========================================================================================*/

  #include <stdio.h>
  int main(void)
  {
  char a[20],b[20],c[20];
  int n,n1=0,n2,i=0,cnt=0,l,l1,sum=0;
  printf("\nHello Enter any to continue : \n");
  printf("1.String Copy\n");
  printf("2.String Length\n");
  printf("3.String Reverse\n");
  printf("4.String Concatenation\n");
  scanf("%d",&n);
  switch(n)
  {
  case 1:
  printf("Enter a string : ");
  scanf("%s",a);
    while(a[i]!='\0')
    {
    cnt++;
    i++;
    }
    for(l=0;l<cnt;l++)
    {
    b[l]=a[l];
    }
    printf("Copied String : %s\n",b);
    break;
  case 2:
  printf("Enter a string : ");
  scanf("%s",a);
    while(a[i]!='\0')
    {
    cnt++;
    i++;
    }
    printf("Length of the string : %d\n",cnt);
    break;
  case 3:
  printf("Enter a string : ");
  scanf("%s",a);
    while(a[i]!='\0')
    {
    cnt++;
    i++;
    }
  printf("Reversed String : \n");
    for(i=(cnt-1);i>=0;i--)
    {
    printf("%c",a[i]);
    }
  break;
  case 4:
  printf("Enter 1st string\n");
  scanf("%s",a);
  printf("Enter 2nd string\n");
  scanf("%s",b);
    while(a[i]!='\0')
    {
    cnt++;
    i++;
    }
    i=0;
    while(b[i]!='\0')
    {
    n1++;
    i++;
    }
    sum=n1+cnt;
    for(l=cnt,l1=0;l<n1;l++,l1++)
    {
    a[l]=b[l1];
    }
    printf("Concatenated String : %s\n",a);
    break;
    default:
    printf("Invalid Entry!!!\n");
  }
}


/*================================OUTPUT================================================

Arvinds-MacBook-Pro:DS arvind$ make string 
cc     string.c   -o string
Arvinds-MacBook-Pro:DS arvind$ ./string 

Hello Enter any to continue : 
1.String Copy
2.String Length
3.String Reverse
4.String Concatenation
2
Enter a string : arvindmishra
Length of the string : 12

-----------------------------------------------------------------------------------------

Hello Enter any to continue : 
1.String Copy
2.String Length
3.String Reverse
4.String Concatenation
3
Enter a string : arvindgreat
Reversed String : 
taergdnivra

======================================================================================*/