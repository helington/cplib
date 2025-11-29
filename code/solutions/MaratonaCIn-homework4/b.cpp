#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
#define endl '\n'

const ll INF=1e9*2500;

bool bellman_ford(vector<tuple<int, int, int>> &edges, vi &ciclo, vector<ll> &dist, int s, int n) {
    dist[s] = 0;
    vector<int> parent(n, -1);

    for (int i = 0 ; i < n - 1; i++) {
        for (auto edge : edges) {
            auto [w, u, v] = edge;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    bool possible = false;
    int v_ciclo;
    int initial_v;
    for (auto [w, u, v] : edges) {
        if (dist[v] > dist[u] + w) {
            parent[v] = u;
            v_ciclo = v;
            possible = true;
            break;
        };
    }

    if (possible) {
        f(i, 0, n) v_ciclo = parent[v_ciclo];
        initial_v = v_ciclo;
        while (true) {
            ciclo.push_back(v_ciclo);
            v_ciclo = parent[v_ciclo];
            if (v_ciclo == initial_v) break;
        }
        ciclo.push_back(v_ciclo);
        reverse(all(ciclo));
    }

    return possible;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    f(i, 0, m) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a - 1, b - 1};
    }

    vi ciclo;
    vector<ll> dist(n, INF);
    bool possible = bellman_ford(edges, ciclo, dist, 0, n);
    if (!possible) cout << "NO";
    else {
        cout << "YES" << endl;
        for (auto v : ciclo) cout << v + 1 << " ";
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