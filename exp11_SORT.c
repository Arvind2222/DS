//Experiment 11

#include <stdio.h>
int a[20],n;
void read()
{
  int i,j;
  printf("Enter the no: of elements");
   scanf("%d",&n);
   printf("Enter the array for sorting\n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
}

void insertion_sort()
{
 int i,j,y;
    read();
   for(i=1;i<n;i++)
   {
       y=a[i];
     for(j=i-1;j>=0&&y<a[j];j--)
     a[j+1]=a[j];
     a[j+1]=y;
   }

}
void radix_sort()
{
  int i,j,l,x,p,k,d=1,bucket[10][20],b[10];
  read();
  printf("Enter the max no: of digits");
  scanf("%d",&p);
  for(i=0;i<p;i++)
  {
    for(j=0;j<10;j++)
    b[j]=0;
    for(k=0;k<n;k++)
    {
       x=(a[k]/d)%10;
      bucket[x][b[x]]=a[k];
      b[x]++;
     }

     l=0;
    for(j=0;j<10;j++)
    {
      for(k=0;k<b[j];k++)
      {
	a[l]=bucket[j][k];
	l++;
      }
    }
    d=d*10;
  }
}

void shell_sort()
{
    int incr,p,k,i,j;
    read();
     incr=n/2;
      for(i=incr;i>0;i=i/2)
       {
	for(j=i;j<n;j++)
	{
	   p=a[j];
	   for(k=j-i;k>=0&&p<a[k];k=k-i)
	   a[k+i]=a[k];
	   a[k+i]=p;
	}
}
}

void display()
{
     int i;
      printf("Sorted is\n");
     for(i=0;i<n;i++)
    {
       printf("%d\t",a[i]);
    }
}

int main()
{
     int op;
     do
     {

	printf("\n1:Insertion Sort\t2:Radix Sort\t3:Shell Sort\t4:Display\t5:Exit\n");
	printf("Enter the option");
	scanf("%d",&op);
	switch(op)
       {
	  case 1:insertion_sort();
		  break;
	  case 2:radix_sort();
		break;
	  case 3:shell_sort();
		     break;
	  case 4:display();break;
	  case 5:return 0;
		break;
       }

     }
     while(op);
     return 0;
}


/*
 1:Insertion Sort 2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option1
Enter the no: of elements3
Enter the array for sorting
45
56
788

1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option4
Sorted is
45  56  788 
1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option3
Enter the no: of elements5
Enter the array for sorting
23
4454
67
89
09

1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option4
Sorted is
9 23  67  89  4454  
1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option5
1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option3
Enter the no: of elements6 
Enter the array for sorting
33
52
1
233
122222
7

1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option4
Sorted is
1 7 33  52  233 122222  
1:Insertion Sort  2:Radix Sort  3:Shell Sort  4:Display 5:Exit
Enter the option


 */
 
