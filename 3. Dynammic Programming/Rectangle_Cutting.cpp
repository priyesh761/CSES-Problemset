//Recursive DP gives TLE go for iterative DP.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(510, vector<int>(510, INT_MAX));

int main()
{
    int a, b;
    cin >> a >> b;

    for (int height = 1; height <= a; height++)
        for (int width = 1; width <= b; width++)
        {
            if (height == width)
                dp[height][width] = 0;
            else
            {
                for (int i = 1; i < height; i++)
                    dp[height][width] = min(dp[height][width], 1 + dp[height - i][width] + dp[i][width]);

                for (int i = 1; i < width; i++)
                    dp[height][width] = min(dp[height][width], 1 + dp[height][width - i] + dp[height][i]);
            }
        }
    cout << dp[a][b];
}