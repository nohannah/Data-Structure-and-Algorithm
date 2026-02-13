#include <stdio.h>
void fun(int n)
{
    if(n>0)
    {
        
        fun(n-1);
        printf("%i",n);
    }
}
int main ()
{
    int x=3;
    fun(x);
    printf("\n");
    return 0; 
}