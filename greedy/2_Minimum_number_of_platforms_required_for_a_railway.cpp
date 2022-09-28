// Problem Statement : We are given two arrays that represent the arrival and departure times of trains that stop at the platform.We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

// Input: N=6,
// arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00}
// dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

// Output:3

#include <bits/stdc++.h>
using namespace std;

int findPlatforms(vector<int> &arrival, vector<int> &departure, int n)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            platforms++;
            i++;
        }
        else if (arrival[i] > departure[j])
        {
            platforms--;
            j++;
        }

        result = max(result, platforms);
    }

    return result;
}

int main()
{
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};

    cout << findPlatforms(arrival, departure, arrival.size()) << endl;

    return 0;
}

// Time Complexity : 2*O(NlogN) + 2*O(N) = O(NlogN)
// Space Complexity : O(1)