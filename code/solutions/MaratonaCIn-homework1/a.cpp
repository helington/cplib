#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

int solve()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<ll> psum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        psum[i + 1] = psum[i] + p[i];
    }

    int q, l, r;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        auto it_lower = lower_bound(x.begin(), x.end(), l);
        int l_index = it_lower - x.begin();

        auto it_upper = upper_bound(x.begin(), x.end(), r);
        int r_index = it_upper - x.begin() - 1;

        if (l_index <= r_index)
        {
            cout << psum[r_index + 1] - psum[l_index] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}