#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{

    ll n, m, k;
    cin >> n >> m >> k;

    ll ap[n], apt[m];

    for (int i = 0; i < n; i++)
        cin >> ap[i];

    for (int i = 0; i < m; i++)
        cin >> apt[i];

    sort(ap, ap + n);
    sort(apt, apt + m);

    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m)
    {
        if (ap[i] - k <= apt[j] && apt[j] <= ap[i] + k)
        {
            i++;
            j++;
            cnt++;
        }
        else if (apt[j] < ap[i] - k)
            j++;
        else
            i++;
    }

    cout << cnt;
}