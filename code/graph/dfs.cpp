// DFS

// Traverses the entire connected component starting from vertex "u".

// O(n + m)

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) dfs(adj, visited, v);
    }
}