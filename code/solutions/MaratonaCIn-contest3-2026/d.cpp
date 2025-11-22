#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int solve() {
    int n, k; cin >> n >> k;

    vector<int> h(n);
    int maximum_heigth = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        if (h[i] > maximum_heigth) maximum_heigth = h[i];
    }

    int height = h[k - 1] + 1;
    sort(h.begin(), h.end());
    int water_level = 1;
    int time_to_teleport;
    int next_teleport;
    bool possible = true;

    while (height - 1 != maximum_heigth) {
        next_teleport = lower_bound(h.begin(), h.end(), height) - h.begin();
        time_to_teleport = h[next_teleport] - height + 1;
        water_level += time_to_teleport;

        if (water_level > height) {
            possible = false;
            break;
        }
        height = h[next_teleport] + 1;
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}