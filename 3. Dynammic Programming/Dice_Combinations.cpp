#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
#define mod 1000000007
#define init ios::sync_with_stdio(0), cin.tie(0);

int main()
{
    init;
    int n;
    cin >> n;

    vector<ll> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 6; j++)
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }

    cout << dp[n];
}