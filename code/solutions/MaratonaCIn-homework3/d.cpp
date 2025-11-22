#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

bool dfs(int i, vector<vector<int> > &adj,vector<bool> &vis, vector<bool> &team, int n) {
    vis[i] = true;
    for (int &u: adj[i]) {
        if (!vis[u]) {
            team[u] = !team[i];
            if (!dfs(u, adj, vis, team, n)) return false;
        }
        else if (team[i]== team[u]) return false;
    }
    return true;
}

bool fill_teams(vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &team, int n) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (!dfs(i, adj, vis, team, n)) {
                return false;
            }
        }
    }
    return true;
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

    vector<bool> vis(n), team(n);
    bool possible = fill_teams(adj, vis, team, n);

    if (possible) {
        for (int i = 0; i < n; i++) {
            if (team[i]) {
                cout << "2";
            } else {
                cout << "1";
            }
            cout << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}