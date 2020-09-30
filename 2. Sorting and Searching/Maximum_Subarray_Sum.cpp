#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    long long sum = ar[0], mx = ar[0];

    for (int i = 1; i < n; i++)
    {
        sum = max(sum + ar[i], ar[i]);
        mx = max(mx, sum);
    }

    cout << mx;
}