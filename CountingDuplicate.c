#include<stdio.h>
int main(){
    int j,i;
     int A[10]= {3,6,8,8,10,12,15,15,15,20};
    int n= 10;
    
    for (i=0;i<n-1;i++){
        if(A[i]==A[i+1])
        {
            j=i+1;
            while(A[j]==A[i])
            {
                j++;
        
            }
        printf("%d is appearing %d time",A[i], j-i);
        i=j-1;
        }
    }
}