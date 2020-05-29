 //BST_for_string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[100];
    struct node*left;
    struct node*right;
}*root=NULL;
struct node* createnode(char *data)//function to create new node
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->data,data);
    newnode->left=NULL;
    newnode->right=NULL;
        return newnode;
}
void inorder(struct node*temp)//traversing tree
{
    if(temp!=NULL)
    {
        inorder(temp->left);
         printf("%s ",temp->data);
        inorder(temp->right);
    }
}
void insertnode(struct node*n,char *data)//function to insert new node
{
    if(strcmp(data,n->data)>0)
    {
        if(n->right)
            insertnode(n->right,data);
        else
            n->right=createnode(data);
    }
    else
    {
        if(n->left)
            insertnode(n->left,data);
        else
            n->left=createnode(data);
    }
}
void main()//driver function
{
    root=createnode("Dorothy");//add data at root than creating the tree
    root->left=createnode("Christy");
    root->right=createnode("Eliza");
    root->left->left=createnode("Arithi");
    root->right->right=createnode("Fraser");
    printf("Before insertion: ");
    inorder(root);
    printf("\n\nAfter insertion: ");
    insertnode(root,"David");// inserting data
   inorder(root);
  printf("\n");
}

