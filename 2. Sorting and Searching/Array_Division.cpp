#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool func(vector<int> &ar, int k, ll mx)
{
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (sum + ar[i] > mx)
        {
            sum = ar[i];
            cnt++;
        }
        else
            sum += ar[i];
    }
    cnt++;
    return cnt <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> ar(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        sum += ar[i];
    }

    ll low = *max_element(ar.begin(), ar.end());
    ll high = sum;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (func(ar, k, mid))
        {
            high = mid - 1;
            ans = mid;
        }
        else
            low = mid + 1;
    }
    cout << ans;
}