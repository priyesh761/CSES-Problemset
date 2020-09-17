#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod ((ll)1e9 + 7)

class trie
{
public:
    unordered_map<char, trie *> mp;
    bool end{0};
};

int main()
{
    trie *dict = new trie();
    string s;
    cin >> s;

    int k;
    cin >> k;

    string t;
    while (k--)
    {
        cin >> t;

        trie *curr = dict;

        for (int i = 0; i < t.length(); i++)
        {
            if (curr->mp.count(t[i]) == 0)
                curr->mp[t[i]] = new trie();
            curr = curr->mp[t[i]];
        }
        curr->end = 1;
    }

    s = ' ' + s;
    //subset sum problem varient
    vector<ll> dp(s.length());
    dp[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (dp[i - 1] > 0)
        {
            trie *curr = dict;
            for (int j = i; j < s.length(); j++)
            {
                if (curr->mp.count(s[j]) == 0)
                    break;
                curr = curr->mp[s[j]];

                if (curr->end)
                    dp[j] += dp[i - 1];
                dp[j] %= mod;
            }
        }
    }

    cout << dp.back();
}