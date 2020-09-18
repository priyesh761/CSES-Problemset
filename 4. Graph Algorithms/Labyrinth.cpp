#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod (ll)(1e9 + 7)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    int x, y;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
                x = i, y = j;
        }

    //BFS
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    char dir[] = {'L', 'R', 'D', 'U'};
    vector<vector<char>> vis(n, vector<char>(m, 0));
    queue<pair<int, int>> qu;
    qu.push({x, y});
    vis[x][y] = 'S';

    while (!qu.empty())
    {
        tie(x, y) = qu.front();
        qu.pop();
        if (v[x][y] == 'B')
            break;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && v[tx][ty] != '#' && vis[tx][ty] == 0)
            {
                qu.push({tx, ty});
                vis[tx][ty] = dir[i];
            }
        }
    }

    string path;
    if (v[x][y] != 'B')
        cout << "NO";
    else
    {
        while (vis[x][y] != 'S')
        {
            path += vis[x][y];
            for (int i = 0; i < 4; i++)
                if (dir[i] == vis[x][y])
                {
                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
        }

        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.length() << '\n';
        cout << path;
    }
}