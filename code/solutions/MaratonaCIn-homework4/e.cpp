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

vector<ll> djikstra(vector<vector<pll>> &adj, int n, int i) {
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, i});
    dist[i] = 0;

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();

        if (d <= dist[v]) {
            for (auto [u, w] : adj[v]) {
                if (dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;
                    pq.push({dist[u], u});
                }
            }
        }
    }

    return dist;
}

ll shortest_path(vector<vector<pll>> &adj, const vi &friends, const int n, const int f) {
    vector<vector<ll>> friend_dists(f);

    f(i, 0, f) {
        friend_dists[i] = djikstra(adj, n, friends[i]);
    }

    vi friends_i(f);
    f(i, 0, f) friends_i[i] = i;

    auto origin_dist = djikstra(adj, n, 0);

    ll shortest = LLONG_MAX;
    do {
        ll current_shortest;
        current_shortest = origin_dist[friends[friends_i[0]]];
        f(i, 0, f - 1) {
            int current_i = friends_i[i]; int next_i = friends[friends_i[i + 1]];
            current_shortest += friend_dists[current_i][next_i];
        }
        current_shortest += friend_dists[friends_i[f - 1]][n - 1];
        shortest = min(shortest, current_shortest);

    } while (next_permutation(all(friends_i)));

    return shortest;
}

int solve() {
    int n, m , f; cin >> n >> m >> f;

    vector<vector<pll>> adj(n);
    f(i, 0, m) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vi friends(f);
    f(i, 0, f) {
        int a; cin >> a; a--;
        friends[i] = a;
    }

    ll ans = shortest_path(adj, friends, n, f);
    cout << ans << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; f(i, 1, tc + 1) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}