#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;

    cin >> n >> x;

    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar, ar + n);

    int cnt = 0;
    int i = n - 1;

    while (i >= 0 && ar[i] > x)
    {
        cnt++;
        i--;
    }

    int j = 0;

    while (j <= i)
    {
        if (ar[j] + ar[i] <= x)
            j++;
        cnt++;
        i--;
    }

    cout << cnt;
}