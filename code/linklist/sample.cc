#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
  int data;
  struct node *next;
}Lnode,*linklist;

void create_linklist_tail(linklist &head,int n)
{
linklist p,t;
int i;
p=(Lnode *)malloc(sizeof(Lnode));
p->next=NULL;
head=p;
t=head;

for(i=1;i<=n;i++)
{
  p=(Lnode *)malloc(sizeof(Lnode));
  p->data=i;
  p->next=NULL;
  t->next=p;
  t=p;
}
}

void create_linklist_head(linklist &head,int n)
{
linklist p;
int i;
p=(Lnode *)malloc(sizeof(Lnode));
p->next=NULL;
head=p;

for(i=1;i<=n;i++)
{
  p=(Lnode *)malloc(sizeof(Lnode));
  p->data=i;

  p->next=head->next;
  head->next=p;
}
}

void print_linklist(linklist head)
{
    linklist p;
    p=head->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void locate_i(linklist head,int i)
{
    int cnt=0;
    linklist p;
    p=head->next;
    while(p&&cnt<i)
    {
        cnt++;
        //printf("p->data=%d,cnt=%d,i=%d\n",p->data,cnt,i);
        p=p->next;
    }
    if(p)
        printf("%d\n",p->data);
    else
        printf("Error Position!\n");
}

void locate_data(linklist head,int d)
{
    linklist p;
    p=head->next;
    while(p&&p->data!=d)
        p=p->next;

    if(p)
        printf("Found it!\n");
    else
        printf("Error Position!\n");
}

void insert_data(linklist &head,int d,int x)
{
    linklist p,q;
    p=head->next;
    while(p&&p->data!=d)
        p=p->next;

    if(p)
    {
        q=(linklist)malloc(sizeof(Lnode));
        q->data=100;
        q->next=p->next;
        p->next=q;
        print_linklist(head);
    }
    else
        printf("Not found!\n");
}

void delete_data(linklist &head,int d)
{
    linklist p,q;
    p=head;
    while(p->next&&p->next->data!=d)
        p=p->next;

    if(p->next)
    {
        q=p->next;
        p->next=q->next;
        free(q);
        print_linklist(head);
    }
    else
        printf("Not found!\n");
}

int main()
{
linklist head;

create_linklist_tail(head,10);
print_linklist(head);

//insert_data(head,2,100);
//delete_data(head,2);

locate_i(head,11);

//locate_data(head,11);
//create_linklist_head(head,10);
//print_linklist(head);

}