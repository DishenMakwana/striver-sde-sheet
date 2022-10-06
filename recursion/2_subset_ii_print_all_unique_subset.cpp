// Problem Statement : Given an array of integers that may contain duplicates the task is to return all possible subsets.Return only unique subsets and they can be in any order.

// Example 1:

// Input: array[] = [1,2,2]

// Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

// Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.

// Input: array[] = [1]

// Output: [ [ ], [1] ]

// Explanation: Only two unique subsets are available

#include <bits/stdc++.h>
using namespace std;

void findSubsets(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx && nums[i] == nums[i - 1])
        {
            continue;
        }

        ds.push_back(nums[i]);

        findSubsets(i + 1, nums, ds, ans);

        ds.pop_back();
    }
}

vector<vector<int>> subsetWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;

    sort(nums.begin(), nums.end());

    findSubsets(0, nums, ds, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 3, 3};

    vector<vector<int>> ans = subsetWithDup(nums);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity : O(2^n * k) where k is the average length of the subset
// Space Complexity : O(2^n * k)