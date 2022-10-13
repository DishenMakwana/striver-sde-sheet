// Problem Statement : Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sum to target.Each number in candidates may only be used once in the combination.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8

// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]]

// Explanation: These are the unique combinations whose sum is equal to target.

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5

// Output: [[1,2,2],[5]]

// Explanation: These are the unique combinations whose sum is equal to target.

#include <bits/stdc++.h>
using namespace std;

void findCombinations(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);

        findCombinations(i + 1, target - arr[i], arr, ans, ds);

        ds.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> ds;

    findCombinations(0, target, candidates, ans, ds);

    return ans;
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = combinationSum(arr, target);

    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}

// Time Complexity : O(2 ^ n * k)
// Space Complexity : O(k * x)