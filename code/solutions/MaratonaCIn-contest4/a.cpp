#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'

void make_graph(vector<string> &maze, vector<vector<vector<pii> > > &adj, int n, int m) {
    vector<pair<int, int> > directions(4);
    directions[0] = make_pair(1, 0); directions[1] = make_pair(0, 1); directions[2] = make_pair(-1, 0); directions[3] = make_pair(0, -1);

    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if (maze[i][j] != '#') {
                vector<pii> edges;

                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;

                    if (ni >= 0 and ni < n and nj >= 0 and nj < m and maze[ni][nj] != '#') {
                        edges.push_back(make_pair(ni, nj));
                    }
                }

                adj[i][j] = edges;
            }
        }
    }
}

void bfs(
    vector<string> &maze, vector<vector<vector<pii> > > &adj,
    vector<vector<int> > &dist, vector<pii> &exits) {
    queue<pii> q;
    for (auto [v_i, v_j] : exits) {
        q.push(make_pair(v_i, v_j));
        dist[v_i][v_j] = 0;
    }

    while (!q.empty()) {
        auto [u_i, u_j] = q.front(); q.pop();
        for (auto [v_i, v_j] : adj[u_i][u_j]) {
            if (dist[v_i][v_j] == -1) {
                dist[v_i][v_j] = dist[u_i][u_j] + 1;
                q.push(make_pair(v_i, v_j));
            }
        }
    }
}

int solve() {
    int n, q; cin >> n >> q;

    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    vector<pii> exits;
    double total_empty_cells = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (maze[i][j] == 'E') exits.push_back(make_pair(i, j));
        else if (maze[i][j] == '.') total_empty_cells++;
    };

    vector<vector<vector<pii> > > adj(n, vector<vector<pii> >(n));
    make_graph(maze, adj, n, n);

    vector<vector<int> > dist(n, vector<int>(n, -1));
    bfs(maze, adj, dist, exits);

    vector<int> cells_at_dist(n * n + 1, 0);
    for (int i = 0 ; i < n ; i++) for (int j = 0 ; j < n ; j++) if (dist[i][j] != -1 && maze[i][j] == '.') cells_at_dist[dist[i][j]]++;

    for (int i = 1 ; i < cells_at_dist.size() ; i++) {
        cells_at_dist[i] += cells_at_dist[i - 1];
    }

    for (int i = 0 ; i < q; i++) {
        int qi;
        double cells; cin >> qi;
        qi--;

        if (qi < cells_at_dist.size()) {
            cells = cells_at_dist[qi];
        } else {
            cells = total_empty_cells;
        }

        double ans = cells / total_empty_cells;

        cout << setprecision(8) <<ans << endl;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}