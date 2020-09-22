#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        x = i;
        while (x > 0)
        {
            int dig = x % 10;
            if (dig != 0)
                dp[i] = min(dp[i], dp[i - dig] + 1);
            x /= 10;
        }
    }

    cout << dp[n];
}