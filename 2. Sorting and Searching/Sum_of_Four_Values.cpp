#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;

    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            v.push_back({ar[i] + ar[j], i + 1, j + 1});

    sort(v.begin(), v.end());

    int i = 0, j = v.size() - 1;

    while (i < j)
    {
        if (get<0>(v[i]) + get<0>(v[j]) < x)
            i++;
        else
        {
            if (get<0>(v[i]) + get<0>(v[j]) == x)
                if ((get<1>(v[i]) != get<1>(v[j])) && (get<1>(v[i]) != get<2>(v[j])) && (get<2>(v[i]) != get<1>(v[j])) && (get<2>(v[i]) != get<2>(v[j])))
                {
                    cout << get<1>(v[i]) << ' ' << get<2>(v[i]) << ' ' << get<1>(v[j]) << ' ' << get<2>(v[j]);
                    return 0;
                }
            j--;
        }
    }

    cout << "IMPOSSIBLE";
}
