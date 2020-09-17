#include <bits/stdc++.h>

using namespace std;
int dfs(vector<vector<int>> &G, vector<int> &sub, int curr)
{

    int cnt = 1;

    for (int i = 0; i < G[curr].size(); i++)
        cnt += dfs(G, sub, G[curr][i]);

    sub[curr] = cnt - 1;
    return cnt;
}
int main()
{
    int n;
    cin >> n;

    vector<int> par(n);
    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par[i]--;
        G[par[i]].push_back(i);
    }

    vector<int> subordinates(n);

    dfs(G, subordinates, 0);

    for (int i = 0; i < n; i++)
        cout << subordinates[i] << ' ';
}