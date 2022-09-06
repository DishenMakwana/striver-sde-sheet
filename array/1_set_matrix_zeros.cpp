// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]

// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]

// Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

// Solution 1 :

// Approach : Using brute force

// #include <bits/stdc++.h>

// using namespace std;

// void setZeroes(vector<vector<int>> &matrix)
// {
//     int rows = matrix.size(), cols = matrix[0].size();

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (matrix[i][j] == 0)
//             {

//                 int ind = i - 1;
//                 while (ind >= 0)
//                 {
//                     if (matrix[ind][j] != 0)
//                     {
//                         matrix[ind][j] = -1;
//                     }
//                     ind--;
//                 }
//                 ind = i + 1;
//                 while (ind < rows)
//                 {
//                     if (matrix[ind][j] != 0)
//                     {
//                         matrix[ind][j] = -1;
//                     }
//                     ind++;
//                 }
//                 ind = j - 1;
//                 while (ind >= 0)
//                 {
//                     if (matrix[i][ind] != 0)
//                     {
//                         matrix[i][ind] = -1;
//                     }
//                     ind--;
//                 }
//                 ind = j + 1;
//                 while (ind < cols)
//                 {
//                     if (matrix[i][ind] != 0)
//                     {
//                         matrix[i][ind] = -1;
//                     }
//                     ind++;
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (matrix[i][j] <= 0)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// int32_t main()
// {
//     vector<vector<int>> arr;

//     arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

//     setZeroes(arr);

//     cout << "The Final Matrix is " << endl;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = 0; j < arr[0].size(); j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }

// Time Complexity : O((N * M) * (N + M))
// Space Complexity : O(1)

// Solution 2 : Better approach

// #include <bits/stdc++.h>
// using namespace std;

// void setZeroes(vector<vector<int>> &matrix)
// {
//     int rows = matrix.size(), cols = matrix[0].size();

//     vector<int> mat1(rows, -1), mat2(cols, -1);

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 mat1[i] = 0;
//                 mat2[j] = 0;
//             }
//         }
//     }
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             if (mat1[i] == 0 || mat2[j] == 0)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// int main()
// {
//     vector<vector<int>> arr;

//     arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

//     setZeroes(arr);

//     cout << "The Final Matrix is " << endl;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = 0; j < arr[0].size(); j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }

// Time Complexity: O(N*M + N*M)
// Space Complexity: O(N)

// Solution 3 : Optimizing the better approach.

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int column = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        // checking if 0 is present in the 0th column or not
        if (matrix[i][0] == 0)
            column = 0;

        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // traversing in the reverse direction and
    // checking if the row or col has 0 or not
    // and setting values of matrix accordingly.

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }

        if (column == 0)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr;

    arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(arr);

    cout << "The Final Matrix is " << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Time Complexity: O(2*(N*M))
// Space Complexity: O(1)