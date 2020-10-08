#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

int main()
{
    int n, m, q;

    cin >> n >> m >> q;

    vector<vector<ll>> W(n, vector<ll>(n, LONG_LONG_MAX));

    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        W[a][b] = min(W[a][b], c);
        W[b][a] = min(W[a][b], c);
    }

    for (int i = 0; i < n; i++)
        W[i][i] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (W[a][b] == LONG_LONG_MAX)
            cout << -1 << '\n';
        else
            cout << W[a][b] << '\n';
    }
}
