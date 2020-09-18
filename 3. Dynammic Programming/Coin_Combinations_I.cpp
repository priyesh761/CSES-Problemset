#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod (ll)(1e9 + 7);

int main()
{

    ll n, sum;
    cin >> n >> sum;

    vector<ll> coin(n);
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    vector<ll> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
        for (int j = 0; j < n; j++)
            if (i - coin[j] >= 0)
            {
                dp[i] += dp[i - coin[j]];
                dp[i] %= mod;
            }

    cout << dp[sum];
}
