//quick sort 2.0
#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
        *a=*b;
        *b=t;
}
int partition(int *a,int l,int u)
{
    int p=a[l];
    int start=l;
    int end=u;
    while(start<end)
    {
        while(a[start]<=p)
        {
            start++;
        }
        while(a[end]>p)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[l],&a[end]);
    return end;
}
void quicksort(int *a,int l,int u)
{
    int c;
    if(l<u)
    {
        c=partition(a,l,u);
        quicksort(a,l,c-1);
        quicksort(a,c+1,u);
    }
}
void main()
{
     int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int ar[n];
    printf("\nenter array:");
    for(int i=0;i<n;i++)
     scanf("%d",&ar[i]);
     quicksort(ar,0,n);
     printf("Sorted array:");
     for(int j=0;j<n;j++)
     printf(" %d ",ar[j]);
}
