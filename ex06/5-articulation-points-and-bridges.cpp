#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define debug(x) (cerr << #x << ": " << (x) << endl)
const auto INF = numeric_limits<ll>::max();

const ll UNVISITED = -1;
void dfs(vector<vector<ll>>& g, 
         vector<ll>& dfs_num, vector<ll>& dfs_min, vector<ll>& dfs_parent,
         vector<ll>& APs, vector<pair<ll, ll>>& bridges, 
         ll& dfs_counter, ll& dfs_root, ll& root_children, ll u) {
    dfs_min[u] = dfs_num[u] = dfs_counter++;
    for (auto v : g[u]) {
        if (dfs_num[v] == UNVISITED) { // tree edge
            dfs_parent[v] = u;
            if (u == dfs_root) root_children++;

            dfs(g, dfs_num, dfs_min, dfs_parent, APs, bridges, dfs_counter, dfs_root, root_children, v);

            if (dfs_num[u] <= dfs_min[v] && u != dfs_root) APs.push_back(u);
            if (dfs_num[u] < dfs_min[v]) bridges.push_back({u, v});
            dfs_min[u] = min(dfs_min[u], dfs_min[v]);
        } else if (v != dfs_parent[u]) // back edge
            dfs_min[u] = min(dfs_min[u], dfs_num[v]);
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    ll V;
    vector<vector<ll>> g(V); 

    ll dfs_counter = 0, dfs_root, root_children;
    vector<ll> dfs_num(V, UNVISITED), dfs_min(V, UNVISITED), dfs_parent(V, -1);
    vector<ll> APs{}; vector<pair<ll, ll>> bridges{};
    for (ll i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED) {
            dfs_root = i; root_children = 0;
            dfs(g, dfs_num, dfs_min, dfs_parent, APs, bridges, dfs_counter, dfs_root, root_children, i);
            if (root_children > 1) { APs.push_back(i); }
        }

    return 0;
}

