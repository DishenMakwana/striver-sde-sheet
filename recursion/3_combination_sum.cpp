// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include <bits/stdc++.h>
using namespace std;

void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[idx] <= target)
    {
        ds.push_back(arr[idx]);

        findCombination(idx, target - arr[idx], arr, ans, ds);

        ds.pop_back();
    }

    findCombination(idx + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;

    findCombination(0, target, candidates, ans, ds);

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(arr, target);

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

// Time Complexity : O(2 ^ t * k)
// Space Complexity: O(k*x)