// Undirected Graph Cycle Detection & Extraction

// Finds a single cycle in an undirected graph and stores it in `cycle`.
// Return states:
//  -1 : No cycle found in this DFS branch.
//  -2 : Cycle has been found and fully built. Stop adding nodes.
// >= 0 : Cycle is currently being built. 'last' is the start/end node of the cycle.

int get_cycle(vector<vector<int>> &adj, vector<bool> &vis, vector<int> &cycle, int u, int past=-1) {
    if (vis[u]) return u;
    vis[u] = true;
    
    for (int v : adj[u]) {
        if (v == past) continue;
        int last = get_cycle(adj, vis, v, u);

        if (last == -2) return -2;
        if (last != -1) {
            cycle.push_back(u);
            if (u == last) return -2;
            else return last;
        }
    }

    return -1;
}