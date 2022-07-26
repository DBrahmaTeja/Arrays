/*
3
2147483647
1
0
Sample Output

2147483648
4294967294
4294967295
Explanation

Take 1 for example, as unsigned 32-bits is 00000000000000000000000000000001 and doing the flipping we get
 11111111111111111111111111111110 which in turn is 4294967294.
*/
long flippingBits(long n) {
    long ans=0,p=1;
    for(int i=0;i<32;i++)
    {
        int last_bit=n&1;
        ans+=(1-last_bit)*p;
        p=p*2;
        n=n>>1;
    }
    return ans;
}