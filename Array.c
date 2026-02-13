#include <stdio.h>
#include <stdlib.h>
struct Array{
    int A[10];
    int size;
    int length;
};

void Display (struct Array arr)
{
    int i;
    printf("element are \n");
    for(i=0 ; i <arr.length;i++)
    {
        printf("%d " , arr.A[i]);
    }
    /* data */
}
void Append(struct Array *arr , int x){
    if(arr ->length < arr->size)
    {
        arr->A [arr->length]=x;

    }
    arr->length++;
}
void Insert (struct Array *arr,int index, int x)
{
    int i;
    if(index >=0 && index<= arr-> length)
    for(i = arr ->length ; i >index ; i--)
    {
        arr->A[i]= arr->A[i-1];       
    }
    arr -> A[index]=x;
    arr-> length++;
}
int Delete (struct Array * arr, int index)
{
    int x=0;
    int i ; 
    if(index >=0 && index <arr->length)
    {
        x=arr->A[index];
        for(i=index ; i < arr-> length-1; i++)
           arr->A[i]=arr->A[i+1];

           arr->length--;
           return x;
    }
    return 0 ; 
}
int main ()
{
    struct Array arr1={{2,3,4,5,6},10,5};
    Append(&arr1,19);
    Insert(&arr1,1,10);
    Delete(&arr1,3);
    Display(arr1);

    return 0;
}

