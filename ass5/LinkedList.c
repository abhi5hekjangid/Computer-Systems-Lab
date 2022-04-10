#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int info;
struct node *next;
};
struct node *first;
void create();
void traverse();
int main()
{

create();
traverse();
return 0;
}
void create()
{
struct node *ptr;
int n;
ptr=(struct node*)malloc(sizeof(struct node));
printf("Enter First Node in List ");
scanf("%d",&n);
ptr->info=n;
ptr->next=NULL;
first=ptr;
}
void traverse()
{
struct node *ptr;
printf("Linked List is ");
ptr=first;
while(ptr!=NULL)
{
printf("%d ",ptr->info);
ptr=ptr->next;
}
}