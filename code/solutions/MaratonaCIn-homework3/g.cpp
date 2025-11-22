#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

int bfs(vector<vector<int> > &adj, vector<int> &dist, int b, int &greatest_dist) {
    dist[b] =  0;
    queue<int> q;
    q.push(b);
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
    int n, m; cin >> n >> m;

    vector<vector<int> > adj(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> dist(n, -1);
    int greatest_dist = 0;
    int node_a = bfs(adj, dist, 0, greatest_dist);

    vector<int> distA(n, -1);
    greatest_dist = 0;
    int node_b = bfs(adj, distA, node_a, greatest_dist);

    vector<int> distB(n, -1);
    greatest_dist = 0;
    bfs(adj, distB, node_b, greatest_dist);

    if (find(distB.begin(), distB.end(), -1) != distB.end()) {
        cout << "=[" << endl;
    } else {
        cout << "=] " << greatest_dist << endl;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}