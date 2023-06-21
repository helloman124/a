//binary search
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int bin(int a[],int n,int key)
{
    int mid,low,high;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        return(mid);
        else if(key<a[mid])
        high=mid-1;
        else 
        low=mid+1;
    }
    return(-1);
}
int main()
{
    double clk;
    clock_t starttime,endtime;
    int n,key,a[5000],f,i,j,temp;
    printf("enter number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("\nthe product id are %d",a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nsorted order:");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nenter product to search:");
    scanf("%d",&key);
    starttime=clock();
    f=bin(a,n,key);
    endtime=clock();
    if(f==-1)
    printf("\nproduct not found");
    else
    printf("\n%d is found at %d",key,f);
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("\nthe runtime is %f",clk);
}
