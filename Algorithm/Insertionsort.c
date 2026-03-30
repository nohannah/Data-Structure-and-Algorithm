#include<stdio.h>
#include <stdlib.h>

void insertion(int A[], int n)
{
    int i, j ,x;
    for(i=1;i<n;i++){
    j=i-1;
    x=A[i];
    while(j>-1 && A[j] > x)
    {
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=x;
}
}
int main() {
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;
    int i;

    printf("Original array: 11 13 7 12 16 9 24 5 10 3\n");

    insertion(A, n);

    printf("Sorted array:   ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}