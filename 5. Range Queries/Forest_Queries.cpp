#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<vector<int>> dp(n, vector<int>(n));
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            dp[i][j] = (c == '*');
            if (i != 0)
                dp[i][j] += dp[i - 1][j];
            if (j != 0)
                dp[i][j] += dp[i][j - 1];
            if (i != 0 && j != 0)
                dp[i][j] -= dp[i - 1][j - 1];
        }

    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, y2--, x1--, x2--;
        int valr = (y1 == 0) ? 0 : dp[y1 - 1][x2];
        int valc = (x1 == 0) ? 0 : dp[y2][x1 - 1];
        int valcm = (x1 == 0 || y1 == 0) ? 0 : dp[y1 - 1][x1 - 1];

        cout << dp[y2][x2] - valr - valc + valcm << '\n';
    }
}