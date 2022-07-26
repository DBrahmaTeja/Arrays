#include<iostream>
#include<bits\stdc++.h>
using namespace std;


void fill(vector<int>arr,vector<vector<int>>&res,int st,int end)
{
    vector<int>temp;
    for(int i=st;i<=end;i++)
    temp.push_back(arr[i]);
    res.push_back(temp);
    return;
}

int main()
{
    int n;
    
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<int>>res;
    for(int i=0;i<n;i++)
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

}