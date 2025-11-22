#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dfs(int n, vector<vector<int> > &adj, vector<bool> &vis, vector<int> &ciclo, int atual, int anterior) {
    if (vis[atual]) return atual;
    vis[atual] = true;

    for (int nxt : adj[atual]) {
        if (nxt == anterior) continue;
        int fim = dfs(n, adj, vis, ciclo, nxt, atual);

        if (fim == -2) return -2;
        if (fim != -1) {
            ciclo.push_back(atual);
            if (atual == fim) return -2;
            return fim;
        }
    }

    return -1;
}

bool find_ciclo(int n, vector<vector<int> > &adj, vector<bool> &vis, vector<int> &ciclo) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ciclo.clear();

            int result = dfs(n, adj, vis, ciclo, i, -1);
            if (result != -1) {
                return true;
            }
        }
    }
    return false;
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

    vector<bool> vis(n);
    vector<int> ciclo;
    bool possible = find_ciclo(n, adj, vis, ciclo);

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
    } else {

        cout << ciclo.size() + 1 << endl;
        cout << ciclo[ciclo.size() - 1] + 1 << " ";
        for (int i = 0; i < ciclo.size(); i++) {
            cout << ciclo[i] + 1 << " ";
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