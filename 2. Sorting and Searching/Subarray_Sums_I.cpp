#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    map<long long, int> mp;
    mp[0] = 1;

    long long pf = 0, cnt = 0, ar;
    for (int i = 0; i < n; i++)
    {
        cin >> ar;
        pf += ar;
        cnt += mp[pf - x];
        mp[pf]++;
    }

    cout << cnt;
}