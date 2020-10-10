#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> ar(n);
    ll total = 0, mx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        total += ar[i];
        mx = max(mx, ar[i]);
    }
    ll tl = total - mx;

    if (tl < mx)
        total = 2 * mx;

    cout << total;
}