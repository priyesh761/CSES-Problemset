#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007
#define init ios::sync_with_stdio(0), cin.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pi;
#define MS(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair

int main()
{
    init;
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    set<int> st;

    int last = -1;
    int cnt = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {

        if (st.count(ar[i]) == 0)
        {
            st.insert(ar[i]);
            cnt++;
            mx = max(mx, cnt);
        }
        else
        {
            for (int j = last + 1; ar[j] != ar[i]; j++)
            {
                auto tmp = st.find(ar[j]);
                if (tmp != st.end())
                    st.erase(tmp);
                last = j;
                cnt--;
            }
            last++;
        }
        //cout<<last<<' ';
    }

    cout << mx;
}