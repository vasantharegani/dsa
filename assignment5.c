#include<stdio.h>
#include<stdlib.h>
struct Node
{
int roll_number;
struct Node*next;
};
struct Node*head=NULL;
struct Node*createNode(int roll)
{
struct Node *newNode=malloc(sizeof(struct Node));
if(!newNode)
  {
    printf("Memory allocation failed \n");
    exit(1);
   }
newNode->roll_number=roll;
newNode->next=NULL;
return newNode;
}
void insertAtBeginning(int roll)
{
 struct Node *newNode=createNode(roll);
 newNode->next=head;
 head=newNode;

 printf("Successfully inserted %d at the BEGINNING.\n", roll);
}
void insertAtEnd(int roll)
{
 struct Node *newNode=createNode(roll);
 if(head==NULL){
   head=newNode;
 }
 else
{
  struct Node* temp=head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next=newNode;
  printf("Successfully inserted %d at the END.\n", roll);
}
}
void deleteValue(int roll)
{
  struct Node *temp=head, *prev=NULL;
  while(temp&&temp->roll_number!=roll)
   {
    prev=temp;
    temp=temp->next;
   }
if(temp==NULL)
{
 printf("Deletion Failed: Roll number %d is NOT AVAILABLE.\n\n", roll);
 return;
}
if(prev==NULL)
 head=temp->next;
else
prev->next=temp->next;
free(temp);
printf("deleted %d from list\n",roll);
}
void searchValue(int roll)
{
  struct Node *temp=head;
  int pos=1;
  while(temp)
  {
    if(temp->roll_number == roll)
      {
         printf("Search Result: Roll number %d FOUND at position %d.\n\n", roll, pos);
          return;
       }
       temp=temp->next;
       pos++;
   }
printf("Search Result: Roll number %d NOT AVAILABLE in the list.\n\n", roll);
}
void display()
{
if(head==NULL)
{
 printf("list is empty\n");
 return;
}
printf("Updated Student Roll Numbers: ");
struct Node *temp=head;
while(temp !=NULL)
{ 
  printf("%d->",temp->roll_number);
  temp=temp->next;
}
printf("NULL\n");
}
int main()
{
 int choice,roll,key;
while(1)
{
  printf("\nMenu: \n1.insert beginning \n2.insert end \n3.delete value \n4. search value \n5.display list \n6.exit\n enter choice:");
  scanf("%d",&choice);
  switch(choice)
{
case 1:printf("enter value:");
scanf("%d",&roll);
insertAtBeginning(roll);
break;

case 2:printf("enter value:");
scanf("%d",&roll);
insertAtEnd(roll);
break;

case 3:printf("enter value to be delete:");
scanf("%d",&roll);
deleteValue(roll);
break;

case 4:printf("enter value to be search:");
scanf("%d",&roll);
searchValue(roll);
break;

case 5:
display();
break;

case 6:
exit(0);

default:
   printf("invalid choice\n");
  }
}
return 0;
}
