int templ, tempr;
int iterate(string s, int l, int r)
{
    int n = s.size(), ans = 0;
    while (l >= 0 and r < n and s[l] == s[r])
    {
        l--;
        r++;
    }
    templ = l + 1;
    tempr = r - 1;
    return r - l - 1;
}

string longestPalindrome(string s)
{
    int ans = 1, n = s.size(), maxr = n;
    string res;
    // consider every index as center of odd length palindrome substring.
    for (int i = 0; i < n; i++)
    {
        int l = i - 1, r = i + 1;
        int k = iterate(s, l, r);

        if (ans < k)
        {
            ans = k;
            res = s.substr(templ, ans);
        }
    }
    // consider every adjacent indexes as even centers.
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i + 1;
        int k = iterate(s, l, r);
        if (ans < k)
        {
            ans = k;
            res = s.substr(templ, ans);
        }
    }
    if (ans == 1)
        return s.substr(0, ans);//substr(left_index,length_from_there)
    return res;
}

/*
Complexity Analysis

Time complexity : O(n^2).
Since expanding a palindrome around its center could take O(n)time, 
the overall complexity is O(n^2).
Space complexity : O(1).
*/