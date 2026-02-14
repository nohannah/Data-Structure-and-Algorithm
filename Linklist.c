#include <stdio.h>
#include <stdlib.h>
// defind the node and structure 
struct Node 
{
     int data; 
     struct Node *next;    
};
struct Node *first = NULL;
void create (int A[], int n)
{
    int i ; 
    struct Node *t, *last;
    first = (struct Node *) malloc (sizeof(struct Node));
    first-> data = A[0];
    first-> next = NULL;
    last = first; 

    for ( i=1 ; i< n ; i++)
    {
        t=(struct Node *) malloc (sizeof(struct Node));
        t->data = A[i];
        t->next =NULL;
        last ->next = t;
        last = t;
    }
}
//display 
void Display (struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

//Insert the nodes
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if (index < 0 || index >count(p))
        return;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = x; 
        if(index==0){
            t->next = first; 
            first = t;
        }
        else {
            for (i=0 ; i<index-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }

}
// count node 
int count (struct Node *p)
{
    int c=0;
    while (p !=NULL){
        c++;
        p=p->next;
    }
    return c; 

}
//sum 
int sum (struct Node *p)
{
    int s=0;
    while (p!=NULL)\
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int main ()
{
    int A[]= {3, 5, 7, 10, 25, 8, 32, 2};
    create ( A,8);
//Display (first);
    Insert(first, 0,15);
    Display(first);
    printf("count nodes %d\n", count(first));
    printf("sum of nodes %d\n", sum(first));
    return 0;
}