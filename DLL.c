#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
}*head=NULL;


void insertAtBeginning()
{

    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted\n");
    scanf("%d",&newnode->data);

    if(head==NULL)
    {
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->prev=NULL;
        newnode->next=head;
        head=newnode;
    }
    printf("\nsuccessfully done insertion the beginning\n");
}

void insertAtEnd()
{
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;

    }
    printf("\ndone insertion at end");
}

/*void deleteAtPos()
{
    int key;
    struct node*temp,*temp1;
    printf("enter the node for delete");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        while(temp->data!=key)
        {
        if(temp->next==NULL)
        {
            printf("node not found");
        }
        temp1=temp;
        temp=temp->next;
        if(temp->next==NULL && temp->prev==NULL)
        {
            head=NULL;
            free(temp);
        }
        else if(temp->prev==NULL && temp->next!=NULL)
        {
            head=temp->next;
            temp->prev=NULL;
            free(temp);
        }
        else if(temp->prev!=NULL && temp->next==NULL)
        {
            temp->next=NULL;
            free(temp);
        }
        else
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
      printf("done...");
    }

}*/


void deleteAtBeg()
{
    if(head==NULL)
    {
        printf("\nempty list\n");

    }
    else
    {
        head=head->next;
        head->prev=NULL;
        printf("\ndone...\n");
    }

}

void deleteAtEnd()
{
    struct node*temp,*temp1;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        temp1=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp1->next=NULL;
        printf("done...");
    }
}
void display()
{
    struct node*temp;
    if(head==NULL)
    {
        printf("empty list");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {

            printf("<==>%d-%d-%d",temp->prev,temp->data,temp->next);
            temp=temp->next;
        }
        printf("\nlist is displayed\n");
    }
}

void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insertion at the beginning\n2.Display the list\n3.Insertion at the End\n4.Insertion at the position\n5.Deletion at beginning\n6.Deletion at End\n7.Deletion at position\n8.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Insertion at beginning\n");
                   insertAtBeginning();
                   break;
            case 2:printf("Displaying the list\n");
                   display();
                   break;
            case 3:printf("Insertion at end\n");
                   insertAtEnd();
                   break;
            case 4:printf("Insertion at position\n");
                   //insertAtpos();
                   break;
            case 5:printf("Deletion at beginning\n");
                   deleteAtBeg();
                   break;
            case 6:printf("Deletion at end\n");
                   deleteAtEnd();
                   break;
            case 7:printf("Deletion at position\n");
                   deleteAtPos();
                   break;
            case 8:exit(0);
                   break;
        }
    }
}


