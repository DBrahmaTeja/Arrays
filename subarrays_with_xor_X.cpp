/*
Return the total number of subarrays having bitwise XOR equals to B.
Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 5
*/
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n=arr.size(),c=0,temp_xor=0;
    /*for(int i=0;i<n;i++)
    {
        int ans=0;
        for(int j=i;j<n;j++)
        {
            ans^=arr[j];
            if(ans==x)
                c+=1;
        }
    }
    return c;*/
    unordered_map<int,int>hm;
    for(int i=0;i<n;i++)
    {
        temp_xor^=arr[i];
        if(temp_xor==x)
            c++;
        int y=temp_xor^x;
        c+=hm[y];
        hm[temp_xor]++;
    }
    return c;
}