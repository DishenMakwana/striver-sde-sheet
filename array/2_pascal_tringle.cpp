// Problem Statement : Given an integer N, return the first N rows of Pascal’s triangle.

// Input Format: N = 5

// Result:
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

// Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.

// Solution 1:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++)
        {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};

int main()
{
    int n = 5;
    Solution s;
    vector<vector<int>> res = s.generate(n);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

// Problem 2: Pascal’s Triangle II
// Find the Nth row in Pascal’s Triangle

// Efficient Approach:

// Unlike the above approach, we will just generate only the numbers of the Nth row.
// We can observe that the Nth row of the Pascals triangle consists of following sequence:

// void generateNthRow(int n)
// {
//     int prev = 1;
//     cout << prev;

//     for (int i = 1; i <= n; i++)
//     {
//         int curr = (prev * (n - i + 1)) / i;
//         cout << ", " << curr;

//         prev = curr;
//     }
// }

// int32_t main()
// {
//     int n = 5;
//     generateNthRow(n);

//     return 0;
// }

// Time Complexity: O(N)
// Space Complexity: O(1)