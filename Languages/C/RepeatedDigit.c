#include<stdio.h>

int main()
{
    int i;
    int rem;
    int N;
    int a[10]={0};

    printf("Enter any number:");
    scanf("%d",&N);

    while(N>0){
        for(i=0;i<9;i++)
            rem = N%10;
            if(a[rem]==1)
                break;
                a[rem]=1;
            N=N/10;
    }

    if(N>0)
    {
        printf("Yes\n");
    }
    else{
        printf("No");
    }
    return 0;
}
