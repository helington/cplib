#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int bfs(vector<vector<int> > &adj, vector<int> &dist, int b) {
    dist[b] =  0;
    queue<int> q;
    q.push(b);
    int greatest_dist = 0;
    int furthest = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > greatest_dist) {
                    greatest_dist = dist[v];
                    furthest = v;
                }
            }
        }
    }

    return furthest;
}

int solve() {
    int n; cin >> n;

    vector<vector<int> > adj(n);
    int a, b;
    for (int i = 0;i < n - 1; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> dist(n, -1);
    int node_a = bfs(adj, dist, 0);

    vector<int> distA(n, -1);
    int node_b = bfs(adj, distA, node_a);

    vector<int> distB(n, -1);
    bfs(adj, distB, node_b);

    for (int i = 0; i < n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
    cout << endl;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}