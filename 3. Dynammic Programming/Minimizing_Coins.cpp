#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;

    cin >> n >> x;

    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
        for (int j = 0; j < n; j++)
            if (i - ar[j] >= 0)
                if (i - ar[j] == 0 || dp[i - ar[j]] != x + 1)
                    dp[i] = min(dp[i], dp[i - ar[j]] + 1);

    if (dp[x] == x + 1)
        cout << -1;
    else
        cout << dp[x];
}