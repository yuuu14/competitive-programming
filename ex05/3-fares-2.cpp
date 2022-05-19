#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> node; // node_id, distance, cur_num_ticket
#define debug(x) (cerr << #x << ": " << (x) << endl)
#define INF numeric_limits<ll>::max()

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E1, E2, T;
    cin >> V >> E1 >> E2 >> T;
    vector<map<ll, ll>> g(V+1); // negative node_id for long-distance
    for (ll i = 0, u, v, w; i < E1; i++) {
        cin >> u >> v >> w;
        if (g[u].find(v) != g[u].end() && g[u][v] < w) continue;
        g[u][v] = w; g[v][u] = w;
    }
    for (ll i = 0, u, v, w; i < E2; i++) {
        cin >> u >> v >> w;
        if (g[u].find(v) != g[u].end() && g[u][v] < w) continue;
        if (g[u].find(-v) != g[u].end() && g[u][-v] < w) continue;
        g[u][-v] = w; g[v][-u] = w;
    }
    // for (auto& m : g) { 
    //     static ll tmp = 0;
    //     cout << tmp++ << " ";
    //     for (auto& [u, w] : m) cout << "(" << u << "," << w << ") ";
    //     cout << "\n";
    // }
    // Dijkstra, record distance of each ticket num
    vector<vector<ll>> dist(V+1, vector(T+1, INF));
    for (auto& d : dist[1]) d = 0;
    auto compare = [&](node a, node b) { return get<1>(a) > get<1>(b); };
    priority_queue<node, vector<node>, decltype(compare)> pq(compare);
    pq.push({1, 0, T}); // start from id=1
    while(!pq.empty()) {
        auto [v, d, t] = pq.top(); pq.pop();
        if (d > dist[v][t]) continue;  // lazy deletion
        for (auto& [u, w] : g[v]) {
            if (u < 0) {
                if (t <= 0) continue;
                if (dist[-u][t-1] > dist[v][t] + w) {
                    dist[-u][t-1] = dist[v][t] + w;
                    pq.push({-u, dist[-u][t-1], t-1});
                }
            }
            else if (dist[u][t] > dist[v][t] + w) {
                dist[u][t] = dist[v][t] + w;
                pq.push({u, dist[u][t], t});
            }
        }
    }
    cout << *min_element(dist[V].begin(), dist[V].end()) << "\n";
    
    return 0;
}

