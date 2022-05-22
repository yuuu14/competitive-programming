#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

// toposort
void dfs(vector<vector<ll>>& g, vector<bool>& visited, deque<ll>& dq, ll v) {
    visited[v] = true;
    for (auto& u : g[v])
        if (!visited[u]) dfs(g, visited, dq, u);
    dq.push_front(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll V, E; cin >> V >> E;
    vector<ll> gold(V, 0), cur_max(V, 0);
    for (auto& g : gold) cin >> g;
    vector<vector<ll>> g(V);
    for (ll i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    vector<bool> visited(V, false);
    deque<ll> dq{};
    for (ll i = 0; i < V; i++)
        if (!visited[i])
            dfs(g, visited, dq, i);
    
    ll res = 0;
    for (auto& u : dq) {
        cur_max[u] += gold[u];
        res = max(res, cur_max[u]);
        for (auto& v : g[u]) {
            cur_max[v] = max(cur_max[v], cur_max[u]);
        }
    }
    cout << res << "\n";

    return 0;
}

