// Experiment 10
// Binary Tree Search Program

#include <stdio.h>
#include <stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};

typedef struct node *tree;
tree root=NULL,ptr=NULL;
int f;

tree insert(tree p,tree temp,int item)
{
 if(item<p->data)
 {
   if(p->left==NULL)
     p->left=temp;
   else
     insert(p->left,temp,item);
 }
 else
 {
  if(p->right==NULL)
    p->right=temp;
  else
    insert(p->right,temp,item);
}
return p;
}

tree findmin(tree p)
{
 if(p==NULL)
  return NULL;
else if(p->left==NULL)
  return p;
else
  findmin(p->left);
return 0;
}

tree find(tree p,int item)
{
 if(p==NULL)
 {
   f=0;
   return NULL;
 }
 else if(p->data==item)
 {
  f=1;
  return p;
}
else
{
  ptr=p;
  if(item<p->data)
    find(p->left,item);
  else
    find(p->right,item);
}
return 0;
}

tree del(tree p,int item)
{
  tree temp,l,x;
  if(p==NULL)
    printf("Tree empty\n");
  else
    l=find(p,item);

  if(l->left!=NULL && l->right==NULL)
  {
    temp=l;
    if(l==root)
      root=l->left;
    else if(ptr->left==l)
      ptr->left=l->left;
    else
      ptr->right=l->left;
    free(temp);
  }
  else if(l->left==NULL && l->right!=NULL)
  {
    temp=l;
    if(l==root)
      root=l->right;
    else if(ptr->left==l)
      ptr->left=l->right;
    else
      ptr->right=l->right;
    free(temp);
  }
  else if(l->left==NULL && l->right==NULL)
  {
    temp=l;
    if(l==root)
      root=NULL;
    else if(l==ptr->left)
     ptr->left=NULL;
   else
     ptr->right=NULL;
   free(temp);
 }
 else
 {
  x=findmin(l->right);
  l->data=x->data;
  ptr=l;
  del(l->right,x->data);
}
printf("Item Deleted");
return NULL;
}


void  create()
{
 int i,n,item;
 tree temp;
 printf("Enter no of nodes:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter item:");
  scanf("%d",&item);
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=item;
  temp->left=NULL;
  temp->right=NULL;
  if(root==NULL)
    root=temp;
  else
    insert(root,temp,item);
}
}
tree display(tree p)
{
  if(p!=NULL)
  {
   display(p->left);
   printf("%d\t",p->data);
   display(p->right);
 }
 return p;
}

int main()
{
 int c,item;
 tree p;
 do
 {
  printf("\n1:Create  2:Search  3:Delete  4:Display  5:exit\n");
  printf("Enter Choice:\t");
  scanf("%d",&c);
  switch(c)
  {
   case 1:create();break;
   case 2:printf("Enter item for search");
   scanf("%d",&item);
   find(root,item);
   if(f==1)
     printf("%d is found",item);
   else
     printf("Item not found");
   break;
   case 3:
   printf("Enter the item to delete:");
   scanf("%d",&item);
   del(root,item);
   break;
   case 4:if(root==NULL)
   printf("Tree Empty");
   else
     display(root);break;
   case 5:
   return 1;
   break;
 }
}
  while(c);
  return 0;
}











/*

1:Create  2:Search  3:Delete  4:Display  5:exit
Enter Choice: 2
Enter item for search2 
Item not found
1:Create  2:Search  3:Delete  4:Display  5:exit
Enter Choice: 1
Enter no of nodes:2
Enter item:23
Enter item:2

1:Create  2:Search  3:Delete  4:Display  5:exit
Enter Choice: 2
Enter item for search23
23 is found
1:Create  2:Search  3:Delete  4:Display  5:exit
Enter Choice: 5

*/
