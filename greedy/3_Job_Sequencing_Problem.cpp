// Problem Statement : You are given a set of N jobs where each job comes with a deadline and profit.The profit can only be earned upon completing the job within its deadline.Find the number of jobs done and the maximum profit that can be obtained.Each job takes a single unit of time and only one job can be performed at a time.

// Example 1:

// Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

// Output: 2 60

// Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
// Profit = 40 + 20 = 60

// Example 2:

// Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}

// Output: 2 127

// Explanation: The  first and third job both having a deadline 2 give the highest profit.
// Profit = 100 + 27 = 127

#include <bits/stdc++.h>
using namespace std;

class Job
{
public:
    int start;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(vector<Job> &arr, int n)
{
    sort(arr.begin(), arr.end(), compare);

    int maxi = arr[0].deadline;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].deadline);
    }

    vector<int> slot(maxi + 1, -1);

    int jobCount = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                jobCount++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return {jobCount, jobProfit};
}

int main()
{
    vector<Job> arr = {{1, 4, 20}, {2, 5, 60}, {3, 6, 70}, {4, 6, 65}, {5, 4, 25}, {6, 2, 80}, {7, 2, 10}, {8, 2, 22}};

    pair<int, int> ans = jobScheduling(arr, arr.size());
    cout << ans.first << " " << ans.second << endl;

    return 0;
}

// Time Complexity : O(NlogN) + O(N*M)
// Space Complexity : O(N)