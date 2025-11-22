#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool check(vector<int> &v, int mid, int c) {
    int past_vec = v[0];
    int cows = 1;
    for (int x : v) {
        if (cows < c && x - past_vec >= mid) {
            past_vec = x;
            cows++;
        }
        if (cows == c) return true;
    }
    return false;
}

int solve() {
    int n, c; cin >> n >> c;

    vector<int> v(n);
    for (int i = 0 ; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int l = 1, r = *(v.end()-1), mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(v, mid, c)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while(tc--) {
        solve();
    }

    return 0;
}