#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second

int main()
{
    int n, x;
    cin >> n >> x;

    int cost[n], pages[n];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<int> dp(x + 1, -1);

    dp[0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = x; j >= cost[i]; j--)
        {
            if (dp[j - cost[i]] != -1)
                dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }

    cout << *max_element(dp.begin(), dp.end());
}