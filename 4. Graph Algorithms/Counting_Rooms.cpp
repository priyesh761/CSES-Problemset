#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007
#define init ios::sync_with_stdio(0), cin.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pi;
#define MS(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void bfs(vector<vector<char>> &G, vector<vector<bool>> &vis, int i, int j)
{

    queue<pair<int, int>> qu;
    qu.push({i, j});
    vis[i][j] = 1;
    while (!qu.empty())
    {
        int x, y;
        tie(x, y) = qu.front();
        qu.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < G.size() && ny >= 0 && ny < G[0].size() && G[nx][ny] == '.' && vis[nx][ny] == 0)
            {
                qu.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    init;
    int n, m;

    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            //cout << i << ' ' << j << endl;
            if (v[i][j] == '.' && vis[i][j] == 0)
            {
                cnt++;
                bfs(v, vis, i, j);
            }
        }

    cout << cnt;
}