#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n, q; cin >> n >> q;

    vector<pair<int,int> > v(n);
    vector<int> c;
    int a, b;
    for (int i = 0 ; i < n; i++) {
        cin >> a >> b;
        v[i] = make_pair(a, b);
        c.push_back(a);
        c.push_back(b);
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    int sz = c.size();
    vector<int> contador(sz + 1, 0);
    vector<int> psum(sz + 1, 0);

    map<int, int> mp;

    for (auto [l, r]: v) {
        int pos1 = lower_bound(c.begin(), c.end(), l) - c.begin();
        int pos2 = lower_bound(c.begin(), c.end(), r) - c.begin();
        contador[pos1]++; contador[pos2]--;
        if (mp.count(r)) {
            mp[r]++;
        } else {
            mp[r] = 1;
        }
    }

    for (int i = 1; i <= sz; i++) {
        psum[i] = psum[i - 1] + contador[i - 1];
    }

    int t;
    int x;
    while (q--) {
        cin >> t;
        x = psum[(upper_bound(c.begin(), c.end(), t) - c.begin())];
        if (mp.count(t)) {
            x += mp[t];
        }
        cout << x << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}