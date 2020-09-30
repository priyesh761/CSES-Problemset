#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<long long, long long>;

int main()
{
    ll n, m;

    cin >> n >> m;

    vector<vector<ll>> G(n);
    vector<vector<ll>> W(n);

    while (m--)
    {
        ll f, t, d;
        cin >> f >> t >> d;
        f--;
        t--;
        G[f].push_back(t);
        W[f].push_back(d);
    }
    vector<ll> dist(n, LONG_LONG_MAX);
    vector<bool> vis(n);
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        ll x, d;
        tie(d, x) = pq.top();
        pq.pop();

        if (vis[x] == 0)
            for (int i = 0; i < G[x].size(); i++)
            {
                if (dist[G[x][i]] > d + W[x][i])
                {
                    dist[G[x][i]] = d + W[x][i];
                    pq.push({dist[G[x][i]], G[x][i]});
                }
            }
        vis[x] = 1;
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << ' ';
}