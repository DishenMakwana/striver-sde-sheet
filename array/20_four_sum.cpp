// 4 Sum | Find Quads that add up to a target value
// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Input Format: arr[] = [1,0,-1,0,-2,2], target = 0

// Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Explanation: We have to find unique quadruplets from
// the array such that the sum of those elements is
// equal to the target sum given that is 0.

// The result obtained is such that the sum of the
// quadruplets yields 0.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;

    if (nums.empty())
    {
        return res;
    }

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        int target_3 = target - nums[i];

        for (int j = i + 1; j < n; j++)
        {
            int target_2 = target_3 - nums[j];

            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {
                int two_sum = nums[front] + nums[back];

                if (two_sum < target_3)
                {
                    front++;
                }
                else if (two_sum > target_2)
                {
                    back--;
                }
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];
                    res.push_back(quad);

                    while (front < back && nums[front] == quad[2])
                    {
                        front++;
                    }

                    while (front < back && nums[back] == quad[3])
                    {
                        back--;
                    }
                }
            }

            while (j + 1 < n && nums[j + 1] == nums[j])
            {
                j++;
            }
        }

        while (i + 1 < n && nums[i + 1] == nums[i])
        {
            i++;
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}