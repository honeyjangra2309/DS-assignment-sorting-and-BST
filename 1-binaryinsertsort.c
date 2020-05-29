//using binary search in insertion sort reduce its time complexity in worst case form O(n*n) to O(log n)//
#include<stdio.h>
int binarysearch(int *a,int temp,int l,int u)//finding the location by binary search
{
    int mid;
    if(l==u)
    {
        return l;
    }
    mid=(l+u)/2;
    if(temp>a[mid])
    {
        return binarysearch(a,temp,mid+1,u);
    }
    else
    {
        return binarysearch(a,temp,l,mid);
    }
    return mid;
}
void insertsort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        int l=binarysearch(a,a[i],0,i);//gettiing location to insert data
        while(j>=l)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void main()//driver function
{
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int ar[n];
    printf("enter array:");
    for(int i=0;i<n;i++)
     scanf("%d",&ar[i]);
     insertsort(ar,n);
     printf("Sorted array:");
     for(int j=0;j<n;j++)
     printf(" %d ",ar[j]);
}

