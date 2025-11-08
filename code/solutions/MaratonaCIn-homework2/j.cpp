#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int solve() {
    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0 ; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int gongolas = 0;
    int right = n - 1;
    int left = 0;
    while (left <= right) {
        if (p[left] + p[right] <= x) {
            left++;
        }
        right--;
        gongolas++;
    }

    cout << gongolas << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}