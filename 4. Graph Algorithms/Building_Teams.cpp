#include <bits/stdc++.h>

using namespace std;
// bipartite check
bool dfs(vector<vector<int>> &G, vector<int> &res, bool color, int curr)
{
    res[curr] = color;

    bool st = 1;
    for (int i = 0; i < G[curr].size(); i++)
    {
        if (res[G[curr][i]] == -1)
            st &= dfs(G, res, !color, G[curr][i]);
        else if (res[curr] == res[G[curr][i]])
            return 0;
    }
    return st;
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
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> res(n, -1);
    bool st = 1;
    for (int i = 0; i < n; i++)
        if (res[i] == -1)
            st &= dfs(G, res, 0, i);

    if (st)
    {
        for (auto i : res)
            cout << ((i) ? 1 : 2) << ' ';
    }
    else
        cout << "IMPOSSIBLE";
}