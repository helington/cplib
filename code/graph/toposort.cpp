// Topological Sort (Kahn's Algorithm)

// Given a DAG, returns a linear ordering of vertices such that for every edge u -> v, u comes before v.
// If ord.size() != n, it's impossible to make a toposort.

// O(n + m)

int n;

vector<int> toposort(vector<vector<int>> &adj) {
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v = : adj[u]) indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ord;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    return ord;
}