/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

int majorityElement(vector<int> &arr)
{
    int ele, count = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            count++;
        }
        else if (count == 0)
        {
            ele = arr[i];
            count = 1;
        }
        else
            count--;
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            count++;
        }
    }

    if (count > n / 2)
        return ele;
    return -1;
}