/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/
#include <bits/stdc++.h> 
 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>hm;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           hm[nums[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            int temp=target-nums[i];
            vector<int>temp_arr=hm[temp];
            for(int j=0;j<temp_arr.size();j++)
            {
                if(temp_arr[j]==i)
                    continue;
                else
                {
                    if(ans.size()<2)
                    {
                    ans.push_back(i);
                    ans.push_back(temp_arr[j]);
                    }
                }
            }
        }
        return ans;
    }
//-----------------------------------------//
/*
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:
Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
Input Format:
The first line of input contains two space-separated integers 'N' and 'S', denoting the size of the input array and the value of 'S'.

The second and last line of input contains 'N' space-separated integers, denoting the elements of the input array: ARR[i] where 0 <= i < 'N'.
Output Format:
Print 'C' lines, each line contains one pair i.e two space-separated integers, where 'C' denotes the count of pairs having sum equals to given value 'S'.
Note:
You are not required to print the output, it has already been taken care of. Just implement the function.
Constraints:
1 <= N <= 10^4
-10^5 <= ARR[i] <= 10^5
-2 * 10^5 <= S <= 2 * 10^5

Time Limit: 1 sec
Sample Input 1:
5 5
1 2 3 4 5
Sample Output 1:
1 4
2 3
Explaination For Sample Output 1:
Here, 1 + 4 = 5
      2 + 3 = 5
Hence the output will be, (1,4) , (2,3).
Sample Input 2:
5 0
2 -3 3 3 -2
Sample Output 2:
-3 3
-3 3
-2 2
Previous
*/
vector<vector<int>> pairSum(vector<int> &nums, int target){
   // Write your code here.
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    int n=nums.size();
    int p1=0,p2=n-1;
    while(p1<p2)
    {
    
        if(nums[p1]+nums[p2]==target)
        {
             vector<int>temp;
            temp.push_back(nums[p1]);
            temp.push_back(nums[p2]);
            if(nums[p1]!=nums[p2])
            {
                int c1=0,c2=0,f_ele=nums[p1],s_ele=nums[p2];
                while(p1<n and nums[p1]==f_ele)
                {
                    c1++;
                    p1++;
                }
                while(p2>=0 and nums[p2]==s_ele)
                {
                    c2++;
                    p2--;
                }
                int k=c1*c2;
                while(k)
                {
                    ans.push_back(temp);
                    k--;
                }
            }
            else
            {
                int c=p2-p1+1;
                c=(c)*(c-1)/2;
                while(c)
                {
                    ans.push_back(temp);
                    c--;
                    p1++;
                    p2--;
                }
            }
           
        }
        else if(nums[p1]+nums[p2]<target)
        {
            p1++;
        }
        else
            p2--;
    }
    return ans;
}