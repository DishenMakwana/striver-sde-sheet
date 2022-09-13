// Search in a sorted 2D matrix
// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

// Given matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

// Example

// Input: matrix =
// [[1,3,5,7],
//  [10,11,16,20],
//  [23,30,34,60]],

// target = 3

// Output: true

// Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;

    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0, h = (n * m) - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (matrix[mid / m][mid % m] == target)
            return true;
        else if (matrix[mid / m][mid % m] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    cout << searchMatrix(matrix, target) << endl;

    return 0;
}

// Time Complexity: O(log(n*m))
// Space Complexity: O(1)