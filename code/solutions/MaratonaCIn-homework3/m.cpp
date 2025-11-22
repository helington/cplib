#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

pair<int, int> move(vector<string> &grid, int i, int j) {
    if (grid[i][j] == 'N') {
        i--;
    } else if (grid[i][j] == 'S') {
        i++;
    } else if (grid[i][j] == 'E') {
        j++;
    } else {
        j--;
    }
    return make_pair(i, j);
}

int find_solution(
    int n, int m, vector<string> &grid, vector<vector<bool> > &vis,
    int i, int j, int &steps, int &loop_steps, int &i_loop, int &j_loop
    ) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return -1;
    }
    if (vis[i][j]) {
        i_loop = i; j_loop = j;
        return -3;
    }
    vis[i][j] = true;
    steps++;
    auto [nxt_i, nxt_j] = move(grid, i, j);

    int solution = find_solution(n, m, grid, vis, nxt_i, nxt_j, steps, loop_steps, i_loop, j_loop);
    if (solution == -2) return -2;
    if (solution == -3) {
        loop_steps++;
        if (i_loop == i and j_loop == j) return -2;
    }
    return solution;
}

int solve() {
    int n, m, k;

    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) {
            break;
        }

        vector<vector<bool> > vis(n, vector<bool>(m, false));
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        int steps = 0, loop_steps = 0, i_loop = 0, j_loop = 0;
        int solution = find_solution(n, m, grid, vis, 0, k - 1, steps, loop_steps, i_loop, j_loop);

        if (solution == -1) {
            cout << steps << " step(s) to exit" << endl;
        } else {
            cout << steps - loop_steps << " step(s) before a loop of " << loop_steps << " step(s)" << endl;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}