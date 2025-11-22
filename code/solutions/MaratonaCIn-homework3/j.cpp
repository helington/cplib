#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool toposort(int n, vector<vector<int> > &adj, vector<int> &deg, vector<pii> &edges, vector<int> &ord) {
    for (auto [u, v]: edges) {
        deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    if (ord.size() != n) return false;
    return true;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<vector<int> > adj(n);
    vector<int> deg(n, 0);

    vector<pii> edges;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
        edges.push_back(make_pair(a - 1, b - 1));
    }

    vector<int> ord;
    bool possible = toposort(n, adj, deg, edges, ord);

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < ord.size(); i++) {
            cout << ord[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}