/*
void printSubArrays(vector<int> arr, int start, int end)
{
    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;
    // Increment the end point and start from 0
    else if (start > end)
        printSubArrays(arr, 0, end + 1);
    // Print the subarray and increment the starting point
    else {
        cout << "[";
        for (int i = start; i < end; i++)
            cout << arr[i] << ", ";
        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }
    return;
}
 
int main()
{
    vector<int> arr = { 1, 2, 3 };
    printSubArrays(arr, 0, 0);
    return 0;
}
*/


#include <iostream>
#include <bits\stdc++.h>
using namespace std;


void fill(vector<int> arr, vector<vector<int>> &res, int st, int end)
{
    vector<int> temp;
    for (int i = st; i <= end; i++)
        temp.push_back(arr[i]);
    res.push_back(temp);
    return;
}

void subsets(vector<int> arr, vector<vector<int>> &res, vector<int> &temp, int ind, int n)
{

    if (ind == n)
    {
        res.push_back(temp);
        return;
    }

    // consider
    temp.push_back(arr[ind]);
    subsets(arr, res, temp, ind + 1, n);
    temp.pop_back();

    // not considering
    subsets(arr, res, temp, ind + 1, n);
}

void subset_sum(vector<int> arr, vector<vector<int>> &res, int cur_sum, int target, vector<int> &temp, int ind, int n)
{
    if (cur_sum == target)
    {
        res.push_back(temp);
        return;
    }
    else if (cur_sum > target or ind == n)
    {
        return;
    }
    else
    {

        // consider
       
            temp.push_back(arr[ind]);
            subset_sum(arr, res, cur_sum + arr[ind], target, temp, ind + 1, n);
            temp.pop_back();
        
        // not consider
        subset_sum(arr, res, cur_sum, target, temp, ind + 1, n);
    }
}

int main()
{
    int n;

    cout << "Enter n" << endl;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> res;
    /* for(int i=0;i<n;i++)
     {
         for(int j=i;j<n;j++)
         {
             fill(arr,res,i,j);
         }
     }
     for(int i=0;i<res.size();i++)
     {
         for(int j=0;j<res[i].size();j++)
         {
             cout<<res[i][j]<<" ";
         }
         cout<<endl;
     }
     vector<vector<int>>res1;
     vector<int>temp;

     subsets(arr,res1,temp,0,n);
     for(int i=0;i<res1.size();i++)
     {
         for(int j=0;j<res1[i].size();j++)
         {
             cout<<res1[i][j]<<" ";
         }
         cout<<endl;
     }    */
    cout << "Enter the sum" << endl;
    int target;
    cin >> target;
    vector<vector<int>> res1;
    vector<int> temp;
    int cur_sum = 0;
    subset_sum(arr, res1, cur_sum, target, temp, 0, n);
    for (int i = 0; i < res1.size(); i++)
    {
        for (int j = 0; j < res1[i].size(); j++)
        {
            cout << res1[i][j] << " ";
        }
        cout << endl;
    }
}