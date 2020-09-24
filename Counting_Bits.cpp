#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    cin >> n;

    long long ans = 0;
    int msb = 0;
    for (int i = 0; i < 62; i++)
    {
        ans += n / (1LL << i);
    }
    cout << ans;
}