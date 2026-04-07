#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

// Dp para resolver o problema das vitaminas: encontrar a melhor mascara cheia de 1

const ll INF = 1e18;
const int BITS = 3;

void solve() {
    int n; cin >> n;

    vector<pair<ll, string>> juices(n);
    for(int i = 0; i < n; i++) {
        cin >> juices[i].first;
        cin >> juices[i].second;
    }

    vector<ll> dp(1<<BITS, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int mask = 0;
        for (char vitamin : juices[i].second) {
            if (vitamin == 'A') mask |= 1;
            else if (vitamin == 'B') mask |= 2;
            else if (vitamin == 'C') mask |= 4;
        }

        for (int j = 0; j < 1<<BITS; j++) {
            int x = j | mask;
            dp[x] = min(dp[x], dp[j] + juices[i].first);
        }
    }

    if (dp[7] == INF) cout << -1 << endl;
    else cout << dp[7] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}