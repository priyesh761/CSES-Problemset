#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll
#define mod (ll)(1e9 + 7)

int32_t main()
{
    int n, m;
    cin >> n >> m;

    int ar[n + 1];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 2));

    if (ar[0] == 0)
        fill(dp[0].begin(), dp[0].end(), 1);
    else
        dp[0][ar[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        if (ar[i] == 0)
        {
            for (int j = 1; j <= m; j++)
                if (dp[i - 1][j])
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    if (j - 1 > 0)
                        dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
                    if (j + 1 <= m)
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
                }
        }
        else
        {
            dp[i][ar[i]] += dp[i - 1][ar[i]];
            if (ar[i] - 1 > 0)
                dp[i][ar[i]] += dp[i - 1][ar[i] - 1];
            if (ar[i] + 1 <= m)
                dp[i][ar[i]] += dp[i - 1][ar[i] + 1];

            dp[i][ar[i]] %= mod;
        }
    }

    ll sum = 0;
    for (int j = 1; j <= m; j++)
        sum = (sum + dp[n - 1][j]) % mod;

    cout << sum;
}