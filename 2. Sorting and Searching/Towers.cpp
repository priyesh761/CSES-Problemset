#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ar[n];

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];

        auto it = mp.upper_bound(ar[i]);

        if (it != mp.end())
        {
            it->second--;
            if (it->second == 0)
                mp.erase(it);
        }
        mp[ar[i]]++;
    }

    int num = 0;
    for (auto i : mp)
        num += i.second;

    cout << num;
}