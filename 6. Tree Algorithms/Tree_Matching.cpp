#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

void dfs(vector<vector<int>> &G, vector<pi> &dp, int par, int curr)
{
    if (G[curr].size() <= 1)
    {
        dp[curr].F = 0;
        dp[curr].S = 0;
    }
    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
            dfs(G, dp, curr, G[curr][i]);

    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
            dp[curr].F += max(dp[G[curr][i]].F, dp[G[curr][i]].S);

    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
        {
            int tmp = max(dp[G[curr][i]].F, dp[G[curr][i]].S);
            dp[curr].S = max(dp[curr].S, dp[curr].F - tmp + dp[G[curr][i]].F + 1);
        }
    //cout << curr + 1 << ' ' << dp[curr].F << ' ' << dp[curr].S  << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> G(n);
    vector<pair<int, int>> dp(n);

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(G, dp, -1, 0);

    cout << max(dp[0].first, dp[0].second);
}