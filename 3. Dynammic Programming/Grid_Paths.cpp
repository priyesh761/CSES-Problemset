#include <bits/stdc++.h>

using namespace std;
#define mod (int)(1e9 + 7)
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    char ch;
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> ch;

            if (ch == '.')
            {
                dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
                dp[i][j] %= mod;
            }
            else
                dp[i][j] = 0;
        }

    cout << dp[n][n];
}