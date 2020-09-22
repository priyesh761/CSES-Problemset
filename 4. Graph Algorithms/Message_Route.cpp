#include <bits/stdc++.h>

using namespace std;

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

    vector<int> vis(n, -1);

    queue<pair<int, int>> qu;
    qu.push({0, 1});
    vis[0] = 0;
    int x, dist = 0;
    while (qu.empty() == 0)
    {
        tie(x, dist) = qu.front();
        qu.pop();

        if (x == n - 1)
            break;

        for (int i = 0; i < G[x].size(); i++)
        {
            if (vis[G[x][i]] == -1)
            {
                qu.push({G[x][i], dist + 1});
                vis[G[x][i]] = x;
            }
        }
    }

    if (vis[n - 1] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << dist << '\n';
    vector<int> path;
    int i = n - 1;

    while (i != 0)
    {
        path.push_back(i + 1);
        i = vis[i];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    for (auto i : path)
        cout << i << ' ';
}