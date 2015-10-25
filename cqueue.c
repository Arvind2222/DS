/*=======================================================================================
    Author : Arvind Mishra 
    Roll No :14CE7029
    Batch : C2
 
 This program implements a menu driven circular queue progeam :) in C
 https://github.com/Arvind2222/cqueue
 
 The program is copyright under the GNU GPL v2.0
 
========================================================================================*/
#include <stdio.h>
#define max 3
int q[10],front=0,rear=-1;

int main(void)
{
    int ch;
    void insert();
    int delet(void);
    int display(void);
    printf("\nCircular Queue operations\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: insert();
            break;
        case 2: delet();
            break;
        case 3:display();
            break;
        case 4:return 1;
        default:printf("Invalid option\n");
        }
    }
    return 0;
}
 
void insert()
{
    int x;
    if((front==0&&rear==max-1)||(front>0&&rear==front-1))
        printf("Queue is overflow\n");
    else
    {
        printf("Enter element to be insert:");
        scanf("%d",&x);
        if(rear==max-1&&front>0)
        {
            rear=0;
            q[rear]=x;
        }
        else
        {
            if((front==0&&rear==-1)||(rear!=front-1))
                q[++rear]=x;
        }
    }
}

int  delet()
{
    int a;
    if((front==0)&&(rear==-1))
    {
        printf("Queue is underflow\n");
         
        return 1;
    }
    if(front==rear)
    {
        a=q[front];
        rear=-1;
        front=0;
    }
    else
        if(front==max-1)
        {
            a=q[front];
            front=0;
        }
        else a=q[front++];
        printf("Deleted element is:%d\n",a);
        return 0;
}
 
int display()
{
    int i,j;
    if(front==0&&rear==-1)
    {
        printf("Queue is underflow\n");
         
        return 1;
    }
    if(front>rear)
    {
        for(i=0;i<=rear;i++)
            printf("\t%d",q[i]);
        for(j=front;j<=max-1;j++)
            printf("\t%d",q[j]);
        printf("\nrear is at %d\n",q[rear]);
        printf("\nfront is at %d\n",q[front]);
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
        printf("\nrear is at %d\n",q[rear]);
        printf("\nfront is at %d\n",q[front]);
    }
    printf("\n");
    return 0;
}

/*======================================output===========================================

 Arvinds-MacBook-Pro:DS arvind$ make cqueue
 cc     cqueue.c   -o cqueue
 Arvinds-MacBook-Pro:DS arvind$ ./cqueue
 
 Circular Queue operations
 1.insert
 2.delete
 3.display
 4.exit
 Enter your choice:1
 Enter element to be insert:32
 Enter your choice:1
 Enter element to be insert:34
 Enter your choice:3
	32	34
 rear is at 34
 
 front is at 32
 
 Enter your choice:2
 Deleted element is:32
 Enter your choice:4

=======================================================================================*/