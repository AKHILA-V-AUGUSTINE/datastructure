#include<stdio.h>
#include<conio.h>
struct node*insertion(struct node*,int);
struct node{
int data;
struct node*left;
struct node*right;
}*root=NULL;

struct node*create(int data)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->left=temp->right=NULL;
temp->data=data;
return temp;
}


struct node*insertion(struct node*node,int item)
{
    if(node==NULL)
    {
        return create(item);
    }
    else{
        if(item>node->data)
        {
            node->right=insertion(node->right,item);
        }
        else if(item<node->data)
        {
            node->left=insertion(node->left,item);
        }
        return node;
    }
}


void search(struct node*temp,int val)
{
    if(temp==NULL)
    {
        printf("item not found");
    }
    if(val==temp->data)
    {
        printf("item found");
    }
    else if(val>temp->data)
    {
        return search(temp->right,val);
    }
    else if(val<temp->data)
    {
        return search(temp->left,val);
    }

}


void inorder(struct node*temp)
{
    if(temp!=NULL)
    {
        if(temp->left!=NULL)
        inorder(temp->left);
        printf("%d-->\t",temp->data);
        if(temp->right!=NULL)
        inorder(temp->right);
    }
}

void postorder(struct node*temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d-->",temp->data);
    }
}

void preorder(struct node*temp)
{
    if(temp!=NULL)
    {
        printf("%d-->",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

int deleteNode(struct node*root,int del)
{
    if(root==NULL)
    {
        return root;
    }
    if(del<root->data)
    root->left=deleteNode(root->left,del);
    else if(del>root->data)
    root->right=deleteNode(root->right,del);
    else {
        if((root->left==NULL)&&(root->right==NULL))
        {
            return NULL;
        }
        else if(root->left==NULL)
        {
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node*temp=root->left;
            free(root);
            return temp;
        }
        else
            exit(0);
    }
    return root;
}

void main()
{
    int choice,dis_switch,dis_while,val,keyval,delval;
    while(1)
    {
        printf("\n------menu------\n");
        printf("\n1.insert\n2.traversal\n3.search\n4.delete\n5.exit");
        printf("Enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter a value to insert");
            scanf("%d",&val);
            if(root==NULL)
            {
                root=insertion(root,val);
            }
            else{
                insertion(root,val);
            }
            break;
            case 2:dis_while=1;
            while(dis_while==1)
            {
                printf("\nTraversa\n");
                printf("\n1.inorder\n2.postorder\n3.preorder");
                printf("Enter a choice");
                scanf("%d",&dis_switch);
                dis_while=0;
                switch(dis_switch)
                {
                    case 1:printf("inoreder\n");
                    inorder(root);
                    break;
                    case 2:printf("postorder\n");
                    postorder(root);
                    break;
                    case 3:printf("preorder\n");
                    preorder(root);
                    break;
                    default:printf("enter a valid choice");
                    break;
                    dis_while=1;
                }
                }
                break;
                case 3:printf("Enter the value to search");
                scanf("%d",&keyval);
                    search(root,keyval);
                    break;
                 case 4:printf("Enter the value to delete");
                 scanf("%d",&delval);
                 deleteNode(root,delval);
                 break;
                 case 5:exit(0);
                 break;
            }
        }
    }

