#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ch;
    struct node *left;
    struct node *right;
}*start;

struct node* newnode(char val)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->ch=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

void preorder(struct node *p)
{
    if(p==NULL)
        return;
    printf("%c ",p->ch);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p)
{
    if(p==NULL)
        return;
    inorder(p->left);
    printf("%c ",p->ch);
    inorder(p->right);
}

void postorder(struct node *p)
{
    if(p==NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%c ",p->ch);
}

int main()
{
    /*
            A
           / \
          /   \
         /     \
        /       \
       C         F
      /         / \
     D         B   E
      \        \
       G        H
               / \
              I   J

    PREORDER
    A C D G F B H I J E

    INORDER
    D G C A B I H J F E

    POSTORDER
    G D C I J H B E F A

    */

    start=newnode('A');
    start->left=newnode('C');
    start->left->left=newnode('D');
    start->left->left->right=newnode('G');
    start->right=newnode('F');
    start->right->left=newnode('B');
    start->right->right=newnode('E');
    start->right->left->right=newnode('H');
    start->right->left->right->right=newnode('J');
    start->right->left->right->left=newnode('I');
    printf("\nPREORDER\n");
    preorder(start);
    printf("\nINORDER\n");
    inorder(start);
    printf("\nPOSTORDER\n");
    postorder(start);
}
