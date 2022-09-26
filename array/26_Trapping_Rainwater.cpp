// Problem Statement : Given an array of non - negative integers representation elevation of ground.Your task is to find the water that can be trapped after rain.

// Example 1:

// Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1, res = 0, maxLeft = 0, maxRight = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }

            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }

            right--;
        }
    }

    return res;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << trapWater(height) << endl;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)