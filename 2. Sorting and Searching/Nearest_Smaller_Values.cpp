#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int main()
{
    int n;
    cin >> n;

    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    stack<pair<int, int>> st;
    st.push({-1, 0});

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && ar[i] <= st.top().F)
            st.pop();
        cout << st.top().S << ' ';
        st.push({ar[i], i + 1});
    }
}