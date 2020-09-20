#include <bits/stdc++.h>

using namespace std;

int diameter = 0;

int dfs(vector<vector<int>> &G, int par, int curr)
{

    int max1 = 0, max2 = 0;
    for (int i = 0; i < G[curr].size(); i++)
        if (G[curr][i] != par)
        {
            int tmp = dfs(G, curr, G[curr][i]);
            if (tmp > max1)
            {
                max2 = max1;
                max1 = tmp;
            }
            else
                max2 = max(tmp, max2);
        }
    if (max1 + max2 + 1 > diameter)
        diameter = max1 + max2 + 1;
    return max1 + 1;
}

int main()
{
    diameter = 0;

    int n;
    cin >> n;

    vector<vector<int>> v(n);

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(v, -1, 0);
    cout << diameter - 1;
}