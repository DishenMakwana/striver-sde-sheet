// Dutch national flag algorithm

// Sort an array of 0s, 1s and 2s

// Problem Statement: Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Input: nums = [0]
// Input: nums = [0]

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &nums)
{
    int l = 0, m = 0, h = nums.size() - 1;

    while (m <= h)
    {
        if (nums[m] == 0)
        {
            swap(nums[l++], nums[m++]);
        }
        else if (nums[m] == 2)
        {
            swap(nums[m++], nums[h--]);
        }
        else
        {
            m++;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortArray(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

// TC: O(N)
// SC: O(1)