// Merge Overlapping Sub-intervals
// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// Example 1:

// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

// Output: [[1,6],[8,10],[15,18]]

// Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
//  intervals.

// Example 2:

// Input: [[1,4],[4,5]]

// Output: [[1,5]]

// Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (res.back()[1] >= intervals[i][0])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
}

// TC : O(NlogN) + O(N)
// SC : O(N)