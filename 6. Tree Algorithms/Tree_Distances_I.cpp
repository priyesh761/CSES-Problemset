#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

// for reference cp handbook page 138- tree algorithms
// compute maximum distance node from child nodes side.
int dfs1(vector<vector<int>> &G, vector<vector<pi>> &dp, int curr, int par)
{
    for (int i = 0; i < G[curr].size(); i++)
    {
        if (G[curr][i] != par)
        {
            int tmp = dfs1(G, dp, G[curr][i], curr);
            if (tmp > dp[curr][0].F)
            {
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = {tmp, G[curr][i]};
            }
            else
                dp[curr][1] = max(dp[curr][1], {tmp, G[curr][i]});
        }
    }
    return dp[curr][0].F + 1;
}

// compute maximum distance node from parent node side.
void dfs2(vector<vector<int>> &G, vector<vector<pi>> &dp, int curr, int par)
{
    if (par != -1)
    {
        if (dp[par][0].S != curr)
        {
            if (dp[par][0].F + 1 > dp[curr][0].F)
            {
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = {dp[par][0].F + 1, par};
            }
            else
                dp[curr][1] = max(dp[curr][1], {dp[par][0].F + 1, par});
        }
        else if (dp[par][1].S != curr)
        {
            if (dp[par][1].F + 1 > dp[curr][0].F)
            {
                dp[curr][1] = dp[curr][0];
                dp[curr][0] = {dp[par][1].F + 1, par};
            }
            else
                dp[curr][1] = max(dp[curr][1], {dp[par][1].F + 1, par});
        }
    }

    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
            dfs2(G, dp, G[curr][i], curr);

    return;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pi>> dp(n + 10, vector<pi>(2, {0, -1}));

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

    dfs1(G, dp, 0, -1);

    dfs2(G, dp, 0, -1);

    for (int i = 0; i < n; i++)
        cout << dp[i][0].F << ' ';

    return 0;
}