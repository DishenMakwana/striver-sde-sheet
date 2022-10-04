// Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

// Example 1:

// Input: V = 70

// Output: 2

// Explanation: We need a 50 Rs note and a 20 Rs note.

// Example 2:

// Input: V = 121

// Output: 3

// Explanation: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

#include <bits/stdc++.h>
using namespace std;

vector<int> findMin(int V)
{
    vector<int> deno = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = deno.size() - 1; i >= 0; i--)
    {
        while (V >= deno[i])
        {
            V -= deno[i];
            ans.push_back(deno[i]);
            // mp[deno[i]]++;
        }
    }

    // for (auto i : mp)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    return ans;
}

int main()
{
    int n = 93;

    vector<int> ans = findMin(n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Time Complexity: O(V)
// Space Complexity: O(1)