#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> ar(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ar[x - 1] = true;
    }

    cout << min_element(ar.begin(), ar.end()) - ar.begin() + 1;
}