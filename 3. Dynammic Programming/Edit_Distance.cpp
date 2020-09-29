#include <bits/stdc++.h>

using namespace std;

int edit_distance(string &s, string &t, vector<vector<int>> &dp, int i, int j)
{
    if (i < 0 || j < 0)
        return max(i, j) + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        return dp[i][j] = edit_distance(s, t, dp, i - 1, j - 1);

    dp[i][j] = 1 + min({edit_distance(s, t, dp, i, j - 1),     //addition
                        edit_distance(s, t, dp, i - 1, j - 1), // replace
                        edit_distance(s, t, dp, i - 1, j)});   // deletion

    return dp[i][j];
}

int main()
{
    string s, t;

    cin >> s >> t;

    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));

    cout << edit_distance(s, t, dp, s.length() - 1, t.length() - 1);
}