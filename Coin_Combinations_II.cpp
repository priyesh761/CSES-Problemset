#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod (ll)(1e9 + 7)

int main()
{

    int n, x;

    cin >> n >> x;

    int ar[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> ar[i];

    vector<int> dp(x + 1);

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= x; j++)
            if (j - ar[i] >= 0 && dp[j - ar[i]])
            {
                dp[j] += dp[j - ar[i]];
                dp[j] %= mod;
            }

    cout << dp[x];
}