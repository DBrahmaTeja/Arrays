/*
Given an array of integers and a positive integer k , determine the number of (i,j) pairs where i<j and ar[i] + ar[j]  is divisible by k.
*/
int fact(int p)
{
    int ans = 1;
    if (p == 0)
        return 1;
    for (int i = 1; i <= p; i++)
        ans *= i;
    return ans;
}
int ncr(int p)
{
    return (fact(p) / (fact(p - 2) * 2));
}
int divisibleSumPairs(int n, int k, vector<int> ar)
{
    /*
    1st Method;
    int i,j,ans=0;
     for(i=0;i<n;i++)
     {
         for(j=i+1;j<n;j++)
         {
             if((ar[i]+ar[j])%k==0)
             ans+=1;
         }
     }
     return ans;*/
    // 2nd Method
    vector<int> temp(k);
    for (int i = 0; i < n; i++)
    {

        temp[ar[i] % k] += 1;
    }
    int ans, p1, p2 = 0, p3 = 0;
    p1 = ncr(temp[0]);
    if (k % 2 == 0)
        p2 = ncr(temp[k / 2]);
    int l = 1, m = k - 1;
    while (l < m)
    {
        p3 += (temp[l] * temp[m]);
        l++;
        m--;
    }
    ans = p1 + p2 + p3;
    return ans;
}


//3rd
// C++ Program to count pairs
// whose sum divisible by 'K'
#include <bits/stdc++.h>
using namespace std;

// Program to count pairs whose sum divisible
// by 'K'
int countKdivPairs(int A[], int n, int K)
{
	// Create a frequency array to count
	// occurrences of all remainders when
	// divided by K
	int freq[K] = { 0 };

	// Count occurrences of all remainders
	for (int i = 0; i < n; i++)
		++freq[A[i] % K];

	// If both pairs are divisible by 'K'
	int sum = freq[0] * (freq[0] - 1) / 2;//nC2

	// count for all i and (k-i)
	// freq pairs
	for (int i = 1; i <= K / 2 && i != (K - i); i++)
		sum += freq[i] * freq[K - i];
	// If K is even
	if (K % 2 == 0)
		sum += (freq[K / 2] * (freq[K / 2] - 1) / 2);
	return sum;
}

// Driver code
int main()
{

	int A[] = { 2, 2, 1, 7, 5, 3 };
	int n = sizeof(A) / sizeof(A[0]);
	int K = 4;
	cout << countKdivPairs(A, n, K);

	return 0;
}
TC:O(N)
SC:O(K)
