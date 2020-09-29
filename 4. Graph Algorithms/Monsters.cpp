#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'U', 'D', ' '};

void bfsM(vector<vector<char>> &G, vector<vector<int>> &path)
{
    queue<pair<int, int>> qu;
    queue<int> dist;

    for (int i = 0; i < G.size(); i++)
        for (int j = 0; j < G[i].size(); j++)
            if (G[i][j] == 'M')
            {
                qu.push({i, j});
                dist.push(0);
                path[i][j] = 0;
            }

    while (!qu.empty())
    {
        int i, j, d;
        tie(i, j) = qu.front();
        d = dist.front();
        qu.pop();
        dist.pop();

        for (int k = 0; k < 4; k++)
            if (i + dx[k] >= 0 && i + dx[k] < G.size() && j + dy[k] >= 0 && j + dy[k] < G[0].size())
                if (path[i + dx[k]][j + dy[k]] == INT_MAX && G[i + dx[k]][j + dy[k]] != '#')
                {
                    path[i + dx[k]][j + dy[k]] = d + 1;
                    qu.push({i + dx[k], j + dy[k]});
                    dist.push(d + 1);
                }
    }
}

void bfsA(vector<vector<char>> &G, vector<vector<int>> &pathM, vector<vector<short>> &pathA)
{
    queue<pair<int, int>> qu;
    queue<int> dist;

    for (int i = 0; i < G.size(); i++)
        for (int j = 0; j < G[i].size(); j++)
            if (G[i][j] == 'A')
            {
                qu.push({i, j});
                dist.push(0);
                pathA[i][j] = 0;
                break;
            }

    while (!qu.empty())
    {
        int i, j, d;
        tie(i, j) = qu.front();
        d = dist.front();
        qu.pop();
        dist.pop();

        for (int k = 0; k < 4; k++)
            if (i + dx[k] >= 0 && i + dx[k] < G.size() && j + dy[k] >= 0 && j + dy[k] < G[0].size())
                if (pathA[i + dx[k]][j + dy[k]] == 5 && pathM[i + dx[k]][j + dy[k]] > d + 1 && G[i + dx[k]][j + dy[k]] != '#')
                {
                    pathA[i + dx[k]][j + dy[k]] = k;
                    qu.push({i + dx[k], j + dy[k]});
                    dist.push(d + 1);
                }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> G(n, vector<char>(m));
    vector<vector<int>> pathM(n, vector<int>(m, INT_MAX));
    vector<vector<short>> pathA(n, vector<short>(m, 5));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> G[i][j];

    bfsM(G, pathM);
    bfsA(G, pathM, pathA);

    int x = -1, y = -1;
    int cx = -1, cy = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (pathA[i][j] != 5)
                    x = i, y = j;
            }
            if (G[i][j] == 'A')
            {
                cx = i, cy = j;
            }
        }

    if (x == -1 && y == -1)
    {
        cout << "NO";
        return 0;
    }

    string res;
    int cnt = 0;
    while (x != cx || y != cy)
    {
        res += dir[pathA[x][y]];
        int tx = dx[pathA[x][y]];
        int ty = dy[pathA[x][y]];
        x -= tx;
        y -= ty;
        cnt++;
    }

    reverse(res.begin(), res.end());

    cout << "YES\n";
    cout << res.length() << '\n';
    cout << res;
}