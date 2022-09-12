// Find the repeating and missing numbers
// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Example
// Input Format:  array[] = {3,1,2,5,3}

// Result: {3,4)

// Explanation: A = 3 , B = 4
// Since 3 is appearing twice and 4 is missing

#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &arr)
{
    int xor1;
    int set_bit_no;

    int i;
    int x = 0, y = 0, n = arr.size();

    xor1 = arr[0];

    for (int i = 1; i < n; ++i)
    {
        xor1 = xor1 ^ arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    set_bit_no = xor1 & ~(xor1 - 1);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
        {
            x = x ^ i;
        }
        else
        {
            y = y ^ i;
        }
    }

    int x_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            x_count++;
        }
    }

    if (x_count == 0)
    {
        return {y, x};
    }

    return {x, y};
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 3};

    vector<int> result = repeatedNumber(arr);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}

// TC : O(n)
// SC : O(1)