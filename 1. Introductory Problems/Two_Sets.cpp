#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007
#define init ios::sync_with_stdio(0), cin.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pi;
#define MS(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    init;
    ll t;
    cin >> t;

    vector<int> v1, v2;

    ll total = (t * (t + 1)) / 2;

    if (total & 1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll req = total / 2;
        ll sum = 0;
        for (int i = t; i > 0; i--)
            if (sum + i > req)
            {
                v2.PB(i);
            }
            else
            {
                v1.PB(i);
                sum += i;
            }

        cout << v1.size() << '\n';
        for (auto i : v1)
            cout << i << ' ';
        cout << '\n';
        cout << v2.size() << '\n';
        for (auto i : v2)
            cout << i << ' ';
        cout << '\n';
    }
}