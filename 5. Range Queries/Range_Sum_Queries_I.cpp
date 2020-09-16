#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{

    int n, q;
    cin >> n >> q;

    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int b_size = sqrt(n);
    vector<ll> v((int)ceil(sqrt(n)));

    for (int i = 0; i < n; i++)
    {
        v[i / b_size] += ar[i];
    }
    // Square root decomposition
    while (q--)
    {

        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ll sum = 0;

        int left = x / b_size + 1;
        int right = y / b_size;

        for (int i = x; i < min(left * b_size, y + 1); i++)
            sum += ar[i];

        for (int i = left; i < right; i++)
            sum += v[i];

        for (int i = max(left, right) * b_size; i <= y; i++)
            sum += ar[i];

        cout << sum << '\n';
    }
}
