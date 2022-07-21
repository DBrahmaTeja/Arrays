void nextPermutation(vector<int>& nums) {
if(nums.size()==0 || nums.size()==1) return ;
        int pos1=-1;
        int pos2=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<=nums[i])
            {
                pos1=i-1;
                break;
            }
        }
        if(pos1<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>=nums[pos1])
                {
                    pos2=i;
                    break;
                }
            }
            swap(nums[pos1],nums[pos2]);
            reverse(nums.begin()+pos1+1,nums.end());
        }
    }