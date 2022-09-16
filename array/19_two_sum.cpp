// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

// Note: Assume that there is exactly one solution, and you are not allowed to use the same element twice. Example: If target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

// Input: nums = [2,7,11,15], target = 9

// Output: [0,1]

// Explanation: Because nums[0] + nums[1] == 9,
// which is the required target, we return
// indexes [0,1]. (0-based indexing)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }

        mp[nums[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)