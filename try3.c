#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
}*front=NULL,*rear=NULL;




void enqueue()
{
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=front;
    printf("Enter the item");
    scanf("%d",&newnode->data);
if(front==NULL&&rear==NULL)
{
front=newnode;
rear=newnode;
newnode->next=front;
}
else
{
    while(temp->next!=front)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=front;
    rear=newnode;
}
printf ("newnode is inserted");
}

void dequeue()
{
    struct node*temp;
    temp=front;
    if(front==NULL&&rear==NULL)
    {
        printf("cll is empty");
    }
    else
    {
        while(temp->next!=front)
        {
            temp=temp->next;
        }
       temp->next=front->next;
       front=front->next;
       printf("deletion done at front");
    }
}

void display()
{
    struct node*temp;
    temp=front;
    if(front==NULL)
    {
        printf("cll is empty");
    }
    else{
        while(temp->next!=front)
        {
            printf("%d-->",temp->data);
            temp=temp->next;

        }
        printf("%d-->",temp->data);
    }
}

void main ()
{
    int choice;
    while(1)
    {
        printf("\n-----MENU------\n");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
        printf("\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
         {
             case 1:enqueue();
             break;
             case 2:dequeue();
             break;
             case 3:display();
             break;
             case 4:exit(0);
             break;
             default:printf ("enter the valid choice" ) ;
             break;
         }
    }
}
