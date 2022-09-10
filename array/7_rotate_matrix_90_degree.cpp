// Rotate Image by 90 degree
// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Example 1:

// Input: [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

// Example 2:

// Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

// Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[i].size(); j++)
            {
                swap(matrix[j][i], matrix[i][j]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size() / 2; j++)
            {
                swap(matrix[i][matrix.size() - j - 1], matrix[i][j]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Solution s;
    s.rotate(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC: O(N^2)
// SC: O(1)