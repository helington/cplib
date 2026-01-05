// Bipartite (2-Coloring)

// Checks if a graph can be colored with 2 colors such that no two adjacent nodes share the same color.

// O(n + m)

bool bipartite(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &color, int u) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            color[v] = !color[u];
            if (!bipartite(adj, visited, color, v)) return false;
        }
        else if (color[u] == color[v]) return false;
    }

    return true;
}