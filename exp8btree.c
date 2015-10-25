//Experiment : 8


#include <stdio.h>
#include <stdlib.h>
struct node
{
 struct node  *left;
 int data;
 struct node *right;
}*root=NULL;
typedef struct node *tree;

void create();
tree insertleft(tree,tree);
tree insertright(tree,tree);
tree insert(tree,tree);
tree inorder(tree);
tree preorder(tree);
tree postorder(tree);

int main()
{
  int c;

  do
  {
    printf("1.Create\t2.Inorder\t3.Preorder\t4.Postorder\t5.Exit\n");
    scanf("%d",&c);
    switch(c)
    {
     case 1:create();
     break;
     case 2:inorder(root);
     break;
     case 3:preorder(root);
     break;
     case 4:postorder(root);
     break;
     case 5:c=-1;
   }
 }while(c!=-1);
}

void create()
{
 tree temp;
 int i,n,item;
 printf("Enter the number of nodes");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
   temp=(struct node *)malloc(sizeof(struct node));
   printf("Enter Item : ");
   scanf("%d",&item);
   temp->data=item;
   temp->left=temp->right=NULL;
   if(root==NULL)
     root=temp;
   else
   {
     root=insert(root,temp);
   }
 }
}

tree insertleft(tree p,tree temp)
{
 if(p->left==NULL)
  p->left=temp;
else
  insert(p->left,temp);
return p;
}

tree insertright(tree p,tree temp)
{

  if(p->right==NULL)
    p->right=temp;
  else
    insert(p->right,temp);
  return p;
}

tree insert(tree root,tree temp){
  char c;
  printf("Insert Left(l) or right(r)");
  c=getchar();
  if(c=='l')
    insertleft(root,temp);
  else if(c=='r')
    insertright(root,temp);
  return root;
}
tree inorder(tree p){
  if(p!=NULL){
    inorder(p->left);
    printf("%d\t",p->data);
    inorder(p->right);
  }
  return p;
}

tree preorder(tree p){
  if(p!=NULL)  {
    printf("%d\t",p->data);
    preorder(p->left);
    preorder(p->right);
  }
  return p;
}

tree postorder(tree p){
  if(p!=NULL){
    postorder(p->left);
    postorder(p->right);
    printf("%d\t",p->data);
  }
  return p;
}

/*
1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
1
Enter the number of nodes2
Enter Item : 23
Enter Item : 9
Insert Left(l) or right(r)1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
4
23  1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
2 
23  1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
1
Enter the number of nodes3
Enter Item : 3
Insert Left(l) or right(r)Enter Item : 66
Insert Left(l) or right(r)Enter Item : 34
Insert Left(l) or right(r)1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
3
23  1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
4
23  1.Create  2.Inorder 3.Preorder  4.Postorder 5.Exit
5
*/
