#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

int main()
{
    int n;
    cin >> n;

    vector<pi> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 0});
        v.push_back({y, 1});
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int mx = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        if (v[i].S)
            cnt--;
        else
            cnt++;

        mx = max(mx, cnt);
    }

    cout << mx;
}