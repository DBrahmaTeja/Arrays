/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hs;
        int n=nums.size(),longeststreak=0;
        for(int i=0;i<n;i++)
        {
            hs.insert(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            int k=nums[i];
            if(hs.find(k-1)==hs.end())
            {
                int cur_num=k;
                int current_streak=1;
                while(hs.find(cur_num+1)!=hs.end())
                {
                    cur_num+=1;
                    current_streak+=1;
                }
                longeststreak=max(longeststreak,current_streak);
            }
        }
        return longeststreak;
    }