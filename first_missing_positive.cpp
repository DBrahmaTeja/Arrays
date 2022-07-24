/*
Approach :
It is evident that the answer lies between [1,n+1]. So bring all the elements to their respective position
i.e if the element is 3 bring it to 3rd position or 2nd index.
for example if the array is [3,1,-4,7] let's say it is nums.
iterate through the array and neglect the element if it is greater than n or leass than equal to 0.
otherwise bring it to its position by swapping using condition while(nums[i]!=nums[nums[i]-1]).

at index 0 3 != nums[3-1] hence swap and the array becomes [-4,1,3,7]
now at index 0 value is negative hence neglect and move forward.
at index 1 1!=nums[1-1] hence swap now the array becomes [1,-4,3,7]
now at index 1 value is negative hence neglect and move forward.
at index 2 3==nums[3-1] the condition is true and 3 is at right position hence neglect and move forward.
at index 3 value is 7 which is greater than n hence neglect
So the final array is [1,-4,3,7]
now iterate through this array and find the first index for which nums[i]!=i+1 or the element which is not at correct position.
this is the answer so in [1,-4,3,7] ans is 2.

so you have to swap if nums[i]!=nums[nums[i]-1] along with the condition 0<nums[i]<=n for all the index.

*/
int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < n; i++)
        if (nums[i] != i + 1)
            return i + 1;
    return n + 1;
}
/*For an array size of N, we have that the first missing positive is between 0 and N+1. This may take some time to think about but the best case is you have all the positive integers from 0 to N, in which case the answer is N+1. If you change any one of those values to something greater than N or less than 0, then the answer will be between 0 and N+1. So this property holds.

We can abuse this property. Any number less than 0 and greater than N+1 will not be inside this range. So we can iterate through and change these values to N+1 (to keep it simple, but they need to be set to something that is at least N+1 or bigger) since they are useless to us.

The next step is to iterate through the array again and use a simple hack: treat the numbers as indicies. We index the array using this value and we make the indexed value negative to "tick" it off. We need to remember to take the absoloute value every time we calculate the index because we are using the array for two purposes: to keep track which ones we tick off, and which ones we need to tick off still. This may be a little unintitive so here is how I thought about it (using an extrra array for visual purposes only):

Starting array: [-5, 2, 3, 5, 1, 8]
Ticked off (# is none, - is ticked): [#,#,#,#,#,#]

After setting to N+1: [7, 2, 3, 5, 1, 7]
Ticked off: [#,#,#,#,#,#]

We index nums[abs(7-1)] which is invalid. So we have
Array: [7, 2, 3, 5, 1, 7]
Ticked off: [#,#,#,#,#,#]

We index nums[abs(2)-1] which is 2. So we have
Array: [7, -2, 3, 5, 1, 7]
Ticked off: [#,-,#,#,#,#]

We index nums[abs(3)-1] which is 3. So we have
Array: [7, -2, -3, 5, 1, 7]
Ticked off: [#,-,-,#,#,#]

We index nums[abs(5)-1] which is 1. So we have
Array: [7, -2, -3, 5, -1, 7]
Ticked off: [#,-,-,#,-,#]

We index nums[abs(-1)-1] which is 7. So we have
Array: [-7, -2, -3, 5, -1, 7]
Ticked off: [-,-,-,#,-,#]

We index nums[abs(7)-1] which is not valid. So we have
Array: [-7, -2, -3, 5, 1, 7]
Ticked off: [-,-,-,#,-,#]

We can see from the example that the ticked array matches the signs in the original array.

We finally iterate through the array (the index of the array starts at 1 for this problem) and return the first index that has a positive number. This will be the first number that has not been ticked off yet. So in the example, we would return 4 as nums[4]=5 is not ticked off.

Here is the code for reference:
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int negatives = nums.size()-1;
        
        // change all negative numbers and numbers bigger than N 
		// (the amount of elements in the list)
        for (int i = nums.size()-1; i >= 0; i--){
            if (nums[i] <= 0 || nums[i] > nums.size()){
                nums[i] = nums.size()+1;
            }
        }
        
        int min = 1;
        
        // use nums[i] as the index and mark them off
        for (int i =0; i < nums.size(); i++){
            int index = abs(nums[i])-1;
            
            // check to see if it's within the bounds and indexable
			// and check to not tick off the same value twice
            if ((index < nums.size() && index >= 0) && nums[index] > 0){
                nums[index] = -nums[index];
            }
        }
        
        // first positive value not ticked off 
        for (min = 0; min < nums.size(); min++){
            if (nums[min] > 0){
                break;
            }
        }
        return min+1;
        
    }
};