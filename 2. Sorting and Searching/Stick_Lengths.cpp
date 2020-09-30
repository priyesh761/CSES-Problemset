#include <bits/stdc++.h>

using namespace std;

long long F(vector<int> &ar, int ind)
{
    long long cost = 0;
    for (auto i : ar)
        cost += abs(i - ar[ind]);
    return cost;
}
int main()
{
    int n;
    cin >> n;

    vector<int> ar(n);

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar.begin(), ar.end());

    int mid = n / 2;
    long long mi = F(ar, mid);
    cout << mi;
}