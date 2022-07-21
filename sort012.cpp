void sortColors(vector<int> &nums)
{
    int mid = 0, low = 0, high = nums.size() - 1;
    while (high >= mid)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low = low + 1;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}