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

vector<pll> djikstra(vector<vector<pll>> &adj, const ll n, const ll l, const ll i) {
    vector<pll> dist(n);
    vector<bool> vis(n, false);
    f(j, 0, n) dist[j] = {LLONG_MAX, LLONG_MAX};
    dist[i] = {0, l};

    ll v;
    pll mn;
    f(i, 0, n) {
        v = -1;
        mn = {LLONG_MAX, LLONG_MAX};
        f(j, 0, n) if (!vis[j] && ((dist[j].first < mn.first) or (dist[j].first == mn.first && dist[j].second > mn.second))) {
            mn = dist[j];
            v = j;
        }
        if (v==-1) break;
        vis[v] = true;
        for (auto [u, w] : adj[v]) {
            pii dist_v_w = dist[v];
            if (dist_v_w.second - w >= 0) {
                dist_v_w.second -= w;
            } else {
                dist_v_w.second = l - w;
                dist_v_w.first++;
            }

            if (dist[u].first > dist_v_w.first or (dist[u].first == dist_v_w.first && dist[u].second < dist_v_w.second)) {
                dist[u] = dist_v_w;
            }
        }
    }

    return dist;
}

int solve() {
    ll n, m, l;
    cin >> n >> m >> l;

    vector<vector<pll>> adj(n);
    f(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c; a--; b--;
        if (c > l) continue;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<vector<pll>> dists(n);
    f(i, 0, n) {
        dists[i] = djikstra(adj, n, l, i);
    }

    ll q; cin >> q; while (q--) {
        ll s, t; cin >> s >> t; s--; t--;
        auto [ans, x] = dists[s][t];
        if (ans == LLONG_MAX) cout << -1;
        else cout << ans;
        cout << endl;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}