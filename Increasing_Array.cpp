#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    long long cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int tmp = max(0, ar[i - 1] - ar[i]);
        ar[i] += tmp;
        cnt += tmp;
    }

    cout << cnt;
}