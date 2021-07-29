#include<stdio.h>

void ele(int A[],int l,int h){
int diff,i;
diff=l-0;
    for(i=0;i<9;i++)
    {
        if(A[i]-i != diff)
        {
            while(A[i]-i > diff)
            {
                printf("%d\n", i+diff);
                diff++;
            }
        }
    }
}
int main()
{
    
    int A[9]={2,3,4,5,6,9,12,13,14};
    ele(A,2,14);
    


}