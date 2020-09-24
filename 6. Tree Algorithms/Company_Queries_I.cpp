#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    int c_size = (int)ceil(log2(n));
    vector<vector<int>> parent(n, vector<int>(c_size, -1));

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        x--;
        parent[i][0] = x;
    }

    //Binary lifting
    for (int j = 1; j < c_size; j++)
        for (int i = 0; i < n; i++)
        {
            int par = parent[i][j - 1];
            if (par != -1)
                parent[i][j] = parent[par][j - 1];
        }

    while (q--)
    {
        int x, k;
        cin >> x >> k;

        int par = (k >= n) ? -1 : x - 1;
        while (k > 0 && par != -1)
        {
            int pow = 0;
            while (k >= (1 << pow))
                pow++;
            pow--;
            k -= (1 << pow);
            par = parent[par][pow];
        }

        cout << par + (par != -1) << '\n';
    }
}