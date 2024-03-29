// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

// Result: 5

// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}

// Result: 8

// Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
// Length of longest subarray = 8

#include <bits/stdc++.h>
using namespace std;

int longestSubArrayWithZeroSum(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }

    return maxi;
}

int main()
{
    int n;

    vector<int> nums = {9, -3, 3, -1, 6, -5};

    cout << longestSubArrayWithZeroSum(nums) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)