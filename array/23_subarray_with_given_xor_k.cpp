// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to B.

// Input Format:  A = [4, 2, 2, 6, 4] , B = 6
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Input Format: A = [5, 6, 7, 8, 9], B = 5
// Result: 2
// Explanation:The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int xorr = 0;
    int cnt = 0;

    for (int it : nums)
    {
        xorr = xorr ^ it;

        if (xorr == k)
        {
            cnt++;
        }

        if (mp.find(xorr ^ k) != mp.end())
        {
            cnt += mp[xorr ^ k];
        }

        mp[xorr]++;
    }

    return cnt;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout << solve(nums, k) << endl;

    nums = {5, 6, 7, 8, 9};
    k = 5;

    cout << solve(nums, k) << endl;

    return 0;
}

// Time Complexity: O(NlogN)
// Space Complexity: O(N)