 //merge sort for string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(char *a,int l,int mid,int u)//sorting element in inc. order
{
    int i=l;
    int j=mid+1;
    int k=l;
    char b[100];
    while(i<=mid &&j<=u)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
         {
           b[k]=a[j];
           j++;
         }
         k++;
    }
    if(i>mid)
    {
        while(j<=u)
        {
            b[k]=a[j];
           j++;
           k++;
        }
    }
    else
    {
       while(i<=mid)
        {
            b[k]=a[i];
           i++;
           k++;
        }
    }
   for(k=l;k<=u;k++)
        a[k]=b[k];
}
void mergesort(char *a,int l,int u)//breaking the element
{
    int mid;
    if(l<u)
    {
      mid=(l+u)/2;
       mergesort(a,l,mid);
       mergesort(a,mid+1,u);
       merge(a,l,mid,u);
    }
}
void main()
{
   char s[100];
   printf("enter string:");
   gets(s);
int n=strlen(s);
     mergesort(s,0,n-1);
    printf("%s",s);
}
