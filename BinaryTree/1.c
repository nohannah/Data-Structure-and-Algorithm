#include<stdio.h>
#include<stdlib.h>
#include "Queue.c"

struct Node {
    int *lchild;
    int data;
    int *rchild;
};
struct Node *root=NULL;
void CreateTree ()
{
    struct Node *p , *t;
    int x;
    
}