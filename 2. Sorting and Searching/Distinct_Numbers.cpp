#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar, ar + n);

    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        int ind = i;

        while (i < n && ar[ind] == ar[i])
            i++;
        cnt++;
    }

    cout << cnt;
}