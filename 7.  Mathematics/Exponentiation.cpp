#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

#define mod ((ll)1e9 + 7)

ll power(ll x, ll y)
{
    ll res = 1;

    while (y > 0)
    {
        if (y & 1)
        {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        ll x, y;
        cin >> x >> y;

        cout << power(x, y) << '\n';
    }
}