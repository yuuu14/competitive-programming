#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<ll, ll> node;
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E1, E2, T;
    cin >> V >> E1 >> E2 >> T;
    vector<vector<node>> g(V); // negative weight for long-distance
    for (ll i = 0, u, v, w; i < E1; i++) {
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (ll i = 0, u, v, w; i < E2; i++) {
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, -w});
        g[v].push_back({u, -w});
    }

    // Dijkstra
    vector<ll> dist(V, INF);
    dist[0] = 0;
    priority_queue<node, vector<node>, greater<node>> pq{};
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [v, d] = pq.top(); pq.pop();
        if (d > dist[v]) continue;  // lazy deletion
        for (auto& [u, w] : g[v]) {
            if (w < 0) continue;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({u, dist[u]});
            }
        }
    }
    cout << dist[V-1] << "\n";
    
    return 0;
}

