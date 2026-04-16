#include <stdio.h>
#include<stdbool.h>
bool duplicate(int n[],int size){
    for (int i =0 ; i<size ; i++)
    {
        for(int j=i+1; j<size ; j++)
        {
            if(n[i]== n[j])
            {
               return true;
            }
        }
    }
    return false;

}

int main(){
    int nums[]={1,2,3,3};
    int size =4 ;
    if(duplicate(nums,size))
    {
        printf("true\n");
    }
    else 
    {
        printf("false/n");
    }

    return 0;
}