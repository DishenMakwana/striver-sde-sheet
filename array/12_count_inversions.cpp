// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Example
// Input Format: N = 5, array[] = {1,2,3,4,5}

// Result: 0

// Explanation: we have a sorted array and the sorted array
// has 0 inversions as for i < j you will never find a pair
// such that A[j] < A[i]. More clear example: 2 has index 1
// and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
// inversion.

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    int inv_count = 0;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;

    if (right > left)
    {
        mid = left + (right - left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];

    int ans = _mergeSort(arr, temp, 0, n - 1);

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(NlogN)
// Space Complexity: O(n)