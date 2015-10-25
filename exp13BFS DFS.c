//Experiment 13

#include <stdio.h>

int adj[20][20],i,j,n,max_edge;
int stack[20],top=-1;
int queue[10],front=-1,rear=-1;

void create()
{
  int o,d;
  printf("\nEnter the no: of nodes");
  scanf("%d",&n);
  max_edge=n*(n-1);
  for(i=0;i<max_edge;i++)
  {
   printf("Enter the origin&destination:");
   scanf("%d%d",&o,&d);
   if(o==0&&d==0)
     break;
   else if(o<0||d<0||o>n||d>n)
   {
    printf("Invalid Edge");
  }
  else
   adj[o][d]=1;
}
}
void dfs()
{
  int node,a,x,visited[10];
  for(i=1;i<=n;i++)
    visited[i]=0;
  printf("Enter the node for visit");
  scanf("%d",&node);
  stack[++top]=node;
  printf("Visited nodes are:\n");
  while(top!=-1)
  {
   a=stack[top--];
   if(visited[a]==0)
   {
    visited[a]=1;
    printf("%d\t",a);
  }

  for(j=1;j<=n;j++)
  {
   if(adj[a][j]==1&&visited[j]==0)
     stack[++top]=j;
 }
}
}

void bfs()
{
 int a,node,visited[10];
 for(i=1;i<=n;i++)
   visited[i]=0;
 printf("Enter the node for visit");
 scanf("%d",&node);
 front=rear=0;
 queue[rear]=node;
 printf("Visited Nodes are\n");
 while(front<=rear)
 {
   a=queue[front++];
   if(visited[a]==0)
   {
     printf("%d\t",a);
     visited[a]=1;
   }
   for(i=1;i<=n;i++)
   {
     if(adj[a][i]==1&&visited[i]==0)
       queue[++rear]=i;
   }
 }
}
void display()
{
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
     printf("%d\t",adj[i][j]);
   printf("\n");
 }
}
int main()
{
 int op;
 do
 {
   printf("\n1:create\t2:dfs\t3:bfs\t4:display\t5:exit\t");
   printf("Enter the choice");
   scanf("%d",&op);
   switch(op)
   {
    case 1:create();
    break;
    case 2:dfs();break;
    case 3:bfs();break;
    case 4:display();break;
    case 5:return 1;break;
  }
}
while(op);
return 0;
}

/*

Enter the origin&destination:1
32
Invalid EdgeEnter the origin&destination:1
3
Enter the origin&destination:2
4
Invalid EdgeEnter the origin&destination:21

12
Invalid EdgeEnter the origin&destination:1
2
Enter the origin&destination:31

1
Invalid Edge
1:create  2:dfs 3:bfs 4:display 5:exit  Enter the choice4
0 1 1 
0 0 0 
0 0 0 

1:create  2:dfs 3:bfs 4:display 5:exit  Enter the choice2
Enter the node for visit3
Visited nodes are:
3 
1:create  2:dfs 3:bfs 4:display 5:exit  Enter the choice3
Enter the node for visit2
Visited Nodes are
2 
1:create  2:dfs 3:bfs 4:display 5:exit  Enter the choice5


*/
