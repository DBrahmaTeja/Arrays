/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
*/

#include <bits/stdc++.h> 
 void merge(vector<int>&nums,int low,int mid,int high,int &c)
    {
        int i=low;
        int j=mid+1; 
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*nums[j])
            {
                c+=(mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
    
       int p1=low,p2=mid+1,temp[high-low+1],k=0;
          while(p1<=mid and p2<=high)
        {
            if(nums[p1]>nums[p2])
            {
                              
                temp[k++]=nums[p2++];
            }
            else
                temp[k++]=nums[p1++];
        }
        while(p1<=mid)
            temp[k++]=nums[p1++];
        while(p2<=high)
            temp[k++]=nums[p2++];
        for(int i=0;i<=high-low;i++)
            nums[i+low]=temp[i];
    }
    void mergeSort(vector<int>&nums,int low,int high,int &c)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid,c);
            mergeSort(nums,mid+1,high,c);
            
            merge(nums,low,mid,high,c);
        }
    } 
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
   
        
        int c=0;
        mergeSort(arr,0,n-1,c);
        return c;
}