#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    sort(l.begin(), l.end());

    vector<int> r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    sort(r.begin(), r.end());

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int price = l[i] + r[i];
        if (price > k)
        {
            break;
        }
        k -= price;
        total++;
    }

    cout << total << endl;

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}