#include <bits/stdc++.h>
using namespace std;

class segTree
{
    vector<int> data;
    int n{0};

    void buildSegTree(vector<int> &ar, int start, int end, int segIndex)
    {
        if (start > end)
            return;
        if (start == end)
        {
            data[segIndex] = ar[start];
            return;
        }

        int mid = start + (end - start) / 2;

        buildSegTree(ar, start, mid, 2 * segIndex + 1);
        buildSegTree(ar, mid + 1, end, 2 * segIndex + 2);

        data[segIndex] = min(data[2 * segIndex + 1], data[2 * segIndex + 2]);
        return;
    }

    void updateSegTree(int ind, int val, int start, int end, int segIndex)
    {
        if (start > end || end < ind || start > ind)
            return;
        if (start == end && start == ind)
        {
            data[segIndex] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        updateSegTree(ind, val, start, mid, 2 * segIndex + 1);
        updateSegTree(ind, val, mid + 1, end, 2 * segIndex + 2);

        data[segIndex] = min(data[2 * segIndex + 1], data[2 * segIndex + 2]);
        return;
    }

    int getVal(int l, int r, int start, int end, int segIndex)
    {
        if (l > end || r < start)
            return INT_MAX;
        if (l <= start && r >= end)
            return data[segIndex];

        int mid = start + (end - start) / 2;

        int v1 = getVal(l, r, start, mid, 2 * segIndex + 1);
        int v2 = getVal(l, r, mid + 1, end, 2 * segIndex + 2);
        return min(v1, v2);
    }

public:
    segTree(vector<int> &ar)
    {
        n = ar.size();
        data.resize(4 * n + 2, INT_MAX);
        buildSegTree(ar, 0, n - 1, 0);
    }
    void updateSegTree(int ind, int val)
    {
        updateSegTree(ind, val, 0, n - 1, 0);
    }

    int getVal(int l, int r)
    {
        return getVal(l, r, 0, n - 1, 0);
    }
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
        int x, y, z;
        cin >> z >> x >> y;

        if (z == 1)
            seg.updateSegTree(x - 1, y);
        else
            cout << seg.getVal(x - 1, y - 1) << '\n';
    }
}