// Problem Statement : Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

// Example 1:

// Input: prices = {1, 1, 0, 1, 1, 1}

// Output: 3

// Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

// Input: prices = {1, 0, 1, 1, 0, 1}

// Output: 2

// Explanation: There are two consecutive 1's in the array.

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0, maxi = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }

        maxi = max(maxi, cnt);
    }

    return maxi;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)