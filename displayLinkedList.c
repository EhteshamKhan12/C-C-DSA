
#include <stdio.h>
#include <stdlib.h>
// #include<climits>
struct Node
{
int data;
struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
int i;
struct Node *t,*last;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node*)malloc(sizeof(struct Node));
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}
void Display(struct Node *p)
{
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
}
void RDisplay(struct Node *p)
{
if(p!=NULL)
{
RDisplay(p->next);
printf("%d ",p->data);
}
}
int count(struct Node *p){
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}
int Rcount(struct Node *p){
    if(p){
        return Rcount(p->next)+1;

    }
    else return 0;
}
int sum (struct Node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int rSum(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return rSum(p->next)+p->data;
}

int Max(struct Node *p)
{
    int max = 0 ;//INT_MIN;
    while(p)
    {
        if(p->data>max)
            max=p->data;
            p=p->next;
    }
    return max;
}

int Rmax(struct Node *p)
{
    int x=0;

    if(p==0)
        return 0;
    x=Rmax(p->next);
    return  x>p->data?x:p->data;
}

struct Node * Lsearch (struct Node *p,int key)
{
    while (p !=NULL){
        if (key==p->data){
             return p;
        p->next;
         }
         return NULL;
    }
}
// Improved linear by move to head
struct Node * ILsearch (struct Node *p,int key)
{
    struct Node *q;
    while (p !=NULL){
        if (key==p->data){
            q->next=p->next;
            p->next=first;
         }
        q=p;
        p=p->next;
    }
}

struct Node * RLsearch (struct Node *p,int key){
    if(p==NULL)
        return NULL;
    if(key==p->data){
        return p; 
    return RLsearch(p->next, key);
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i; 
    if(index<0 || index > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        t->next=p->next;
        p->next=t;
        }
    }
}

void SortedInsert(struct Node *p, int x){
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q-> next=t;

        }
    }
}

int delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1;
    if(index<1 || index> count(p))
        return -1;
    if(index==1){
        x=first->data;
        q=first;
        first=first->next;
        free(q);
        return x;
    }
    else{
        p=first;
        q=NULL;
    }
    for(int i=0;i<index-1 && p;i++)
    {
        q=p;
        p=p->next;
    }
    if(p)
    {
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}
int isSorted(struct Node * p){
    int x=-65536;
    while (p!=NULL){
        if (p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1; 
}

void Rduplicate(struct Node *p){
    struct Node *q;
    p=first;
    q=first->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
        p->next=q->next;
        free(q);
        q=p->next;
        }

    }
}




int main()
{
struct Node *temp;
int A[]={3,7,7,10,25,32};
create(A,6);
// printf("%d\n", isSorted(first)); 
Rduplicate(first);
// delete(first,8);
Display(first);







// RDisplay(first);

// temp=Lsearch(first,25);
// if(temp)
//     printf("key is found %d\n",temp->data);
// else
//     print ("Not found");
return 0;

}