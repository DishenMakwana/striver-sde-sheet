// Problem Statement : There is one meeting room in a firm.You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting.Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time.Print the order in which these meetings will be performed.

// Example:

// Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

// Output: 1 2 4 5

#include <bits/stdc++.h>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    int pos;
};

bool compare(Meeting a, Meeting b)
{
    if (a.end < b.end)
    {
        return true;
    }
    else if (a.end > b.end)
    {
        return false;
    }
    else if (a.pos < b.pos)
    {
        return true;
    }
    return false;
}

vector<int> maxMeetings(vector<int> &startTime, vector<int> &endTime, int n)
{
    class Meeting meet[n];

    for (int i = 0; i < n; i++)
    {
        meet[i].start = startTime[i];
        meet[i].end = endTime[i];
        meet[i].pos = i + 1;
    }

    sort(meet, meet + n, compare);

    vector<int> ans;

    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }

    return ans;
}

int main()
{

    vector<int> startTime = {1, 3, 0, 5, 8, 5};
    vector<int> endTime = {2, 4, 5, 7, 9, 9};

    vector<int> ans = maxMeetings(startTime, endTime, startTime.size());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity : O(N) + O(NlogN) + O(N) = O(NlogN)
// Space Complexity : O(N)