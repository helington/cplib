#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>

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

void make_dist(vector<vector<int> > &dist, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            dist[i][j] = -1;
        }
    }
}

void bfs_monsters(
    vector<string> &maze, vector<vector<vector<pii> > > &adj, vector<vector<int> > &dist, vector<pii> &monsters, int n, int m
    ) {
    queue<pii> q;
    for (auto [v_i, v_j] : monsters) {
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

char compute_step(pii current_step, pii past_step) {
    auto [current_step_i, current_step_j] = current_step;
    auto [past_step_i, past_step_j] = past_step;

    char step;
    if (current_step_i > past_step_i) step = 'D';
    else if (current_step_i < past_step_i) step = 'U';
    else if (current_step_j > past_step_j) step = 'R';
    else step = 'L';

    return step;
}

bool bfs_person(
    vector<string> &maze, vector<vector<vector<pii> > > &adj,
    vector<vector<int> > &dist_monsters, vector<vector<int> > &dist_person,
    pii &person, string &steps, int n, int m
    ) {
    auto [person_i, person_j] = person;
    if (person_i == n - 1 or person_j == m - 1 or person_i == 0 and person_j == 0) return true;

    queue<pii> q;
    q.push(person);

    dist_person[person_i][person_j] = 0;
    pii initial_pair = make_pair(-1, -1);
    vector<vector<pii> > parent(n, vector<pii>(m, initial_pair));

    bool possible = false;
    pii destiny;
    while (!q.empty()) {
        auto [u_i, u_j] = q.front(); q.pop();
        for (auto [v_i, v_j] : adj[u_i][u_j]) {
            if (dist_person[v_i][v_j] == -1) {
                parent[v_i][v_j] = make_pair(u_i, u_j);
                dist_person[v_i][v_j] = dist_person[u_i][u_j] + 1;
                if (dist_monsters[v_i][v_j] != -1 and dist_monsters[v_i][v_j] <= dist_person[v_i][v_j]) {
                    continue;
                }

                pii v = make_pair(v_i, v_j);
                if (v_i == n - 1 or v_j == m - 1 or v_i == 0 or v_j == 0) {
                    destiny = v;
                    possible = true;
                    break;
                }
                q.push(v);
            }
        }
    }

    if (possible) {
        pii current = destiny;
        while (current != make_pair(-1, -1)) {
            auto [current_i, current_j] = current;
            if (parent[current_i][current_j] != make_pair(-1, -1)) steps += compute_step(current, parent[current_i][current_j]);
            current = parent[current_i][current_j];
        }
        reverse(steps.begin(), steps.end());
    }

    return possible;
}

bool solve_maze(
    vector<string> &maze, string &steps, vector<pii> monsters,
    pii person, int n, int m
    ){
    vector<vector<vector<pii> > > adj(n, vector<vector<pii> >(m));
    make_graph(maze, adj, n, m);

    vector<vector<int> > dist_monsters(n, vector<int>(m));
    make_dist(dist_monsters, n, m);
    bfs_monsters(maze, adj, dist_monsters, monsters, n, m);

    vector<vector<int> > dist_person(n, vector<int>(m));
    make_dist(dist_person, n, m);
    return bfs_person(maze, adj, dist_monsters, dist_person, person, steps, n, m);
}

int solve() {
    int n, m; cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0; i < n; i++) cin >> maze[i];

    vector<pii> monsters;
    pii person;
    for (int i = 0 ; i < n; i++) for (int j = 0; j < m; j++) if (maze[i][j] == 'M') monsters.push_back(make_pair(i, j)); else if (maze[i][j] == 'A') person = make_pair(i, j);

    string steps = "";
    bool ans = solve_maze(maze, steps, monsters, person, n, m);

    if (!ans) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << steps.size() << endl;
        cout << steps << endl;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}