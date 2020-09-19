#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, q;
    cin >> n >> q;

    int ar[n];
    int size = (int)(sqrt(n));

    vector<int> sq(size + 1, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        sq[i / size] = min(sq[i / size], ar[i]);
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int left = x / size + 1;
        int right = y / size;
        int mi = INT_MAX;
        for (int i = x; i < min(left * size, y + 1); i++)
            mi = min(mi, ar[i]);
        for (int i = left; i < right; i++)
            mi = min(mi, sq[i]);
        for (int i = max(left, right) * size; i <= y; i++)
            mi = min(mi, ar[i]);

        cout << mi << endl;
    }
}