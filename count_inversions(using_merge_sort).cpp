#include <bits/stdc++.h> 
long long int cnt=0;
void merge(long long *arr,int l,int mid,int r)
{
    long long temp[r-l+1];
    int p1=l,p2=mid+1,k=0;
   
    while (p1<=mid and p2<=r)
    {
        if(arr[p1]<=arr[p2])
        {
            temp[k++]=arr[p1++];
        }
        else
        {
        temp[k++]=arr[p2++];
            cnt=cnt+mid-p1+1;
        }
    }
    while(p1<=mid)
    {
         temp[k++]=arr[p1++];
    }
    while(p2<=r)
    {
        temp[k++]=arr[p2++];
    }
    for(int i=0;i<=r-l;i++)
    {
        arr[i+l]=temp[i];
    }
}

void mergesort(long long *arr,int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    mergesort(arr,0,n-1);
    return cnt;
}