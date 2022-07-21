/*
First Approach:

Following are the steps to find all prime factors. 
1) While n is divisible by 2, print 2 and divide n by 2. 
2) After step 1, n must be odd. Now start a loop from i = 3 to the square root of n. While i divides n, print i, and divide n by i. After i fails to divide n, increment i by 2 and continue. 
3) If n is a prime number and is greater than 2, then n will not become 1 by the above two steps. So print n if it is greater than 2. 
*/

// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime
// factors of a given number n
void primeFactors(int n)
{
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		cout << 2 << " ";
		n = n/2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			cout << i << " ";
			n = n/i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		cout << n << " ";
}

/* Driver code */
int main()
{
	int n = 315;
	primeFactors(n);
	return 0;
}

// This is code is contributed by rathbhupendra
