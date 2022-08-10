/*
First Approach:

Following are the steps to find all prime factors. 
1) While n is divisible by 2, print 2 and divide n by 2. 
2) After step 1, n must be odd. Now start a loop from i = 3 to the square root of n. While i divides n, print i, and divide n by i. 
After i fails to divide n, increment i by 2 and continue. 
3) If n is a prime number and is greater than 2, then n will not become 1 by the above two steps. 
So print n if it is greater than 2. 
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
/*
How does this work? 
The steps 1 and 2 take care of composite numbers and step 3 takes care of prime numbers. 
To prove that the complete algorithm works, we need to prove that steps 1 and 2 actually take care of composite numbers.
This is clear that step 1 takes care of even numbers.
And after step 1, all remaining prime factors must be odd (difference of two prime factors must be at least 2),
this explains why i is incremented by 2. 

Now the main part is, the loop runs till the square root of n not till n. To prove that this optimization works, 
let us consider the following property of composite numbers. 

Every composite number has at least one prime factor less than or equal to the square root of itself. 
This property can be proved using a counter statement. Let a and b be two factors of n such that a*b = n. 
If both are greater than √n, then a.b > √n, * √n, which contradicts the expression “a * b = n”. 

In step 2 of the above algorithm, we run a loop and do the following in loop 
a) Find the least prime factor i (must be less than √n,) 
b) Remove all occurrences i from n by repeatedly dividing n by i. 
c) Repeat steps a and b for divided n and i = i + 2. The steps a and b are repeated till n becomes either 1 or a prime number.*/

/*Second Approach: This approach is similar to Sieve of Eratosthenes.
We can achieve O(log n) for all composite numbers by consecutive dividing of the given number by an integer
starting from 2 representing current factor of that number. 
This approach works on the fact that all composite numbers have factors in pairs other than 1 or number itself like 6=3 x 2 and 9=3 x 3
whereas for prime numbers there is no such pair other than 1 or the number itself.
Therefore if we start dividing the number by the smallest possible prime number (2)
then all of its multiples or composite numbers will automatically be removed before we actually reach that number.

Example: We can divide 12 by 2 two times and remove that factors from 12 to get 3 
thus making sure that composite number 4 (multiple of 2) does not occur at any later point of time.
Similarly, if we have a big number that is not divisible by any value of c=2 to n-1 means 
it is prime like 13 (not divisible from 2 to 12).*/


#include <bits/stdc++.h>
using namespace std;
 
void primeFactors(int n)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        cout<<c<<" ";
        n/=c;
        }
        else c++;
    }
}
 
/* Driver code */
int main()
{
    int n = 315;
    primeFactors(n);
    return 0;
}
Time Complexity: This Approach is best for all composite numbers and achieves O(log n) but is O(n) otherwise.

Auxiliary Space: O(1)