#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &G, vector<int> &depth, int par, int curr, int dep)
{
    depth[curr] = dep;

    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
            dfs(G, depth, curr, G[curr][i], dep + 1);
}

//Lowest common ancestor using binary lifting
int LCA(vector<vector<int>> &parent, vector<int> &depth, int a, int b)
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
        if (pow != 0)
            pow--;
        a = parent[a][pow];
        b = parent[b][pow];
    }

    return a;
}

int main()
{
    int n, q;
    cin >> n >> q;
    int c_size = ceil(log2(n));
    vector<vector<int>> G(n);

    vector<vector<int>> parent(n, vector<int>(c_size, -1));
    vector<int> depth(n);

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        G[x].push_back(i);
        parent[i][0] = x;
    }

    dfs(G, depth, -1, 0, 0);
    // Binary lifting table
    for (int j = 1; j < c_size; j++)
        for (int i = 0; i < n; i++)
        {
            int par = parent[i][j - 1];
            if (par != -1)
                parent[i][j] = parent[par][j - 1];
        }

    while (q--)
    {

        int a, b;
        cin >> a >> b;

        a--;
        b--;

        cout << LCA(parent, depth, a, b) + 1 << '\n';
    }
}