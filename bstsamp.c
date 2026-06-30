#include <stdio.h>
#include <stdlib.h>
struct node* createNode();
void search();
void inorder();
void preorder();
void postorder();
void search();
void diff();
struct node* insertion();
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* root= NULL;

struct node* createNode(int item){
    struct node* temp= (struct node*) malloc(sizeof(struct node));
    temp->left= temp->right=NULL;
    temp->data= item;
    return temp;
}

void main(){
    int size,choice,height=0,SumN=0;
    int totalN=0;
    int val;
    int keyval;
    int del_choice,del_switch_error;
    int dis_choice, dis_switch_error;
    printf("BST Operations\n");

    while(1){
        printf("\n\n");
        printf("1. Insertion\n2.Traversal\n3. Search\n4.Total no of Nodes in the tree\n5.Sum of Nodes\n6.delete\n7. Exit\n\n");
        printf("Enter the option number to perform operation : ");
        scanf("%d",&choice);
        fflush(stdin);

        switch(choice){
            case 1:
                        totalN=totalN+1;

                        printf("Enter the value to insert into the BST : ");
                        scanf("%d",&keyval);
                        SumN=SumN+keyval;
                        if(root==NULL){
                            root= insertion(root, keyval);
                        }
                        else{
                            insertion(root,keyval);
                        }

                        break;

            case 2:
            dis_switch_error=1;
                        while(dis_switch_error==1){
                            printf("\n1. In-Order Traversal.\n2. Pre-Order Traversal.\n3. Post-Order Traversal.");
                            printf("\n\nChoose type of traversal - ");
                            scanf("%d",&dis_choice);
                            fflush(stdin);

                            dis_switch_error=0;
                            switch(dis_choice){
                                case 1:
                                            inorder(root);
                                            break;


                                case 2:
                                            preorder(root);
                                            break;


                                case 3:
                                            postorder(root);
                                            break;


                                default:
                                            printf("Invalid Operation !!!");
                                            dis_switch_error=1;

                            }
                        }
                        break;


            case 3:

                        printf("Enter the number that you want to search : ");
                        scanf("%d",&val);
                        search(root, val);
                        break;
            case 4:
                        printf("\nTotal no of nodes are : %d\n",totalN);
                        break;
            case 5:
                        printf("\nsum of nodes are : %d\n",SumN);
                        break;


            case 6:  printf("enter the keyvalue you want to delete");
                  scanf("%d",&keyval);
                deleteNode(root,keyval);
                        break;
            case 7: exit(0);

        }
    }
}

struct node* insertion(struct node* node, int item){

    if(node==NULL){
        return createNode(item);
    }
    else{
        if(item < node->data){
            node->left= insertion(node->left, item);
        }
        else if(item > node->data){
            node->right= insertion(node->right, item);
        }
        return node;
    }
}

void inorder(struct node *temp){
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d \n", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node *temp){
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d \n", temp->data);
    }
}

void preorder(struct node *temp){
    if (temp != NULL) {
        printf("%d \n", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void search(struct node *temp, int val){
    if(temp==NULL){
        printf("Element not found !! or List empty !!\n");
    }
    else if(val==temp->data){
        printf("Element %d found\n", val);
    }
    else if(val > temp->data){
        return search(temp->right, val);
    }
    else if(val < temp->data){
        return search(temp->left, val);
    }

}
void diff(struct node *temp, int val){
    if(temp==NULL){
        printf("Element not found !! or List empty !!\n");
    }
    else if(val==temp->data){
        if(temp->left->data>temp->right->data){
            printf("\nLeft child:%d \n",temp->left->data);
            printf("\nRight child:%d \n",temp->right->data);
            printf("\nLeft child is the greatest diff is:%d \n",temp->left->data-temp->right->data);
        }else if(temp->left->data<temp->right->data){
            printf("\nLeft child:%d \n",temp->left->data);
            printf("\nRight child:%d \n",temp->right->data);
            printf("\nRight child is the greatest diff is:%d \n",temp->right->data-temp->left->data);
        }else{
        printf("\nBoth the child have same value\n ",temp->left->data);
        }
    }
    else if(val > temp->data){
        return diff(temp->right, val);
    }
    else if(val < temp->data){
        return diff(temp->left, val);
    }
}
int deleteNode( struct node* root,int keyval)
{
    if (root == NULL)
        return root;
    if (keyval < root->data)
        root->left = deleteNode(root->left, keyval);
    else if (keyval > root->data)
        root->right = deleteNode(root->right, keyval);
    else {
        if ((root->left==NULL)&&(root->right==NULL))
            return NULL;

        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);

            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);


            return temp;
        }
        else
            exit(0);
    }
    return root;


}
