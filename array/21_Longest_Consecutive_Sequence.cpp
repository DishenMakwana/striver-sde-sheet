// Longest Consecutive Sequence in an Array
// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

// Example 1:

// Input: [100, 200, 1, 3, 2, 4]

// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// Input: [3, 8, 5, 7, 6]

// Output: 4

// Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    set<int> s;

    for (int num : nums)
    {
        s.insert(num);
    }

    int longestStreak = 0;

    for (int num : nums)
    {
        if (!s.count(num - 1))
        {
            int currentNum = num;
            int currentStreak = 1;

            while (s.count(currentNum + 1))
            {
                currentNum++;
                currentStreak++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main()
{
    vector<int> nums = {100, 200, 1, 3, 2, 4};
    cout << longestConsecutive(nums) << endl;
    return 0;
}

// Time Complexity: 3*O(n) = O(n)
// Space Complexity: O(n)