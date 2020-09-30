#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

bool cmp(pi &a, pi &b)
{
    if (a.S == b.S)
        return a.F < b.F;

    return a.S < b.S;
}

int main()
{
    int n;
    cin >> n;

    vector<pi> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);

    int rt = 0;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].F >= rt)
        {
            cnt++;
            rt = v[i].S;
        }
    }

    cout << cnt;
}