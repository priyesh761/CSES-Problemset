#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bt(vector<int> &ar, int ind, ll s1, ll s2)
{

    if (ind == ar.size())
        return abs(s1 - s2);

    ll v1 = bt(ar, ind + 1, s1 + ar[ind], s2);
    ll v2 = bt(ar, ind + 1, s1, s2 + ar[ind]);

    return min(v1, v2);
}
int main()
{

    int n;
    cin >> n;

    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    cout << bt(ar, 0, 0, 0);
}