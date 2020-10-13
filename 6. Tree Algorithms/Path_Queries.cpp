#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define F first
#define S second

void dfs(vector<vi> &G, vi &eu, vector<pi> &tl, int node, int par)
{
    tl[node].F = eu.size();
    eu.push_back(node);

    for (int i = 0; i < G[node].size(); i++)
        if (G[node][i] != par)
            dfs(G, eu, tl, G[node][i], node);

    tl[node].S = eu.size();
    eu.push_back(node);
}

class segTree
{
private:
    vector<long long> data;
    int size{0};

    void build(vi &ar, int start, int end, int segIndex)
    {
        if (start == end)
        {
            data[segIndex] = ar[start];
            return;
        }

        int mid = start + (end - start) / 2;
        build(ar, start, mid, 2 * segIndex + 1);
        build(ar, mid + 1, end, 2 * segIndex + 2);
        data[segIndex] = data[2 * segIndex + 1] + data[2 * segIndex + 2];
    }

    void update(int ind, int val, int start, int end, int segIndex)
    {
        if (start > ind || end < ind)
            return;
        if (start == end && start == ind)
            data[segIndex] = val;
        else
        {
            int mid = start + (end - start) / 2;
            update(ind, val, start, mid, 2 * segIndex + 1);
            update(ind, val, mid + 1, end, 2 * segIndex + 2);
            data[segIndex] = data[2 * segIndex + 1] + data[2 * segIndex + 2];
        }
    }
    ll query(int l, int r, int start, int end, int segIndex)
    {
        if (l > end || r < start)
            return 0;
        if (l <= start && end <= r)
            return data[segIndex];

        int mid = start + (end - start) / 2;
        return query(l, r, start, mid, 2 * segIndex + 1) + query(l, r, mid + 1, end, 2 * segIndex + 2);
    }

public:
    segTree(vi &ar)
    {
        size = ar.size();
        data.resize(size * 4 + 3, 0);
        build(ar, 0, size - 1, 0);
    }

    void updateSegTree(int ind, int val) { update(ind, val, 0, size - 1, 0); }

    ll getRangeVal(int l, int r) { return query(l, r, 0, size - 1, 0); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> node(n);
    for (int i = 0; i < n; i++)
        cin >> node[i];

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

    vector<int> eu;
    vector<pi> tl(n);
    dfs(G, eu, tl, 0, -1);

    for (int i = 0; i < tl.size(); i++)
    {
        eu[tl[i].F] = node[i];
        eu[tl[i].S] = -1 * node[i];
    }

    segTree seg(eu);

    while (q--)
    {
        int type, s, x;
        cin >> type >> s;
        s--;
        if (type == 1)
        {
            cin >> x;
            seg.updateSegTree(tl[s].F, x);
            seg.updateSegTree(tl[s].S, -1 * x);
        }
        else
        {
            ll val = seg.getRangeVal(0, tl[s].F);
            cout << val << '\n';
        }
    }
}