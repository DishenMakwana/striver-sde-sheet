// Merge two Sorted Arrays Without Extra Space
// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int ar2[], int n, int m)
{
    int gap = ceil((float)(n + m) / 2);

    while (gap > 0)
    {
        int i = 0;
        int j = gap;

        while (j < (n + m))
        {
            if (j < n && ar1[i] > ar1[j])
            {
                swap(ar1[i], ar1[j]);
            }
            else if (j >= n && i < n && ar1[i] > ar2[j - n])
            {
                swap(ar1[i], ar2[j - n]);
            }
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
            {
                swap(ar2[i - n], ar2[j - n]);
            }
            i++;
            j++;
        }

        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil((float)gap / 2);
        }
    }
}

int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};

    merge(arr1, arr2, 5, 3);

    cout << "Array 1: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << endl;

    cout << "Array 2: ";
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}

// TC : O(n+m)
// SC : O(1)