/*
Given a string input of length n, find the length of the longest substring without repeating characters i.e return a substring that does not have any repeating characters.
Substring is the continuous sub-part of the string formed by removing zero or more characters from both ends.

Sample Input 1:
 abcabcbb 
Sample Output1:
 3
Explanation For Sample Input 1:
Substring "abc" has no repeating character with the length of 3.
Sample Input 2:
 aaaa
Sample Output 2:
1
*/
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char,int>  hm;
    int n=input.size(),ans=0,l=0,r=0;
   while(r<n)
   {
       if(hm.find(input[r])!=hm.end())
       {
           l=max(hm[input[r]]+1,l);
       }
       hm[input[r]]=r;
       ans=max(ans,r-l+1);
       r++;     
   }
    return ans;
}