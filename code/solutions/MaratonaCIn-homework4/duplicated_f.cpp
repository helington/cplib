pair<ll, bool> bellman_ford(vector<tuple<int,int,int>> &edges, int n) {
    vector<ll> distFrom0(n, -INF);
    distFrom0[0] = 0;

    for (int i = 0 ; i < n - 1; i++) {
        for (auto edge : edges) {
            auto [w, u, v] = edge;
            distFrom0[v] = max(distFrom0[v], distFrom0[u] + w);
        }
    }

    bool cicloNegativoFrom0 = false;
    for (auto [w, u, v] : edges) {
        if (distFrom0[v] < distFrom0[u] + w) cicloNegativoFrom0 = true;
    }

    vector<ll> distFromN(n, -INF);
    distFromN[n - 1] = 0;

    for (int i = 0 ; i < n - 1; i++) {
        for (auto edge : edges) {
            auto [w, u, v] = edge;
            distFromN[v] = max(distFromN[v], distFromN[u] + w);
        }
    }

    bool cicloNegativoFromN = false;
    for (auto [w, u, v] : edges) {
        if (distFromN[v] < distFromN[u] + w) cicloNegativoFrom0 = cicloNegativoFromN;
    }

    bool cicloNegativo = cicloNegativoFrom0 and cicloNegativoFromN;

    return {distFrom0[n - 1], cicloNegativo};
}
