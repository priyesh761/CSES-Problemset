#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<long long, int> mp;
    mp[0] = 1;

    long long pf = 0, cnt = 0, ar;
    for (int i = 0; i < n; i++)
    {
        cin >> ar;
        pf += ar;
        long long key = pf % n;
        if (key < 0)
            key += n;
        cnt += mp[key];
        mp[key]++;
    }

    cout << cnt;
}