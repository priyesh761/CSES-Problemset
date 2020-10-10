//CSES
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
    cout << t << ' ';

    while (t != 1)
    {
        if (t & 1)
            t = t * 3 + 1;
        else
            t /= 2;
        cout << t << ' ';
    }
}
