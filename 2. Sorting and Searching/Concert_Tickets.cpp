#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
bool cmp(pi &a, pi &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ar(n);
    vector<int> b(m);
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        mp[ar[i]]++;
    }
    vector<int> res(m, -1);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        auto tmp = mp.lower_bound(b[i]);
        if (tmp != mp.end() && tmp->second > 0)
        {
            tmp->second--;
            res[i] = tmp->first;
            if (tmp->second == 0)
                mp.erase(tmp);
        }
    }

    for (auto i : res)
        cout << i << '\n';
}
