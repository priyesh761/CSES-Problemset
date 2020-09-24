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
int main()
{
    // cin cout time matters for this problem. Fast I/O and buffering required
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

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

    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int lca = LCA(a, b);
        int distance = depth[a] + depth[b] - 2 * depth[lca];
        ans[i] = distance;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}