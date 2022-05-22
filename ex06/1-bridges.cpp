#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

const ll UNVISITED = -1;
void dfs(vector<vector<ll>>& g, 
         vector<ll>& dfs_num, vector<ll>& dfs_min, vector<ll>& dfs_parent,
         ll& dfs_counter, ll& dfs_root, ll& root_children, ll& num_bridges, ll u) {
    dfs_min[u] = dfs_num[u] = dfs_counter++;
    for (auto v : g[u]) {
        if (dfs_num[v] == UNVISITED) { // tree edge
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            dfs(g, dfs_num, dfs_min, dfs_parent, dfs_counter, dfs_root, root_children, num_bridges, v);

            if (dfs_num[u] < dfs_min[v]) num_bridges++;
            dfs_min[u] = min(dfs_min[u], dfs_min[v]);
        } else if (v != dfs_parent[u]) // back edge
            dfs_min[u] = min(dfs_min[u], dfs_num[v]);
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    ll V, E; cin >> V >> E; 
    vector<vector<ll>> g(V); 
    for (ll i = 0, u, v; i < E; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll dfs_counter = 0, dfs_root, root_children, num_bridges = 0;
    vector<ll> dfs_num(V, UNVISITED), dfs_min(V, UNVISITED), dfs_parent(V, -1);
    for (ll i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED) {
            dfs_root = i; root_children = 0;
            dfs(g, dfs_num, dfs_min, dfs_parent, dfs_counter, dfs_root, root_children, num_bridges, i);
        }
    cout << num_bridges << "\n";

    return 0;
}

