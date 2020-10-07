#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

int main()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> get<0>(v[i]) >> get<1>(v[i]);
        get<2>(v[i]) = i;
    }

    sort(v.begin(), v.end());

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> res(n);
    int cnt = 0, mx = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && pq.top().F < get<0>(v[i]))
        {
            st.insert(pq.top().S);
            pq.pop();
            cnt--;
        }

        cnt++;
        if (st.empty())
        {
            pq.push({get<1>(v[i]), cnt});
            res[get<2>(v[i])] = cnt;
        }
        else
        {
            res[get<2>(v[i])] = *st.begin();
            pq.push({get<1>(v[i]), *st.begin()});
            st.erase(st.begin());
        }

        mx = max(mx, cnt);
    }

    cout << mx << '\n';

    for (auto i : res)
        cout << i << ' ';
}