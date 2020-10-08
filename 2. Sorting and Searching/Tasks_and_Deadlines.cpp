#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

int main()
{
    int n;
    cin >> n;

    vector<pi> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].F >> v[i].S;

    sort(v.begin(), v.end());
    long long time = 0, j = 0;
    long long price = 0;

    for (auto i : v)
    {
        time += i.F;
        price += (i.S - time);
    }

    cout << price;
}