#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int mx = 0;
    int i = 0;

    while (i < s.length())
    {
        int j = i;
        while (i < s.length() && s[i] == s[j])
            i++;
        mx = max(mx, i - j);
    }

    cout << mx;
}