#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

ll numProd(vector<ll> &v, ll time)
{
    ll sum = 0;
    for (auto i : v)
        sum += time / i;

    return sum;
}

int main()
{
    int n, t;
    cin >> n >> t;

    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    ll low = 0, high = 1e18 + 100;
    ll ans = -1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (numProd(v, mid) >= t)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << ans;
}