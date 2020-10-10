#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
#define F first
#define S second

int bs(vector<pi> &ar, int low, int target)
{
    int high = ar.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ar[mid].F == target)
            return ar[mid].S;
        else if (ar[mid].F < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i].F;
        ar[i].S = i + 1;
    }

    sort(ar.begin(), ar.end());

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
        {
            int ind = bs(ar, j + 1, x - ar[i].F - ar[j].F);
            if (ind != -1)
            {
                cout << ar[i].S << ' ' << ar[j].S << ' ' << ind;
                return 0;
            }
        }

    cout << "IMPOSSIBLE";
}
