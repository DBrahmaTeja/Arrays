int maxSubArray(vector<int>& nums) {
        //dp state max subarray sum ending at index i;
        //dp expr dp[i]=max(ar[i],ar[i]+dp[i-1]);        
        int prev=nums[0],ans=nums[0],cur;
        for(int i=1;i<nums.size();i++)
        {
            cur=max(nums[i],nums[i]+prev);
            prev=cur;
            ans=max(ans,cur);
        }
        return ans;
}