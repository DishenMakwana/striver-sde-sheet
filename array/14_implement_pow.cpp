// Implement Pow(x,n) | X raised to the power N
// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

// Example 1:

// Input: x = 2.00000, n = 10

// Output: 1024.00000

// Explanation: You need to calculate 2.00000 raised to 10 which gives ans 1024.00000

// Example 2:

// Input: x = 2.10000, n = 3

// Output: 9.26100

// Explanation: You need to calculate 2.10000 raised to 3 which gives ans 9.26100

#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;

    if (nn < 0)
    {
        nn = -1 * nn;
    }

    while (nn)
    {
        if (nn % 2)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }

    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }

    return ans;
}

int main()
{
    double x = 2;
    int n = 10;

    cout << myPow(x, n) << endl;

    return 0;
}

// Time Complexity: O(log(n))
// Space Complexity: O(1)