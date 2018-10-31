#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node
{
    char ch;
    struct node *left;
    struct node *right;
}*start;

int top=-1;
struct node* stack[20];

struct node* newnode(char val)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->ch=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

void push(struct node *p)
{
    if(top>=MAX-1)
    {
        printf("\n\tStack overflow");

    }
    else
    {
        top++;
        stack[top]=p;
    }
}

struct node* pop()
{
    struct node *p;
    if(top<=-1)
    {
        printf("\n\tStack underflow");
    }
    else
    {
        p=stack[top];
        top--;
    }
    return p;
}

void inorder()
{
    struct node *root=start;
    top=-1;
    here:while(root!=NULL)
    {
        push(root);
        root=root->left;
    }

    if(root==NULL && top!=-1)
    {
        struct node *p;
        p=pop();
        printf("%c ",p->ch);
        root=p->right;
        goto here;
    }
}

void preorder()
{
    struct node *root=start;
    top=-1;
    struct node *p;
    push(root);
    while(top!=-1)
    {
        p=pop();
        printf("%c ",p->ch);
        if(p->right)
            push(p->right);
        if(p->left)
            push(p->left);
    }
}

void postorder()
{
    struct node *root=start;
    top=-1;
    do{
        while(root!=NULL)
        {
            if(root->right)
                push(root->right);
            push(root);
            root=root->left;
        }

        root=pop();

        if(root->right!=NULL && (root->right)==stack[top])
        {
            pop();
            push(root);
            root=root->right;
        }
        else
        {
            printf("%c ",root->ch);
            root=NULL;
        }
    }while(top!=-1);
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
    preorder();
    printf("\nINORDER\n");
    inorder();
    printf("\nPOSTORDER\n");
    postorder();
}
