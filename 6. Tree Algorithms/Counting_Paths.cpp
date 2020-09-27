#include <bits/stdc++.h>

using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi G(2e5 + 10);
vvi parent(2e5 + 10, vi(log2(2e5) + 100, -1));
vi depth(2e5 + 10);

void dfs(int par, int curr, int dep)
{
    depth[curr] = dep;
    parent[curr][0] = par;
    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
            dfs(curr, G[curr][i], dep + 1);
}

// Lowest common ancestor using binary lifting
int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    int levDiff = depth[a] - depth[b];

    while (levDiff > 0)
    {
        int pow = 0;
        while (levDiff >= (1 << pow))
            pow++;
        pow--;
        levDiff -= (1 << pow);
        a = parent[a][pow];
    }

    while (a != b)
    {
        int pow = 0;
        while (parent[a][pow] != parent[b][pow])
            pow++;
        if (pow)
            pow--;
        a = parent[a][pow];
        b = parent[b][pow];
    }

    return a;
}

int dfs1(vector<int> &path, vector<int> &lca, int par, int curr)
{
    int sum = 0;
    for (int i = 0; i < G[curr].size(); i++)
        if (par != G[curr][i])
            sum += dfs1(path, lca, curr, G[curr][i]);

    path[curr] += sum - lca[curr];

    return path[curr] - lca[curr];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int c_size = ceil(log2(n)) + 1;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(-1, 0, 0);

    for (int j = 1; j < c_size; j++)
        for (int i = 0; i < n; i++)
        {
            int par = parent[i][j - 1];
            if (par != -1)
                parent[i][j] = parent[par][j - 1];
        }

    vector<int> path(n);
    vector<int> lca(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        int ablca = LCA(a, b);
        path[a]++;
        path[b]++;
        lca[ablca]++;
    }

    dfs1(path, lca, -1, 0);
    for (auto i : path)
        cout << i << ' ';
}
