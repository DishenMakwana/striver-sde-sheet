// Find the Majority Element that occurs more than N/2 times
// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// Example

// Input Format: N = 3, nums[] = {3,2,3}

// Result: 3

// Explanation: When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution.

// Moore’s Voting Algorithm

// Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

// Majority element count = N/2 + x;

// Minority/Other elements = N/2 – x;

// Where x is the number of times it occurs after reaching the minimum value N/2.

// Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int cnt = 0, candidate = 0;

    for (int num : nums)
    {
        if (cnt == 0)
        {
            candidate = num;
        }

        if (num == candidate)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    return candidate;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums) << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)