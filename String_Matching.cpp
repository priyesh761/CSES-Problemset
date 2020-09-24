#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class roll_hash
{
    vector<long long> hash;
    vector<long long> power;

    int p = 31;
    ll mod = 1e9 + 9;

public:
    roll_hash(string s)
    {
        s = " " + s;
        hash.resize(s.length());
        power.resize(s.length());
        power[0] = 1;

        for (int i = 1; i < s.length(); i++)
        {
            hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * power[i - 1]) % mod;
            power[i] = (power[i - 1] * p) % mod;
            cout << hash[i] << ' ';
        }
        cout << endl;
    }

    long long get_hash(int left, int right)
    {
        ll rhs = (hash[right + 1] - hash[left] * power[right - left + 1]) % mod;
        if (rhs < 0)
            rhs += mod;
        cout << right << ' ' << hash[right + 1] << ' ' << left << ' ' << hash[left] << ' ' << rhs << ' ' << power[right - left + 1] << '\n';

        return rhs;
    }
};

int main()
{
    string s, k;
    cin >> s;
    cin >> k;

    roll_hash hashS(s), hashK(k);
    ll k_hval = hashK.get_hash(0, k.length() - 1);

    int cnt = 0;
    for (int i = 0; i + k.length() - 1 < s.length(); i++)
    {
        if (hashS.get_hash(i, i + k.length() - 1) == k_hval)
            cnt++;
    }

    cout << cnt;
}