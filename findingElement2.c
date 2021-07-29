#include<stdio.h>

void ele(int A[],int l,int h){
int i;

int B[14]={};
    for(i=0;i<10;i++)
    {
        B[A[i]]++;
    }
    for(i=l;i<h;i++)
    {
        if(B[i]==0)
            printf("%d\n", i);
    }
}
int main()
{
    
    int A[10]={2,3,6,4,5,9,12,13,14};
    
    ele(A,2,14);
    


}