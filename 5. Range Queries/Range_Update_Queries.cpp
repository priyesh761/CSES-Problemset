#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class segTree
{
private:
    vector<ll> data;
    vector<ll> lazy;
    int n{0};

    void build(vector<int> &ar, int start, int end, int segIndex)
    {
        //cout << start << ' ' << end << ' ' << segIndex << '\n';
        if (start == end)
            data[segIndex] = ar[start];
        else
        {
            int mid = start + (end - start) / 2;
            build(ar, start, mid, 2 * segIndex + 1);
            build(ar, mid + 1, end, 2 * segIndex + 2);
            data[segIndex] = data[2 * segIndex + 1] + data[2 * segIndex + 2];
        }
    }

    void update(int l, int r, int val, int start, int end, int segIndex)
    {
        if (end < l || r < start)
            return;

        if (l <= start && end <= r)
        {
            data[segIndex] += (end + 1 - start) * (ll)val;
            if (start != end)
            {
                lazy[2 * segIndex + 1] += val;
                lazy[2 * segIndex + 2] += val;
            }
            return;
        }

        int mid = start + (end - start) / 2;
        update(l, r, val, start, mid, 2 * segIndex + 1);
        update(l, r, val, mid + 1, end, 2 * segIndex + 2);
        data[segIndex] = data[2 * segIndex + 1] + data[2 * segIndex + 2];
    }

    ll query(int l, int r, int start, int end, int segIndex)
    {
        data[segIndex] += (end + 1 - start) * lazy[segIndex];
        if (start != end)
        {
            lazy[2 * segIndex + 1] += lazy[segIndex];
            lazy[2 * segIndex + 2] += lazy[segIndex];
        }
        lazy[segIndex] = 0;

        if (end < l || r < start)
            return 0;

        if (l <= start && end <= r)
            return data[segIndex];

        int mid = start + (end - start) / 2;
        return query(l, r, start, mid, 2 * segIndex + 1) + query(l, r, mid + 1, end, 2 * segIndex + 2);
    }

public:
    segTree(vector<int> &ar)
    {
        n = ar.size();
        data.resize(4 * n + 3);
        lazy.resize(4 * n + 3);
        build(ar, 0, n - 1, 0);
    }
    void update(int l, int r, int val) { update(l, r, val, 0, n - 1, 0); }
    ll query(int l, int r) { return query(l, r, 0, n - 1, 0); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    segTree seg(ar);
    while (q--)
    {
        int type, a, b, u, k;
        cin >> type;

        if (type == 1)
        {
            cin >> a >> b >> u;
            seg.update(a - 1, b - 1, u);
        }
        else
        {
            cin >> k;
            cout << seg.query(k - 1, k - 1) << '\n';
        }
    }
}