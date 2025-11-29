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

void dijkstra(vector<vector<tuple<ll, ll>>> &adj, vl &dist) {
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, greater<tuple<ll, ll>>> pq;

    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();

        if (d <= dist[v]) {
            for (auto [u, w] : adj[v]) {
                if (dist[u] > dist[v] + w) {
                    dist[u] = dist[v] + w;
                    pq.push({dist[u], u});
                }
            }
        }
    }
}