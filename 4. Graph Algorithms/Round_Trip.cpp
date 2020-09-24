#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int dfs(vector<vector<int>> &G, vector<bool> &vis, int curr, int par = -1)
{
    vis[curr] = 1;
    for (int i = 0; i < G[curr].size(); i++)
        if (vis[G[curr][i]])
        {
            if (G[curr][i] != par)
            {
                res.push_back(G[curr][i] + 1);
                res.push_back(curr + 1);
                return G[curr][i];
            }
        }
        else
        {
            int var = dfs(G, vis, G[curr][i], curr);
            if (var == -2)
                continue;
            if (var != -1)
                res.push_back(curr + 1);
            return (var == curr) ? -1 : var;
        }

    return -2;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0 && res.empty())
            dfs(G, vis, i);

    if (res.empty())
        cout << "IMPOSSIBLE";
    else
    {
        cout << res.size() << '\n';
        for (auto i : res)
            cout << i << ' ';
    }
}