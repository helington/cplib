#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
#define endl '\n'

ll djikstra(vector<vector<pll>> &adj, vector<pii> &times, const int n, const int i) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, i});
    dist[i] = 0;

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();

        if (d <= dist[v]) {
            for (auto [u, w] : adj[v]) {
                auto time = times[u];
                auto [r, g] = time;
                ll current_w = dist[v] + w;
                if (u != n - 1 and current_w >= r and current_w % (r + g) >= r) {
                    current_w += (r + g) - (current_w % (r + g));
                }
                if (dist[u] > current_w) {
                    dist[u] = current_w;
                    pq.push({dist[u], u});
                }
            }
        }
    }

    return dist[n - 1];
}

int solve() {
    int n, m; cin >> n >> m;

    vector<pii> times(n);
    f(i, 0, n) cin >> times[i].first >> times[i].second;

    vector<vector<pll>> adj(n);
    f(i, 0, m) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    ll ans = djikstra(adj, times, n, 0);
    cout << ans << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}