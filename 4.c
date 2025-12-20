#include<stdio.h>
#include<stdlib.h>
void display();
void insert();
void menu();
void del_id();


struct student
{
 struct student *prev;
 int id;
 int maths;
 int science;
 struct student *next;
};

struct student *head;//this is a global variable

int main()
{
 menu();
}

void menu()
{
 while(1)
 {
 int item;
 printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
 printf("Enter the item number from menu :");
 scanf("%d",&item);
 if(item==1)
 {
  insert();
 }
 else if(item==2)
 {
  del_id();
 }
 else if(item==3)
 {
  display();
 }
 else
  break;
 }
}

void insert()
{
 struct student *newnode,*temp,*next_id;
 head=0;
 int after_id;

 while(1)
 {
 newnode=(struct student *)malloc(sizeof(struct student));
 printf("Enter id: ");
 scanf("%d",&newnode->id);

   if(newnode->id== -1)//to break the loop of creating new nodes
  {
       free(newnode);
       break;
  }

 if(head==0)
 {
       printf("Enter maths mark:");
       scanf("%d",&newnode->maths);

       printf("Enter science mark:");
       scanf("%d",&newnode->science);

       newnode->next=0;
       newnode->prev=0;
       temp=head=newnode;
}

 else
 {
         display();
         printf("After which id you want to display:");
         scanf("%d",&after_id);
         temp=head;

          while(temp!=0)
         {

                  if(temp->id==after_id)
                  {
                          printf("Enter maths mark:");
                         scanf("%d",&newnode->maths);

                         printf("Enter science mark:");
                         scanf("%d",&newnode->science);

                         if(temp->next==0)
                         {
                          newnode->prev=temp;
                          newnode->next=0;
                          temp->next=newnode;
                         }

                         else
                         {
                          newnode->prev=temp;
                          next_id=temp->next;//this is to store the next address temporarily before giving to the next of the newnode
                          temp->next=newnode;
                          temp=next_id;
                          newnode->next=next_id;
                          temp->prev=newnode;
                         }
                  }

                       temp=temp->next;
          }
          }
         }
        }

void display()
 {
 struct student *temp;
 temp=head;
  while(temp!=0)
         {
                    printf("Id: %d Maths mark: %d Science mark: %d\n",temp->id,temp->maths,temp->science);
                    temp=temp->next;
        }
}

void del_id()
{
 int del;
 struct student *temp, *prev_add, *next_add;
 temp=head;
 printf("Enter the id you want to delete:");
 scanf("%d",&del);
 while(temp!=0)
 {
  if(temp->id==del)
  {
   if(temp->prev==0)
   {
       prev_add=temp;
       free(prev_add);
       temp=temp->next;
       head=temp;
       temp->prev=0;
       display();
    }

    else if(temp->next==0)
    {
     temp=temp->prev;
     temp->next=0;
     display();
    }

    else
    {
     prev_add=temp->prev;
     next_add=temp->next;
     temp=prev_add;
     temp->next=next_add;
     temp=next_add;
     temp->prev=prev_add;
     display();
    }
  }
  temp=temp->next;
 }
}
