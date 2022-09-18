// Length of Longest Substring without any Repeating Character
// Problem Statement: Given a String, find the length of longest substring without any repeating character.

// Example 1:

// Input: s = ”abcabcbb”

// Output: 3

// Explanation: The answer is abc with length of 3.

// Example 2:

// Input: s = ”bbbbb”

// Output: 1

// Explanation: The answer is b with length of 1 units.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> mp(266, -1);

    int l = 0, r = 0, n = s.size(), len = 0;

    while (r < n)
    {
        if (mp[s[r]] != -1)
        {
            l = max(l, mp[s[r]] + 1);
        }

        mp[s[r]] = r;

        len = max(len, r - l + 1);
        r++;
    }

    return len;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)