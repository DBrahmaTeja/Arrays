/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{

    /*int tot_size=nums1.size(),i=0,j=0;
    while(i<tot_size and j<n)
    {
        if(nums1[i]==0 and i>=m+j)
            break;
        if(nums1[i]<=nums2[j])
        {
            i++;
        }
        else
        {
            for(int k=tot_size-1;k>i;k--)
            nums1[k]=nums1[k-1];
            nums1[i]=nums2[j];
            i++;
            j++;
        }
    }
     while(i<tot_size and j<n)
        {
            nums1[i++]=nums2[j++];
        }*/
    int i = m - 1;
    int j = n - 1;
    int lastIndex = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[lastIndex] = arr1[i];
            i--;
        }
        else
        {

            arr1[lastIndex] = arr2[j];
            j--;
        }

        lastIndex--;
    }
}