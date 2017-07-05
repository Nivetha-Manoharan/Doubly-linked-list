#include<stdio.h>
#include<stdlib.h>
struct node
{
 float element;
 struct node *prev, *next;
}*a,*t,*b,*r;
int isempty();
int create();
int ins_front();
int ins_end();
int ins_pos();
int del_front();
int del_end();
int del_pos();
int del_search();
int find();
int display();
int print_rev();
int main()
{
 int ch,z;
 do
 {
  printf("\n1.create linked list");
  printf("\n2.Insert at front");
  printf("\n3.Insert at end");
  printf("\n4.Insert at position");
  printf("\n5.Delete at front");
  printf("\n6.Delete at end");
  printf("\n7.Delete at position");
  printf("\n8.Search and delete");
  printf("\n9.Find");
  printf("\n10.Display");
  printf("\n11.print reverse");
  printf("\nEnter ur choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    if(isempty())
    create();
    else
    printf("List contains node");
   break;
   case 2:
    ins_front();
   break;
   case 3:
    ins_end();
   break;
   case 4:
    ins_pos();
   break;
   case 5:
    del_front();
   break;
   case 6:
    del_end();
   break;
   case 7:
    del_pos();
   break;
   case 8:
    del_search();
   break;
   case 9:
    find();
   break;
   case 10:
    display();
   break;
   case 11:
    print_rev();
   break;
   default:
    printf("Enter the correct choice");
   break;
  }
  printf("\nPress 1 to contn:");
  scanf("%d",&z);
 }while(z==1);
return 0;
}
int isempty()
{
 if(a==NULL)
 return 1;
 else
 return 0;
}

int create()
{
 int num;
  a=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  a->element=num;
  a->prev=NULL;
  a->next=NULL;
  display();
}

int ins_front()
{
 int num;
 if(!isempty())
 {
  t=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  t->element=num;
  t->prev=NULL;
  t->next=a;
  a->prev=t;
  a=t;
  display();
 }
 else
 printf("List is empty");
}

int ins_end()
{
 int num;
 if(!isempty())
 {
  b=a;
  while(b->next!=NULL)
  b=b->next;
  t=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  t->element=num;
  b->next=t;
  t->prev=b;
  t->next=NULL;
  display();
 }
 else
 printf("\nList is empty");
}

int ins_pos()
{
 int pos,i;
 float num;
 b=a;
 if(!isempty())
 {
  printf("\nEnter the position and element:");
  scanf("%d %f",&pos,&num);
  for(i=0;i<pos;i++)
  b=b->next;
  t=malloc(sizeof(struct node));
  t->element=num;
  t->next=b->next;
  (b->next)->prev=t;
  t->prev=b;
  b->next=t;
  display();
 }
 else
 printf("\nList is empty");
}

int del_front()
{
 if(!isempty())
 {
  t=a;
  a=a->next;
  a->prev=NULL;
  free(t);
  display();
 }
 else
 printf("\nList is empty");
}

int del_end()
{
 if(!isempty())
 {
  b=a;
  r=b;
  while(b->next!=NULL)
  {
   r=b;
   b=b->next;
  }
  if(a==b)
  {
   free(b);
   a=NULL;
  }
  else
  {
   (b->prev)->next=NULL;
   free(b);
  }
  display();
 }
 else
 printf("\nList is empty");
}

int del_pos()
{
 int pos,i;
 if(!isempty())
 {
  printf("\nEnter the position:");
  scanf("%d",&pos);
  b=a;
  r=b;
  for(i=0;i<pos;i++)
  b=b->next;
  (b->prev)->next=b->next;
  (b->next)->prev=b->prev;
  free(b);
  display();
 }
 else
 printf("\nList is empty");
}

int find()
{
 int num;
 printf("\nEnter the element");
 scanf("%d",&num);
 if(!isempty())
 {
  b=a;
  while(b!=NULL)
  {
   if(b->element==num)
   {
    printf("\nElement is found");
    break;
   }
   b=b->next;
  }
  if(b==NULL)
  printf("\nElement is not found");
 }
}
  
int del_search()
{
 int num;
 printf("\nEnter the element");
 scanf("%d",&num);
 if(!isempty())
 {
  if(a->element==num)
  {
   t=a;
   a=a->next;
   free(t);
   a->prev=NULL;
   display();
  }
  else
  {
   b=a;
   while(b!=NULL)
   {
    if(b->element==num)
    {
     if(b->next==NULL)
     {
      (b->prev)->next=NULL;
      free(b);
     }
     else
     {
      (b->prev)->next=b->next;
      (b->next)->prev=b->prev;
      free(b);
      break;
     }
    }
    b=b->next;
   }
  }
  display();
 }
 else
 printf("\nElement is not found");
}

int print_rev()
{
 int i,j;
 if(!isempty())
 {
  b=a;
  i=0;
  while(b->next!=NULL)
  b=b->next;
  while(b!=NULL)
  {
   printf("%f\t",b->element);
   b=b->prev;
  }
 }
 else
 printf("\nList is empty");
}

int display()
{
 if(!isempty())
 {
  b=a;
  while(b!=NULL)
  {
   printf("%f\t",b->element);
   b=b->next;
  }
 }
}
