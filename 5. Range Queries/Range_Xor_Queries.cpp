#include <bits/stdc++.h>
using namespace std;

class segTree
{
    vector<int> data;
    int n{0};

    void buildSegTree(vector<int> &ar, int start, int end, int segIndex)
    {
        if (start == end)
        {
            data[segIndex] = ar[start];
            return;
        }

        int mid = start + (end - start) / 2;
        buildSegTree(ar, start, mid, 2 * segIndex + 1);
        buildSegTree(ar, mid + 1, end, 2 * segIndex + 2);
        data[segIndex] = data[2 * segIndex + 1] ^ data[2 * segIndex + 2];
    }

    int getVal(int l, int r, int start, int end, int segIndex)
    {
        if (l > end || r < start)
            return 0;
        if (l <= start && r >= end)
            return data[segIndex];

        int mid = start + (end - start) / 2;
        int v1 = getVal(l, r, start, mid, 2 * segIndex + 1);
        int v2 = getVal(l, r, mid + 1, end, 2 * segIndex + 2);
        return v1 ^ v2;
    }

public:
    segTree(vector<int> &ar)
    {
        n = ar.size();
        data.resize(4 * n + 2, INT_MAX);
        buildSegTree(ar, 0, n - 1, 0);
    }

    int getVal(int l, int r) { return getVal(l, r, 0, n - 1, 0); }
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    segTree seg(ar);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << seg.getVal(x - 1, y - 1) << '\n';
    }
}