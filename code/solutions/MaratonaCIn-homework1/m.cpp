#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    multiset<int> window_r;
    multiset<int> window_l;
    int bound = k % 2 == 0 ? k / 2 - 1 : k / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (i < k)
        {
            window_r.insert(a[i]);
        }
    }

    for (int i = 0; i <= bound; i++) {
        window_l.insert(*window_r.begin());
        window_r.erase(window_r.begin());
    }

    int median = *--window_l.end();
    cout << median;
    for (int left = 0, right = k; right < n; right++, left++) {
        if (a[right] > median) {
            window_r.insert(a[right]);
        } else {
            window_l.insert(a[right]);
        }

        if (a[left] > median) {
            window_r.erase(window_r.find(a[left]));
        } else {
            window_l.erase(window_l.find(a[left]));
        }

        while (window_r.size() > window_l.size()) {
            auto k = window_r.begin();
            window_l.insert(*k);
            window_r.erase(k);
        }

        while (window_l.size() > bound + 1) {
            auto k = --window_l.end();
            window_r.insert(*k);
            window_l.erase(k);
        }

        median = *--window_l.end();
        cout << " "<< median;
    }
    cout << endl;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}