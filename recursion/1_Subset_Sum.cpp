// Problem Statement : Given an array print all the sum of the subset generated from it, in the increasing order.

// Example 1:

// Input: N = 3, arr[] = {5,2,1}

// Output: 0,1,2,3,5,6,7,8

// Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8

// Input: N=3,arr[]= {3,1,2}

// Output: 0,1,2,3,3,4,5,6

// Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6

#include <bits/stdc++.h>
using namespace std;

void rec(int idx, int sum, vector<int> &arr, vector<int> &sumSubset)
{
    if (idx == arr.size())
    {
        sumSubset.push_back(sum);
        return;
    }

    rec(idx + 1, sum + arr[idx], arr, sumSubset);

    rec(idx + 1, sum, arr, sumSubset);
}

vector<int> subsetSum(vector<int> &arr)
{
    vector<int> sumSubset;

    rec(0, 0, arr, sumSubset);

    sort(sumSubset.begin(), sumSubset.end());

    return sumSubset;
}

int32_t main()
{
    vector<int> arr = {3, 2, 1};
    vector<int> sumSubset = subsetSum(arr);

    for (auto x : sumSubset)
        cout << x << " ";

    return 0;
}

// Time Complexity: O(2^n)+O(2^n log(2^n))
// Space Complexity: O(2^n)