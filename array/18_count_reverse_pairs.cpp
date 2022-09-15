// Count Reverse Pairs
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Example 1:

// Input: N = 5, array[] = {1,3,2,3,1)

// Output: 2

// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

// Example 2:

// Input: N = 4, array[] = {3,2,1,4}

// Output: 1

// Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    int total = 0;
    int j = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2 * nums[j])
        {
            j++;
        }
        total += (j - (mid + 1));
    }

    vector<int> tmp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            tmp.push_back(nums[left++]);
        }
        else
        {
            tmp.push_back(nums[right++]);
        }
    }

    while (left <= mid)
    {
        tmp.push_back(nums[left++]);
    }

    while (right <= high)
    {
        tmp.push_back(nums[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = tmp[i - low];
    }

    return total;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = low + (high - low) / 2;

    int inv = mergeSort(nums, low, mid);
    inv += mergeSort(nums, mid + 1, high);

    inv += merge(nums, low, mid, high);

    return inv;
}

int reversePairs(vector<int> &arr)
{
    return mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1, 3, 2, 3, 1};

    cout << reversePairs(arr) << endl;
}

// Time Complexity: O(NlogN) + O(N) + O(N)
// Space Complexity: O(N)