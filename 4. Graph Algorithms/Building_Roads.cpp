#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &G, vector<bool> &vis, int curr)
{
    vis[curr] = 1;
    for (int i = 0; i < G[curr].size(); i++)
        if (vis[G[curr][i]] == 0)
            dfs(G, vis, G[curr][i]);
}
int main()
{
    int n, m;

    cin >> n >> m;
    vector<vector<int>> G(n);

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<bool> vis(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(G, vis, i);
            res.push_back(i);
        }
    }

    cout << res.size() - 1 << '\n';
    for (int i = 1; i < res.size(); i++)
        cout << res[i] + 1 << ' ' << res[i - 1] + 1 << '\n';
}