#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0 ; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> b(m);
    for (int i = 0 ; i < m; i ++) cin >> b[i];
    sort(b.begin(), b.end());

    int pointer = 0;
    int total = 0;
    for (int i = 0; i < m; i++) {
        while (pointer < n) {
            if (b[i] - k <= a[pointer] and a[pointer] <= b[i] + k) {
                total++;
                pointer++;
                break;
            } else if (a[pointer] < b[i] - k) {
                pointer++;
            } else {
                break;
            }
        }
    }

    cout << total << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}