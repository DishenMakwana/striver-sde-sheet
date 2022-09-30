// Problem Statement : The weight of N items and their corresponding values are given.We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

// Example:

// Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

// Output: 240.00

// Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00

#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int value;
    int weight;
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &arr, int n)
{
    sort(arr.begin(), arr.end(), compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return finalValue;
}

int main()
{
    int W = 3;

    vector<Item> arr = {{100, 20}, {60, 10}, {120, 30}};

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << fractionalKnapsack(W, arr, arr.size()) << endl;

    return 0;
}

// Time Complexity : O(NlogN) + O(N) = O(NlogN)
// Space Complexity : O(1)