#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;

    cin >> n >> x;

    int a = -1, b = -1;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (mp.count(x - num))
        {
            a = mp[x - num];
            b = i + 1;
        }
        mp[num] = i + 1;
    }

    if (a == -1)
        cout << "IMPOSSIBLE";
    else
        cout << a << ' ' << b;
}