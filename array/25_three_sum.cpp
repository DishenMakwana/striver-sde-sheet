// Problem Statement : Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero.In short, you need to return an array of all the unique triplets[arr[a], arr[b], arr[c]] such that i != j, j != k, k != i, and their sum is equal to zero.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]

// Output: [[-1,-1,2],[-1,0,1]]

// Explanation: Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

// Example 2:

// Input: nums=[-1,0,1,0]
// Output: Output: [[-1,0,1],[-1,1,0]]
// Explanation: Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of summing up to zero with i!=j!=k

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &num)
{
    sort(num.begin(), num.end());

    vector<vector<int>> ans;

    for (int i = 0; i < num.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && num[i] != num[i - 1]))
        {
            int lo = i + 1, hi = num.size() - 1, sum = 0 - num[i];

            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[lo]);
                    tmp.push_back(num[hi]);
                    ans.push_back(tmp);

                    while (lo < hi && num[lo] == num[lo + 1])
                        lo++;

                    while (lo < hi && num[hi] == num[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (num[lo] + num[hi] < sum)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

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

// Time Complexity : O(n^2)
// Space Complexity : O(3*k) = O(k)