/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/
int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
      
    vector<int>prefix(n);
    prefix[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=nums[i]+prefix[i-1];
    }
    unordered_map<int,int>hm;
    int longestsubset=0;
    for(int i=0;i<n;i++)
    {
        if(prefix[i]==0)
        {
            longestsubset=max(longestsubset,i+1);
        }
        else
        {
            if(hm.find(prefix[i])!=hm.end())
            {
                longestsubset=max(longestsubset,i-hm[prefix[i]]);
            }
            else
                hm.insert({prefix[i],i});
        }
    }
    return longestsubset;
    }