/*=======================================================================================
 
 Author : Arvind Mishra
 Roll No : 14CE7029
 Batch : C2
 
 This program implements a menu driven Stack program in C
 https://github.com/Arvind2222/stack/tree/master
 
 The program is copyright under the GNU General Public Licence v2.0.
 
=======================================================================================*/
#include <stdio.h>

#define MAX 5
int top, status;
 
void push (int stack[], int item)
{   if (top == (MAX-1))
	status = 0;
    else
    {   status = 1;
	++top;
	stack [top] = item;
    }
}
 
int pop (int stack[])
{  
    int ret;
    if (top == -1)
    {   ret = 0;
	status = 0;
    }
    else
    {   status = 1;
	ret = stack [top];
	--top;
    }
return ret;
}
 
void display (int stack[])
{   int i;
    printf ("\nThe Stack is: ");
    if (top == -1)
	printf ("empty");
    else
    {   for (i=top; i>=0; --i)
	   printf ("\n--------\n|%3d   |\n--------",stack[i]);
    }
    printf ("\n");
}
 
int main(void)
{  
    int stack [MAX], item;
    int ch;
    top = -1;
 
    do
    {  do
       {   printf ("\nMAIN MENU");
	   printf ("\n1.PUSH (Insert) in the Stack");
	   printf ("\n2.POP  (Delete) from the Stack");
	   printf ("\n3.Exit (End the Execution)");
	   printf ("\nEnter Your Choice: ");
	   scanf  ("%d", &ch);
	   if (ch<1 || ch>3)
	       printf ("\nInvalid Choice, Please try again");
	}while (ch<1 || ch>3);
       switch (ch)
       {case 1:
		printf ("\nEnter the Element to be pushed : ");
		scanf  ("%d", &item);
		printf (" %d", item);
		push (stack, item);
		if (status)
		{   printf ("\nAfter Pushing ");
		    display (stack);
		    if (top == (MAX-1))
			printf ("\nThe Stack is Full");
		}
		else
		    printf ("\nStack overflow on Push");
		break;
       case 2:
		item = pop (stack);
		if (status)
		{    printf ("\nThe Popped item is %d.  After Popping: ",item);
		     display (stack);
		}
		else
		     printf ("\nStack underflow on Pop");
		break;
       default:
		printf ("\nEND OF EXECUTION");
       }
    }while (ch != 3);
   return 0;
}

/*======================================OUTPUT===========================================

 Arvinds-MacBook-Pro:DS arvind$ make stack
 cc     stack.c   -o stack
 Arvinds-MacBook-Pro:DS arvind$ ./stack
 
 MAIN MENU
 1.PUSH (Insert) in the Stack
 2.POP  (Delete) from the Stack
 3.Exit (End the Execution)
 Enter Your Choice: 1
 
 Enter the Element to be pushed : 233
 233
 After Pushing
 The Stack is:
 --------
 |233   |
 --------
 
 MAIN MENU
 1.PUSH (Insert) in the Stack
 2.POP  (Delete) from the Stack
 3.Exit (End the Execution)
 Enter Your Choice: 2
 
 The Popped item is 233.  After Popping:
 The Stack is: empty
 
 MAIN MENU
 1.PUSH (Insert) in the Stack
 2.POP  (Delete) from the Stack
 3.Exit (End the Execution)
 Enter Your Choice: 3
 
 END OF EXECUTION
 
 ======================================================================================*/