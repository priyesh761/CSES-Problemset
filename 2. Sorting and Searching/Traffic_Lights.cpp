// Ambigious question refer https://codeforces.com/blog/entry/68127

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    set<int> st;
    set<int, greater<int>> st1;
    map<int, int, greater<int>> gap;

    gap[n]++;

    for (int i = 0; i < x; i++)
    {
        int tmp;
        cin >> tmp;
        auto rtp = st.upper_bound(tmp);
        auto lfp = st1.upper_bound(tmp);

        int lf = (lfp == st1.end()) ? 0 : *lfp;
        int rt = (rtp == st.end()) ? n : *rtp;
        // cout << lf << ' ' << tmp << ' ' << rt << '\n';

        gap[rt - lf]--;
        if (gap[rt - lf] == 0)
            gap.erase(rt - lf);
        gap[rt - tmp]++;
        gap[tmp - lf]++;
        cout << gap.begin()->first << ' ';

        st.insert(tmp);
        st1.insert(tmp);
    }
}