#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
#define int ll
#define F first
#define S second
pi dfs(vector<vector<int>> &G, vector<pi> &dp, int par, int curr)
{
    for (int i = 0; i < G[curr].size(); i++)
        if (par != G[curr][i])
        {
            int cnt, sum;
            tie(cnt, sum) = dfs(G, dp, curr, G[curr][i]);
            dp[curr].S += cnt;
            dp[curr].F += sum;
        }

    dp[curr].F += dp[curr].S;

    return {dp[curr].S + 1, dp[curr].F};
}

void dfs1(vector<vector<int>> &G, vector<pi> &dp, int par, int curr)
{
    if (par != -1)
    {
        int p_sum = dp[par].F - (dp[curr].F + dp[curr].S + 1);
        int p_count = dp[par].S - (dp[curr].S + 1);

        dp[curr].F += p_sum + p_count + 1;
        dp[curr].S += p_count + 1;
    }

    for (int i = 0; i < G[curr].size(); i++)
        if (par != G[curr][i])
            dfs1(G, dp, curr, G[curr][i]);
}

int32_t main()
{
    int n;
    cin >> n;

    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<pi> dp(n);

    dfs(G, dp, -1, 0);
    dfs1(G, dp, -1, 0);

    for (auto i : dp)
        cout << i.F << ' ';
}