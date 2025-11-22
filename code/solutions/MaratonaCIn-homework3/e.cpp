#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void bfs(vector<vector<pii> > &adj, vector<int> &dist, pii b, vector<bool> &teams) {
    dist[b.first] =  0;
    queue<pii> q;
    q.push(b);

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        for (pii v : adj[u.first]) {
            if (dist[v.first] == -1) {
                dist[v.first] = dist[u.first] + v.second;
                if (dist[v.first] % 2 != 0) teams[v.first] = true;
                q.push(v);
            }
        }
    }
}

int solve() {
    int n; cin >> n;

    vector<vector<pii> > adj(n);
    vector<ll> dist(n, -1);
    vector<pii> distances;
    int a, b, w;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> w;
        adj[a - 1].push_back(make_pair(b - 1, w));
        adj[b - 1].push_back(make_pair(b - 1, w));
    }

    pii initial = adj[0];

    vector<bool> teams(n, false);
    bfs(adj, dist, dist, initial, teams);


    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}