#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<int> primes;
vector<bool> vis(1e6 + 10, 1);

void seive()
{

    vis[0] = 0;
    vis[1] = 0;
    for (ll i = 2; i <= 1e6 + 1; i++)
    {
        if (vis[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= 1e6 + 1; j += i)
                vis[j] = 0;
        }
    }
}

int main()
{
    seive();
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> mp;
        int i = 0;
        if (vis[n] == 0)
            while (primes[i] * primes[i] <= n)
            {
                int pow = 0;
                while (n % primes[i] == 0)
                {
                    pow++;
                    n /= primes[i];
                }
                mp[primes[i]] = pow;
                i++;
            }
        if (n != 1)
            mp[n]++;

        int prod = 1;
        for (auto i : mp)
            prod *= (i.second + 1);
        cout << prod << '\n';
    }
}