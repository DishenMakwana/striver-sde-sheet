// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Input: N = 5, array[] = {1,2,2,3,2}

// Ouput: 2

// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == num1)
        {
            cnt1++;
        }
        else if (nums[i] == num2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            num1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            num2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == num1)
        {
            cnt1++;
        }
        else if (nums[i] == num2)
        {
            cnt2++;
        }
    }

    if (cnt1 > n / 3)
    {
        ans.push_back(num1);
    }

    if (cnt2 > n / 3)
    {
        ans.push_back(num2);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 2};

    vector<int> ans = majorityElement(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)