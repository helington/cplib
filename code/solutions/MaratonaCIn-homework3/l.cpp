#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>

int bfs(vector<vector<pii> > &adj, vector<int> &dist, vector<int> &p, vector<bool> &used_edges, int n) {
    queue<int> q;
    for (int v : p) {
        dist[v] = 0;
        q.push(v);
    }
    int edges = 0;
    vector<vector<int> > newAdj(n);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, i] : adj[u]) {
            if (dist[v] == -1) {
                newAdj[v].push_back(u);
                newAdj[u].push_back(v);
                dist[v] = dist[u] + 1;
                used_edges[i] = true;
                edges++;
                q.push(v);
            }
        }
    }

    return edges;
}

int solve() {
    int n, k, d; cin >> n >> k >> d;

    vector<int> p(k);
    int a;
    for (int i = 0 ; i < k; i++) {
        cin >> a;
        p[i] = a - 1;
    }

    vector<vector<pii> > adj(n);

    int u, v;
    for (int i = 0 ; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(make_pair(v - 1, i));
        adj[v - 1].push_back(make_pair(u - 1, i));
    }

    vector<bool> used_edges(n - 1, false);
    vector<int> dist(n, -1);
    int edges = bfs(adj, dist, p, used_edges, n);

    cout << n - 1 - edges << endl;
    for (int i = 0 ; i < n - 1; i++) {
        if (!used_edges[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}