/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/

//can be done using cycle detection in linkedlist
int findDuplicate(vector<int>& nums) {
        /*int sum=0,n=nums.size(),temp;
        vector<int>cnt1(nums.size(),0);
        for(int i=0;i<n;i++)
        {
           if(cnt1[nums[i]]>=1)
           {temp= nums[i];
            break;}
            cnt1[nums[i]]++;
        }
        return temp;*/
        //cycle detection in linked list.
        int fast=nums[0];
            int slow=nums[0];
            do{
                fast=nums[nums[fast]];
                slow=nums[slow];
            }while(fast!=slow);
            fast=nums[0];
            while(fast!=slow){
                 slow=nums[slow];
                fast=nums[fast];
            }

        return fast;

    }