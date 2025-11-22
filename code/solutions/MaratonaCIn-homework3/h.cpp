#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool toposort(vector<vector<int> > &adj, vector<int> &deg, vector<pii> &edges, vector<int> &ord) {
    for (auto [u, v]: edges) {
        deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ord.push_back(u);
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }

    if (ord.size() != 26) return false;
    return true;
}

int solve() {
    int n; cin >> n;

    vector<vector<int> > adj(26);
    vector<int> deg(26, 0);
    vector<pii> edges;

    string s;
    for (int i = 0 ; i < n ; i++) {
        cin >> s;
        for (int i = 1 ; i < s.length() ; i++) {
            if (s[i] != s[i-1]) {
                adj[s[i - 1]-'a'].push_back(s[i]-'a');
                edges.push_back(make_pair(s[i - 1]-'a', s[i]-'a'));
            }
        }
    };

    vector<int> ord;
    bool possible = toposort(adj, deg, edges, ord);

    if (!possible) {
        cout << "NAO" << endl;
    } else {
        cout << "SIM" << endl;
        for (int i = 0; i < ord.size(); i++) {
            char c = ord[i] + 'a';
            cout << c;
        }
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